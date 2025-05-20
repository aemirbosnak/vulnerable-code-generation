//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    unsigned int size;
    unsigned char *data;
} HappyBuffer;

void happyPrint(const char *msg) {
    for (int i = 0; msg[i]; i++) {
        putchar(isalpha(msg[i]) ? toupper(msg[i]) : msg[i]);
    }
    putchar('\n');
}

void happyHexPrint(const unsigned char *data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        putchar('%');
        putchar("0123456789ABCDEF"[data[i] >> 4]);
        putchar("0123456789ABCDEF"[data[i] & 0xF]);
        if ((i + 1) % 32 == 0) {
            putchar('\n');
        } else {
            putchar(' ');
        }
    }
}

unsigned int happyCalcChecksum(const unsigned char *data, size_t size) {
    unsigned int sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += data[i];
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum = (sum >> 16) + (sum & 0xffff);
    return sum;
}

HappyBuffer happyReadFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    size_t filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    HappyBuffer buffer;
    buffer.size = filesize;
    buffer.data = malloc(filesize);
    size_t bytesRead = fread(buffer.data, sizeof(unsigned char), filesize, file);
    fclose(file);

    if (bytesRead != filesize) {
        free(buffer.data);
        buffer.size = 0;
        happyPrint("Error: Could not read file completely.\n");
        exit(EXIT_FAILURE);
    }

    return buffer;
}

int main() {
    srand(time(NULL));

    const char *filename = "input.bin";
    HappyBuffer fileContent = happyReadFile(filename);

    printf("Read %u bytes from file '%s'\n", fileContent.size, filename);
    happyPrint("File content before checksum calculation:\n");
    happyHexPrint(fileContent.data, fileContent.size);

    unsigned int checksum = happyCalcChecksum(fileContent.data, fileContent.size);
    printf("Checksum: %08X\n", checksum);

    // Randomly modify some bytes in the buffer
    for (size_t i = rand() % fileContent.size; i < fileContent.size; i += rand() % 10 + 1) {
        fileContent.data[i] ^= rand() % 0xFF;
    }

    printf("File content after modification:\n");
    happyHexPrint(fileContent.data, fileContent.size);

    checksum = happyCalcChecksum(fileContent.data, fileContent.size);
    printf("Checksum after modification: %08X\n", checksum);

    free(fileContent.data);

    return EXIT_SUCCESS;
}