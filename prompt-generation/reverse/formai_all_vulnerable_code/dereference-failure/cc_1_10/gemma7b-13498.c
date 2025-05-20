//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

void summarize(Node *head) {
    Node *current = head;
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;

    while (current) {
        strcpy(buffer, current->data);
        // Remove common words
        char *common_words[] = {"the", "a", "of", "a", "to", "in", "that", "in", "for"};
        for (int j = 0; j < 9; j++) {
            if (strstr(buffer, common_words[j])) {
                char *ptr = strstr(buffer, common_words[j]);
                ptr = NULL;
            }
        }

        // Summarize remaining text
        buffer[strlen(buffer) - 1] = '\0';
        printf("%s ", buffer);
        current = current->next;
    }

    printf("\n");
}

int main() {
    Node *head = malloc(sizeof(Node));
    head->data = "This is a sample text that will be summarized.";

    Node *second = malloc(sizeof(Node));
    second->data = "It is a long text with many words.";

    Node *third = malloc(sizeof(Node));
    third->data = "I would like to summarize this text.";

    head->next = second;
    second->next = third;

    summarize(head);

    return 0;
}