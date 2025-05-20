//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000
#define MAX_LINE 100

char input_file[MAX_SIZE];
char output_file[MAX_SIZE];
char line[MAX_LINE];

void read_file(FILE *file) {
    int i = 0;
    while (fgets(line, MAX_LINE, file)!= NULL) {
        for (int j = 0; j < strlen(line); j++) {
            if (isalpha(line[j])) {
                line[j] = toupper(line[j]);
            }
        }
        strcat(input_file, line);
        i++;
        if (i == MAX_SIZE) {
            printf("Error: Input file is too large.\n");
            exit(1);
        }
    }
}

void write_file(FILE *file) {
    int i = 0;
    while (input_file[i]!= '\0') {
        fprintf(file, "%s", input_file);
        i += strlen(input_file);
        if (i == MAX_SIZE) {
            printf("Error: Output file is too large.\n");
            exit(1);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./program input_file output_file\n");
        exit(1);
    }

    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);

    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: Output file cannot be created.\n");
        exit(1);
    }

    read_file(input);
    fclose(input);

    write_file(output);
    fclose(output);

    printf("File successfully edited.\n");

    return 0;
}