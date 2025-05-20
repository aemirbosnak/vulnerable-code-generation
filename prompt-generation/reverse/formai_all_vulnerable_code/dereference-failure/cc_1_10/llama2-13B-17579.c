//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 100
#define MAX_POEMS 5

typedef struct poem {
    char *name;
    char *text;
} poem_t;

poem_t poems[MAX_POEMS];

void generate_poems(void) {
    int i, j;
    char *line;
    char *words[MAX_LINE_LENGTH];

    for (i = 0; i < MAX_POEMS; i++) {
        poems[i].name = malloc(sizeof(char *) * (size_t) strlen(getenv("USER")) + 1);
        strcpy(poems[i].name, getenv("USER"));

        for (j = 0; j < MAX_LINE_LENGTH; j++) {
            line = malloc(sizeof(char) * (size_t) rand() % 10 + 1);
            words[j] = line;
            if (j == (MAX_LINE_LENGTH - 1)) {
                break;
            }
            line[rand() % 10] = ' ';
        }

        poems[i].text = malloc(sizeof(char *) * (size_t) strlen(line) + 1);
        strcpy(poems[i].text, line);
    }
}

void print_poems(void) {
    int i;

    for (i = 0; i < MAX_POEMS; i++) {
        printf("%s: %s\n", poems[i].name, poems[i].text);
    }
}

int main(void) {
    srand(time(NULL));
    generate_poems();
    print_poems();
    return 0;
}