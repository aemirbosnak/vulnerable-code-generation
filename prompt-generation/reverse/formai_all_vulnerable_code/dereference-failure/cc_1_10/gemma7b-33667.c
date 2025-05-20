//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

typedef struct Node {
    char **data;
    struct Node *next;
} Node;

void insert(Node **head, char **str) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = str;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void summarize(Node *head) {
    char **summary = (char **)malloc(MAX * sizeof(char *));
    int i = 0;

    while (head) {
        summary[i++] = malloc(strlen(head->data) + 1);
        strcpy(summary[i - 1], head->data);
        head = head->next;
    }

    printf("Summary:\n");
    for (int j = 0; j < i; j++) {
        printf("%s\n", summary[j]);
    }

    for (int j = 0; j < i; j++) {
        free(summary[j]);
    }
    free(summary);
}

int main() {
    Node *head = NULL;
    char **str1 = (char **)malloc(MAX * sizeof(char *));
    str1[0] = "This is a sample text.";
    str1[1] = "It is a long text, but I will summarize it.";
    insert(&head, str1);

    char **str2 = (char **)malloc(MAX * sizeof(char *));
    str2[0] = "Another text.";
    str2[1] = "It is a short text, but I will also summarize it.";
    insert(&head, str2);

    summarize(head);

    for (int i = 0; str1[i] != NULL; i++) {
        free(str1[i]);
    }
    free(str1);

    for (int i = 0; str2[i] != NULL; i++) {
        free(str2[i]);
    }
    free(str2);

    return 0;
}