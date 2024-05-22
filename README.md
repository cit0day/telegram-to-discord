# Telegram to Discord Message Forwarder

This project reads messages from a Telegram group using the Telegram API, then sends those messages to a Discord webhook. It provides a seamless integration to forward messages from Telegram to Discord.

## Features

- 🔄 **Telegram to Discord Forwarding**: Automatically forward messages from a specified Telegram group to a Discord channel.
- ⚙️ **Easy Setup**: Simple configuration with your Telegram bot token and Discord webhook URL.
- 📡 **Real-time Updates**: Receive messages in real-time as they are posted in the Telegram group.

## Installation

To get started with the Telegram to Discord Message Forwarder, follow these steps:

1. **Clone the repository:**
    ```bash
    git clone https://github.com/cit0day/telegram-to-discord.git
    ```
2. **Navigate to the project directory:**
    ```bash
    cd telegram-to-discord
    ```
3. **Install the dependencies:**
    Make sure you have the `libcurl` and `jsoncpp` libraries installed.
    ```bash
    # On Ubuntu, you can install these with:
    sudo apt-get install libcurl4-openssl-dev libjsoncpp-dev
    ```
4. **Compile the program:**
    ```bash
    g++ -o telegram_to_discord telegram_to_discord.cpp -lcurl -ljsoncpp
    ```

## Usage

After installation, you can start using the Telegram to Discord Message Forwarder by following these steps:

1. **Replace the placeholders:**
    - `YOUR_TELEGRAM_BOT_TOKEN` with your Telegram bot token.
    - `YOUR_CHAT_ID` with the ID of the Telegram group.
    - `YOUR_DISCORD_WEBHOOK_URL` with the URL of the Discord webhook.

2. **Run the program:**
    ```bash
    ./telegram_to_discord
    ```

## Contributing

We welcome contributions from the community! To contribute, follow these steps:

1. Fork the repository.
2. Create a new branch:
    ```bash
    git checkout -b feature-branch
    ```
3. Make your changes and commit them:
    ```bash
    git commit -m "Add new feature"
    ```
4. Push to the branch:
    ```bash
    git push origin feature-branch
    ```
5. Open a pull request on GitHub.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Important Note

This program reads messages from the Telegram group using the Telegram API, then sends those messages to the Discord webhook. You should properly handle updating message IDs and other optimizations based on your specific needs.

---

![GitHub followers](https://img.shields.io/github/followers/cit0day?style=social)
![GitHub stars](https://img.shields.io/github/stars/cit0day/telegram-to-discord?style=social)
