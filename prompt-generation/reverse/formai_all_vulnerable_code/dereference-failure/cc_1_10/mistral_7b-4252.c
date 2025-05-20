//MISTRAL-7B DATASET v1.0 Category: File Synchronizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r");
    if (!file1) die("Could not open file1");

    FILE *file2 = fopen(argv[2], "r");
    if (!file2) die("Could not open file2");

    char line1[MAX_LINE_SIZE], line2[MAX_LINE_SIZE];
    int line_num = 1;

    while (fgets(line1, sizeof(line1), file1) && fgets(line2, sizeof(line2), file2)) {
        size_t len1 = strlen(line1);
        size_t len2 = strlen(line2);

        if (len1 != len2) {
            printf("Lines %d and %d differ in length:\n", line_num, line_num + 1);
            printf("%s\n%s\n", line1, line2);
            goto fail;
        }

        // Compare lines character by character
        for (size_t i = 0; i < len1; ++i) {
            if (line1[i] != line2[i]) {
                printf("Lines %d and %d differ at character %d:\n", line_num, line_num + 1, i + 1);
                printf("%s\n%s\n", line1, line2);
                goto fail;
            }
        }

        ++line_num;
    }

    if (feof(file1) && feof(file2)) {
        printf("Files are identical.\n");
    } else {
        char remaining1[MAX_LINE_SIZE], remaining2[MAX_LINE_SIZE];
        fgets(remaining1, sizeof(remaining1), file1);
        fgets(remaining2, sizeof(remaining2), file2);

        if (strlen(remaining1) != strlen(remaining2)) {
            printf("Files differ in remaining data.\n");
            goto fail;
        }

        printf("Files are mostly identical, but have some differences.\n");
        printf("Line %d in file1 is missing in file2:\n%s\n", line_num, remaining1);
        printf("Line %d in file2 is missing in file1:\n%s\n", line_num + 1, remaining2);
    }

    fclose(file1);
    fclose(file2);
    return 0;

fail:
    fclose(file1);
    fclose(file2);
    return 1;
}