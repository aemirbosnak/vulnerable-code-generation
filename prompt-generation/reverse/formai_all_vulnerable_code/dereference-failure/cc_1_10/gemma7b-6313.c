//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

void insertAtTail(Node **head, char *data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void textSummarizer(Node *head) {
    char *summary = malloc(MAX_BUFFER_SIZE);
    int summaryLength = 0;

    Node *current = head;
    while (current) {
        char *text = current->data;
        int textLength = strlen(text);

        // Calculate the summary length based on the text length
        int newSummaryLength = summaryLength + textLength + 1;

        // If the summary length exceeds the buffer size, resize the summary
        if (newSummaryLength > MAX_BUFFER_SIZE) {
            summary = realloc(summary, MAX_BUFFER_SIZE * 2);
            summaryLength *= 2;
        }

        // Append the text to the summary
        strcat(summary, text);
        strcat(summary, "\n");

        current = current->next;
    }

    // Print the summary
    printf("%s", summary);

    // Free the memory allocated for the summary
    free(summary);
}

int main() {
    // Insert some text nodes into the linked list
    Node *head = NULL;
    insertAtTail(&head, "This is the first text.");
    insertAtTail(&head, "This is the second text.");
    insertAtTail(&head, "This is the third text.");

    // Summarize the text
    textSummarizer(head);

    return 0;
}