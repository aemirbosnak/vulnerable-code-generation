//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

// Define a structure to represent a spam message
typedef struct {
    char* message;
    int length;
} SpamMessage;

// Define a function to parse a message and extract keywords
bool parseMessage(SpamMessage* message) {
    char* word = strtok(message->message, " ");
    int count = 0;
    while (word!= NULL) {
        if (strncmp(word, "buy", 3) == 0 || strncmp(word, "free", 3) == 0 || strncmp(word, "offer", 4) == 0 || strncmp(word, "discount", 7) == 0) {
            count++;
        }
        word = strtok(NULL, " ");
    }
    if (count > 2) {
        message->length = count;
        return true;
    }
    return false;
}

// Define a function to determine if a message is spam
bool isSpam(SpamMessage* message) {
    if (message->length > 5) {
        return true;
    }
    return false;
}

// Define a function to print a message
void printMessage(SpamMessage* message) {
    printf("%s\n", message->message);
}

// Define a function to parse a message and determine if it's spam
void processMessage(SpamMessage* message) {
    if (parseMessage(message) && isSpam(message)) {
        printf("This message is spam!\n");
        printMessage(message);
    } else {
        printf("This message is not spam.\n");
    }
}

// Define a function to generate a random spam message
SpamMessage* generateSpamMessage() {
    char* message = (char*)malloc(100);
    srand(time(NULL));
    int length = rand() % 10 + 1;
    int i;
    for (i = 0; i < length; i++) {
        message[i] = 'a' + rand() % 26;
    }
    message[length] = '\0';
    return (SpamMessage*)malloc(sizeof(SpamMessage));
}

// Define a function to run the spam detection system
int main() {
    SpamMessage* message = generateSpamMessage();
    processMessage(message);
    free(message);
    return 0;
}