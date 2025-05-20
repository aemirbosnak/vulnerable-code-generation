//FormAI DATASET v1.0 Category: QR code reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_CODE_SIZE 8192  // Maximum QR code size

static int version, data_capacity, ec_bytes;
static unsigned char *input_data_array = NULL;

// Helper function to check if a QR code version is valid
bool is_valid_version(int v) {
    return v >= 1 && v <= 40;
}

// Helper function to convert a string to a char array
void string_to_char_array(char* str, unsigned char* arr) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        arr[i] = (unsigned char) str[i];
    }
}

// Function to read QR code from file
bool read_qr_code(char *filename) {
    // Open file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", filename);
        return false;
    }

    // Read QR code data from file
    input_data_array = (unsigned char *) malloc(MAX_CODE_SIZE);
    int size = fread(input_data_array, sizeof(unsigned char), MAX_CODE_SIZE, fp);
    fclose(fp);

    // Check if data was read successfully
    if (size == 0) {
        printf("Error: file %s is empty\n", filename);
        return false;
    }

    // Parse QR code from data
    version = input_data_array[0];
    if (!is_valid_version(version)) {
        printf("Error: QR code version %d is invalid\n", version);
        return false;
    }

    data_capacity = input_data_array[1];
    ec_bytes = input_data_array[2];
    return true;
}

// Main function to parse and display QR code data
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error: missing input file argument\n");
        return 1;
    }

    if (!read_qr_code(argv[1])) {
        printf("Error: unable to read QR code\n");
        return 1;
    }

    // Convert input data to char array for display
    unsigned char *data = input_data_array + 3 + ec_bytes;
    char *out = (char *) malloc(data_capacity + 1);
    memcpy(out, data, data_capacity);
    out[data_capacity] = '\0';
    printf("%s\n", out);

    free(out);
    free(input_data_array);
    return 0;
}