//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define ASCII_ART_WIDTH 80
#define ASCII_ART_HEIGHT 24

typedef struct {
    char *text;
    int x, y;
} TextPosition;

void generate_ascii_art(char *input_text) {
    int num_lines = 0;
    char **lines = NULL;
    int line_length = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    TextPosition *text_positions = NULL;

    while (input_text[i]!= '\0') {
        if (line_length >= MAX_LINE_LENGTH) {
            lines[num_lines] = malloc(MAX_LINE_LENGTH);
            strncpy(lines[num_lines], input_text + j, MAX_LINE_LENGTH - 1);
            lines[num_lines][MAX_LINE_LENGTH - 1] = '\0';
            num_lines++;
            line_length = 0;
        }

        if (isspace(input_text[i])) {
            line_length++;
        } else {
            lines[num_lines - 1][line_length++] = tolower(input_text[i]);
        }

        i++;
    }

    if (line_length > 0) {
        lines[num_lines] = malloc(MAX_LINE_LENGTH);
        strncpy(lines[num_lines], input_text + j, MAX_LINE_LENGTH - 1);
        lines[num_lines][MAX_LINE_LENGTH - 1] = '\0';
        num_lines++;
    }

    text_positions = malloc(sizeof(TextPosition) * num_lines);

    for (i = 0; i < num_lines; i++) {
        text_positions[i].text = lines[i];
        text_positions[i].x = (i % ASCII_ART_HEIGHT) * (ASCII_ART_WIDTH / ASCII_ART_HEIGHT);
        text_positions[i].y = i / ASCII_ART_HEIGHT;
    }

    for (i = 0; i < ASCII_ART_HEIGHT; i++) {
        for (j = 0; j < ASCII_ART_WIDTH; j++) {
            for (k = 0; k < num_lines; k++) {
                if (text_positions[k].x == j && text_positions[k].y == i) {
                    printf("%s", text_positions[k].text);
                }
            }
        }
        printf("\n");
    }

    for (i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    for (i = 0; i < num_lines; i++) {
        free(text_positions[i].text);
    }
    free(text_positions);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_text>\n", argv[0]);
        return 1;
    }

    char *input_text = argv[1];
    generate_ascii_art(input_text);

    return 0;
}