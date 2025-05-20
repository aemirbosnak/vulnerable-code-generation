//FormAI DATASET v1.0 Category: Spam Detection System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 10 // maximum number of spam words to check against
#define MAX_WORD_LENGTH 20 // maximum length of a spam word

char** get_spam_words(int num_words) {
    char** spam_words = malloc(num_words * sizeof(char*)); // allocate space for array of words
    
    printf("Enter %d spam words:\n", num_words);
    for (int i = 0; i < num_words; i++) {
        spam_words[i] = malloc(MAX_WORD_LENGTH * sizeof(char)); // allocate space for each word
        scanf("%s", spam_words[i]); // read in word from input
    }
    
    return spam_words;
}

int is_spam(char* message, char** spam_words, int num_words) {
    char* token;
    char* copy = strdup(message); // make a copy of the message to tokenize
    int spam_count = 0;

    token = strtok(copy, " "); // tokenize message by spaces
    while (token != NULL) {
        for (int i = 0; i < num_words; i++) {
            if (strcmp(token, spam_words[i]) == 0) { // compare each token to each spam word
                spam_count++;
            }
        }
        token = strtok(NULL, " ");
    }

    free(copy);
    return spam_count >= num_words / 2; // if more than half the spam words are present, it is likely spam
}

int main() {
    char** spam_words;
    char message[500];

    spam_words = get_spam_words(MAX_SPAM_WORDS);
    
    printf("Enter a message:\n");
    fgets(message, sizeof(message), stdin); // read in entire line of input
    
    if (is_spam(message, spam_words, MAX_SPAM_WORDS)) {
        printf("This message may be spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        free(spam_words[i]); // free individual word memory
    }
    free(spam_words); // free array memory
    
    return 0;
}