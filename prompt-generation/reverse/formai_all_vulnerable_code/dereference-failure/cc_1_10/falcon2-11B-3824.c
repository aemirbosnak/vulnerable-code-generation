//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 100

int main(int argc, char *argv[]) {
    char file1[MAX_PATH], file2[MAX_PATH], file1_new[MAX_PATH], file2_new[MAX_PATH];
    FILE *fp1, *fp2;

    if (argc!= 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        exit(1);
    }

    strcpy(file1, argv[1]);
    strcpy(file2, argv[2]);

    // Open the two files for reading and writing
    fp1 = fopen(file1, "r+");
    fp2 = fopen(file2, "r+");
    if (!fp1 ||!fp2) {
        printf("Error opening files.\n");
        exit(1);
    }

    // Copy the contents of the first file to the second file
    fseek(fp1, 0, SEEK_SET);
    fread(file2_new, sizeof(char), MAX_PATH, fp1);
    fseek(fp2, 0, SEEK_SET);
    fwrite(file2_new, sizeof(char), MAX_PATH, fp2);

    // Swap the contents of the two files
    fseek(fp1, 0, SEEK_SET);
    fseek(fp2, 0, SEEK_SET);
    char *p1 = file1_new, *p2 = file2_new;
    while (*p1 && *p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
        p1++;
        p2++;
    }

    // Close the files and print the results
    fclose(fp1);
    fclose(fp2);
    printf("File %s has been synchronized with %s.\n", file1, file2);
    return 0;
}