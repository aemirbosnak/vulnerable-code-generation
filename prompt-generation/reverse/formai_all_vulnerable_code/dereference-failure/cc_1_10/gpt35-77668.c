//FormAI DATASET v1.0 Category: Spell checking ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_FILE "dictionary.txt"

// Struct for storing each word in the dictionary
typedef struct dictionary_word_t {
    char word[MAX_WORD_LENGTH];
    struct dictionary_word_t* next;
} dictionary_word;

// Our dictionary, implemented as a linked list
dictionary_word* dictionary = NULL;

// Load the dictionary from file
void load_dictionary() {
    FILE* file = fopen(DICTIONARY_FILE, "r");

    if (file == NULL) {
        printf("Error: Could not open dictionary file '%s'\n", DICTIONARY_FILE);
        exit(1);
    }

    char current_word[MAX_WORD_LENGTH];
    while (fgets(current_word, MAX_WORD_LENGTH, file) != NULL) {
        dictionary_word* new_word = (dictionary_word*) malloc(sizeof(dictionary_word));
        if (new_word == NULL) {
            printf("Error: Could not allocate memory for dictionary word '%s'\n", current_word);
            exit(1);
        }
        // Remove newline character at the end of current_word
        current_word[strcspn(current_word, "\n")] = 0;
        strcpy(new_word->word, current_word);
        new_word->next = dictionary;
        dictionary = new_word;
    }

    fclose(file);
}

// Check if a word is spelled correctly, returns 1 for correct and 0 for incorrect
int is_spelled_correctly(char* word) {
    // Strip any non-letter characters from the beginning and end of the word
    int word_length = strlen(word);
    int start_index = 0;
    int end_index = word_length - 1;

    while (!isalpha(word[start_index]) && start_index < word_length) {
        start_index++;
    }
    while (!isalpha(word[end_index]) && end_index >= 0) {
        end_index--;
    }

    int stripped_word_length = end_index - start_index + 1;

    if (stripped_word_length <= 0) {
        return 1; // If there are no letters in the word, consider it correct
    }

    char stripped_word[MAX_WORD_LENGTH];
    strncpy(stripped_word, word + start_index, stripped_word_length);
    stripped_word[stripped_word_length] = '\0';

    // Check if the word is in the dictionary
    dictionary_word* current_word = dictionary;
    while (current_word != NULL) {
        if (strcasecmp(current_word->word, stripped_word) == 0) {
            return 1;
        }
        current_word = current_word->next;
    }

    return 0;
}

// Main function
int main() {
    load_dictionary();

    printf("Enter a sentence: ");
    char sentence[MAX_WORD_LENGTH * 100];
    fgets(sentence, MAX_WORD_LENGTH * 100, stdin);

    printf("Misspelled words:\n");

    char* current_word = strtok(sentence, " ");
    while (current_word != NULL) {
        if (!is_spelled_correctly(current_word)) {
            printf("%s\n", current_word);
        }
        current_word = strtok(NULL, " ");
    }

    return 0;
}