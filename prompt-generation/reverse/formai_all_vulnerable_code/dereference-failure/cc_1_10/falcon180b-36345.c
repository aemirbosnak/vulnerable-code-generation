//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function declarations
void read_file(FILE *file, char **lines);
int count_words(char *line);
int count_sentences(char *line);
int count_paragraphs(char *line);

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s'.\n", argv[1]);
        return 1;
    }

    char **lines = NULL;
    int num_lines = 0;
    read_file(file, &lines);

    for (int i = 0; i < num_lines; i++) {
        printf("Line %d:\n", i + 1);
        printf("Words: %d\n", count_words(lines[i]));
        printf("Sentences: %d\n", count_sentences(lines[i]));
        printf("Paragraphs: %d\n\n", count_paragraphs(lines[i]));
    }

    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    fclose(file);
    return 0;
}

void read_file(FILE *file, char **lines) {
    char line[MAX_LINE_LENGTH];
    int num_lines = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        lines = realloc(lines, sizeof(char *) * ++num_lines);
        lines[num_lines - 1] = strdup(line);
    }
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

int count_sentences(char *line) {
    int count = 0;
    char *sentence = strtok(line, ".");

    while (sentence!= NULL) {
        count++;
        sentence = strtok(NULL, ".");
    }

    return count;
}

int count_paragraphs(char *line) {
    int count = 0;
    char *paragraph = strtok(line, "\n");

    while (paragraph!= NULL) {
        count++;
        paragraph = strtok(NULL, "\n");
    }

    return count;
}