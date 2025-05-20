//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct message {
    char *text;
    int length;
    struct word_count *word_counts;
};

void init_word_counts(struct word_count *word_counts) {
    for (int i = 0; i < MAX_WORDS; i++) {
        word_counts[i].count = 0;
    }
}

void process_message(struct message *message) {
    char *p = message->text;
    int in_word = 0;
    while (*p) {
        if (isalpha(*p)) {
            in_word = 1;
        } else if (in_word) {
            if (message->word_counts[0].count >= MAX_WORD_LENGTH) {
                break;
            }
            strncat(message->word_counts[0].word, p, MAX_WORD_LENGTH);
            message->word_counts[0].count++;
            in_word = 0;
        }
        p++;
    }
}

int main() {
    struct message message;
    message.text = (char *)malloc(1000 * sizeof(char));
    message.length = 0;
    message.word_counts = (struct word_count *)malloc(MAX_WORDS * sizeof(struct word_count));
    init_word_counts(message.word_counts);

    printf("Enter message: ");
    fgets(message.text, 1000, stdin);
    message.length = strlen(message.text);

    process_message(&message);

    printf("Word counts:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (message.word_counts[i].count > 0) {
            printf("%s: %d\n", message.word_counts[i].word, message.word_counts[i].count);
        }
    }

    free(message.text);
    free(message.word_counts);

    return 0;
}