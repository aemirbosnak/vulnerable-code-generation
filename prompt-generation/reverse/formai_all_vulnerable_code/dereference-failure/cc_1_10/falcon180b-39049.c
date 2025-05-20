//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[MAX_LINE_SIZE], output_filename[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];
    int hex_color_code = 0;
    int decimal_color_code = 0;
    int red = 0, green = 0, blue = 0;

    // Prompt the user for the input and output file names
    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    // Open the input and output files
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read the input file line by line
    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        // Convert the hex color code to decimal
        if (hex_color_code == 0) {
            sscanf(line, "#%02X%02X%02X", &red, &green, &blue);
            hex_color_code = 1;
        } else {
            // Convert the decimal color code to hex
            sprintf(line, "%02X%02X%02X", red, green, blue);
        }

        // Write the converted color code to the output file
        fprintf(output_file, "%s\n", line);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}