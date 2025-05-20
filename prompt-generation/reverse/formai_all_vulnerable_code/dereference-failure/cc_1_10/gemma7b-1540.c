//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100

typedef struct Node {
    char word[MAX_WORDS];
    struct Node* next;
} Node;

void insertWord(Node** head, char* word) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void printWords(Node* head) {
    while (head) {
        printf("%s ", head->word);
        head = head->next;
    }
}

int main() {
    time_t start, end;
    char word[MAX_WORDS];
    Node* head = NULL;

    start = time(NULL);

    for (int i = 0; i < 10; i++) {
        printf("Enter a word: ");
        scanf("%s", word);
        insertWord(&head, word);
    }

    printWords(head);

    end = time(NULL);

    printf("Time taken: %.2lf seconds\n", (double)(end - start));

    return 0;
}