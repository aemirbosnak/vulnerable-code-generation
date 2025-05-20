//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

unsigned int checksum(unsigned char *data, int length) {
    unsigned int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += data[i];
    }
    return sum;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUF_SIZE];
    int bytes_read;
    unsigned int calculated_checksum = 0;

    while ((bytes_read = fread(buffer, sizeof(char), BUF_SIZE, fp)) > 0) {
        calculated_checksum += checksum(buffer, bytes_read);
    }

    fclose(fp);

    unsigned char checksum_byte[sizeof(unsigned int)];
    memcpy(checksum_byte, &calculated_checksum, sizeof(unsigned int));

    // Print the checksum to the console
    printf("Calculated checksum: %08x\n", calculated_checksum);
    printf("Stored checksum: %08x\n", *((unsigned int *)argv[2]));

    // Compare the calculated and stored checksums
    if (calculated_checksum != *((unsigned int *)argv[2])) {
        printf("Error: Checksums do not match!\n");
        return 1;
    }

    return 0;
}