//FormAI DATASET v1.0 Category: Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Encode the message using a statistical encryption algorithm*/
void encode(char *message) {
    int length = strlen(message);
    char *newMessage = (char *) malloc(sizeof(char) * length);

    int i;
    for (i = 0; i < length; i++) {
        switch(message[i]) {
            case 'a':
                newMessage[i] = '5';
                break;
            case 'b':
                newMessage[i] = '8';
                break;
            case 'c':
                newMessage[i] = '3';
                break;
            case 'd':
                newMessage[i] = '2';
                break;
            case 'e':
                newMessage[i] = '9';
                break;
            case 'f':
                newMessage[i] = '4';
                break;
            case 'g':
                newMessage[i] = '7';
                break;
            case 'h':
                newMessage[i] = '1';
                break;
            case 'i':
                newMessage[i] = '6';
                break;
            case 'j':
                newMessage[i] = '0';
                break;
            default:
                newMessage[i] = message[i];
        }
    }

    newMessage[length] = '\0';

    printf("Original message:\n%s\n", message);
    printf("Encoded message:\n%s\n", newMessage);
}

int main() {
    char *message = "hello world";
    encode(message);
    return 0;
}