//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 40
#define MAX_LINES 20

struct line {
    char *data;
    int length;
};

struct ascii_art {
    struct line *lines;
    int num_lines;
};

void generate_ascii_art(struct ascii_art *art, char *input) {
    int i, j, k;
    char *line_data;
    int line_length;
    int num_lines = 0;

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '\n') {
            num_lines++;
        }
    }

    art->lines = malloc(num_lines * sizeof(struct line));
    art->num_lines = num_lines;

    i = 0;
    j = 0;
    while (i < strlen(input)) {
        if (input[i] == '\n') {
            line_data = malloc(j * sizeof(char));
            strncpy(line_data, input + k, j);
            line_data[j - 1] = '\0';
            line_length = strlen(line_data);
            art->lines[num_lines - 1].data = line_data;
            art->lines[num_lines - 1].length = line_length;
            j = 0;
            num_lines--;
        } else {
            j++;
        }
        i++;
    }
}

void print_ascii_art(struct ascii_art *art) {
    int i;

    for (i = 0; i < art->num_lines; i++) {
        printf("%s", art->lines[i].data);
    }
}

int main() {
    char *input;
    struct ascii_art art;

    printf("Enter text to convert to ASCII art:\n");
    scanf("%s", input);

    generate_ascii_art(&art, input);
    print_ascii_art(&art);

    free(art.lines);

    return 0;
}