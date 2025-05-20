//FormAI DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH_MAX 50
#define DICTIONARY_SIZE 500

typedef struct Node {
    char word[WORD_LENGTH_MAX];
    struct Node *next;
} Node;

// Function declarations
void loadDictionary(Node *dictionary[], FILE *filePtr);
void checkSpelling(Node *dictionary[], char *word);
void convertToLowercase(char *string);
void insert(Node **head, char *word);
void freeLinkedList(Node *head);

int main() {
    // Open dictionary file
    FILE *dictionaryFile = fopen("dictionary.txt", "r");
    if (dictionaryFile == NULL) {
        printf("Unable to open file\n");
        return 1;
    }

    // Allocate memory for dictionary array
    Node **dictionary = malloc(DICTIONARY_SIZE * sizeof(Node*));
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        dictionary[i] = NULL;
    }

    // Load dictionary into array of linked lists
    loadDictionary(dictionary, dictionaryFile);

    // Close dictionary file
    fclose(dictionaryFile);

    // Prompt user to enter word
    printf("Enter a word to spell check (or type 'exit' to quit): ");
    char input[WORD_LENGTH_MAX];
    fgets(input, WORD_LENGTH_MAX, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character

    while (strcmp(input, "exit") != 0) {
        checkSpelling(dictionary, input);

        // Prompt user to enter another word
        printf("\nEnter another word to spell check (or type 'exit' to quit): ");
        fgets(input, WORD_LENGTH_MAX, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character
    }

    // Free memory allocated for dictionary array
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        freeLinkedList(dictionary[i]);
    }
    free(dictionary);

    return 0;
}

// Load dictionary into array of linked lists
void loadDictionary(Node *dictionary[], FILE *filePtr) {
    char word[WORD_LENGTH_MAX];
    while (fscanf(filePtr, "%s", word) != EOF) {
        convertToLowercase(word);
        int hashIndex = word[0] - 'a';
        insert(&dictionary[hashIndex], word);
    }
}

// Check if word is spelled correctly
void checkSpelling(Node *dictionary[], char *word) {
    convertToLowercase(word);
    int hashIndex = word[0] - 'a';
    Node *currNode = dictionary[hashIndex];
    while (currNode != NULL) {
        if (strcmp(currNode->word, word) == 0) {
            printf("%s is spelled correctly!\n", word);
            return;
        }
        currNode = currNode->next;
    }
    printf("%s is spelled incorrectly.\n", word);
}

// Convert string to lowercase
void convertToLowercase(char *string) {
    for (int i = 0; string[i]; i++) {
        string[i] = tolower(string[i]);
    }
}

// Insert word into linked list
void insert(Node **head, char *word) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    strcpy(newNode->word, word);
    newNode->next = *head;
    *head = newNode;
}

// Free linked list memory
void freeLinkedList(Node *head) {
    Node *currNode = head;
    while (currNode != NULL) {
        Node *temp = currNode->next;
        free(currNode);
        currNode = temp;
    }
}