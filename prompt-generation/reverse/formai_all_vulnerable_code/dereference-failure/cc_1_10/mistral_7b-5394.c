//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_WORD_LEN 50
#define NUM_STOP_WORDS 10

struct StopWord {
    char word[MAX_WORD_LEN];
};

struct StopWord stop_words[NUM_STOP_WORDS] = {{"THE"}, {"A"}, {"AN"}, {"AND"}, {"IN"}, {"TO"}, {"IS"}, {"IT"}, {"FOR"}, {"ON"}};

bool is_stop_word(char word[MAX_WORD_LEN]) {
    for (int i = 0; i < NUM_STOP_WORDS; i++) {
        if (strcasecmp(stop_words[i].word, word) == 0) {
            return true;
        }
    }
    return false;
}

void process_line(char line[1024], char output[1024]) {
    char word[MAX_WORD_LEN];
    char *token;
    int i = 0;

    strcpy(output, "");

    token = strtok(line, " ");
    while (token != NULL) {
        // Convert to uppercase
        for (int j = 0; j < strlen(token); j++) {
            token[j] = toupper(token[j]);
        }

        // Check if stop word
        if (!is_stop_word(token)) {
            strcat(output, token);
            strcat(output, " ");
            i++;
        }

        token = strtok(NULL, " ");
    }

    // Remove last space
    if (i > 0) {
        output[strlen(output) - 1] = '\0';
    }
}

int main(int argc, char *argv[]) {
    FILE *input, *output;
    char line[1024];
    char output_line[1024];

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    input = fopen(argv[1], "r");
    output = fopen(argv[2], "w");

    if (input == NULL || output == NULL) {
        perror("Error opening files");
        return 1;
    }

    while (fgets(line, sizeof(line), input) != NULL) {
        process_line(line, output_line);
        fputs(output_line, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}