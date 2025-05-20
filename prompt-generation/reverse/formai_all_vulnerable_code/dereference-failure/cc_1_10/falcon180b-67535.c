//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} word_count_t;

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    int line_count;
    word_count_t *word_counts;
    int num_words;
} file_t;

int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void read_file(const char *filename, file_t *file) {
    FILE *f;
    char ch;
    char line[1000];
    int line_count = 0;
    int word_count = 0;
    int i = 0;

    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while ((ch = fgetc(f))!= EOF) {
        if (ch == '\n') {
            line_count++;
        }
        if (line_count > 0 && isalpha(ch)) {
            line[i++] = tolower(ch);
        }
        if (i >= MAX_WORD_LENGTH - 1) {
            line[i] = '\0';
            strcpy(file->word_counts[word_count].word, line);
            word_count++;
            i = 0;
        }
    }
    if (i > 0) {
        line[i] = '\0';
        strcpy(file->word_counts[word_count].word, line);
        word_count++;
    }
    fclose(f);

    qsort(file->word_counts, word_count, sizeof(word_count_t), compare_strings);

    file->line_count = line_count;
    file->num_words = word_count;
}

void print_word_counts(file_t *file) {
    int i;

    printf("Word counts for file %s:\n", file->filename);
    printf("Line count: %d\n", file->line_count);
    printf("Number of words: %d\n", file->num_words);
    printf("Words:\n");

    for (i = 0; i < file->num_words; i++) {
        printf("%s: %d\n", file->word_counts[i].word, file->word_counts[i].count);
    }
}

int main(int argc, char **argv) {
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file_t file;

    strcpy(file.filename, argv[1]);
    read_file(argv[1], &file);
    print_word_counts(&file);

    return 0;
}