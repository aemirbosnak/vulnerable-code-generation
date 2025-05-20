//Falcon-180B DATASET v1.0 Category: Text processing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char *word;
    int count;
} WordCount;

void word_count(char *filename, WordCount *word_counts, int max_words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *word = strtok(line, " \t\n\r\f\v.,!?;:\"'()[]{}<>");
        while (word!= NULL) {
            WordCount *wc = word_counts;
            while (wc->word!= NULL && strcasecmp(word, wc->word)!= 0) {
                wc++;
            }
            if (wc->word == NULL) {
                if (max_words == 0 || word_counts < max_words) {
                    wc->word = strdup(word);
                    wc->count = 1;
                    word_counts++;
                }
            } else {
                wc->count++;
            }
            word = strtok(NULL, " \t\n\r\f\v.,!?;:\"'()[]{}<>");
        }
    }

    fclose(file);
}

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> [<max_words>]\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int max_words = (argc > 2)? atoi(argv[2]) : 0;

    WordCount word_counts[100];
    word_count(filename, word_counts, max_words);

    int num_words = 0;
    while (word_counts[num_words].word!= NULL) {
        num_words++;
    }

    printf("Word counts for file %s:\n", filename);
    print_word_counts(word_counts, num_words);

    return 0;
}