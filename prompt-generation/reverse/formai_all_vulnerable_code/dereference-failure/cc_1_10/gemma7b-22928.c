//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: decentralized
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
        ((*head)->next = newNode)->next = *head;
        *head = newNode;
    }
}

char *translate(char *sentence) {
    Node *head = NULL;
    char *translatedSentence = malloc(MAX_BUFFER_SIZE);

    for (int i = 0; sentence[i] != '\0'; i++) {
        switch (sentence[i]) {
            case 'a':
                insertAtTail(&head, "ala");
                break;
            case 'e':
                insertAtTail(&head, "era");
                break;
            case 'i':
                insertAtTail(&head, "ido");
                break;
            case 'o':
                insertAtTail(&head, "omo");
                break;
            case 'u':
                insertAtTail(&head, "ura");
                break;
            default:
                insertAtTail(&head, &sentence[i]);
                break;
        }
    }

    int j = 0;
    for (Node *node = head; node; node = node->next) {
        translatedSentence[j++] = node->data[0];
    }

    translatedSentence[j] = '\0';

    return translatedSentence;
}

int main() {
    char *sentence = "The quick brown fox jumps over the lazy dog.";
    char *translatedSentence = translate(sentence);

    printf("%s\n", translatedSentence);

    free(translatedSentence);
    return 0;
}