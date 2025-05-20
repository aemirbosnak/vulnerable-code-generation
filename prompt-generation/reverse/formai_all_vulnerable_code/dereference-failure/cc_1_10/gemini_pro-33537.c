//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Color structure
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

// Convert a hex color string to a Color structure
Color hex_to_color(const char *hex) {
    Color color;
    sscanf(hex, "%02hhx%02hhx%02hhx", &color.red, &color.green, &color.blue);
    return color;
}

// Convert a Color structure to a hex color string
char *color_to_hex(Color color) {
    char *hex = malloc(7);
    sprintf(hex, "#%02hhx%02hhx%02hhx", color.red, color.green, color.blue);
    return hex;
}

// Print the usage information
void usage() {
    printf("Usage: color_code_converter [-h] [-i input_file] [-o output_file]\n");
    printf("Convert color codes between hex and RGB formats.\n");
    printf("\nOptions:\n");
    printf("  -h        Print this help message and exit.\n");
    printf("  -i input_file  Specify the input file containing the color codes.\n");
    printf("  -o output_file Specify the output file to write the converted color codes to.\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Parse command-line arguments
    char *input_file = NULL;
    char *output_file = NULL;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            usage();
            return EXIT_SUCCESS;
        } else if (strcmp(argv[i], "-i") == 0) {
            if (i + 1 < argc) {
                input_file = argv[i + 1];
                i++;
            } else {
                fprintf(stderr, "Error: missing input file.\n");
                return EXIT_FAILURE;
            }
        } else if (strcmp(argv[i], "-o") == 0) {
            if (i + 1 < argc) {
                output_file = argv[i + 1];
                i++;
            } else {
                fprintf(stderr, "Error: missing output file.\n");
                return EXIT_FAILURE;
            }
        } else {
            fprintf(stderr, "Error: invalid argument '%s'.\n", argv[i]);
            return EXIT_FAILURE;
        }
    }

    // Open input file
    FILE *input = stdin;
    if (input_file != NULL) {
        input = fopen(input_file, "r");
        if (input == NULL) {
            fprintf(stderr, "Error: could not open input file '%s'.\n", input_file);
            return EXIT_FAILURE;
        }
    }

    // Open output file
    FILE *output = stdout;
    if (output_file != NULL) {
        output = fopen(output_file, "w");
        if (output == NULL) {
            fprintf(stderr, "Error: could not open output file '%s'.\n", output_file);
            return EXIT_FAILURE;
        }
    }

    // Read color codes from input file
    char line[256];
    while (fgets(line, sizeof(line), input) != NULL) {
        // Convert color code to Color structure
        Color color = hex_to_color(line);

        // Convert Color structure to hex color string
        char *hex = color_to_hex(color);

        // Write converted color code to output file
        fprintf(output, "%s\n", hex);

        // Free allocated memory
        free(hex);
    }

    // Close input and output files
    if (input != stdin) {
        fclose(input);
    }
    if (output != stdout) {
        fclose(output);
    }

    return EXIT_SUCCESS;
}