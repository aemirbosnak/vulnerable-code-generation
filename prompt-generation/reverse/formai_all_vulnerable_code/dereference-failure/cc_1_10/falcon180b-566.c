//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 200
#define MAX_WORDS 1000
#define MAX_LINES 2000

typedef struct {
    char *text;
    int length;
} Word;

typedef struct {
    Word *words;
    int num_words;
    int max_words;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
    int max_lines;
} Ebook;

void init_ebook(Ebook *ebook) {
    ebook->lines = NULL;
    ebook->num_lines = 0;
    ebook->max_lines = MAX_LINES;
}

void add_line(Ebook *ebook, char *line) {
    if (ebook->num_lines >= ebook->max_lines) {
        printf("Error: Maximum number of lines reached.\n");
        return;
    }

    Word *words = NULL;
    int num_words = 0;
    char *text = strdup(line);
    char *word = strtok(text, " ");

    while (word!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Maximum number of words in a line reached.\n");
            free(text);
            return;
        }

        Word *new_word = malloc(sizeof(Word));
        new_word->text = strdup(word);
        new_word->length = strlen(word);
        words = realloc(words, sizeof(Word) * ++num_words);
        words[num_words - 1] = *new_word;

        word = strtok(NULL, " ");
    }

    Line *new_line = malloc(sizeof(Line));
    new_line->words = words;
    new_line->num_words = num_words;
    new_line->max_words = MAX_WORDS;
    ebook->lines = realloc(ebook->lines, sizeof(Line) * ++ebook->num_lines);
    ebook->lines[ebook->num_lines - 1] = *new_line;
}

void print_ebook(Ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        for (int j = 0; j < ebook->lines[i].num_words; j++) {
            printf("%s ", ebook->lines[i].words[j].text);
        }
        printf("\n");
    }
}

int main() {
    Ebook ebook;
    init_ebook(&ebook);

    char line[MAX_CHARS];
    while (fgets(line, MAX_CHARS, stdin)!= NULL) {
        add_line(&ebook, line);
    }

    print_ebook(&ebook);

    return 0;
}