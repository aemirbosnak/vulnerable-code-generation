//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 10

void highlight_names(char *line, char *name1, char *name2) {
    int len1 = strlen(name1);
    int len2 = strlen(name2);
    int pos1 = -1, pos2 = -1;

    pos1 = strpos(line, name1);
    if (pos1 == -1) {
        printf("%s\n", line);
        return;
    }

    pos2 = strpos(line + pos1 + len1, " ");
    if (pos2 == -1) {
        printf("Error: No space found after %s in line: %s\n", name1, line);
        exit(EXIT_FAILURE);
    }

    strncpy(line + pos1, "< highlight >", len1 + 6);
    strncpy(line + pos1 + len1 + 6, name2, len2);
    line[pos1 + len1 + len2 + 6] = '\0';
    printf("%s\n", line);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[1024];
    char name1[NAME_LEN] = "Romeo";
    char name2[NAME_LEN] = "Juliet";

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        highlight_names(line, name1, name2);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}

int strpos(const char *haystack, const char *needle) {
    size_t i;

    for (i = 0; haystack[i] != '\0'; i++) {
        if (memcmp(haystack + i, needle, strlen(needle)) == 0)
            return i;
    }

    return -1;
}