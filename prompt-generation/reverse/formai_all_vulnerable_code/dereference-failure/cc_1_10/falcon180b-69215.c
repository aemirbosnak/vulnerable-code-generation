//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

char *get_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        fprintf(stderr, "Error: Unable to read file.\n");
        exit(1);
    }
    return line;
}

void print_text_art(char *text, int font_size) {
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        if (text[i] == '\n') {
            printf("\n");
        } else {
            for (j = 0; j < font_size; j++) {
                printf(" ");
            }
            printf("%c", text[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <font_size>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file.\n");
        return 1;
    }

    int font_size = atoi(argv[2]);

    char *line = get_line(file);
    while (line!= NULL) {
        print_text_art(line, font_size);
        free(line);
        line = get_line(file);
    }

    fclose(file);
    return 0;
}