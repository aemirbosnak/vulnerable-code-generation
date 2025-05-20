//FormAI DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int countWords(char *str) {    
    int count = 0;
    
    // Loop through the string, counting whitespace-separated words
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            count++;
        }
    }
    
    // Return the word count
    return count + 1;
}

// Function to replace all occurrences of a string with another string
char *replaceString(char *str, char *find, char *replace) {
    char *result;   // Pointer to the newly created string
    char *start;    // Pointer to the start of the current match
    char *end;      // Pointer to the end of the current match
    int len;        // Length of the original string
    
    // Make a copy of the original string
    len = strlen(str);
    result = calloc(len + 1, sizeof(char));
    strcpy(result, str);
    
    // Loop through the string, replacing all occurrences of the find string with the replace string
    start = strstr(result, find);
    while (start) {
        end = start + strlen(find);  // Pointer to the end of the match
        // Copy the part of the original string before the match
        strncat(result, str, start - str);
        // Append the replacement string
        strcat(result, replace);
        // Move the pointer to after the match
        str = end;
        // Find the next occurrence of the find string
        start = strstr(str, find);
    }
    
    // Append the remainder of the original string to the result string
    strcat(result, str);
    
    // Return the pointer to the new string
    return result;
}

int main() {
    char text[1024];    // Input string
    char find[256];     // String to find
    char replace[256];  // String to replace the found string with
    int numWords;       // Number of words in the input string
    
    // Prompt the user for input
    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin);
    
    // Count the number of words in the input string
    numWords = countWords(text);
    printf("The input string contains %d words.\n", numWords);
    
    // Prompt the user for the string to find and the replacement string
    printf("Enter the string to find: ");
    fgets(find, sizeof(find), stdin);
    printf("Enter the replacement string: ");
    fgets(replace, sizeof(replace), stdin);
    
    // Remove the newline characters at the end of the input strings
    find[strcspn(find, "\n")] = 0;
    replace[strcspn(replace, "\n")] = 0;
    
    // Replace all occurrences of the find string with the replace string
    char *newText = replaceString(text, find, replace);
    printf("The new text is: %s\n", newText);
    
    // Free the memory allocated for the new string
    free(newText);
    
    return 0;
}