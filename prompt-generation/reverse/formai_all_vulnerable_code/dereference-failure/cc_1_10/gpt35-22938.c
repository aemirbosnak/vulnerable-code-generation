//FormAI DATASET v1.0 Category: HTML beautifier ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINES 512
#define MAX_LENGTH 1024

void beautify(char *filename, char *outputFilename);

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    beautify(argv[1], argv[2]);

    return 0;
}

void beautify(char *filename, char *outputFilename) {
    FILE *file = fopen(filename, "r");
    FILE *out = fopen(outputFilename, "w");

    if (file == NULL) {
        printf("ERROR: Input file not found.\n");
        exit(1);
    } else {
        char lines[MAX_LINES][MAX_LENGTH];
        int numLines = 0;
        char line[MAX_LENGTH];

        while (fgets(line, sizeof(line), file) != NULL) {
            strcpy(lines[numLines], line);
            numLines++;
        }

        for (int a = 0; a < numLines; a++) {
            char c;
            int start = 0;
            int end = strlen(lines[a]);
            char line2[MAX_LENGTH + 4];

            for (int b = 0; b < strlen(lines[a]); b++) {
                c = lines[a][b];

                if (isspace(c)) {
                    continue;
                }

                if (c == '<') {
                    if (start != 0) {
                        memset(line2, ' ', (start - 1));
                        line2[start - 1] = '\0';
                    }

                    start = b;
                }

                if (c == '>') {
                    end = b + 1;

                    if (end < strlen(lines[a])) {
                        memset(line2 + end, ' ', strlen(lines[a]) - end);
                        line2[strlen(lines[a])] = '\0';
                    }
                }
            }

            memset(line2, ' ', start);

            for (int b = start; b < end; b++) {
                line2[b] = lines[a][b];
            }

            line2[end] = '\0';
            fprintf(out, "%s\n", line2);
        }

        fclose(file);
        fclose(out);
    }
}