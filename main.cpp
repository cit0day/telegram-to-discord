/*




              Telegram Messages To Discord Webhook

              dc: cit0day / 1224772989346775043
              tg: cit0day



*/


// including main header file
#include "main.h"

// Function to send HTTP request
void sendDiscordWebhook(const std::string& webhook_url, const std::string& content) {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        Json::Value root;
        root["content"] = content;
        Json::StreamWriterBuilder writer;
        std::string json_data = Json::writeString(writer, root);

        curl_easy_setopt(curl, CURLOPT_URL, webhook_url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data.c_str());

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    curl_global_cleanup();
}

// Function to scan tellegram messages
std::string getTelegramMessages(const std::string& bot_token, const std::string& chat_id) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        std::string url = "https://api.telegram.org/bot" + bot_token + "/getUpdates?chat_id=" + chat_id;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return readBuffer;
}

// Callback function
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    std::string bot_token = "YOUR_TELEGRAM_BOT_TOKEN";
    std::string chat_id = "YOUR_CHAT_ID";
    std::string webhook_url = "YOUR_DISCORD_WEBHOOK_URL";

    // Scan Telegram Messages
    std::string messages = getTelegramMessages(bot_token, chat_id);

    // Send Messages To Webhook
    sendDiscordWebhook(webhook_url, messages);

    return 0;
}
