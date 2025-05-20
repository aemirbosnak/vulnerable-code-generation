//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char *english;
    char *alien;
} word_t;

word_t words[MAX_WORDS];
int num_words = 0;

void add_word(char *english, char *alien) {
    if (num_words >= MAX_WORDS) {
        fprintf(stderr, "Error: Too many words.\n");
        exit(1);
    }
    words[num_words].english = strdup(english);
    words[num_words].alien = strdup(alien);
    num_words++;
}

void load_words(FILE *file) {
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *english = strtok(line, ",");
        char *alien = strtok(NULL, ",");
        if (english && alien) {
            add_word(english, alien);
        } else {
            fprintf(stderr, "Error: Invalid word.\n");
        }
    }
}

void save_words(FILE *file) {
    for (int i = 0; i < num_words; i++) {
        fprintf(file, "%s,%s\n", words[i].english, words[i].alien);
    }
}

bool search_word(const char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, words[i].english) == 0) {
            printf("%s -> %s\n", word, words[i].alien);
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [load|save|search] [filename]\n", argv[0]);
        return 1;
    }

    char *mode = argv[1];
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file.\n");
        return 1;
    }

    if (strcmp(mode, "load") == 0) {
        load_words(file);
    } else if (strcmp(mode, "save") == 0) {
        save_words(file);
    } else if (strcmp(mode, "search") == 0) {
        char word[1024];
        while (fgets(word, sizeof(word), stdin)) {
            search_word(word);
        }
    } else {
        fprintf(stderr, "Error: Invalid mode.\n");
        return 1;
    }

    fclose(file);
    return 0;
}