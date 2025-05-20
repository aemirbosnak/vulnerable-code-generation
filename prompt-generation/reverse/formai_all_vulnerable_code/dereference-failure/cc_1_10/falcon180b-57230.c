//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024

char *input_file_name = NULL;
char *output_file_name = NULL;

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file_name> <output_file_name>\n", argv[0]);
        exit(1);
    }

    input_file_name = argv[1];
    output_file_name = argv[2];

    FILE *input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *color_code = strstr(line, "\\#");
        if (color_code!= NULL) {
            char color[7];
            strncpy(color, color_code + 2, 6);
            color[6] = '\0';

            int r = 0, g = 0, b = 0;
            if (sscanf(color, "%02X%02X%02X", &r, &g, &b) == 3) {
                char hex_color_code[9];
                sprintf(hex_color_code, "\\#%02X%02X%02X", r, g, b);
                fprintf(output_file, "%s", hex_color_code);
            } else {
                fprintf(output_file, "Error: invalid color code '%s'\n", color);
            }
        } else {
            fprintf(output_file, "%s", line);
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("Done.\n");
    return 0;
}