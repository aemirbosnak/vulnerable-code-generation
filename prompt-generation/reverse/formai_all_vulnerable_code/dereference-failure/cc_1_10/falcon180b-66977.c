//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to remove all whitespace characters from a string
void remove_whitespace(char *str) {
    int len = strlen(str);
    int new_len = 0;
    char *new_str = (char *)malloc(len + 1);

    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            new_str[new_len++] = tolower(str[i]);
        }
    }

    new_str[new_len] = '\0';

    strcpy(str, new_str);
    free(new_str);
}

// Function to compare two strings (case insensitive)
bool compare_strings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1!= len2) {
        return false;
    }

    for (int i = 0; i < len1; i++) {
        if (tolower(str1[i])!= tolower(str2[i])) {
            return false;
        }
    }

    return true;
}

// Function to scan a file for viruses
void scan_file(FILE *file, char *filename) {
    char line[1024];
    char *virus_name = "EICAR";
    int virus_length = strlen(virus_name);

    while (fgets(line, 1024, file)!= NULL) {
        remove_whitespace(line);

        if (compare_strings(line, virus_name)) {
            printf("Virus found in %s\n", filename);
            exit(1);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    scan_file(file, argv[1]);

    fclose(file);
    exit(0);
}