//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This program is a sample metadata extractor that can read a file and extract useful metadata from it.
 * It has been written in C for performance and portability, and is able to work with a wide variety of file types.
 * The metadata extracted includes file name, file size, and file type.
 * This program can serve as a starting point for more advanced metadata extraction tasks.
 */

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (!fp) {
        printf("Unable to open file: %s\n", argv[1]);
        return 1;
    }

    // Get file size
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Extract file type
    char *extension = strrchr(argv[1], '.');

    if (extension == NULL) {
        printf("Unable to determine file type\n");
        return 1;
    }

    char type[10];

    if (strcmp(extension, ".txt") == 0) {
        strcpy(type, "TEXT");
    } else if (strcmp(extension, ".jpg") == 0 || strcmp(extension, ".jpeg") == 0) {
        strcpy(type, "JPEG");
    } else if (strcmp(extension, ".png") == 0) {
        strcpy(type, "PNG");
    } else if (strcmp(extension, ".pdf") == 0) {
        strcpy(type, "PDF");
    } else {
        strcpy(type, "UNKNOWN");
    }

    printf("File Name: %s\n", argv[1]);
    printf("File Size: %ld bytes\n", size);
    printf("File Type: %s\n", type);

    fclose(fp);
    return 0;
}