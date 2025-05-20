//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char *text;
    int length;
} Text;

typedef struct {
    double wpm;
    int errors;
    int words;
    int characters;
} Results;

Text load_text(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    long length = ftell(fp);
    rewind(fp);

    char *text = malloc(length + 1);
    if (text == NULL) {
        fprintf(stderr, "Error: could not allocate memory for text\n");
        exit(EXIT_FAILURE);
    }

    fread(text, 1, length, fp);
    text[length] = '\0';

    fclose(fp);

    Text result = {text, length};
    return result;
}

Results test_typing(Text text) {
    printf("Type the following text as accurately and quickly as possible:\n\n");
    printf("%s\n\n", text.text);

    char input[text.length + 1];
    scanf("%s", input);

    int errors = 0;
    int words = 0;
    int characters = 0;

    for (int i = 0; i < text.length; i++) {
        if (text.text[i] != input[i]) {
            errors++;
        }
        if (text.text[i] == ' ' || text.text[i] == '\n') {
            words++;
        }
        characters++;
    }

    double wpm = (words / 5) * (60 / (characters / 60));

    Results result = {wpm, errors, words, characters};
    return result;
}

void print_results(Results results) {
    printf("Your typing speed is %f WPM\n", results.wpm);
    printf("You made %d errors\n", results.errors);
    printf("You typed %d words\n", results.words);
    printf("You typed %d characters\n", results.characters);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Text text = load_text(argv[1]);
    Results results = test_typing(text);
    print_results(results);

    return EXIT_SUCCESS;
}