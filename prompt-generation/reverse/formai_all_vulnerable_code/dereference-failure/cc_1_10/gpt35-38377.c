//FormAI DATASET v1.0 Category: Spam Detection System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold information about each message
typedef struct message {
    char content[500];
    int spam;
} message;

// Function to check if a word is in the spam list
int is_spam(char* word, char** spam_list, int num_spam_words) {
    for (int i = 0; i < num_spam_words; i++) {
        if (strcmp(word, spam_list[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a message is spam
int check_spam(char* message_content, char** spam_list, int num_spam_words) {
    // Tokenize message into words
    char* word = strtok(message_content, " ");
    while (word != NULL) {
        if (is_spam(word, spam_list, num_spam_words)) {
            return 1;
        }
        word = strtok(NULL, " ");
    }
    return 0;
}

int main() {
    int num_messages = 5;
    int num_spam_words = 2;
    char* spam_list[2] = {"buy", "now"};

    // Create an array to hold the messages
    message* messages = (message*)malloc(num_messages * sizeof(message));
    messages[0].spam = 0;
    strcpy(messages[0].content, "Hi, how are you?");
    messages[1].spam = 0;
    strcpy(messages[1].content, "Want to grab lunch tomorrow?");
    messages[2].spam = 1;
    strcpy(messages[2].content, "Buy this product now!");
    messages[3].spam = 0;
    strcpy(messages[3].content, "Did you finish the report yet?");
    messages[4].spam = 1;
    strcpy(messages[4].content, "Limited time offer, buy now!");

    // Print out the messages and whether they are spam or not
    for (int i = 0; i < num_messages; i++) {
        printf("Message %d: %s\n", i, messages[i].content);
        if (check_spam(messages[i].content, spam_list, num_spam_words)) {
            printf("This message is spam!\n");
        } else {
            printf("This message is not spam.\n");
        }
    }

    // Free the malloced memory
    free(messages);

    return 0;
}