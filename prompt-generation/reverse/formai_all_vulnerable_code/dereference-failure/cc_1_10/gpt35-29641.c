//FormAI DATASET v1.0 Category: Browser Plugin ; Style: puzzling
// Include necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <regex.h>

// Define Word Reverser function
void wordReverser(char *input) 
{
    // Initialize variables
    char *tokenPtr;
    char *charPtr;
    const char separator[2] = " ";
    static char reversedString[10000];
    int count = 0;
 
    // Get the first token
    tokenPtr = strtok(input,separator);
 	
    // Loop through the string to extract all tokens
    while(tokenPtr != NULL) {
        count = strlen(tokenPtr);
        charPtr = tokenPtr + count - 1;
        while(count--) {
            strncat(reversedString, charPtr, 1);
            charPtr--;
        }
        strcat(reversedString, " ");
        tokenPtr = strtok(NULL, separator);
    }
 
    // Print the reversed string
    printf("%s\n",reversedString);
}

// Define main function
int main(void)
{ 
    // Initialize variables
    char buffer[1000000];
    size_t bytesRead;
 
    // Read in the HTML file
    FILE *htmlFile = fopen("index.html", "r");
    if(htmlFile == NULL) {
        printf("Error: Could not open HTML file.\n");
        return -1;
    }
    bytesRead = fread(buffer, 1, 1000000, htmlFile);
    if(bytesRead == 0) {
        printf("Error: Could not read HTML file.\n");
        return -1;
    }
    fclose(htmlFile);
 
    // Call the wordReverser function
    wordReverser(buffer);
    return 0;
}