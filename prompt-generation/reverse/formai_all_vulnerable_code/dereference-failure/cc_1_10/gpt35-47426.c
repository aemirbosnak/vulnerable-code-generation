//FormAI DATASET v1.0 Category: Compression algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* inputStr = (char*) malloc(1000 * sizeof(char)); // Allocate space for the input string
    char* compressedStr = (char*) calloc(1000, sizeof(char)); // Allocate space for the compressed string
    
    // Get input string from the user
    printf("Enter a string to compress: ");
    scanf("%[^\n]", inputStr);
    
    int count = 1;
    char currentChar = inputStr[0];
    int compressedIndex = 0;
    
    for (int i = 1; i < strlen(inputStr); i++) {
        
        if (inputStr[i] == currentChar) {
            
            count++;
            
            // If count is greater than 9, append the count as a separate character
            if (count > 9) {
                compressedStr[compressedIndex++] = (char) (count/10 + '0');
                compressedStr[compressedIndex++] = (char) (count%10 + '0');
                compressedStr[compressedIndex++] = currentChar;
                count = 1;
                currentChar = inputStr[i];
            }
        } else {
            
            // Append the count and current character to the compressed string
            compressedStr[compressedIndex++] = (char) (count + '0');
            compressedStr[compressedIndex++] = currentChar;
            count = 1;
            currentChar = inputStr[i];
        }
    }
    
    // Append the final count and character to the compressed string
    compressedStr[compressedIndex++] = (char) (count + '0');
    compressedStr[compressedIndex++] = currentChar;
    
    // Print the compressed string
    printf("Compressed string: %s\n", compressedStr);
    
    free(inputStr);
    free(compressedStr);
    
    return 0;
}