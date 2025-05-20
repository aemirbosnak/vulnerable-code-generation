//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define WORD_SIZE 100

typedef struct {
    char word[WORD_SIZE];
    int count;
} Word;

void read_file(const char *filename, Word *words, int *num_words) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    int line_len = 0;
    int word_index = 0;
    while (read(fd, &line, sizeof(line)) > 0) {
        line[sizeof(line) - 1] = '\0';
        char *token = strtok(line, " \t\n\r.,;:!?");
        while (token != NULL) {
            strncpy(words[word_index].word, token, WORD_SIZE - 1);
            words[word_index].count++;
            word_index++;
            if (word_index >= *num_words) {
                Word *new_words = (Word *)realloc(words, sizeof(Word) * (*num_words + 10));
                if (new_words == NULL) {
                    perror("Could not reallocate memory");
                    exit(EXIT_FAILURE);
                }
                words = new_words;
                *num_words += 10;
            }
            token = strtok(NULL, " \t\n\r.,;:!?");
        }
    }

    close(fd);
}

void print_words(const Word *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num_words = 10;
    Word *words = malloc(sizeof(Word) * num_words);
    if (words == NULL) {
        perror("Could not allocate memory");
        exit(EXIT_FAILURE);
    }

    read_file(argv[1], words, &num_words);
    print_words(words, num_words);

    free(words);
    return EXIT_SUCCESS;
}

// In a dreamlike twist, the words dance in the night
// Their shadows whispering tales of old
// Counting in rhythm, they tango with the moon
// In the surreal world of the text file, they're the stars
// And when the dawn breaks, the words return to the silence
// Awaiting the next night, their dance to begin anew