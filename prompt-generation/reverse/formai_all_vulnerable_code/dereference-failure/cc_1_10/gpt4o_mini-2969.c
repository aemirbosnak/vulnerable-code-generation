//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a data structure for a single linked list node
typedef struct Node {
    char *word;
    struct Node *next;
} Node;

// Function prototypes
Node *createNode(const char *word);
void insert(Node **head, const char *word);
void freeList(Node *head);
int loadDictionary(const char *filename, Node **dictionary);
int is_word_in_dictionary(const char *word, Node *dictionary);
void to_lowercase(char *str);

// Main program for spell checking
int main(int argc, char *argv[]) {
    // Check for proper number of arguments
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    Node *dictionary = NULL;
    // Load the dictionary from the given file
    if (loadDictionary(argv[1], &dictionary) == 0) {
        printf("Failed to load dictionary.\n");
        return 1;
    }

    // Open the text file for spell checking
    FILE *textFile = fopen(argv[2], "r");
    if (textFile == NULL) {
        printf("Failed to open text file.\n");
        freeList(dictionary);
        return 1;
    }

    char word[100];
    int line_num = 1;
    while (fscanf(textFile, "%99s", word) == 1) {
        to_lowercase(word);  // Convert the word to lowercase for matching
        if (!is_word_in_dictionary(word, dictionary)) {
            printf("Misspelled word on line %d: %s\n", line_num, word);
        }
        // Detect end of line
        if (strchr(word, '\n')) {
            line_num++;
        }
    }

    fclose(textFile);
    freeList(dictionary);
    return 0;
}

// Function to create a new node for the linked list
Node *createNode(const char *word) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->word = strdup(word);
    new_node->next = NULL;
    return new_node;
}

// Function to insert a word in the linked list preserving alphabetical order
void insert(Node **head, const char *word) {
    Node *new_node = createNode(word);
    if (*head == NULL || strcmp((*head)->word, word) > 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        Node *current = *head;
        while (current->next != NULL && strcmp(current->next->word, word) < 0) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Function to free the memory used by the linked list
void freeList(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp->word);
        free(temp);
    }
}

// Function to load the dictionary from the specified file
int loadDictionary(const char *filename, Node **dictionary) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }
    char word[100];
    while (fscanf(file, "%99s", word) == 1) {
        to_lowercase(word);
        insert(dictionary, word);
    }
    fclose(file);
    return 1;
}

// Function to check if a word exists in the dictionary
int is_word_in_dictionary(const char *word, Node *dictionary) {
    Node *current = dictionary;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;  // Word found
        }
        current = current->next;
    }
    return 0;  // Word not found
}

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (char *p = str; *p; ++p) {
        *p = tolower((unsigned char)*p);
    }
}