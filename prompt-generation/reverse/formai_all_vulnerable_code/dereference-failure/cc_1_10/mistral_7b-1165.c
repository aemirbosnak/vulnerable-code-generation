//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20
#define WORD_LIST_SIZE (MAX_WORDS * MAX_WORD_LEN + MAX_WORDS * sizeof(char *))

char word_list[WORD_LIST_SIZE];
int num_words = 0;

void add_word(char *word) {
    int len = strlen(word);
    if (num_words >= MAX_WORDS) {
        printf("Error: Maximum number of words reached\n");
        return;
    }

    memcpy(word_list + num_words * (MAX_WORD_LEN + sizeof(char *)), word, len + sizeof(char *) + 1);
    num_words++;
}

int is_spam(char *message, int len) {
    int i, j;
    for (i = 0; i < num_words; i++) {
        char *word = word_list + i * (MAX_WORD_LEN + sizeof(char *));
        int word_len = strlen(word);
        if (len < i * MAX_WORD_LEN + word_len) {
            continue;
        }

        for (j = 0; j < word_len && j < len - i * MAX_WORD_LEN; j++) {
            if (tolower(message[j + i * MAX_WORD_LEN]) != tolower(word[j])) {
                break;
            }
        }

        if (j == word_len) {
            return 1;
        }
    }

    return 0;
}

int main() {
    add_word("buy");
    add_word("sell");
    add_word("viagra");
    add_word("mortgage");

    char message[100];
    fgets(message, sizeof(message), stdin);

    int len = strlen(message);
    if (is_spam(message, len)) {
        printf("Spam detected!\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}