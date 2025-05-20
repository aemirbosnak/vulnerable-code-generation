//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char* text;
    int length;
} Line;

typedef struct {
    char* text;
    int length;
} Word;

Line* read_line(FILE* file) {
    Line* line = malloc(sizeof(Line));
    char* buffer = malloc(MAX_LINE_LENGTH);
    int length = 0;

    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }
        length += strlen(buffer);
    }

    line->text = malloc(length + 1);
    line->length = length;

    strcpy(line->text, buffer);

    free(buffer);

    return line;
}

Word* read_word(FILE* file) {
    Word* word = malloc(sizeof(Word));
    char* buffer = malloc(MAX_WORD_LENGTH);
    int length = 0;

    while (fscanf(file, "%s", buffer)!= EOF) {
        if (strlen(buffer) > 0 && isalpha(buffer[0])) {
            length += strlen(buffer);
        }
    }

    word->text = malloc(length + 1);
    word->length = length;

    strcpy(word->text, buffer);

    free(buffer);

    return word;
}

void print_line(Line* line) {
    printf("%s\n", line->text);
}

void print_word(Word* word) {
    printf("%s\n", word->text);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    Line* line = read_line(file);
    Word* word = read_word(file);

    print_line(line);
    print_word(word);

    fclose(file);

    free(line->text);
    free(line);
    free(word->text);
    free(word);

    return 0;
}