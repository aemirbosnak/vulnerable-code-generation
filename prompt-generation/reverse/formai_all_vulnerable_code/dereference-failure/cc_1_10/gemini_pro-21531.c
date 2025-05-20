//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: inquisitive
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two strings
int compareStrings(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

// Function to print the longest common substring
void printLongestCommonSubstring(char *str1, char *str2, int len)
{
    printf("The longest common substring is: ");
    for (int i = 0; i < len; i++)
    {
        printf("%c", str1[i]);
    }
    printf("\n");
}

// Function to find the longest common substring
int findLongestCommonSubstring(char *str1, char *str2)
{
    // Create a matrix to store the lengths of the longest common substrings
    int **LCSmatrix = (int **)malloc(sizeof(int *) * (strlen(str1) + 1));
    for (int i = 0; i < strlen(str1) + 1; i++)
    {
        LCSmatrix[i] = (int *)malloc(sizeof(int) * (strlen(str2) + 1));
    }

    // Initialize the first row and column of the matrix to 0
    for (int i = 0; i < strlen(str1) + 1; i++)
    {
        LCSmatrix[i][0] = 0;
    }
    for (int j = 0; j < strlen(str2) + 1; j++)
    {
        LCSmatrix[0][j] = 0;
    }

    // Fill the rest of the matrix
    for (int i = 1; i < strlen(str1) + 1; i++)
    {
        for (int j = 1; j < strlen(str2) + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                LCSmatrix[i][j] = LCSmatrix[i - 1][j - 1] + 1;
            }
            else
            {
                LCSmatrix[i][j] = 0;
            }
        }
    }

    // Find the maximum length of the longest common substring
    int maxLength = 0;
    int maxI = 0;
    int maxJ = 0;
    for (int i = 0; i < strlen(str1) + 1; i++)
    {
        for (int j = 0; j < strlen(str2) + 1; j++)
        {
            if (LCSmatrix[i][j] > maxLength)
            {
                maxLength = LCSmatrix[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }

    // Free the memory allocated for the matrix
    for (int i = 0; i < strlen(str1) + 1; i++)
    {
        free(LCSmatrix[i]);
    }
    free(LCSmatrix);

    // Print the longest common substring
    printLongestCommonSubstring(str1 + maxI - maxLength, str2 + maxJ - maxLength, maxLength);

    // Return the length of the longest common substring
    return maxLength;
}

// Driver code
int main()
{
    // Get the two strings from the user
    char str1[101];
    char str2[101];
    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string: ");
    gets(str2);

    // Find the length of the longest common substring
    int len = findLongestCommonSubstring(str1, str2);

    // Print the length of the longest common substring
    printf("The length of the longest common substring is: %d\n", len);

    return 0;
}