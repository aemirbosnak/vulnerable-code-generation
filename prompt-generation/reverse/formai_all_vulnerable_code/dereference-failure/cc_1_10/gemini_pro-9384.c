//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// shannon entropy of a string
double shannon_entropy(char *str) {
    int len = strlen(str);
    int freq[256] = {0};
    for (int i = 0; i < len; i++) {
        freq[str[i]]++;
    }
    double entropy = 0.0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            double p = (double)freq[i] / len;
            entropy -= p * log2(p);
        }
    }
    return entropy;
}

// compare two files using shannon entropy
int compare_files(char *file1, char *file2) {
    FILE *fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        perror("fopen");
        return -1;
    }
    FILE *fp2 = fopen(file2, "r");
    if (fp2 == NULL) {
        perror("fopen");
        return -1;
    }
    char buf1[1024];
    char buf2[1024];
    int len1, len2;
    double entropy1, entropy2;
    while ((len1 = fread(buf1, 1, 1024, fp1)) > 0 && (len2 = fread(buf2, 1, 1024, fp2)) > 0) {
        if (len1 != len2) {
            return -1;
        }
        entropy1 = shannon_entropy(buf1);
        entropy2 = shannon_entropy(buf2);
        if (entropy1 != entropy2) {
            return -1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}

// synchronize two files using shannon entropy
int synchronize_files(char *file1, char *file2) {
    FILE *fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        perror("fopen");
        return -1;
    }
    FILE *fp2 = fopen(file2, "w");
    if (fp2 == NULL) {
        perror("fopen");
        return -1;
    }
    char buf1[1024];
    char buf2[1024];
    int len1, len2;
    double entropy1, entropy2;
    while ((len1 = fread(buf1, 1, 1024, fp1)) > 0) {
        entropy1 = shannon_entropy(buf1);
        while ((len2 = fread(buf2, 1, 1024, fp2)) > 0) {
            entropy2 = shannon_entropy(buf2);
            if (entropy1 > entropy2) {
                fwrite(buf1, 1, len1, fp2);
                break;
            }
        }
        if (len2 == 0) {
            fwrite(buf1, 1, len1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        return -1;
    }
    char *file1 = argv[1];
    char *file2 = argv[2];
    int result = compare_files(file1, file2);
    if (result == 0) {
        printf("Files are identical.\n");
    } else if (result == -1) {
        printf("Files are different.\n");
        result = synchronize_files(file1, file2);
        if (result == 0) {
            printf("Files have been synchronized.\n");
        } else {
            printf("Failed to synchronize files.\n");
        }
    } else {
        printf("Error: %d\n", result);
    }
    return 0;
}