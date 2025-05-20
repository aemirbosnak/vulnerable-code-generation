//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_LOG_FILE_SIZE 1073741824  // 1 GB
#define MAX_LOG_LINES 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} word_t;

typedef struct {
    char *file_name;
    word_t *words;
    int file_size;
    int line_count;
} log_file_t;

static void load_log_file(log_file_t *log_file, char *file_name);
static void analyze_log_file(log_file_t *log_file);
static void print_stats(log_file_t *log_file);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file_path>\n", argv[0]);
        return 1;
    }

    log_file_t *log_file = malloc(sizeof(log_file_t));
    strcpy(log_file->file_name, argv[1]);

    load_log_file(log_file, argv[1]);
    analyze_log_file(log_file);
    print_stats(log_file);

    free(log_file);
    return 0;
}

static void load_log_file(log_file_t *log_file, char *file_name) {
    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    log_file->file_size = lseek(fd, 0, SEEK_END);
    if (log_file->file_size == -1) {
        perror("lseek");
        exit(1);
    }

    log_file->line_count = (int) (log_file->file_size / 1024);

    char *buffer = malloc(1024);
    read(fd, buffer, 1024);

    word_t *words = malloc(log_file->line_count * sizeof(word_t));
    int i = 0;
    while (i < log_file->line_count) {
        char *word = strtok(buffer, " ");
        while (word != NULL) {
            words[i].word = word;
            words[i].count = 1;
            i++;
            word = strtok(NULL, " ");
        }
        buffer += 1024;
    }

    log_file->words = words;
    close(fd);
}

static void analyze_log_file(log_file_t *log_file) {
    int i = 0;
    for (i = 0; i < log_file->line_count; i++) {
        word_t *word = log_file->words + i;
        if (word->count > 1) {
            // Do something with the word
            printf("%s appears %d times in line %d\n", word->word, word->count, i + 1);
        }
    }
}

static void print_stats(log_file_t *log_file) {
    int i = 0;
    for (i = 0; i < log_file->line_count; i++) {
        word_t *word = log_file->words + i;
        if (word->count > 0) {
            printf("%s appears %d times\n", word->word, word->count);
        }
    }
}