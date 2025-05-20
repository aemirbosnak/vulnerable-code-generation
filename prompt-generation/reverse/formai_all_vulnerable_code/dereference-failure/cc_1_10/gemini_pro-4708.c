//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 50

typedef struct {
    char *word;
    int count;
} word_t;

int compare_words(const void *a, const void *b) {
    const word_t *wa = (const word_t *)a;
    const word_t *wb = (const word_t *)b;

    return strcmp(wa->word, wb->word);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <spam file> <ham file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *spam_file = fopen(argv[1], "r");
    if (spam_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE *ham_file = fopen(argv[2], "r");
    if (ham_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char *spam_text = NULL;
    size_t spam_text_len = 0;
    getline(&spam_text, &spam_text_len, spam_file);

    char *ham_text = NULL;
    size_t ham_text_len = 0;
    getline(&ham_text, &ham_text_len, ham_file);

    fclose(spam_file);
    fclose(ham_file);

    char *words[MAX_WORDS];
    int word_count = 0;

    char *token = strtok(spam_text, " ");
    while (token != NULL) {
        words[word_count++] = token;
        token = strtok(NULL, " ");
    }

    token = strtok(ham_text, " ");
    while (token != NULL) {
        words[word_count++] = token;
        token = strtok(NULL, " ");
    }

    qsort(words, word_count, sizeof(char *), compare_words);

    word_t word_counts[MAX_WORDS];
    int unique_word_count = 0;

    for (int i = 0; i < word_count; i++) {
        if (i == 0 || strcmp(words[i], words[i - 1]) != 0) {
            word_counts[unique_word_count].word = words[i];
            word_counts[unique_word_count].count = 1;
            unique_word_count++;
        } else {
            word_counts[unique_word_count - 1].count++;
        }
    }

    for (int i = 0; i < unique_word_count; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return EXIT_SUCCESS;
}