//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 7

enum {
    COLOR_BLACK = 0,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_YELLOW,
    COLOR_BLUE,
    COLOR_MAGENTA,
    COLOR_CYAN,
    COLOR_WHITE
};

char *color_names[] = {
    [COLOR_BLACK] = "black",
    [COLOR_RED] = "red",
    [COLOR_GREEN] = "green",
    [COLOR_YELLOW] = "yellow",
    [COLOR_BLUE] = "blue",
    [COLOR_MAGENTA] = "magenta",
    [COLOR_CYAN] = "cyan",
    [COLOR_WHITE] = "white"
};

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    char line[MAX_CODE_LENGTH + 1];
    while (fgets(line, MAX_CODE_LENGTH + 1, input_file)!= NULL) {
        int code_length = strlen(line);
        if (code_length > MAX_CODE_LENGTH) {
            printf("Error: Code too long.\n");
            fclose(input_file);
            fclose(output_file);
            return 1;
        }

        char *color_name = strtok(line, " ");
        int color_code = -1;

        for (int i = 0; i < sizeof(color_names) / sizeof(char *); i++) {
            if (strcmp(color_name, color_names[i]) == 0) {
                color_code = i;
                break;
            }
        }

        if (color_code == -1) {
            printf("Error: Invalid color name.\n");
            fclose(input_file);
            fclose(output_file);
            return 1;
        }

        fprintf(output_file, "#define %s %d\n", color_name, color_code);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}