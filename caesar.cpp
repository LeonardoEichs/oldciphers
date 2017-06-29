#include <stdio.h>

class Caesar {
public:
  char* encrypt(int key, char *message){
    char ch;

    for (int i = 0; message[i] != '\0'; i++){
        ch = message[i];
        if (ch >= 'a' && ch <= 'z'){
            ch = ch + key;

            if (ch > 'z')
                ch = ch - 'z' + 'a' - 1;

            message[i] = ch;
        }

        else if (ch >= 'A' && ch <= 'Z'){
            ch = ch + key;

            if(ch > 'Z')
                ch = ch - 'Z' + 'A' - 1;

            message[i] = ch;
        }
    }
    return message;
  }

  char* decrypt(int key, char *message){
    char ch;
    for (int i = 0; message[i] != '\0'; i++){
        ch = message[i];
        if (ch >= 'a' && ch <= 'z'){
            ch = ch - key;

            if (ch > 'z')
                ch = ch - 'z' + 'a' - 1;

            message[i] = ch;
        }

        else if (ch >= 'A' && ch <= 'Z'){
            ch = ch - key;

            if(ch > 'Z')
                ch = ch - 'Z' + 'A' - 1;

            message[i] = ch;
        }
    }
    return message;
  }

 };


int main() {
    char message[100];
    int key;

    printf("Type message:\n>> ");
    fgets(message, 100, stdin);

    printf("Enter shift key:\n>> ");
    scanf("%d",&key);

    Caesar caesar;

    printf("Original:\n>> %s", message);

    char* encrypted = caesar.encrypt(key, message);
    printf("Encrypted:\n>> %s", encrypted);

    char* decrypted = caesar.decrypt(key, encrypted);
    printf("Decrypted:\n>> %s", decrypted);

    return 0;
}
