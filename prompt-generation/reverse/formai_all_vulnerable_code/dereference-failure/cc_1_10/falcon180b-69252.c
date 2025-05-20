//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

// structure to hold a word and its translation
typedef struct {
    char english[MAX_WORD_LEN];
    char alien[MAX_WORD_LEN];
} Word;

int main() {
    FILE *dict;
    char line[MAX_WORD_LEN];
    Word words[MAX_WORDS];
    int num_words = 0;

    // open the dictionary file
    dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    // read the words from the file
    while (fgets(line, MAX_WORD_LEN, dict)!= NULL) {
        line[strcspn(line, "\n")] = '\0'; // remove newline character
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary too large.\n");
            fclose(dict);
            return 1;
        }
        // split the line into English and alien words
        char *token = strtok(line, " ");
        strcpy(words[num_words].english, token);
        token = strtok(NULL, " ");
        strcpy(words[num_words].alien, token);
        num_words++;
    }
    fclose(dict);

    // prompt the user for input
    printf("Enter a sentence to translate:\n");
    fgets(line, MAX_WORD_LEN, stdin);
    line[strcspn(line, "\n")] = '\0'; // remove newline character

    // tokenize the input sentence
    char *token = strtok(line, " ");
    while (token!= NULL) {
        // search for the word in the dictionary
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                // found the word, print its alien translation
                printf("%s ", words[i].alien);
                break;
            }
        }
        if (i == num_words) {
            // word not found, print an error message
            printf("Error: unknown word '%s'.\n", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}