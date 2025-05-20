//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_RESUME_LENGTH 1000

// Node structure for linked list
typedef struct node {
    char data[MAX_WORD_LENGTH];
    struct node* next;
} Node;

// Function to split a string into words
void split(char* str, Node** head) {
    char* word = strtok(str, " ");
    while (word!= NULL) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        strncpy(newNode->data, word, MAX_WORD_LENGTH);
        newNode->next = *head;
        *head = newNode;
        word = strtok(NULL, " ");
    }
}

// Function to count the frequency of a word in a linked list
int countFrequency(Node* head, char* word) {
    Node* currNode = head;
    int count = 0;
    while (currNode!= NULL) {
        if (strcmp(currNode->data, word) == 0) {
            count++;
        }
        currNode = currNode->next;
    }
    return count;
}

// Function to print a linked list
void printList(Node* head) {
    Node* currNode = head;
    while (currNode!= NULL) {
        printf("%s ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

int main() {
    FILE* fp;
    char line[MAX_RESUME_LENGTH];
    char* token;
    Node* head = NULL;

    // Open the resume file
    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read the resume line by line
    while (fgets(line, MAX_RESUME_LENGTH, fp)!= NULL) {
        // Remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';

        // Split the line into words
        split(line, &head);
    }

    // Close the resume file
    fclose(fp);

    // Print the frequency of each word
    printf("Word frequencies:\n");
    while (head!= NULL) {
        printf("'%s': %d\n", head->data, countFrequency(head, head->data));
        head = head->next;
    }

    return 0;
}