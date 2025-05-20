//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SHADOW_SIZE 25

typedef struct {
    char text[1024];
    int shadow[SHADOW_SIZE][SHADOW_SIZE];
} Line;

void generate_shadow(const char *line, Line *result) {
    int x, y, i, j;
    char c;

    memset(result->shadow, 0, sizeof(result->shadow));

    for (i = 0; i < strlen(line); i++) {
        c = line[i];
        x = i % SHADOW_SIZE;
        y = i / SHADOW_SIZE;

        if (isalpha(c)) {
            result->shadow[y][x] += (toupper(c) - 'A' + 1);
            result->shadow[y][x] %= 26;
            result->shadow[y][x] += 'A';
        }
    }
}

void print_shadow(const Line *line) {
    int x, y;

    for (y = 0; y < SHADOW_SIZE; y++) {
        for (x = 0; x < SHADOW_SIZE; x++) {
            printf("%c", line->shadow[y][x]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    Line line;
    char filename[1024];

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line.text, sizeof(line.text), fp) != NULL) {
        generate_shadow(line.text, &line);
        print_shadow(&line);
    }

    fclose(fp);

    return 0;
}