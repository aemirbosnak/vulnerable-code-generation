//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_WORD_LENGTH 20

typedef struct SpamWord {
    char word[MAX_WORD_LENGTH];
    struct SpamWord* next;
} SpamWord;

SpamWord* insertWord(SpamWord* head, char* word) {
    SpamWord* newWord = malloc(sizeof(SpamWord));
    strcpy(newWord->word, word);
    newWord->next = NULL;

    if (head == NULL) {
        return newWord;
    } else {
        head->next = newWord;
        return head;
    }
}

int main() {
    SpamWord* head = NULL;

    // Insert some spam words
    insertWord(head, "free");
    insertWord(head, "lottery");
    insertWord(head, "miracle");
    insertWord(head, "prize");

    // Get the email text
    char emailText[] = "You have won a lottery! Free prize!";

    // Check if the email text contains any spam words
    if (searchWord(head, emailText)) {
        printf("Email contains spam words!\n");
    } else {
        printf("Email does not contain spam words.\n");
    }

    return 0;
}

int searchWord(SpamWord* head, char* text) {
    while (head) {
        if (strstr(text, head->word) != NULL) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}