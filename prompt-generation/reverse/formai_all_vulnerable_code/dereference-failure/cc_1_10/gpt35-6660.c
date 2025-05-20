//FormAI DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000000

// function for compressing the input string
char* compress(char* input) {

    // initialize count to 1, and allocate memory for the output string
    int count = 1;
    char* output = (char*)malloc(sizeof(char)*(strlen(input)+1));
    
    // store the first character of the input string in output
    output[0] = input[0];
    int i;
    
    // loop through the input string
    for (i = 1; input[i] != '\0'; i++) {
        
        // if the previous character is the same as the current character, increment the count
        if (input[i] == input[i-1]) {
            count += 1;
        }
        else {
            // if the previous character is not the same as the current character, store the count and the current character
            output[strlen(output)] = count + '0';
            output[strlen(output)] = input[i];
            
            // reset the count to 1
            count = 1;
        }
    }
    
    // add the count of the last character to the output
    output[strlen(output)] = count + '0';
    output[strlen(output)] = '\0'; // add null terminator at the end
    
    return output;
}

int main() {
    char input[MAX_LEN];
    printf("Enter string to be compressed: ");
    scanf("%[^\n]%*c", input); // read input till new line
    
    // compress the input string
    char* output = compress(input);
    
    // print the compressed string
    printf("The compressed string is: %s", output);
    
    free(output); // free the memory allocated for output
    
    return 0;
}