//MISTRAL-7B DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LINE 1024
#define MAX_WORDS 50
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordStat;

void processLine(char *line, WordStat words[]) {
    char *token;
    int i;

    token = strtok(line, " \t\n\r.,;:!?");

    for (i = 0; i < MAX_WORDS && token != NULL; ++i) {
        strcpy(words[i].word, token);
        words[i].count = 1;
        token = strtok(NULL, " \t\n\r.,;:!?");
    }
}

void loadFile(const char *filename, WordStat words[]) {
    int fd;
    char line[MAX_LINE];

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE, fd) != NULL) {
        processLine(line, words);
    }

    close(fd);
}

void printStats(const WordStat words[], int num_words) {
    int i;

    for (i = 0; i < num_words; ++i) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    WordStat words[MAX_WORDS];
    int num_words = 0;

    loadFile(argv[1], words);
    printStats(words, num_words);

    return EXIT_SUCCESS;
}