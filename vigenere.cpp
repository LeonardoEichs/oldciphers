#include <iostream>
#include <string>
using namespace std;

class Vigenere{
public:
    string key;

    Vigenere(string key) {
        for (int i = 0; i < key.size(); i++) {
            if (key[i] >= 'A' && key[i] <= 'Z')
                this->key += key[i];
            else if (key[i] >= 'a' && key[i] <= 'z')
                this->key += key[i] + 'A' - 'a';
        }
    }

    string encrypt(string message) {
        string result;

        for (int i = 0, j = 0; i < message.length(); ++i) {
            char c = message[i];

            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;

            result += (c + key[j] - 2*'A') % 26 + 'A';
            j = (j + 1) % key.length();
        }

        return result;
    }

    string decrypt(string message) {
        string result;

        for(int i = 0, j = 0; i < message.length(); ++i) {
          char c = message[i];

          if (c >= 'a' && c <= 'z')
              c += 'A' - 'a';
          else if (c < 'A' || c > 'Z')
              continue;

          result += (c - key[j] + 26) % 26 + 'A';
          j = (j + 1) % key.length();
        }

        return result;
    }

};

int main() {
    string key;
    cout << "Enter key:\n>> ";
    getline(cin, key);
    Vigenere cipher(key);

    string message;
    cout << "Enter message:\n>> ";
    getline(cin, message);

    string encrypted = cipher.encrypt(message);
    string decrypted = cipher.decrypt(encrypted);

    cout << "-----------------------" << endl;
    cout << "Original\n>> ";
    cout << message << endl;
    cout << "Encrypted\n>> ";
    cout << encrypted << endl;
    cout << "Decrypted\n>> ";
    cout << decrypted << endl;
}
