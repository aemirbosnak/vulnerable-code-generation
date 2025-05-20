//Falcon-180B DATASET v1.0 Category: Data mining ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_PATTERN_LENGTH 100
#define MAX_NUM_FILES 1000

char *file_names[MAX_NUM_FILES];
int num_files;

void read_file_names(char *filename) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    num_files = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        file_names[num_files] = strdup(line);
        num_files++;
    }
    fclose(fp);
}

int search_file(char *file_name, char *pattern, int case_sensitive) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int line_num = 1;
    int found = 0;

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", file_name);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (strstr(line, pattern)!= NULL) {
            if (case_sensitive) {
                printf("Line %d: %s\n", line_num, line);
            } else {
                printf("Line %d: %s\n", line_num, toupper(line));
            }
            found = 1;
        }
        line_num++;
    }

    fclose(fp);
    return found;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <file_name> <pattern> [case_sensitive]\n", argv[0]);
        exit(1);
    }

    strcpy(file_names[0], argv[1]);
    num_files = 1;

    char *pattern = argv[2];
    int pattern_len = strlen(pattern);
    if (pattern_len > MAX_PATTERN_LENGTH) {
        printf("Error: pattern length exceeds maximum allowed length.\n");
        exit(1);
    }

    int case_sensitive = 1;
    if (argc > 3) {
        if (strcmp(argv[3], "case_sensitive") == 0) {
            case_sensitive = 1;
        } else if (strcmp(argv[3], "case_insensitive") == 0) {
            case_sensitive = 0;
        } else {
            printf("Error: invalid option for case sensitivity.\n");
            exit(1);
        }
    }

    int found = 0;
    for (int i = 0; i < num_files; i++) {
        found |= search_file(file_names[i], pattern, case_sensitive);
    }

    if (!found) {
        printf("Pattern not found in any file.\n");
    }

    return 0;
}