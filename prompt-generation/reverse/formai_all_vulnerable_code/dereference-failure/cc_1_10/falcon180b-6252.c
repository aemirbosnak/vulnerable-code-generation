//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

void print_art(char art[MAX_HEIGHT][MAX_WIDTH]) {
    for (int i = 0; i < MAX_HEIGHT; i++) {
        printf("%s\n", art[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char input_file[100] = {0};
    strcpy(input_file, argv[1]);

    char output_file[100] = {0};
    strcpy(output_file, argv[2]);

    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char art[MAX_HEIGHT][MAX_WIDTH] = {0};
    int x = 0, y = 0;

    while ((fscanf(input, "%c", &art[y][x]))!= EOF) {
        if (art[y][x] == '\n') {
            y++;
            x = 0;
        } else {
            x++;
        }
    }

    fclose(input);

    int max_width = x;

    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < max_width; j++) {
            art[i][j] = '*';
        }
    }

    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < max_width; j++) {
            if (art[i][j]!= '*') {
                art[i][j] = art[i][j] + 32;
            }
        }
    }

    printf("ASCII art generated successfully!\n");

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    for (int i = 0; i < MAX_HEIGHT; i++) {
        fprintf(output, "%s\n", art[i]);
    }

    fclose(output);

    return 0;
}