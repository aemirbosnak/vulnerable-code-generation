//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define WORD_LEN 50

typedef struct {
    char word[WORD_LEN];
    int sentiment;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

bool is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int get_word(char **text, int *pos) {
    char word[WORD_LEN];
    int len = 0;

    while (is_alpha(**text) || **text == '_') {
        word[len++] = **text++;
        (*pos)++;
    }

    word[len] = '\0';

    return len;
}

void load_dictionary(const char *filename) {
    FILE *fp;
    char line[100];

    fp = fopen(filename, "r");

    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp)) {
        int len = strlen(line) - 1;
        if (line[len] == '\n') line[len] = '\0';

        int pos = 0;
        int word_len = get_word(&line, &pos);

        strcpy(dictionary[num_words].word, line);
        dictionary[num_words].sentiment = word_len > 0 ? 1 : 0;
        num_words++;
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_dictionary("dictionary.txt");

    int pos = 0;
    char text[1024];

    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0';

    int sentiment = 0;

    char *token = strtok(text, " .,?!:;");

    while (token != NULL) {
        for (int i = 0; i < num_words; i++) {
            int len = strlen(dictionary[i].word);
            if (len < strlen(token) || strncmp(dictionary[i].word, token, len) != 0) continue;
            sentiment += dictionary[i].sentiment;
            break;
        }

        token = strtok(NULL, " .,?!:;");
    }

    printf("Sentiment: %s\n", sentiment > 0 ? "Positive" : "Negative");

    return EXIT_SUCCESS;
}