//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Cryptic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 

#define MAX_SIZE 100 // maximum size of input metadata string 

/* Function to extract metadata */
char* extract_metadata(char* input) 
{ 
    char* result = (char*)malloc(MAX_SIZE * sizeof(char));
    if (result) { 
        int i = 0; 
        int j = 0; 

        // Skip leading spaces
        while (isspace(input[i])) 
            i++; 

        // Check if first character is not a letter and not an asterisk
        if (!isalpha(input[i]) && input[i] != '*' ) 
            return NULL; 

        // Copy metadata string to result variable
        while (input[i] != '\0' && !isspace(input[i])) 
            result[j++] = input[i++];

        // Add null terminator to the result variable
        result[j] = '\0'; 
    } 
    return result; 
} 

/* Main function */
int main() 
{ 
    char input[MAX_SIZE]; 
    printf("Enter metadata string: "); 
    fgets(input, sizeof(input), stdin); 

    /* Extract metadata */
    char* metadata = extract_metadata(input); 

    /* Check if metadata exists and print the result */
    if (metadata != NULL) 
        printf("Metadata: %s\n", metadata); 
    else 
        printf("Invalid metadata string\n"); 

    /* Free memory */
    free(metadata); 

    return 0; 
}