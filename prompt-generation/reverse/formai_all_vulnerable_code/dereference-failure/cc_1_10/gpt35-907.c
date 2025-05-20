//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to calculate the sum of the ASCII values of a string
unsigned int string_sum(char* str) {
    int i = 0;
    unsigned int sum = 0;
    while (str[i] != '\0') {
        sum += (unsigned int)str[i];
        i++;
    }
    return sum;
}

// Function to check if the given integer is a prime number
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to insert a watermark into an image
void insert_watermark(unsigned char* image_data, int image_size, char* watermark) {
    // Calculate the sum of the watermark string
    unsigned int sum = string_sum(watermark);
    // Find the nearest prime number greater than the sum
    int prime = sum + 1;
    while (!is_prime(prime)) {
        prime++;
    }
    // Insert the prime number into the first 4 bytes of the image data
    unsigned char* prime_bytes = (unsigned char*)&prime;
    image_data[0] = prime_bytes[0];
    image_data[1] = prime_bytes[1];
    image_data[2] = prime_bytes[2];
    image_data[3] = prime_bytes[3];
    // Insert the watermark string into the remaining bytes of the image data
    int watermark_len = strlen(watermark);
    for (int i = 0; i < watermark_len; i++) {
        image_data[i + 4] = (unsigned char)watermark[i];
    }
}

// Function to extract a watermark from an image
char* extract_watermark(unsigned char* image_data, int image_size) {
    // Extract the prime number from the first 4 bytes of the image data
    int prime = 0;
    unsigned char* prime_bytes = (unsigned char*)&prime;
    prime_bytes[0] = image_data[0];
    prime_bytes[1] = image_data[1];
    prime_bytes[2] = image_data[2];
    prime_bytes[3] = image_data[3];
    // Extract the watermark string from the remaining bytes of the image data
    int watermark_len = prime - 4;
    char* watermark = (char*)malloc((watermark_len + 1) * sizeof(char));
    for (int i = 0; i < watermark_len; i++) {
        watermark[i] = (char)image_data[i + 4];
    }
    watermark[watermark_len] = '\0';
    return watermark;
}

int main() {
    // Create a sample image data
    int image_size = 100;
    unsigned char* image_data = (unsigned char*)malloc(image_size * sizeof(unsigned char));
    for (int i = 0; i < image_size; i++) {
        image_data[i] = (unsigned char)(i % 256);
    }
    // Insert a watermark into the image data
    char* watermark = "Hello, world!";
    insert_watermark(image_data, image_size, watermark);
    // Extract the watermark from the image data
    char* extracted_watermark = extract_watermark(image_data, image_size);
    // Print the extracted watermark
    printf("Extracted watermark: %s", extracted_watermark);
    // Free memory
    free(image_data);
    free(extracted_watermark);
    return 0;
}