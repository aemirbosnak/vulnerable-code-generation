//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50 // Maximum length of a word

// Node structure for linked list
struct Node {
    char* word;
    int count;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char* word) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->word = word;
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of a linked list
void addNode(struct Node** head, char* word) {
    struct Node* newNode = createNode(word);

    // If linked list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    // Traverse to end of linked list and add new node
    struct Node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

// Function to search for a word in a linked list and increment its count
void searchAndUpdate(struct Node** head, char* word) {
    // Traverse linked list and search for the word
    struct Node* curr = *head;
    while (curr != NULL) {
        if (strcmp(curr->word, word) == 0) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }
    // If word not found, add node to linked list
    addNode(head, word);
}

// Function to print the linked list of word counts
void printList(struct Node* head) {
    printf("Word counts:\n");
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%s: %d\n", curr->word, curr->count);
        curr = curr->next;
    }
}

// Function to convert a word to lowercase
void lowercase(char* word) {
    int i = 0;
    while (word[i]) {
        word[i] = tolower(word[i]);
        i++;
    }
}

// Main function
int main() {
    printf("Enter text to count words:\n");

    char* input = (char*) malloc(sizeof(char) * 1000);
    fgets(input, 1000, stdin);

    struct Node* head = NULL;

    char* currWord = strtok(input, " "); // Get first word
    while (currWord != NULL) {
        if (strlen(currWord) > MAX_WORD_LENGTH) { // Skip words that are too long
            currWord = strtok(NULL, " ");
            continue;
        }
        lowercase(currWord); // Convert word to lowercase
        searchAndUpdate(&head, currWord); // Add word to linked list or increment its count
        currWord = strtok(NULL, " "); // Get next word
    }

    printList(head);

    free(input);
    return 0;
}