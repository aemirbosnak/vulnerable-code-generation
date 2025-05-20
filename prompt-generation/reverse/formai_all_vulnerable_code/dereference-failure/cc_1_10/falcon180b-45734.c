//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

char* read_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    char* buffer = malloc(MAX_LINE_SIZE);
    char* result = NULL;
    size_t len = 0;

    while (fgets(buffer, MAX_LINE_SIZE, fp)!= NULL) {
        len += strlen(buffer);
        result = realloc(result, len + 1);
        strcat(result, buffer);
    }

    fclose(fp);
    return result;
}

unsigned char calculate_checksum(char* data) {
    unsigned char checksum = 0;
    int i;

    for (i = 0; i < strlen(data); i++) {
        checksum += tolower(data[i]);
    }

    return checksum;
}

void print_checksum(unsigned char checksum) {
    printf("Checksum: %02X\n", checksum);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    char* data = read_file(filename);
    unsigned char checksum = calculate_checksum(data);
    free(data);

    print_checksum(checksum);

    return 0;
}