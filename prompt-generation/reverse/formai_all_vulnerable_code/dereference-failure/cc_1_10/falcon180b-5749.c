//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

typedef struct {
    char name[20];
    int hex_value;
    int r;
    int g;
    int b;
} Color;

Color colors[MAX_COLORS];

int main() {
    int num_colors;
    char input_file[50], output_file[50];

    printf("Enter the number of colors you want to convert: ");
    scanf("%d", &num_colors);

    printf("Enter the input file name: ");
    scanf("%s", input_file);

    printf("Enter the output file name: ");
    scanf("%s", output_file);

    FILE *input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    FILE *output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    // Read in colors from input file
    int i = 0;
    while (fscanf(input_fp, "%s %d %d %d", colors[i].name, &colors[i].hex_value, &colors[i].r, &colors[i].g)!= EOF) {
        i++;
        if (i >= num_colors) {
            printf("Error: too many colors in input file.\n");
            exit(1);
        }
    }

    // Convert colors to RGB
    for (int j = 0; j < i; j++) {
        char hex_str[7];
        sprintf(hex_str, "%06X", colors[j].hex_value);
        colors[j].r = strtol(hex_str, NULL, 16) >> 16;
        colors[j].g = strtol(hex_str, NULL, 16) >> 8 & 0xFF;
        colors[j].b = strtol(hex_str, NULL, 16) & 0xFF;
    }

    // Write colors to output file
    fprintf(output_fp, "#define MAX_COLORS %d\n", num_colors);
    fprintf(output_fp, "Color colors[] = {\n");
    for (int j = 0; j < i; j++) {
        fprintf(output_fp, "    { \"%s\", 0x%06X, %d, %d, %d },\n", colors[j].name, colors[j].hex_value, colors[j].r, colors[j].g, colors[j].b);
    }
    fprintf(output_fp, "};\n");

    fclose(input_fp);
    fclose(output_fp);

    printf("Color conversion completed successfully!\n");

    return 0;
}