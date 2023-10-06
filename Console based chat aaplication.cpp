#include <iostream>
#include <vector>
#include <string>

class Message {
public:
    std::string sender;
    std::string content;

    Message(const std::string& sender, const std::string& content) : sender(sender), content(content) {}
};

class ChatRoom {
public:
    void addMessage(const std::string& sender, const std::string& content) {
        messages.push_back(Message(sender, content));
    }

    void displayMessages() const {
        for (const auto& message : messages) {
            std::cout << message.sender << ": " << message.content << std::endl;
        }
    }

private:
    std::vector<Message> messages;
};

int main() {
    ChatRoom chatRoom;

    std::string user;
    std::string message;
    
    std::cout << "Enter your name: ";
    std::getline(std::cin, user);

    std::cout << "Chat started. Type 'exit' to end the chat." << std::endl;

    while (true) {
        std::cout << user << ": ";
        std::getline(std::cin, message);

        if (message == "exit") {
            break;
        }

        chatRoom.addMessage(user, message);
    }

    std::cout << "Chat ended. Here is the chat history:" << std::endl;
    chatRoom.displayMessages();

    return 0;
}
