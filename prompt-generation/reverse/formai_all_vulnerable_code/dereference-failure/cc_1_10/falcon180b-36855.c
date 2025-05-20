//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000 //1 MB
#define MAX_VIRUS_NAME_SIZE 100

//function to check if a string is a palindrome
int is_palindrome(char *str) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (tolower(str[i])!= tolower(str[j])) {
            return 0;
        }
    }
    return 1;
}

//function to check if a file is infected with a virus
int check_virus(FILE *fp, char *virus_name) {
    char buffer[MAX_FILE_SIZE];
    int virus_found = 0;
    int buffer_size = 0;

    while (fgets(buffer + buffer_size, MAX_FILE_SIZE - buffer_size, fp)!= NULL) {
        buffer_size += strlen(buffer + buffer_size);

        char *line = strtok(buffer, "\n");
        while (line!= NULL) {
            if (is_palindrome(line)) {
                if (strlen(line) >= MAX_VIRUS_NAME_SIZE) {
                    printf("Possible virus found: %s\n", line);
                    virus_found = 1;
                }
            }
            line = strtok(NULL, "\n");
        }
    }

    return virus_found;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <virus_name>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char virus_name[MAX_VIRUS_NAME_SIZE];
    strncpy(virus_name, argv[2], MAX_VIRUS_NAME_SIZE - 1);
    virus_name[MAX_VIRUS_NAME_SIZE - 1] = '\0';

    int virus_found = check_virus(fp, virus_name);

    fclose(fp);

    if (virus_found) {
        printf("Virus found in file: %s\n", argv[1]);
    } else {
        printf("No virus found in file: %s\n", argv[1]);
    }

    return 0;
}