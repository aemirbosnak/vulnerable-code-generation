//FormAI DATASET v1.0 Category: Compression algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to compress the input string using a post-apocalyptic style compression algorithm
void compress(char input[], char output[]) {

    // Initialize variables
    int idx = 0;
    int count = 1;

    // Loop through the input string
    for(int i=0; i < strlen(input); i++) {
        
        // If the current character is the same as the previous character, increment the count
        if(input[i] == input[i-1]) {
            count++;
        }
        // Otherwise, add the count and the previous character to the output string
        else {
            // If the count is greater than 1, add the number of occurrences to the output string
            if(count > 1) {
                sprintf(output+idx, "%d", count); // Convert int to string and add to output string
                idx = strlen(output);
            }
            // Add the current character to the output string
            output[idx] = input[i];
            idx++;
            count = 1;
        }
    }

    // Add the final count and character to the output string
    if(count > 1) {
        sprintf(output+idx, "%d", count);
        idx = strlen(output);
    }
    output[idx] = '\0';
}

int main() {

    // Initialize variables
    char input[MAX_SIZE];
    char output[MAX_SIZE];

    // Get input from user
    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    // Compress the input string using the post-apocalyptic style algorithm
    compress(input, output);
    printf("Compressed string: %s", output);

    return 0;
}