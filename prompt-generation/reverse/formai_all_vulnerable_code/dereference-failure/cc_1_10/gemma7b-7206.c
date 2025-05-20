//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: complete
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100
#define WORDS_PER_LINE 20

typedef struct Word {
    char word[20];
    struct Word* next;
} Word;

Word* insertWord(Word* head, char* word) {
    Word* newWord = malloc(sizeof(Word));
    strcpy(newWord->word, word);
    newWord->next = NULL;

    if (head == NULL) {
        head = newWord;
    } else {
        head->next = newWord;
    }

    return head;
}

void printWords(Word* head) {
    Word* currentWord = head;
    while (currentWord) {
        printf("%s ", currentWord->word);
        currentWord = currentWord->next;
    }

    printf("\n");
}

int main() {
    Word* head = NULL;

    // Insert words into the list
    insertWord(head, "Hello");
    insertWord(head, "World");
    insertWord(head, "This");
    insertWord(head, "Is");
    insertWord(head, "A");
    insertWord(head, "List");

    // Print the words
    printWords(head);

    // Start the timer
    time_t start = time(NULL);

    // Type the words as fast as you can
    printWords(head);

    // Stop the timer
    time_t end = time(NULL);

    // Calculate the time taken
    int timeTaken = end - start;

    // Print the time taken
    printf("Time taken: %d seconds\n", timeTaken);

    return 0;
}