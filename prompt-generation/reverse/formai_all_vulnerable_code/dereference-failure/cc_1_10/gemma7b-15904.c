//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: rigorous
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct MorseCodeWord {
    char word[MAX_WORD_LENGTH];
    int length;
    struct MorseCodeWord* next;
} MorseCodeWord;

MorseCodeWord* createMorseCodeWord(char* word, int length) {
    MorseCodeWord* wordNode = malloc(sizeof(MorseCodeWord));
    wordNode->length = length;
    strcpy(wordNode->word, word);
    wordNode->next = NULL;
    return wordNode;
}

MorseCodeWord* insertMorseCodeWord(MorseCodeWord* head, char* word, int length) {
    MorseCodeWord* newNode = createMorseCodeWord(word, length);
    if (head == NULL) {
        return newNode;
    }
    MorseCodeWord* current = head;
    MorseCodeWord* previous = NULL;
    while (current) {
        if (newNode->length < current->length) {
            previous = current;
            current = current->next;
        } else if (strcmp(newNode->word, current->word) == 0) {
            return head;
        }
    }
    if (previous) {
        previous->next = newNode;
    } else {
        head = newNode;
    }
    return head;
}

void convertTextToMorseCode(MorseCodeWord* head) {
    for (MorseCodeWord* current = head; current; current = current->next) {
        printf("%s ---. ", current->word);
    }
    printf("\n");
}

int main() {
    MorseCodeWord* head = NULL;
    insertMorseCodeWord(head, "HELLO", 5);
    insertMorseCodeWord(head, "WORLD", 6);
    insertMorseCodeWord(head, "HOW", 3);
    insertMorseCodeWord(head, "ARE", 2);
    insertMorseCodeWord(head, "YOU?", 4);

    convertTextToMorseCode(head);

    return 0;
}