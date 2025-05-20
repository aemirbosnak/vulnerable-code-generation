//FormAI DATASET v1.0 Category: Pattern printing ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

// Function to print the pattern
void printPattern(int n) {
    // Calculate the total number of characters required
    int max_char = n*2 - 1;
    // Initialize the character array
    char** pattern = (char**)malloc(n * sizeof(char*));
    for(int i=0; i<n; i++) {
        pattern[i] = (char*)malloc(max_char * sizeof(char));
        // Set all characters to space
        for(int j=0; j<max_char; j++)
            pattern[i][j] = ' ';
    }
    int current_row = 0;
    int current_col = n-1;
    for(int i=1; i<=n; i++) {
        // Print the character
        pattern[current_row][current_col] = '*';
        // Update the row and column based on the pattern
        current_row++;
        current_col--;
        if(current_col < 0) {
            current_col = n-1;
            current_row--;
        }
        // Print the pattern for the current row
        for(int j=0; j<=current_col; j++)
            printf("%c ", pattern[i-1][j]);
        printf("\n");
    }
    // Free the memory used by the character array
    for(int i=0; i<n; i++)
        free(pattern[i]);
    free(pattern);
}

int main() {
    // Ask the user for the number of rows
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    // Check if the number of rows is valid
    if(n < 1 || n > 20) {
        printf("Invalid number of rows. Please enter a number between 1 and 20.\n");
        return 0;
    }
    // Print the pattern
    printPattern(n);
    return 0;
}