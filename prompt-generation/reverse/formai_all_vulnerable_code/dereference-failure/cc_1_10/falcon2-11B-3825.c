//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_files(const char *fname1, const char *fname2) {
    FILE *fp1, *fp2;
    char buf[256];
    int len1, len2;

    // Open the files for reading
    if ((fp1 = fopen(fname1, "r")) == NULL ||
        (fp2 = fopen(fname2, "r")) == NULL) {
        return -1;
    }

    // Get the length of each file
    if (fread(buf, sizeof(char), sizeof(buf), fp1) == 0 ||
        fread(buf, sizeof(char), sizeof(buf), fp2) == 0) {
        return -1;
    }
    len1 = fseek(fp1, 0, SEEK_END);
    len2 = fseek(fp2, 0, SEEK_END);

    // Compare the files
    if (fread(buf, sizeof(char), sizeof(buf), fp1) == 0 ||
        fread(buf, sizeof(char), sizeof(buf), fp2) == 0) {
        return -1;
    }
    if (len1 == len2 &&
        strncmp(buf, buf, sizeof(buf))) {
        return 1;
    } else if (len1 > len2 &&
                strncmp(buf, buf, sizeof(buf))) {
        return 1;
    } else if (len2 > len1 &&
                strncmp(buf, buf, sizeof(buf))) {
        return 2;
    } else {
        return 0;
    }
}

int synchronize_files(const char *fname1, const char *fname2) {
    FILE *fp1, *fp2;
    char buf[256];
    int len1, len2;

    // Open the files for reading
    if ((fp1 = fopen(fname1, "r")) == NULL ||
        (fp2 = fopen(fname2, "r")) == NULL) {
        return -1;
    }

    // Get the length of each file
    if (fread(buf, sizeof(char), sizeof(buf), fp1) == 0 ||
        fread(buf, sizeof(char), sizeof(buf), fp2) == 0) {
        return -1;
    }
    len1 = fseek(fp1, 0, SEEK_END);
    len2 = fseek(fp2, 0, SEEK_END);

    // Compare the files
    if (fread(buf, sizeof(char), sizeof(buf), fp1) == 0 ||
        fread(buf, sizeof(char), sizeof(buf), fp2) == 0) {
        return -1;
    }
    if (len1 == len2 &&
        strncmp(buf, buf, sizeof(buf))) {
        return -1;
    } else {
        // Update the longer file to match the shorter file
        if (len1 > len2) {
            fwrite(buf, sizeof(char), len2, fp2);
            fseek(fp2, 0, SEEK_END);
        } else if (len2 > len1) {
            fwrite(buf, sizeof(char), len1, fp1);
            fseek(fp1, 0, SEEK_END);
        }
    }

    return 0;
}

int main() {
    const char *fname1 = "in.txt";
    const char *fname2 = "out.txt";
    int ret = synchronize_files(fname1, fname2);
    if (ret!= 0) {
        printf("Error synchronizing files\n");
    } else {
        printf("Files synchronized successfully\n");
    }

    return 0;
}