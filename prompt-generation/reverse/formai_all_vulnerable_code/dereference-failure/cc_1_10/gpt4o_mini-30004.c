//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Struct to hold data for each thread.
typedef struct {
    int decimal;
    char binary[33]; // 32 bits + null terminator
} ConversionData;

// Function that converts a decimal number to binary.
void* convertToBinary(void* arg) {
    ConversionData* data = (ConversionData*)arg;
    int num = data->decimal;
    
    if (num == 0) {
        strcpy(data->binary, "0");
        return NULL;
    }
    
    data->binary[32] = '\0'; // Null-terminate the binary string
    for (int i = 31; i >= 0; --i) {
        data->binary[i] = (num % 2) ? '1' : '0';
        num /= 2;
    }

    // Trim leading zeros
    char* first_one = strchr(data->binary, '1');
    if (first_one != NULL) {
        // Move the resulting binary string to the start of the array
        memmove(data->binary, first_one, 33 - (first_one - data->binary));
    } else {
        strcpy(data->binary, "0");
    }
    
    return NULL;
}

// Function to handle thread creation and processing.
void convertAndDisplayBinary(int decimal) {
    pthread_t thread;
    ConversionData data;
    data.decimal = decimal;

    // Create a new thread to perform conversion.
    if (pthread_create(&thread, NULL, convertToBinary, &data) != 0) {
        perror("Failed to create thread");
        return;
    }

    // Wait for the thread to complete
    pthread_join(thread, NULL);
    
    // Display the result
    printf("Decimal: %d, Binary: %s\n", decimal, data.binary);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <decimal_number> [<decimal_number>...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Process each decimal number provided as command-line arguments asynchronously.
    for (int i = 1; i < argc; i++) {
        int decimal = atoi(argv[i]);
        convertAndDisplayBinary(decimal);
    }

    return EXIT_SUCCESS;
}