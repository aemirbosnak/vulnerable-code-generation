//FormAI DATASET v1.0 Category: Spell checking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 30

// Function to check if a word is valid
int is_valid_word(char *word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to remove non-alphabetic characters from a word
void sanitize_word(char *word) {
    int i = 0, j = 0;
    while (word[i] != '\0') {
        if (isalpha(word[i])) {
            word[j] = tolower(word[i]);
            j++;
        }
        i++;
    }
    word[j] = '\0';
}

int main() {
    // Open the dictionary file
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (!dict_file) {
        printf("Error: Could not open dictionary file\n");
        return 1;
    }

    // Load the dictionary words into memory
    char **dict_words = malloc(sizeof(char*) * 100000);
    char buffer[MAX_WORD_LENGTH];
    int i, num_words = 0;
    while (fgets(buffer, MAX_WORD_LENGTH, dict_file)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // remove newline
        if (is_valid_word(buffer)) {
            sanitize_word(buffer);
            dict_words[num_words] = malloc(sizeof(char) * (strlen(buffer) + 1));
            strcpy(dict_words[num_words], buffer);
            num_words++;
        }
    }
    fclose(dict_file);

    // Get the input text
    char *input_text = malloc(sizeof(char) * 1000000);
    printf("Please enter your text:\n");
    fgets(input_text, 1000000, stdin);

    // Tokenize the input text and check each word against the dictionary
    char *word;
    word = strtok(input_text, " ,.!?\n\"'");
    while (word != NULL) {
        sanitize_word(word);
        int found = 0;
        for (i = 0; i < num_words; i++) {
            if (strcmp(dict_words[i], word) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Did you mean: %s?\n", dict_words[rand() % num_words]);
        }
        word = strtok(NULL, " ,.!?\n\"'");
    }

    // Free memory
    for (i = 0; i < num_words; i++) {
        free(dict_words[i]);
    }
    free(dict_words);
    free(input_text);

    return 0;
}