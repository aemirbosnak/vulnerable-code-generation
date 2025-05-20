//FormAI DATASET v1.0 Category: Spell checking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000
#define DICTIONARY_FILE "dictionary.txt"

char** load_dictionary(int* num_words) {
    FILE* file = fopen(DICTIONARY_FILE, "r");
    if (!file) {
        printf("Error loading dictionary file");
        exit(1);
    }
    char** words = calloc(MAX_NUM_WORDS, sizeof(char*));
    char buffer[MAX_WORD_LENGTH];
    int i = 0;
    while (fgets(buffer, MAX_WORD_LENGTH, file)) {
        buffer[strcspn(buffer, "\n")] = 0; // remove newline
        words[i] = malloc(strlen(buffer) + 1);
        strcpy(words[i], buffer);
        i++;
    }
    fclose(file);
    *num_words = i;
    return words;
}

int main() {
    int num_words;
    char** dictionary = load_dictionary(&num_words);

    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence: ");
    fgets(input, MAX_WORD_LENGTH, stdin);

    char** tokens = malloc(MAX_NUM_WORDS * sizeof(char*));
    char* token = strtok(input, " .,:;");
    int num_tokens = 0;
    while (token) {
        tokens[num_tokens] = malloc(strlen(token) + 1);
        strcpy(tokens[num_tokens], token);
        num_tokens++;
        token = strtok(NULL, " .,:;");
    }

    printf("Words not in dictionary: ");
    for (int i = 0; i < num_tokens; i++) {
        int found = 0;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(tokens[i], dictionary[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s ", tokens[i]);
        }
    }
    printf("\n");
    
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i]);
    }
    free(tokens);
    for (int i = 0; i < num_words; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
    return 0;
}