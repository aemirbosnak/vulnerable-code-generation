//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 255 // Define a maximum number for analysis

// Function to count set bits in a number
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1; // Increment count if the last bit is set
        n >>= 1; // Right shift n to process the next bit
    }
    return count;
}

// Function to generate statistics of set bits in a defined range
void generateStatistics(int max) {
    int *bitCountFrequency = malloc((max + 1) * sizeof(int));
    int totalNumbers = 0;

    // Initialize frequency array
    for (int i = 0; i <= max; i++) {
        bitCountFrequency[i] = 0;
    }

    // Count set bits for each number and update frequency
    for (int i = 0; i <= max; i++) {
        int setBits = countSetBits(i);
        bitCountFrequency[setBits]++;
        totalNumbers++;
    }

    // Printing out statistics
    printf("Statistics of Set Bits from 0 to %d:\n", max);
    printf("Total Numbers: %d\n", totalNumbers);
    printf("Set Bits Frequency Distribution:\n");
    printf("Number of Set Bits | Frequency\n");
    printf("------------------|----------\n");

    for (int i = 0; i <= 8; i++) { // Maximum 8 set bits for numbers up to 255
        printf("         %2d       |    %d\n", i, bitCountFrequency[i]);
    }
    
    // Calculate and display percentages
    printf("\nPercentage Distribution of Set Bits:\n");
    printf("Number of Set Bits | Percentage\n");
    printf("------------------|-----------\n");

    for (int i = 0; i <= 8; i++) {
        double percentage = ((double)bitCountFrequency[i] / totalNumbers) * 100;
        printf("         %2d       |   %.2f%%\n", i, percentage);
    }

    // Cleanup
    free(bitCountFrequency);
}

int main() {
    generateStatistics(MAX_NUM);
    return 0;
}