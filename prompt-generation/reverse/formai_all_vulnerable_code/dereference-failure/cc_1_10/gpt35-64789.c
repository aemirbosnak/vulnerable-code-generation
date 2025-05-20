//FormAI DATASET v1.0 Category: Compression algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compression(char *input, char *output) {

    FILE *in_file, *out_file;
    int c, count = 0;
    char current;

    //Open the input file for reading
    in_file = fopen(input, "r");
    if (in_file == NULL) {
        printf("Could not open %s for reading\n", input);
        exit(EXIT_FAILURE);
    }

    //Open the output file for writing
    out_file = fopen(output, "w");
    if (out_file == NULL) {
        printf("Could not open %s for writing\n", output);
        exit(EXIT_FAILURE);
    }

    //Get the first character from the input
    current = fgetc(in_file);

    //Loop through the input file until end of file is reached
    while (current != EOF) {

        //Increment the count for the current character
        count++;

        //Get the next character from the input
        c = fgetc(in_file);

        //If the next character is different, write the count and current character to the output file
        if (c != current) {
            fprintf(out_file, "%d%c", count, current);
            count = 0;
            current = c;
        }
    }

    //Write the final count and current character to the output file
    fprintf(out_file, "%d%c", count, current);

    //Close the input and output files
    fclose(in_file);
    fclose(out_file);
}

int main() {
    char input[] = "input.txt";
    char output[] = "output.txt";

    compression(input, output);

    printf("Compression complete!\n");

    return 0;
}