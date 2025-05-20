//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

int main() {
    char input_file[100];
    FILE *input;
    char line[MAX_LINE_LENGTH];

    // Get input file name from command line argument
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    // Open input file for reading
    input = fopen(input_file, "r");

    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read each line from input file and convert to ASCII art
    while (fgets(line, MAX_LINE_LENGTH, input)!= NULL) {

        // Remove newline character from end of line
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        // Convert each character to corresponding ASCII art
        char *ascii_art = (char *)malloc(strlen(line) * 2 + 1);
        int i = 0;
        for (int j = 0; j < strlen(line); j++) {
            if (isalpha(line[j])) {
                ascii_art[i++] = line[j];
            } else {
                ascii_art[i++] = '.';
            }
        }
        ascii_art[i] = '\0';

        // Print ASCII art
        printf("%s\n", ascii_art);
    }

    // Close input file
    fclose(input);

    return 0;
}