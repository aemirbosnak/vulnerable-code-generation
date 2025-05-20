//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define WORD_LENGTH 50
#define VOCAB_SIZE 5000
#define DICTIONARY_FILE "dictionary.txt"
#define DATA_FILE "input.txt"

typedef struct {
    char word[WORD_LENGTH];
    int score;
} Word;

Word dictionary[VOCAB_SIZE];
int num_words = 0;

void load_dictionary() {
    int fd = open(DICTIONARY_FILE, O_RDONLY);
    char line[1024];

    if (fd < 0) {
        perror("Error opening dictionary file");
        exit(1);
    }

    while (fgets(line, sizeof(line), fd) != NULL) {
        char *token = strtok(line, " ");
        int i;

        for (i = 0; i < num_words && strcmp(token, dictionary[i].word) != 0; i++);

        if (i == num_words) {
            strcpy(dictionary[num_words].word, token);
            dictionary[num_words].score = 0;
            num_words++;
        }
    }

    close(fd);
}

void process_line(char *line) {
    char *token = strtok(line, " ");
    int i, j, word_score = 0;

    while (token != NULL) {
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, dictionary[i].word) == 0) {
                word_score += dictionary[i].score;
                break;
            }
        }

        if (i == num_words) {
            for (i = 0; i < num_words; i++) {
                if (strlen(token) <= strlen(dictionary[i].word) &&
                    strlen(token) > 2 &&
                    strstr(dictionary[i].word, token) != NULL) {
                    word_score += dictionary[i].score;
                    break;
                }
            }
        }

        token = strtok(NULL, " ");
    }

    printf("Sentiment score: %d\n", word_score);
}

int main() {
    load_dictionary();

    int fd = open(DATA_FILE, O_RDONLY);

    if (fd < 0) {
        perror("Error opening input file");
        exit(1);
    }

    char line[1024];

    while (fgets(line, sizeof(line), fd) != NULL) {
        process_line(line);
    }

    close(fd);

    return 0;
}