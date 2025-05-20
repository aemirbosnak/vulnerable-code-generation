//FormAI DATASET v1.0 Category: Word Count Tool ; Style: enthusiastic
/*
Welcome to the Word Count Tool! This program will help you count the frequency of words in a given text file.
Excited to get started? Let's dive in!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Maximum length of a single word, can be changed as per need
#define MAX_WORD_LENGTH 50

// Defining the structure for a word node
typedef struct word_node {
    char word[MAX_WORD_LENGTH];
    int frequency;
    struct word_node* next_node;
} word_node;

// Defining functions used in the program
void add_word(word_node** head_node_ptr, char* word_to_add);
void print_word_count(word_node* head_node);
void to_lower_case(char* word);

// Let's start the main function
int main(int argc, char* argv[]) {

    // Check if the file name has been passed as an argument
    if (argc != 2) {
        printf("Please enter the file name as an argument.\n");
        return 1;
    }

    // Open the file in read mode
    FILE* file_to_count = fopen(argv[1], "r");

    // Check if the file can be opened
    if (file_to_count == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Declare a buffer to store each word
    char word_buffer[MAX_WORD_LENGTH];

    // Declare a head node pointer
    word_node* head_node_ptr = NULL;

    // Read each word in the text file
    while (fscanf(file_to_count, "%s", word_buffer) == 1) {
        // Convert each word to lowercase
        to_lower_case(word_buffer);
        // Add the word to the word list
        add_word(&head_node_ptr, word_buffer);
    }

    // Close the file
    fclose(file_to_count);

    // Print the word count
    print_word_count(head_node_ptr);

    // Free the memory allocated for the word list
    word_node* current_node_ptr = head_node_ptr;
    word_node* next_node_ptr = NULL;

    while (current_node_ptr != NULL) {
        next_node_ptr = current_node_ptr->next_node;
        free(current_node_ptr);
        current_node_ptr = next_node_ptr;
    }

    // Indicate successful completion of the program
    return 0;
}

// This function adds a word to the word list
void add_word(word_node** head_node_ptr, char* word_to_add) {

    // Declare a node pointer
    word_node* new_node_ptr = NULL;

    // Search for the word in the word list
    word_node** current_node_ptr = head_node_ptr;
    while (*current_node_ptr != NULL) {
        if (strcmp((*current_node_ptr)->word, word_to_add) == 0) {
            (*current_node_ptr)->frequency++;
            return;
        }
        current_node_ptr = &((*current_node_ptr)->next_node);
    }

    // Create a new node and add it to the word list
    new_node_ptr = malloc(sizeof(word_node));
    strcpy(new_node_ptr->word, word_to_add);
    new_node_ptr->frequency = 1;
    new_node_ptr->next_node = NULL;

    *current_node_ptr = new_node_ptr;
}

// This function prints the frequency of each word in the word list
void print_word_count(word_node* head_node) {

    // Check if the word list is empty
    if (head_node == NULL) {
        printf("The word list is empty.\n");
        return;
    }

    int total_words = 0;

    // Traverse the word list and print the frequency of each word
    while (head_node != NULL) {
        printf("%s : %d\n", head_node->word, head_node->frequency);
        total_words += head_node->frequency;
        head_node = head_node->next_node;
    }

    printf("Total words: %d\n", total_words);
}

// This function converts a word to lowercase
void to_lower_case(char* word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}