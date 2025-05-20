//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 256

void process_line(char *line, FILE *input, FILE *output) {
    int i, j;
    char temp[MAX_LINE_LEN];

    // Remove leading and trailing whitespaces
    for (i = 0; i < strlen(line); i++) {
        if (!isspace((unsigned char)line[i])) {
            temp[0] = line[i];
            break;
        }
    }

    for (j = strlen(line) - 1; j >= 0; j--) {
        if (!isspace((unsigned char)line[j])) {
            temp[strlen(temp) + 1] = line[j];
            temp[strlen(temp)] = '\0';
            break;
        }
    }

    // Reverse the line
    for (i = 0, j = strlen(temp) - 1; i < strlen(temp); i++, j--) {
        line[i] = temp[j];
    }

    // Replace all occurrences of "the" with "a"
    for (i = 0, j = 0; line[i] != '\0'; i++) {
        if (i > 0 && strncmp(&line[i - 2], "the", 3) == 0) {
            for (int k = i; k < i + 3; k++) {
                line[k] = 'a';
            }
            i -= 2; // Move back the index by 2 since we changed the length of the string
            j += 3; // Increment the count of replaced occurrences
        }
    }

    // Write the modified line to the output file
    fprintf(output, "%s\n", line);
}

int main(int argc, char *argv[]) {
    FILE *input, *output;

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    input = fopen(argv[1], "r");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    output = fopen(argv[2], "w");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), input) != NULL) {
        process_line(line, input, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}