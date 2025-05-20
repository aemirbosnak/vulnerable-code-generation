//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_CHAR 128
#define ART_WIDTH 50
#define ART_HEIGHT 10

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    char symbol;
    point pos;
} cell;

void generate_ascii_art(char *text) {
    int i, j, k;
    int text_len = strlen(text);
    cell ascii_arr[MAX_CHAR][ART_HEIGHT];

    memset(ascii_arr, 0, sizeof(ascii_arr));

    for (i = 0; i < text_len; i++) {
        char c = text[i];
        point p;

        p.x = i % ART_WIDTH;
        p.y = i / ART_WIDTH;

        if (c >= 'A' && c <= 'Z') {
            ascii_arr[p.x][p.y].symbol = c;
            continue;
        }

        switch (c) {
            case ' ':
                ascii_arr[p.x][p.y].symbol = ' ';
                break;
            case '\n':
                ascii_arr[p.x][p.y].symbol = '\n';
                p.x = 0;
                i++;
                break;
            case '\t':
                ascii_arr[p.x][p.y].symbol = '\t';
                for (j = 1; j < ART_WIDTH; j++) {
                    ascii_arr[p.x + j][p.y].symbol = ' ';
                }
                break;
            default:
                for (j = 0; j < ART_HEIGHT; j++) {
                    for (k = 0; k < 8; k++) {
                        if ((c & (1 << (7 - k))) != 0) {
                            ascii_arr[p.x + (j % 2)][p.y + j / 2].symbol = '#';
                        }
                    }
                }
                break;
        }
    }

    FILE *fp = fopen("output.asc", "w");

    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    for (i = 0; i < ART_HEIGHT; i++) {
        for (j = 0; j < ART_WIDTH; j++) {
            fprintf(fp, "%c", ascii_arr[j][i].symbol);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        exit(1);
    }

    char *text = argv[1];

    if (access("output.asc", F_OK) != -1) {
        unlink("output.asc");
    }

    generate_ascii_art(text);

    printf("ASCII art generated successfully. Check 'output.asc' file.\n");

    return 0;
}