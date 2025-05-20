//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEYWORD_LEN 20
#define MAX_LINE_LEN 1024

struct keyword {
    char keyword[MAX_KEYWORD_LEN];
    int value;
};

struct keyword keywords[] = {
    {"education", 1},
    {"experience", 2},
    {"skills", 3},
    {"projects", 4},
    {"certifications", 5},
    {"languages", 6},
    {"interests", 7}
};

int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

int is_keyword(char *word) {
    int i;
    for (i = 0; i < num_keywords; i++) {
        if (strcmp(word, keywords[i].keyword) == 0) {
            return i;
        }
    }
    return -1;
}

void parse_line(char *line, int *section, int *subsection) {
    char *word;
    char *saveptr;
    int i;

    *section = -1;
    *subsection = -1;

    word = strtok_r(line, ":", &saveptr);
    while (word!= NULL) {
        i = is_keyword(word);
        if (i == -1) {
            printf("Unknown keyword: %s\n", word);
        } else {
            if (*section == -1) {
                *section = i;
            } else {
                *subsection = i;
            }
        }
        word = strtok_r(NULL, ":", &saveptr);
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LEN];
    int section = -1;
    int subsection = -1;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        parse_line(line, &section, &subsection);
    }

    fclose(fp);
    return 0;
}