//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    struct Word* next;
} Word;

Word* insertWord(Word* head, char* word) {
    Word* newWord = malloc(sizeof(Word));
    strcpy(newWord->word, word);
    newWord->next = NULL;

    if (head == NULL) {
        head = newWord;
    } else {
        Word* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newWord;
    }

    return head;
}

int main() {
    Word* head = NULL;
    char word[MAX_WORD_LENGTH];

    // Insert words into the dictionary
    insertWord(head, "apple");
    insertWord(head, "banana");
    insertWord(head, "orange");
    insertWord(head, "grape");

    // Spell check
    printf("Enter a word: ");
    scanf("%s", word);

    Word* current = head;
    while (current) {
        if (strcmp(word, current->word) == 0) {
            printf("Word found!\n");
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Word not found.\n");
    }

    return 0;
}