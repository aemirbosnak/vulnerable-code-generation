//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: systematic
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct CatWord {
    char word[20];
    struct CatWord* next;
} CatWord;

CatWord* insertWord(CatWord* head, char* word) {
    CatWord* newNode = malloc(sizeof(CatWord));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        CatWord* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

void translateCat(CatWord* head) {
    printf("Meow, human!\n");
    printf("Here is your translation:\n");

    CatWord* current = head;
    while (current) {
        printf("%s - ", current->word);
        current = current->next;
    }

    printf("\n");
}

int main() {
    CatWord* head = NULL;

    insertWord(head, "Meow");
    insertWord(head, "Woof");
    insertWord(head, "Chirp");
    insertWord(head, "Buzz");
    insertWord(head, "Meow");

    translateCat(head);

    return 0;
}