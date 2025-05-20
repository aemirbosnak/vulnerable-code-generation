//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

// Node to store word frequencies
struct word_frequency {
    char* word;
    int frequency;
    struct word_frequency* next;
};

// Function to create a new node
struct word_frequency* create_node(char* word) {
    struct word_frequency* node = (struct word_frequency*) malloc(sizeof(struct word_frequency));
    node->word = (char*) malloc(MAX_WORD_LENGTH * sizeof(char));
    strcpy(node->word, word);
    node->frequency = 1;
    node->next = NULL;
    return node;
}

// Function to delete all nodes in the list
void delete_list(struct word_frequency* head) {
    while(head) {
        struct word_frequency* node = head;
        head = head->next;
        free(node->word);
        free(node);
    }
}

// Function to add a node to the list
void add_node(struct word_frequency** head, char* word) {
    if (*head == NULL) {
        *head = create_node(word);
    } else {
        struct word_frequency* current = *head;
        while(current) {
            if (strcmp(current->word, word) == 0) {
                current->frequency++;
                break;
            }
            if (current->next == NULL) {
                current->next = create_node(word);
                break;
            }
            current = current->next;
        }
    }
}

// Function to read input from file
void read_input(char* filename, struct word_frequency** head) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        for(int i = 0; word[i]; i++){
            word[i] = tolower(word[i]);
        }
        add_node(head, word);
    }

    fclose(file);
}

// Function to print the node list in descending order of frequency
void print_word_freq(struct word_frequency* head) {
    struct word_frequency* current = head;

    // Find number of unique words
    int num_words = 0;
    while(current) {
        num_words++;
        current = current->next;
    }

    // Create an array of nodes to make sorting easier
    struct word_frequency** array = (struct word_frequency**) malloc(num_words * sizeof(struct word_frequency*));
    current = head;
    for(int i = 0; i < num_words; i++) {
        array[i] = current;
        current = current->next;
    }

    // Selection sort the array of nodes in descending order based on frequency
    for (int i = 0; i < num_words-1; i++) {
        int max_index = i;
        for (int j = i+1; j < num_words; j++) {
            if (array[j]->frequency > array[max_index]->frequency) {
                max_index = j;
            }
        }
        if (max_index != i) {
            struct word_frequency* temp = array[i];
            array[i] = array[max_index];
            array[max_index] = temp;
        }
    }

    // Print the words and their frequencies
    printf("%-20s %s\n", "WORD", "FREQUENCY");
    printf("=====================\n");
    for(int i = 0; i < num_words; i++) {
        printf("%-20s %d\n", array[i]->word, array[i]->frequency);
    }

    free(array);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Please provide a filename as an argument\n");
        return 1;
    }

    struct word_frequency* head = NULL;
    read_input(argv[1], &head);
    print_word_freq(head);
    delete_list(head);

    return 0;
}