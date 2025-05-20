//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLOR_NAMES 100

typedef struct {
    char *color_name;
    char *color_code;
} ColorCodePair;

int main() {
    char input_line[MAX_LINE_LENGTH];
    char *token;
    ColorCodePair *color_code_pairs = NULL;
    int num_color_codes = 0;

    // Read in the input file
    FILE *input_file = fopen("color_codes.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Parse the input file and store the color code pairs in a linked list
    while (fgets(input_line, MAX_LINE_LENGTH, input_file)!= NULL) {
        token = strtok(input_line, "\t");
        while (token!= NULL) {
            num_color_codes++;
            if (num_color_codes > MAX_COLOR_NAMES) {
                printf("Error: Too many color codes.\n");
                return 1;
            }
            color_code_pairs = realloc(color_code_pairs, sizeof(ColorCodePair) * num_color_codes);
            color_code_pairs[num_color_codes - 1].color_name = strdup(token);
            color_code_pairs[num_color_codes - 1].color_code = strdup(token);
            token = strtok(NULL, "\t");
        }
    }
    fclose(input_file);

    // Print out the color code pairs
    printf("Color Code Pairs:\n");
    for (int i = 0; i < num_color_codes; i++) {
        printf("%s\t%s\n", color_code_pairs[i].color_name, color_code_pairs[i].color_code);
    }

    // Free the memory allocated for the color code pairs
    for (int i = 0; i < num_color_codes; i++) {
        free(color_code_pairs[i].color_name);
        free(color_code_pairs[i].color_code);
    }
    free(color_code_pairs);

    return 0;
}