//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 4096

void syncFiles(char *src, char *dst) {
    char buffer[BUF_SIZE];
    FILE *srcFile = fopen(src, "r");
    FILE *dstFile = fopen(dst, "r");

    if (!srcFile ||!dstFile) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    char *srcContent = (char *) malloc(BUF_SIZE);
    char *dstContent = (char *) malloc(BUF_SIZE);

    if (!srcContent ||!dstContent) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUF_SIZE, srcFile)!= NULL) {
        strcpy(srcContent, buffer);
    }
    fclose(srcFile);

    while (fgets(buffer, BUF_SIZE, dstFile)!= NULL) {
        strcpy(dstContent, buffer);
    }
    fclose(dstFile);

    if (strcmp(srcContent, dstContent)!= 0) {
        printf("Differences detected!\n");
        printf("Source: %s\n", src);
        printf("Destination: %s\n", dst);
        printf("Source content:\n");
        printf("%s\n", srcContent);
        printf("Destination content:\n");
        printf("%s\n", dstContent);
        printf("---\n");
    } else {
        printf("No differences.\n");
    }

    free(srcContent);
    free(dstContent);
}

int main() {
    syncFiles("src.txt", "dst.txt");
    return 0;
}