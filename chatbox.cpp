#include <iostream>
#include <string>

using namespace std;

void hotelChatbot() {
    string userInput;
    cout << "Welcome to Hotel Bot! How can I assist you today?" << endl;
    
    while (true) {
        cout << "> ";
        getline(cin, userInput);

        if (userInput == "book room") {
            cout << "Sure! Please provide your check-in and check-out dates." << endl;
        } else if (userInput == "amenities") {
            cout << "Our hotel offers a range of amenities including a swimming pool, gym, and spa." << endl;
        } else if (userInput == "restaurant") {
            cout << "Our hotel has an on-site restaurant serving a variety of cuisines." << endl;
        } else if (userInput == "checkout") {
            cout << "To checkout, please visit the front desk at your convenience." << endl;
        } else if (userInput == "help") {
            cout << "You can ask me about booking a room, available amenities, restaurant, or checkout process." << endl;
        } else if (userInput == "bye") {
            cout << "Thank you for choosing Hotel Bot! Have a pleasant day." << endl;
            break;
        } else {
            cout << "I'm sorry, I didn't understand that. Please type 'help' for assistance." << endl;
        }
    }
}

int main() {
    hotelChatbot();
    return 0;
}
