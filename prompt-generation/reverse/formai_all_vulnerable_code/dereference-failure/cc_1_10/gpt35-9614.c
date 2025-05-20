//FormAI DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char* inputCode = (char*)malloc(sizeof(char) * 1000);    // Allocate memory to store the user input code
    char* beautifiedCode = (char*)malloc(sizeof(char) * 1000);    // Allocate memory to store the beautified code
    int depth = 0;    // variable to track the depth of the html code
    
    // Prompt the user for the HTML code
    printf("Welcome to HTML Beautifier!\nPlease enter your HTML code:\n");
    fgets(inputCode, 1000, stdin);    // Store the user input in inputCode variable
    
    // Loop through all the characters in inputCode
    for (int i = 0; i < strlen(inputCode); i++)
    {
        if (inputCode[i] == '<')
        {
            beautifiedCode[strlen(beautifiedCode)] = inputCode[i];
            if (inputCode[i+1] == '/')
            {
                depth--;
                for (int j = 0; j < depth; j++)
                {
                    strcat(beautifiedCode, "\t");    // Add tab characters for indentation
                }
            }
            else
            {
                for (int j = 0; j < depth; j++)
                {
                    strcat(beautifiedCode, "\t");    // Add tab characters for indentation
                }
                depth++;
            }
        }
        else if (inputCode[i] == '>')
        {
            beautifiedCode[strlen(beautifiedCode)] = inputCode[i];
            strcat(beautifiedCode, "\n");    // Add a new line character after each tag
        }
        else
        {
            beautifiedCode[strlen(beautifiedCode)] = inputCode[i];
        }
    }
    printf("Your beautified code:\n%s", beautifiedCode);    // Print the beautified code
    free(inputCode);    // Free the memory allocated for inputCode
    free(beautifiedCode);    // Free the memory allocated for beautifiedCode
}