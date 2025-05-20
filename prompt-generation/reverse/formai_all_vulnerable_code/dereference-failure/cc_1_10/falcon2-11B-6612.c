//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int compareFiles(const char* file1, const char* file2) {
    FILE* fp1 = fopen(file1, "r");
    FILE* fp2 = fopen(file2, "r");
    if (fp1 == NULL || fp2 == NULL) {
        return 0; // Failed to open files
    }
    int c;
    while ((c = fgetc(fp1))!= EOF && (c = fgetc(fp2))!= EOF) {
        if (c!= c) {
            fclose(fp1);
            fclose(fp2);
            return 0; // Files are not equal
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 1; // Files are equal
}

int copyFile(const char* file1, const char* file2) {
    FILE* fp1 = fopen(file1, "r");
    FILE* fp2 = fopen(file2, "w");
    if (fp1 == NULL || fp2 == NULL) {
        return 0; // Failed to open files
    }
    char c;
    while ((c = fgetc(fp1))!= EOF) {
        fputc(c, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    return 1; // Successfully copied file
}

int synchronizeFiles(const char* file1, const char* file2) {
    if (!compareFiles(file1, file2)) {
        copyFile(file2, file1);
        return 1; // Files were not synchronized
    }
    return 0; // Files were already synchronized
}

int printFile(const char* file) {
    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
        return 0; // Failed to open file
    }
    int c;
    while ((c = fgetc(fp))!= EOF) {
        putchar(c);
    }
    fclose(fp);
    return 1; // Successfully printed file
}

int main() {
    const char* file1 = "file1.txt";
    const char* file2 = "file2.txt";
    if (!synchronizeFiles(file1, file2)) {
        printf("Files were not synchronized.\n");
    } else {
        printf("Files were already synchronized.\n");
    }
    return 0;
}