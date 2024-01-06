#include <iostream>
#include <string>
#include <map>

class SubscriberBook{
private:
    std::map<std::string, std::string> subscriber;

public:
    void setAddSubscriber(const std::string& name, const std::string& phoneNumber){
        subscriber[name] = phoneNumber;
    }

    const std::string& getNumberPhone(const std::string& nameSubscriber){
        auto it = subscriber.find(nameSubscriber);
        if (it != subscriber.end()){
            return  it -> second;
        } else {
            static const std::string emptyBook;
            return  emptyBook;
        }
    }
};

class Phone{
private:
    SubscriberBook book;
public:
    void addContactBook (const std::string& str1, const std::string& strNumb){
        book.setAddSubscriber(str1, strNumb);
    }

    void callPhone(){
        std::string bookEntry;
        std::cout << "Enter the name or phone number to call: ";
        std::cin >> bookEntry;

        const std::string& phoneNumber = book.getNumberPhone(bookEntry);
        if (!phoneNumber.empty()) {
            std::cout << "CALL " << phoneNumber << std::endl;
        } else {
            std::cout << "Contact not found." << std::endl;
        }
    }

    void smsPhone(){
        std::string contact, message;
        std::cout << "Enter the name or phone number to send a message: ";
        std::cin >> contact;
        std::cin.ignore();
        std::cout << "Enter the message: ";
        std::getline(std::cin, message);

        const std::string& phoneNumber = book.getNumberPhone(contact);
        if (!phoneNumber.empty()) {
            std::cout << "Sending SMS to " << phoneNumber << ": " << message << std::endl;
        } else {
            std::cout << "Contact not found." << std::endl;
        }
    }
};

int main() {
    Phone mobilePhone;
    std::string command, name, number;

    while (true){
        std::cout << "Enter command (add, call, sms, exit): ";
        std::cin >> command;

        if (command == "add") {
            std::cout << "Enter the name of the contact: ";
            std::cin >> name;
            std::cout << "Enter the phone number: ";
            std::cin >> number;
            mobilePhone.addContactBook(name, number);
        } else if (command == "call") {
            mobilePhone.callPhone();
        } else if (command == "sms") {
            mobilePhone.smsPhone();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    return 0;
}
