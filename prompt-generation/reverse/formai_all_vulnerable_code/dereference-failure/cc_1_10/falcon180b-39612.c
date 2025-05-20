//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_SUMMARY_LENGTH 100

char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error reading file.\n");
        exit(1);
    }
    return line;
}

int count_words(char *line) {
    int count = 0;
    char *word = strtok(line, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

void summarize_text(char *filename, int num_sentences) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int sentence_count = 0;
    char *line;
    while ((line = read_line(file))!= NULL) {
        int word_count = count_words(line);
        if (sentence_count == num_sentences && word_count > 0) {
            printf("...\n");
            break;
        } else if (sentence_count < num_sentences) {
            printf("%s", line);
            sentence_count++;
        }
        free(line);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <num_sentences>\n", argv[0]);
        return 1;
    }

    summarize_text(argv[1], atoi(argv[2]));

    return 0;
}