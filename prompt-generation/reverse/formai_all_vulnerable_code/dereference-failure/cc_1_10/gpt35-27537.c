//FormAI DATASET v1.0 Category: Spam Detection System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000

int is_spam(char *message) {
    char *spam_keywords[] = {"free", "offer", "discount", "click here", "act now"};
    int num_keywords = sizeof(spam_keywords)/sizeof(spam_keywords[0]);
    
    char *word;
    char *message_copy = malloc(strlen(message) + 1);
    strcpy(message_copy, message);
    
    int spam_score = 0;
    
    word = strtok(message_copy, " \t\n");
    while (word != NULL) {
        for (int i = 0; i < num_keywords; i++) {
            if (strstr(word, spam_keywords[i]) != NULL) {
                spam_score++;
            }
        }
        word = strtok(NULL, " \t\n");
    }
    
    free(message_copy);
    
    if (spam_score >= 2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int is_spam_flag;
    
    printf("Enter a message:\n");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    
    is_spam_flag = is_spam(message);
    
    if (is_spam_flag) {
        printf("Warning: This message may be spam.");
    } else {
        printf("This message is not considered to be spam.");
    }
    
    return 0;
}