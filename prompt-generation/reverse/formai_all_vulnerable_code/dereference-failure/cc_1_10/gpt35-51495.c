//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char file1[MAX_SIZE], file2[MAX_SIZE];
    printf("Enter the names of the two files you want to synchronize:\n");
    scanf("%s %s", file1, file2);

    FILE *fp1, *fp2;
    fp1 = fopen(file1, "r");
    if(fp1 == NULL) {
        printf("Error in opening file %s\n", file1);
        exit(EXIT_FAILURE);
    }
    fp2 = fopen(file2, "r");
    if(fp2 == NULL) {
        printf("Error in opening file %s\n", file2);
        exit(EXIT_FAILURE);
    }

    char c1, c2;
    int line = 1, column = 0;
    while(1) {
        c1 = fgetc(fp1);
        c2 = fgetc(fp2);
        column++;
        if(c1 == '\n') {
            line++;
            column = 0;
            if(c2 == '\n') continue;
            printf("Files don't match at line %d, column %d\n", line, column);
            break;
        }
        if(c2 == '\n') {
            line++;
            column = 0;
            printf("Files don't match at line %d, column %d\n", line, column);
            break;
        }
        if(c1 == EOF && c2 == EOF) {
            printf("Files are synchronized!\n");
            break;
        }
        if(c1 != c2) {
            printf("Files don't match at line %d, column %d\n", line, column);
            break;
        }
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}