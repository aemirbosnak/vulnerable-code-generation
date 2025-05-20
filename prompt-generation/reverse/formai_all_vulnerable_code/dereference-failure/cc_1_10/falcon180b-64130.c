//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    struct word_count *word1 = (struct word_count *)a;
    struct word_count *word2 = (struct word_count *)b;

    return strcmp(word1->word, word2->word);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[1024];
    char word[MAX_WORD_LENGTH];
    struct word_count *word_counts = malloc(MAX_WORDS * sizeof(struct word_count));
    int num_words = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        int i = 0;
        while (i < strlen(buffer)) {
            char c = tolower(buffer[i]);
            if (isalpha(c)) {
                if (num_words >= MAX_WORDS) {
                    printf("Maximum number of words reached\n");
                    break;
                }

                strcpy(word, "");
                while (i < strlen(buffer) && isalpha(buffer[i])) {
                    strcat(word, &buffer[i]);
                    i++;
                }

                int found = 0;
                for (int j = 0; j < num_words; j++) {
                    if (strcmp(word_counts[j].word, word) == 0) {
                        word_counts[j].count++;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    strcpy(word_counts[num_words].word, word);
                    word_counts[num_words].count = 1;
                    num_words++;
                }
            }
            i++;
        }
    }

    fclose(file);

    qsort(word_counts, num_words, sizeof(struct word_count), compare_words);

    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);

    return 0;
}