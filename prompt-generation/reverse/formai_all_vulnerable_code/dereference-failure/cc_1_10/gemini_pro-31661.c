//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Colors!
#define CYAN "\x1b[36m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define MAGENTA "\x1b[35m"
#define RESET "\x1b[0m"

// Adjectives for our friendly messages
char *adjectives[] = {
    "astounding", "beautiful", "charming", "delightful", "enchanting",
    "fantastic", "glamorous", "handsome", "incredible", "lovely",
    "magnificent", "nice", "outstanding", "pleasant", "quaint",
    "remarkable", "splendid", "superb", "terrific", "wonderful"
};

// Word frequency counter function
void countWords(char *text) {
    // Define hashtable
    struct hashtable {
        char *key;
        int value;
    };
    struct hashtable *hashtable = calloc(1000, sizeof(struct hashtable));

    // Tokenize the text
    char *token = strtok(text, ".,?!:; ");
    while (token != NULL) {
        // Convert to lowercase
        char *lower = strdup(token);
        for (int i = 0; lower[i]; i++) {
            lower[i] = tolower(lower[i]);
        }

        // Check if word exists in hashtable
        int found = 0;
        for (int i = 0; i < 1000; i++) {
            if (hashtable[i].key != NULL && strcmp(hashtable[i].key, lower) == 0) {
                hashtable[i].value++;
                found = 1;
                break;
            }
        }

        // If not, add it
        if (!found) {
            for (int i = 0; i < 1000; i++) {
                if (hashtable[i].key == NULL) {
                    hashtable[i].key = lower;
                    hashtable[i].value = 1;
                    break;
                }
            }
        }

        // Get next token
        token = strtok(NULL, ".,?!:; ");
    }

    // Print the results
    printf(CYAN "Behold, the word frequencies you seek:" RESET "\n");
    for (int i = 0; i < 1000; i++) {
        if (hashtable[i].key != NULL) {
            printf(GREEN "%-15s" YELLOW "%d\n" RESET, hashtable[i].key, hashtable[i].value);
        }
    }

    // Free the hashtable
    for (int i = 0; i < 1000; i++) {
        if (hashtable[i].key != NULL) {
            free(hashtable[i].key);
        }
    }
    free(hashtable);
}

// Main function
int main() {
    // Get the text
    char *text = NULL;
    size_t len = 0;
    getline(&text, &len, stdin);

    // Count the words
    countWords(text);

    // Cleanup
    free(text);

    return 0;
}