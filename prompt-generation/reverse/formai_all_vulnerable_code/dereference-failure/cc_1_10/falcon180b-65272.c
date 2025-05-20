//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the given string using the RLE algorithm
char* compress(char* str) {
    int len = strlen(str);
    char* compressed = (char*) malloc(len + 1); // Allocate memory for the compressed string
    compressed[0] = '\0'; // Initialize the compressed string as an empty string
    int count = 1; // Initialize the count for the current character
    char* ptr = compressed; // Initialize the pointer for the compressed string
    
    for(int i=0; i<len; i++) {
        if(i == 0 || str[i]!= str[i-1]) { // If the current character is different from the previous character
            if(count > 1) { // If the count is greater than 1, add the count and the character to the compressed string
                sprintf(ptr, "%d%c", count, str[i]);
                ptr += strlen(ptr);
            } else { // If the count is 1, add only the character to the compressed string
                sprintf(ptr, "%c", str[i]);
                ptr += strlen(ptr);
            }
            count = 1; // Reset the count for the current character
        } else { // If the current character is the same as the previous character
            count++; // Increment the count for the current character
        }
    }
    
    if(count > 1) { // If the count is greater than 1, add the count and the character to the compressed string
        sprintf(ptr, "%d%c", count, str[len-1]);
        ptr += strlen(ptr);
    } else { // If the count is 1, add only the character to the compressed string
        sprintf(ptr, "%c", str[len-1]);
        ptr += strlen(ptr);
    }
    
    compressed[ptr-compressed] = '\0'; // Add null terminator to the compressed string
    
    return compressed; // Return the compressed string
}

int main() {
    char str[1000];
    printf("Enter a string to compress: ");
    scanf("%[^\n]", str); // Read the input string
    
    char* compressed = compress(str); // Compress the input string
    
    printf("Compressed string: %s\n", compressed); // Print the compressed string
    
    free(compressed); // Free the memory allocated for the compressed string
    
    return 0;
}