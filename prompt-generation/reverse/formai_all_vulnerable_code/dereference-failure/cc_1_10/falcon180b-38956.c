//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_LINE_SIZE 1024
#define MAX_LOG_FILE_NAME_SIZE 256
#define MAX_WORD_SIZE 64

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *words;
    int num_words;
} WordCountTable;

void initialize_word_count_table(WordCountTable *table) {
    table->num_words = 0;
    table->words = NULL;
}

void add_word_to_table(WordCountTable *table, char *word) {
    if (table->num_words == 0) {
        table->words = malloc(sizeof(WordCount));
    } else {
        table->words = realloc(table->words, sizeof(WordCount) * (table->num_words + 1));
    }

    strcpy(table->words[table->num_words].word, word);
    table->words[table->num_words].count = 1;
    table->num_words++;
}

void print_word_count_table(WordCountTable *table) {
    for (int i = 0; i < table->num_words; i++) {
        printf("%s: %d\n", table->words[i].word, table->words[i].count);
    }
}

void free_word_count_table(WordCountTable *table) {
    for (int i = 0; i < table->num_words; i++) {
        free(table->words[i].word);
    }
    free(table->words);
}

int is_word_char(char c) {
    return isalnum(c) || c == '_';
}

void analyze_log_file(char *log_file_name) {
    FILE *log_file = fopen(log_file_name, "r");
    if (log_file == NULL) {
        printf("Error opening log file: %s\n", log_file_name);
        exit(1);
    }

    WordCountTable word_count_table;
    initialize_word_count_table(&word_count_table);

    char log_line[MAX_LOG_LINE_SIZE];
    while (fgets(log_line, MAX_LOG_LINE_SIZE, log_file)!= NULL) {
        char *word_start = log_line;
        while (*word_start!= '\0' &&!is_word_char(*word_start)) {
            word_start++;
        }

        char *word_end = word_start;
        while (*word_end!= '\0' && is_word_char(*word_end)) {
            word_end++;
        }

        if (word_start < word_end) {
            char word[MAX_WORD_SIZE];
            strncpy(word, word_start, word_end - word_start);
            word[word_end - word_start] = '\0';

            add_word_to_table(&word_count_table, word);
        }
    }

    print_word_count_table(&word_count_table);

    fclose(log_file);
    free_word_count_table(&word_count_table);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file_name>\n", argv[0]);
        exit(1);
    }

    analyze_log_file(argv[1]);
    return 0;
}