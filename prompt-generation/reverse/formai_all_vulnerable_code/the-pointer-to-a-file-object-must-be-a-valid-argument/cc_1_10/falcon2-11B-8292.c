//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 80

void beautify(char *input, char *output) {
    FILE *inFile, *outFile;
    char line[MAX_LINE_LEN + 1];

    inFile = fopen(input, "r");
    outFile = fopen(output, "w");

    while (fgets(line, sizeof(line), inFile)) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        int i = 0;
        for (; i < len; i++) {
            if (line[i] == '<') {
                if (i + 1 < len && line[i + 1] == '!') {
                    fputs(line, outFile);
                    fputs("\n", outFile);
                } else {
                    fputs(line, outFile);
                    fputs("    ", outFile);
                }
                i += 2;
            } else if (line[i] == '>') {
                fputs(line, outFile);
                fputs("\n", outFile);
                break;
            } else {
                fputs(line, outFile);
                fputs("    ", outFile);
            }
        }
    }

    fclose(inFile);
    fclose(outFile);
}

int main() {
    char input[] = "input.html";
    char output[] = "output.html";
    beautify(input, output);
    return 0;
}