//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_SIZE 1024

void synchronize_files(char *file1, char *file2) {
    FILE *fp1, *fp2;
    char line1[MAX_LINE_SIZE], line2[MAX_LINE_SIZE];
    int c1, c2;

    // Open the files
    fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        printf("Error opening file 1: %s\n", strerror(errno));
        exit(1);
    }

    fp2 = fopen(file2, "r");
    if (fp2 == NULL) {
        printf("Error opening file 2: %s\n", strerror(errno));
        exit(1);
    }

    // Initialize the file pointers
    rewind(fp1);
    rewind(fp2);

    // Compare the files line by line
    while ((c1 = fgetc(fp1))!= EOF || (c2 = fgetc(fp2))!= EOF) {
        if (c1!= c2) {
            printf("Files are different\n");
            exit(1);
        }
    }

    printf("Files are the same\n");

    // Close the files
    fclose(fp1);
    fclose(fp2);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(1);
    }

    synchronize_files(argv[1], argv[2]);

    return 0;
}