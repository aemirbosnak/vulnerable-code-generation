//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 30

// Function to generate ASCII art
void generate_ascii_art(char* text, char (*art)[MAX_COLS]) {
    int i, j, k;
    int len = strlen(text);
    int start_row = 0;
    
    // Loop through each row of the art
    for (i = 0; i < MAX_ROWS; i++) {
        // Start a new line for the text every 5 rows
        if (i % 5 == 0) {
            start_row = 0;
            printf("%s\n", text);
        }
        
        // Loop through each column of the art
        for (j = start_row; j < MAX_COLS; j++) {
            // Add a space character if the text has ended
            if (k >= len) {
                art[i][j] = ' ';
            }
            // Otherwise, add the next character of the text
            else {
                art[i][j] = text[k];
                k++;
            }
        }
        // Move to the next row of the art
        printf("%s\n", art[i]);
        start_row++;
    }
}

int main() {
    char text[100];
    char art[MAX_ROWS][MAX_COLS];
    
    // Get input from the user
    printf("Enter some text:\n");
    fgets(text, 100, stdin);
    
    // Remove the newline character from the input
    text[strlen(text) - 1] = '\0';
    
    // Generate the ASCII art
    generate_ascii_art(text, art);
    
    return 0;
}