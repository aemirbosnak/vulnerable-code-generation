//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 50

// Define the maximum number of words in the dictionary
#define MAX_DICTIONARY_SIZE 10000

// Define the structure of a word
typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} Word;

// Define the structure of the dictionary
typedef struct {
    Word words[MAX_DICTIONARY_SIZE];
    int size;
} Dictionary;

// Create a new dictionary
Dictionary* create_dictionary() {
    Dictionary* dictionary = malloc(sizeof(Dictionary));
    dictionary->size = 0;
    return dictionary;
}

// Add a word to the dictionary
void add_word_to_dictionary(Dictionary* dictionary, char* word) {
    // Convert the word to lowercase
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // Check if the word is already in the dictionary
    for (int i = 0; i < dictionary->size; i++) {
        if (strcmp(dictionary->words[i].word, word) == 0) {
            dictionary->words[i].count++;
            return;
        }
    }

    // Add the word to the dictionary
    strcpy(dictionary->words[dictionary->size].word, word);
    dictionary->words[dictionary->size].count = 1;
    dictionary->size++;
}

// Print the dictionary
void print_dictionary(Dictionary* dictionary) {
    for (int i = 0; i < dictionary->size; i++) {
        printf("%s: %d\n", dictionary->words[i].word, dictionary->words[i].count);
    }
}

// Free the memory allocated for the dictionary
void free_dictionary(Dictionary* dictionary) {
    free(dictionary);
}

// Count the number of words in a file
int count_words_in_file(char* filename) {
    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Count the number of words in the file
    int word_count = 0;
    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF) {
        word_count++;
    }

    // Close the file
    fclose(file);

    return word_count;
}

// Generate a random word from the dictionary
char* generate_random_word(Dictionary* dictionary) {
    // Get a random number between 0 and the size of the dictionary
    int random_index = rand() % dictionary->size;

    // Return the word at the random index
    return dictionary->words[random_index].word;
}

// Play a word game with the user
void play_word_game(Dictionary* dictionary) {
    // Get a random word from the dictionary
    char* word = generate_random_word(dictionary);

    // Ask the user to guess the word
    printf("Guess the word: ");
    char guess[MAX_WORD_LENGTH + 1];
    scanf("%s", guess);

    // Check if the user guessed the word correctly
    if (strcmp(guess, word) == 0) {
        printf("Congratulations! You guessed the word correctly.\n");
    } else {
        printf("Sorry, you guessed the word incorrectly.\n");
    }
}

// Main function
int main() {
    // Create a dictionary
    Dictionary* dictionary = create_dictionary();

    // Add words to the dictionary
    add_word_to_dictionary(dictionary, "hello");
    add_word_to_dictionary(dictionary, "world");
    add_word_to_dictionary(dictionary, "computer");
    add_word_to_dictionary(dictionary, "science");
    add_word_to_dictionary(dictionary, "programming");

    // Print the dictionary
    print_dictionary(dictionary);

    // Count the number of words in a file
    int word_count = count_words_in_file("words.txt");
    printf("The file contains %d words.\n", word_count);

    // Generate a random word from the dictionary
    char* word = generate_random_word(dictionary);
    printf("The random word is: %s\n", word);

    // Play a word game with the user
    play_word_game(dictionary);

    // Free the memory allocated for the dictionary
    free_dictionary(dictionary);

    return 0;
}