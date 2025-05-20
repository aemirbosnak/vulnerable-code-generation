//FormAI DATASET v1.0 Category: Compression algorithms ; Style: peaceful
// Welcome to the peaceful world of compression algorithms in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000       // Maximum length of the input string
#define MAX_CODES 256      // Maximum number of codes that can be used
#define END_CODE 256       // Code used to indicate the end of the input

// Define the structure for the compression table which will hold the codes
typedef struct
{
    int code;              // The code associated with the string
    char *string;          // The input string associated with the code
} CodeTable;

// Function to compress the input string using LZW algorithm
void compress(char *inputString)
{
    CodeTable *table = (CodeTable *)malloc(sizeof(CodeTable) * MAX_CODES);  // Allocate memory for the code table
    int i, j, len = strlen(inputString);
    char *prevString = (char *)malloc(sizeof(char) * MAX_LEN);              // Store the previous string
    char *curString = (char *)malloc(sizeof(char) * MAX_LEN);               // Store the current string
    int prevCode = -1, curCode = -1;
    int codeCount = 256;

    // Initialize the code table with the ASCII codes for all characters
    for (i = 0; i < 256; i++)
    {
        table[i].code = i;
        table[i].string = (char *)malloc(sizeof(char) * 2);
        table[i].string[0] = i;
        table[i].string[1] = '\0';
    }

    // Start the compression
    prevString[0] = inputString[0];
    prevString[1] = '\0';

    for (i = 1; i < len; i++)
    {
        curString[0] = inputString[i];
        curString[1] = '\0';

        // Check if the current string is already in the code table
        for (j = 0; j < codeCount; j++)
        {
            if (strcmp(prevString, table[j].string) == 0 && strcmp(curString, "") != 0)
            {
                curCode = table[j].code;
                strcat(prevString, curString);
                break;
            }
        }

        // If the current string is not in the code table, add it to the table
        if (j == codeCount)
        {
            if (codeCount < MAX_CODES)
            {
                table[codeCount].code = codeCount;
                table[codeCount].string = (char *)malloc(sizeof(char) * (strlen(prevString) + 2));
                strcpy(table[codeCount].string, prevString);
                strcat(table[codeCount].string, curString);
                curCode = codeCount;
                codeCount++;
            }
        }

        // Output the previous code and start again with the current string
        if (curCode != -1)
        {
            printf("%d ", prevCode);
            prevCode = curCode;
        }
        else
        {
            curCode = prevCode;
        }

        strcpy(prevString, table[curCode].string);
        curCode = -1;
    }

    // Output the final code and end code, indicating the end of the input
    printf("%d %d\n", prevCode, END_CODE);

    // Free memory allocated for the code table
    for (i = 0; i < MAX_CODES; i++)
    {
        free(table[i].string);
    }

    free(table);
    free(prevString);
    free(curString);
}

int main()
{
    char inputString[MAX_LEN];
    printf("Enter the input string: ");
    gets(inputString);

    printf("\nCompressed output: ");
    compress(inputString);

    return 0;
}