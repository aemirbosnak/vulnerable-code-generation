//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

void print_binary(int num) {
    // Check if num is 0 or negative
    if (num <= 0) {
        printf("0");
        return;
    }
  
    // Allocate memory for the binary representation
    char *binary = (char *) malloc(sizeof(char) * 33);
  
    // Start from the end of the binary representation
    int index = 31;
  
    // Convert the number to binary
    while (num > 0) {
        // If the number is odd, set the bit to 1
        if (num % 2 == 1) {
            binary[index] = '1';
        }
        // If the number is even, set the bit to 0
        else {
            binary[index] = '0';
        }
  
        // Divide the number by 2 to get the next digit
        num /= 2;
  
        // Decrement the index
        index--;
    }
  
    // Add the null terminator
    binary[32] = '\0';
  
    // Print the binary representation
    printf("%s", binary);
  
    // Free the memory allocated for the binary representation
    free(binary);
}

int main() {
    // Get the number from the user
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
  
    // Print the binary representation of the number
    printf("Binary representation of %d: ", num);
    print_binary(num);
    printf("\n");
  
    return 0;
}