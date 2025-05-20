//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int score;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open dictionary file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \t\n");
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcasecmp(token, dictionary[i].word) == 0) {
                goto next_line;
            }
        }

        strncpy(dictionary[num_words].word, token, WORD_LENGTH);
        dictionary[num_words].score = 0;
        num_words++;

next_line: {}
    }

    fclose(file);
}

int get_word_score(const char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcasecmp(dictionary[i].word, word) == 0) {
            return dictionary[i].score;
        }
    }

    // If the word is not in the dictionary, assume a neutral sentiment
    return 0;
}

void process_sentence(const char *sentence) {
    char *token = strtok(sentence, " .!?");
    int total_score = 0;

    while (token != NULL) {
        int word_score = get_word_score(token);
        total_score += word_score;
        token = strtok(NULL, " .!?");
    }

    printf("Sentiment score: %d\n", total_score);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dictionary_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    load_dictionary(argv[1]);

    const char *sentence = "Today is a beautiful day! The sun is shining and the birds are singing.";
    process_sentence(sentence);

    return EXIT_SUCCESS;
}