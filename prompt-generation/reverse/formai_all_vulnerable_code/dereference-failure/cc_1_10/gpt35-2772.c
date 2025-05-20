//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

struct Node {
    char* word;
    int frequency;
    struct Node* next;
};

void addWord(struct Node** head, char* word) {
    if(*head == NULL) {
        // create new node at head
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->word = strdup(word);
        newNode->frequency = 1;
        newNode->next = NULL;

        *head = newNode;
    } else {
        struct Node* curr = *head;

        // check if word already in list
        while(curr != NULL) {
            if(strcmp(curr->word, word) == 0) {
                curr->frequency++;
                return;
            }
            curr = curr->next;
        }

        // word not in list, add to end
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->word = strdup(word);
        newNode->frequency = 1;
        newNode->next = NULL;

        curr = *head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void printWords(struct Node* head) {
    struct Node* curr = head;

    // find longest word for formatting
    int maxWordLen = 0;
    while(curr != NULL) {
        int wordLen = strlen(curr->word);
        if(wordLen >= maxWordLen) {
            maxWordLen = wordLen;
        }
        curr = curr->next;
    }

    // print headers
    printf("\n%-*s %s\n", maxWordLen, "Word", "Frequency");
    printf("------------------------\n");

    // print words
    curr = head;
    while(curr != NULL) {
        printf("%-*s %d\n", maxWordLen, curr->word, curr->frequency);
        curr = curr->next;
    }
}

int main() {
    // initialize empty linked list
    struct Node* head = NULL;

    // get text input from user
    printf("Enter text to count word frequency:\n");
    char* input = malloc(sizeof(char) * 1000);
    fgets(input, 1000, stdin);

    // convert input to lowercase for case-insensitive counting
    int inputLen = strlen(input);
    for(int i = 0; i < inputLen; i++) {
        input[i] = tolower(input[i]);
    }

    // parse input into words and add to linked list
    char* word = strtok(input, " ,.;:\n\r\t");
    while(word != NULL) {
        int wordLen = strlen(word);
        if(wordLen > MAX_WORD_LEN) {
            // word too long, skip
            word = strtok(NULL, " ,.;:\n\r\t");
            continue;
        }
        addWord(&head, word);
        word = strtok(NULL, " ,.;:\n\r\t");
    }

    // print results
    printWords(head);

    return 0;
}