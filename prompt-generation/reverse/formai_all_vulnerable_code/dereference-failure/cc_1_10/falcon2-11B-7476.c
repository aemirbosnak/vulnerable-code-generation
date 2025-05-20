//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 256

int main() {
    char src[MAX_PATH_LENGTH];
    char dst[MAX_PATH_LENGTH];
    char file[MAX_PATH_LENGTH];
    FILE *inFile, *outFile;

    printf("Enter the source file name: ");
    fgets(src, MAX_PATH_LENGTH, stdin);

    printf("Enter the destination file name: ");
    fgets(dst, MAX_PATH_LENGTH, stdin);

    printf("Enter the filename to backup: ");
    fgets(file, MAX_PATH_LENGTH, stdin);

    inFile = fopen(src, "r");
    outFile = fopen(dst, "a");

    if (inFile == NULL) {
        printf("Error opening source file\n");
        return 1;
    }

    if (outFile == NULL) {
        printf("Error opening destination file\n");
        fclose(inFile);
        return 1;
    }

    printf("Backing up %s to %s\n", file, dst);

    char buf[4096];
    size_t len;

    while ((len = fread(buf, 1, sizeof(buf), inFile)) > 0) {
        fwrite(buf, 1, len, outFile);
    }

    fclose(inFile);
    fclose(outFile);

    printf("Backup complete\n");

    return 0;
}