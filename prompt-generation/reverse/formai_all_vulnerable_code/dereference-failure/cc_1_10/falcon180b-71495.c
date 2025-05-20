//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100000
#define MAX_LINE 1000

char input_file[MAX_SIZE];
char output_file[MAX_SIZE];
char line[MAX_LINE];
char *word;

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);

    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, input)!= NULL) {
        char *p = line;
        while (*p!= '\0') {
            if (isalpha(*p)) {
                word = p;
                while (isalpha(*p)) {
                    p++;
                }
                *p = '\0';
                p++;
            } else {
                p++;
            }
        }
        fprintf(output, "%s\n", line);
    }

    fclose(input);
    fclose(output);

    return 0;
}