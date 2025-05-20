//Falcon-180B DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    int count = 0;

    if (argc < 3) {
        printf("Error: Invalid number of arguments.\n");
        printf("Usage: %s <filename> <delimiter>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    token = strtok(argv[2], ",");
    while (token!= NULL) {
        int delimiter_len = strlen(token);
        if (delimiter_len == 0) {
            printf("Error: Invalid delimiter.\n");
            fclose(file);
            return 1;
        }
        count++;
        token = strtok(NULL, ",");
    }

    if (count == 0) {
        printf("Error: No delimiters specified.\n");
        fclose(file);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *saveptr = NULL;
        int field_count = 0;

        token = strtok_r(line, argv[2], &saveptr);
        while (token!= NULL) {
            field_count++;
            token = strtok_r(NULL, argv[2], &saveptr);
        }

        if (field_count!= count) {
            printf("Error: Invalid number of fields in line.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}