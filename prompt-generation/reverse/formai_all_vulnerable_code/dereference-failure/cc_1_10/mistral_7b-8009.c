//MISTRAL-7B DATASET v1.0 Category: File Synchronizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define FILENAME_LENGTH 50

void print_differences(char *file1, char *file2) {
    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");

    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    int line_number = 1;

    if (fp1 == NULL || fp2 == NULL) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line1, sizeof(line1), fp1) != NULL && fgets(line2, sizeof(line2), fp2) != NULL) {
        size_t len1 = strlen(line1);
        size_t len2 = strlen(line2);

        int i;
        for (i = 0; i < len1 && i < len2 && tolower(line1[i]) == tolower(line2[i]); i++) {}

        if (i == len1) {
            printf("Line %d in file1 is the same as line %d in file2.\n", line_number, line_number);
            line_number++;
            continue;
        }

        printf("Line %d in file1 is different from line %d in file2:\n", line_number, line_number);
        printf("%s", line1);
        printf(" |");
        for (int j = 0; j < len1 + 10 - len2; j++) {
            printf(" ");
        }
        printf("^");
        printf("%s", line2);
        printf("\n");
        line_number++;
    }

    if (feof(fp1) && feof(fp2)) {
        printf("Both files have been processed.\n");
    } else if (feof(fp1)) {
        printf("Error reading file2.\n");
        fclose(fp2);
    } else if (feof(fp2)) {
        printf("Error reading file1.\n");
        fclose(fp1);
    } else {
        fprintf(stderr, "Error reading files.\n");
        exit(EXIT_FAILURE);
    }

    fclose(fp1);
    fclose(fp2);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char file1[FILENAME_LENGTH];
    char file2[FILENAME_LENGTH];

    strcpy(file1, argv[1]);
    strcpy(file2, argv[2]);

    print_differences(file1, file2);

    return EXIT_SUCCESS;
}