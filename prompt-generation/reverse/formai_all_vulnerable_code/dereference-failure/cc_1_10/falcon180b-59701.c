//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word {
    char word[MAX_WORD_LEN];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word *w1 = a;
    const struct word *w2 = b;
    return strcmp(w1->word, w2->word);
}

int is_spam(const char *email) {
    int spam_count = 0;
    char *words[MAX_WORDS];
    int num_words = 0;
    char *token;

    // tokenize email into words
    token = strtok(email, " ");
    while (token!= NULL) {
        if (num_words >= MAX_WORDS) {
            break;
        }
        if (strlen(token) > MAX_WORD_LEN) {
            token = strtok(NULL, " ");
            continue;
        }
        words[num_words++] = strdup(token);
        token = strtok(NULL, " ");
    }

    // count frequency of words
    qsort(words, num_words, sizeof(char *), compare_words);
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i], "viagra") == 0 || strcmp(words[i], "cialis") == 0) {
            spam_count++;
        }
        if (strcmp(words[i], "free") == 0 || strcmp(words[i], "offer") == 0) {
            spam_count++;
        }
        if (strcmp(words[i], "earn") == 0 || strcmp(words[i], "money") == 0) {
            spam_count++;
        }
    }

    // return spam count
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    return spam_count;
}

int main() {
    char email[1000];
    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    int spam_count = is_spam(email);
    if (spam_count > 0) {
        printf("Spam!\n");
    } else {
        printf("Not spam.\n");
    }
    return 0;
}