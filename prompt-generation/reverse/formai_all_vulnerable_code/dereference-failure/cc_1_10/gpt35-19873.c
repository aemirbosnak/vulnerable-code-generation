//FormAI DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];

    // Open input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file\n");
        exit(EXIT_FAILURE);
    }

    // Open output file
    FILE *out_fp = fopen("output.txt", "w");
    if (out_fp == NULL) {
        printf("Error opening output file\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        char *token;
        token = strtok(line, " ");

        // Loop through each word in the line
        while (token != NULL) {
            int length = strlen(token);

            // Check if the word contains the character 'c'
            for (int i = 0; i < length; i++) {
                if (token[i] == 'c') {
                    // Remove the character 'c' from the word
                    for (int j = i; j < length - 1; j++) {
                        token[j] = token[j+1];
                    }
                    token[length - 1] = '\0';
                    length--;
                    i--;
                }
            }

            // Output the modified word
            fprintf(out_fp, "%s ", token);

            token = strtok(NULL, " ");
        }

        fprintf(out_fp, "\n");
    }

    // Close files
    fclose(fp);
    fclose(out_fp);

    return 0;
}