//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <checksum>\n", argv[0]);
        return 1;
    }

    FILE *fp;
    char *filename = argv[1];
    char *checksum = argv[2];

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char buffer[file_size];
    size_t bytes_read = fread(buffer, 1, file_size, fp);

    if (bytes_read!= file_size) {
        printf("Error: Could not read file %s\n", filename);
        fclose(fp);
        return 1;
    }

    unsigned char checksum_buffer[32];
    sprintf(checksum_buffer, "%08X", file_size);

    int i;
    for (i = 0; i < strlen(checksum_buffer); i++) {
        checksum_buffer[i] = tolower(checksum_buffer[i]);
    }

    int checksum_ok = 1;
    for (i = 0; i < 32; i++) {
        if (checksum_buffer[i]!= checksum[i]) {
            checksum_ok = 0;
            break;
        }
    }

    if (checksum_ok) {
        printf("Checksum is valid.\n");
    } else {
        printf("Checksum is invalid.\n");
    }

    fclose(fp);
    return 0;
}