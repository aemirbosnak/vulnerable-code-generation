//FormAI DATASET v1.0 Category: HTML beautifier ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautifyHTML(char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {

        // remove leading spaces
        while (line[0] == ' ') {
            memmove(line, line+1, strlen(line));
        }

        // replace tabs with 4 spaces
        char *tab = "\t";
        char *replacement = "    ";
        int tabIndex = 0;
        while ((tabIndex = strstr(line, tab) - line) != -1) {
            memmove(line+tabIndex+strlen(replacement), line+tabIndex+strlen(tab), strlen(line)-tabIndex-strlen(tab)+1);
            strncpy(line+tabIndex, replacement, strlen(replacement));
        }

        // remove trailing spaces
        int i = strlen(line)-1;
        while (i >= 0 && line[i] == ' ') {
            line[i] = '\0';
            i--;
        }

        // print beautified line
        printf("%s\n", line);
    }

    fclose(fp);
    if (line)
        free(line);
}

int main() {
    char *filename = "index.html";
    beautifyHTML(filename);
    return 0;
}