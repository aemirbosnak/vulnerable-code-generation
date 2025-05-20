//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define HAPPY_CHAR ':'

void process_line(char *line) {
    int i, j;
    char *happy_line = (char *) malloc(strlen(line) + 1);

    for (i = 0; i < strlen(line); i++) {
        if (isalpha(line[i])) {
            happy_line[i] = toupper(line[i]);
        } else if (line[i] == ' ') {
            happy_line[i] = ' ';
            for (j = i; j < strlen(line) && line[j] != ' '; j++) {
                if (isalpha(line[j])) {
                    happy_line[i+1] = towupper(line[j]);
                }
                i++;
            }
            i += j - i;
        } else if (line[i] == '\n') {
            happy_line[i] = HAPPY_CHAR;
            happy_line[i+1] = '\0';
            break;
        } else {
            happy_line[i] = line[i];
        }
    }

    FILE *output_file = fopen("output.txt", "a");
    fprintf(output_file, "%s\n", happy_line);
    fclose(output_file);

    free(happy_line);
}

int main() {
    FILE *input_file = fopen("happyfile.txt", "r");
    char line[MAX_LINE];

    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE, input_file) != NULL) {
        process_line(line);
    }

    fclose(input_file);

    printf("Happy processing completed! :)\n");

    return 0;
}