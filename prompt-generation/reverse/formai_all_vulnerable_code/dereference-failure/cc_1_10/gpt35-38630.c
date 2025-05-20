//FormAI DATASET v1.0 Category: HTML beautifier ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1024

char* beautify_html(char* input);

int main(void) {
    // get user input
    char input[MAX_LEN];
    printf("Enter HTML code to beautify:\n");
    fgets(input, MAX_LEN, stdin);
    
    // beautify the HTML
    char* output = beautify_html(input);
    
    // print the beautified HTML
    printf("\nBeautified HTML:\n");
    printf("%s\n", output);
    
    // free the output memory
    free(output);
    
    return 0;
}

char* beautify_html(char* input) {
    // allocate memory for the output string
    char* output = (char*)malloc(sizeof(char) * MAX_LEN);
    int output_index = 0;
    
    // initialize whitespace and indentation variables
    int whitespace_count = 0;
    char indentation[100] = "";
    
    // loop through each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        
        // if the character is a tag opening '<', add whitespace and increase indentation
        if (input[i] == '<') {
            // add whitespace
            for (int j = 0; j < whitespace_count; j++) {
                output[output_index] = ' ';
                output_index++;
            }
            // add indentation and increase count
            strcat(output, indentation);
            output_index += strlen(indentation);
            whitespace_count += 4;
        }
        
        // if the character is a tag closing '>', decrease whitespace and decrease indentation
        if (input[i] == '>') {
            // decrease whitespace count
            whitespace_count -= 4;
            // add newline and whitespace
            output[output_index] = '\n';
            output_index++;
            for (int j = 0; j < whitespace_count; j++) {
                output[output_index] = ' ';
                output_index++;
            }
            // add indentation
            strcat(output, indentation);
            output_index += strlen(indentation);
        }
        
        // add the current character to the output string
        output[output_index] = input[i];
        output_index++;
        
        // if the character is a newline, add whitespace and the current indentation to the output string
        if (input[i] == '\n') {
            // add whitespace
            for (int j = 0; j < whitespace_count; j++) {
                output[output_index] = ' ';
                output_index++;
            }
            // add indentation
            strcat(output, indentation);
            output_index += strlen(indentation);
        }
        
        // if the character is a tag closing '/', decrease indentation
        if (input[i] == '/') {
            whitespace_count -= 4;
        }
        
        // if the character is a space and the previous character is a tag closing '>', add whitespace
        if (isspace(input[i]) && input[i-1] == '>') {
            output[output_index] = ' ';
            output_index++;
        }
        
        // if the character is a tag attribute '=', add a space before and after
        if (input[i] == '=') {
            output[output_index] = ' ';
            output_index++;
            output[output_index] = '=';
            output_index++;
            output[output_index] = ' ';
            output_index++;
        }
        
        // if the character is a tag attribute value '"' or "'", toggle the variable isInQuote
        static int isInQuote = 0;
        if (input[i] == '"' || input[i] == '\'') {
            isInQuote = !isInQuote;
        }
        
        // if the character is a space and outside of a tag attribute value, add to the indentation variable
        if (isspace(input[i]) && !isInQuote) {
            strncat(indentation, &input[i], 1);
        }
        
        // if the character is a tag closing '/', remove the last 4 whitespace characters from the indentation variable
        if (input[i] == '/' && input[i+1] == '>') {
            indentation[strlen(indentation) - 4] = '\0';
        }
    }
    
    // add null terminator to output string
    output[output_index] = '\0';
    
    return output;
}