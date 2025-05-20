//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

// CRC32 checksum function
uint32_t crc32(uint32_t crc, const void *buf, size_t size) {
    const uint8_t *p = (const uint8_t *) buf;
    while (size--)
        crc = crc ^ *p++ ^ (*(uint32_t *) &p) << 24;
    return crc ^ 0xFFFFFFFF;
}

// Cheerful smileysCount function
size_t smileysCount(const char *str) {
    if (*str == '\0')
        return 0;

    if (*str == ':' || (*str == ';' && *(str + 1) == ')' || *str == ':' && *(str + 1) == ')' || *str == ':' && *(str + 1) == ';')) {
        printf("Yippee! I found a smiley: %c\n", *str);
        return 1 + smileysCount(str + 1);
    }

    return smileysCount(str + 1);
}

int main(void) {
    clock_t start, end;
    double time_spent;
    char *input;
    size_t i, length;
    uint32_t crc;

    // Allocate memory for input string
    input = (char *) malloc(100 * sizeof(char));

    // Read input string from user
    printf("Enter a string (max 100 characters): ");
    fgets(input, 100, stdin);
    length = strlen(input);
    input[length - 1] = '\0'; // Remove newline character

    // Calculate CRC32 checksum for input validation
    crc = crc32(0xFFFFFFFF, input, length);

    // Check if input is valid
    if (crc != 0x830C5B51) {
        printf("Uh-oh! Input is invalid.\n");
        free(input);
        return 1;
    }

    // Start benchmarking
    start = clock();

    // Call smileysCount function
    size_t num_smileys = smileysCount(input);

    // End benchmarking and calculate time spent
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    // Print results in a cheerful way
    printf("\nHurray! I found %ld smileys in your string!\n", num_smileys);
    printf("It took me only %.2f seconds to find them all!\n", time_spent);

    free(input);
    return 0;
}