//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 100

typedef struct Word {
    char *word;
    int length;
    struct Word *next;
} Word;

Word *head = NULL;
Word *current = NULL;
Word *temp = NULL;

void addWord(char *word) {
    if (head == NULL) {
        head = (Word *) malloc(sizeof(Word));
        head->word = strdup(word);
        head->length = strlen(word);
        head->next = NULL;
        current = head;
    } else {
        current->next = (Word *) malloc(sizeof(Word));
        temp = current->next;
        temp->word = strdup(word);
        temp->length = strlen(word);
        temp->next = NULL;
        current = temp;
    }
}

void displayList() {
    Word *ptr = head;
    printf("Word List:\n");
    while (ptr != NULL) {
        printf("[%s]\n", ptr->word);
        ptr = ptr->next;
    }
}

void freeMemory() {
    Word *ptr = head;
    Word *next;
    while (ptr != NULL) {
        next = ptr->next;
        free(ptr->word);
        free(ptr);
        ptr = next;
    }
    head = NULL;
    current = NULL;
}

int main() {
    char input[MAX_WORD_LENGTH];
    int choice;

    printf("Ultra Precise Memory Management Example Program\n");
    printf("1. Add Word\n");
    printf("2. Display Word List\n");
    printf("3. Exit\n");

    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a word: ");
                scanf("%s", input);
                addWord(input);
                break;
            case 2:
                displayList();
                break;
            case 3:
                freeMemory();
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}