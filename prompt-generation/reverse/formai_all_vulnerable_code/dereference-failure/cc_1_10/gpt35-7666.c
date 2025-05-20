//FormAI DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 50

/*
 * Function to check if a given string is entirely composed of alphabets
 * Returns 1 if alphabets only, 0 otherwise
 */
int is_alpha(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

/*
 * Function to convert a given word to lowercase
 * Returns a new string in lowercase
 */
char *to_lowercase(char *word) {
    char *lowercase = (char*)malloc(strlen(word) + 1);
    int i = 0;
    while (word[i]) {
        lowercase[i] = tolower(word[i]);
        i++;
    }
    lowercase[i] = '\0';
    return lowercase;
}

int main() {
    // Open the file to be spell-checked
    FILE *file = fopen("text.txt", "r");
    if (!file) {
        printf("Could not open file\n");
        return 1;
    }

    // Create a dictionary of known words
    FILE *dict = fopen("dictionary.txt", "r");
    if (!dict) {
        printf("Could not open dictionary file\n");
        return 1;
    }

    // Populate the dictionary with known words
    char **words = (char**)malloc(sizeof(char*) * 5000);
    int num_words = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(dict, "%s", word) != EOF) {
        if (is_alpha(word)) {
            char *lowercase = to_lowercase(word);
            words[num_words] = lowercase;
            num_words++;
        }
    }
    fclose(dict);

    // Loop through each word in the file to be spell-checked
    int line_num = 1;
    int word_num = 1;
    while (fgets(word, MAX_WORD_LENGTH, file)) {
        char *token = strtok(word, " \t\n");
        while (token != NULL) {
            if (!is_alpha(token)) {
                token = strtok(NULL, " \t\n");
                word_num++;
                continue;
            }

            char *lowercase = to_lowercase(token);
            int found = 0;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(lowercase, words[i]) == 0) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Error: Word \"%s\" not found in dictionary at line %d, word %d\n", token, line_num, word_num);
            }

            free(lowercase);
            token = strtok(NULL, " \t\n");
            word_num++;
        }
        line_num++;
        word_num = 1;
    }

    // Cleanup
    fclose(file);
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
    return 0;
}