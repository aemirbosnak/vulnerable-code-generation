//FormAI DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
} word_count;

int num_words = 0;
word_count word_list[MAX_WORDS];
bool finished_reading = false;

void count_words(char* buffer, size_t length) {
    char* current = buffer;
    char* start = buffer;
    char* end = buffer + length;
    while (current < end) {
        if (isspace(*current) || ispunct(*current)) {
            if (current - start > 0) {
                char* word = malloc(sizeof(char) * MAX_WORD_LENGTH);
                strncpy(word, start, current - start);
                word[current - start] = '\0';
                bool word_exists = false;
                for (int i = 0; i < num_words; i++) {
                    if (strcmp(word_list[i].word, word) == 0) {
                        word_exists = true;
                        word_list[i].count++;
                        break;
                    }
                }
                if (!word_exists) {
                    strncpy(word_list[num_words].word, word, MAX_WORD_LENGTH);
                    word_list[num_words].count = 1;
                    num_words++;
                }
                free(word);
            }
            start = current + 1;
        }
        current++;
    }
}

void print_word_list() {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_list[i].word, word_list[i].count);
    }
}

void async_read_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }
    int block_size = MAX_WORD_LENGTH * 1024;
    char* buffer = malloc(sizeof(char) * block_size);
    size_t read_size;
    while ((read_size = fread(buffer, sizeof(char), block_size, fp)) == block_size) {
        count_words(buffer, block_size);
        memset(buffer, 0, block_size);
    }
    count_words(buffer, read_size);
    free(buffer);
    fclose(fp);
    finished_reading = true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    async_read_file(argv[1]);
    while (!finished_reading) {
        printf("Reading file...\n");
    }
    print_word_list();
    return 0;
}