//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000
#define MIN_WORD_LENGTH 3
#define MIN_NUM_WORDS 3
#define SPAM_THRESHOLD 0.8

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int is_spam(char* email) {
    int num_words = 0;
    int num_spam_words = 0;
    Word* word_list = malloc(MAX_NUM_WORDS * sizeof(Word));

    memset(word_list, 0, MAX_NUM_WORDS * sizeof(Word));

    char* word = strtok(email, " ");
    while (word!= NULL) {
        if (strlen(word) >= MIN_WORD_LENGTH) {
            num_words++;

            Word* current_word = word_list;
            while (current_word < word_list + MAX_NUM_WORDS && current_word->word[0]!= '\0') {
                if (strcmp(current_word->word, word) == 0) {
                    current_word->count++;
                    break;
                }
                current_word++;
            }

            if (current_word >= word_list + MAX_NUM_WORDS) {
                if (num_words >= MIN_NUM_WORDS) {
                    if (num_spam_words >= MIN_NUM_WORDS) {
                        free(word_list);
                        return 1;
                    }
                }
                current_word->word[0] = word[0];
                strcpy(current_word->word + 1, word + 1);
                current_word->count = 1;
            }
        }
        word = strtok(NULL, " ");
    }

    if (num_words >= MIN_NUM_WORDS) {
        float spam_ratio = (float)num_spam_words / num_words;
        if (spam_ratio >= SPAM_THRESHOLD) {
            free(word_list);
            return 1;
        }
    }

    free(word_list);
    return 0;
}

int main() {
    char* email = "This is a spam email. It contains words like viagra and cialis. Please do not buy from this email.";
    int result = is_spam(email);

    if (result == 1) {
        printf("Email is spam\n");
    } else {
        printf("Email is not spam\n");
    }

    return 0;
}