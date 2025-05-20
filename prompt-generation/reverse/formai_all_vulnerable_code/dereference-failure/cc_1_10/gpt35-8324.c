//FormAI DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "secretkey"

int encryptFile(const char *fname) {
    FILE *fp;
    char *data;
    int size;
    fp = fopen(fname, "rb");
    if (fp == NULL) {
        printf("Unable to open file: %s\n", fname);
        return 1;
    }
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    data = (char *)malloc(size + 1);
    if (data == NULL) {
        printf("Memory allocation error!\n");
        fclose(fp);
        return 1;
    }
    fread(data, 1, size, fp);
    fclose(fp);

    // Encrypt file
    for (int i = 0; i < size; i++) {
        data[i] ^= KEY[i % strlen(KEY)];
    }

    // Write encrypted data to file
    fp = fopen(fname, "wb");
    if (fp == NULL) {
        printf("Unable to write to file: %s\n", fname);
        free(data);
        return 1;
    }
    fwrite(data, 1, size, fp);
    fclose(fp);
    free(data);

    printf("File '%s' has been encrypted successfully.\n", fname);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    const char *fname = argv[1];

    int result = encryptFile(fname);
    if (result != 0) {
        printf("An error occurred.\n");
        return 1;
    }
    return 0;
}