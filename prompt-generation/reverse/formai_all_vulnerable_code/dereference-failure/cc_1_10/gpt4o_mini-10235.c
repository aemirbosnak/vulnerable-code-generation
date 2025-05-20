//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum sizes for the buffer and word length
#define MAX_WORD_LENGTH 100
#define MAX_BUFFER_SIZE 1024

// Node structure for the linked list
typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(const char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        strncpy(newNode->word, word, MAX_WORD_LENGTH);
        newNode->word[MAX_WORD_LENGTH - 1] = '\0'; // Null-terminate
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a word into the linked list
void insertWord(Node** head, const char* word) {
    Node* newNode = createNode(word);
    newNode->next = *head;
    *head = newNode;
}

// Function to check if a word exists in the linked list
int checkWord(Node* head, const char* word) {
    Node* current = head;
    while (current != NULL) {
        if (strcasecmp(current->word, word) == 0) {
            return 1; // Word found
        }
        current = current->next;
    }
    return 0; // Word not found
}

// Function to free the linked list
void freeList(Node* head) {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

// Function to load the dictionary into memory
Node* loadDictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open dictionary file");
        exit(EXIT_FAILURE);
    }

    Node* dictionary = NULL;
    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline char
        insertWord(&dictionary, buffer);
    }

    fclose(file);
    return dictionary;
}

// Function to check spelling in a text file
void checkSpelling(const char* textFilename, Node* dictionary) {
    FILE* file = fopen(textFilename, "r");
    if (file == NULL) {
        perror("Could not open text file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        char* token = strtok(buffer, " \n");
        while (token != NULL) {
            if (!checkWord(dictionary, token)) {
                printf("Misspelled: %s\n", token);
            }
            token = strtok(NULL, " \n");
        }
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <dictionary file> <text file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* dictionaryFile = argv[1];
    char* textFile = argv[2];

    // Load the dictionary
    Node* dictionary = loadDictionary(dictionaryFile);

    // Check spelling in the provided text file
    checkSpelling(textFile, dictionary);

    // Free the allocated memory for the dictionary
    freeList(dictionary);

    return EXIT_SUCCESS;
}