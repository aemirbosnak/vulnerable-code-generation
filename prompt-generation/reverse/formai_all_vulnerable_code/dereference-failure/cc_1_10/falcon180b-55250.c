//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to print the ASCII art
void printASCIIArt(char* text, int width) {
    int i, j;
    int len = strlen(text);

    // Calculate the height of the ASCII art
    int height = (len * 2) / width;

    // Loop through each line of the ASCII art
    for (i = 0; i < height; i++) {
        // Calculate the starting index for the line
        int start = i * (len / height);

        // Calculate the ending index for the line
        int end = (i + 1) * (len / height) - 1;

        // Loop through each character in the line
        for (j = 0; j < width; j++) {
            // Print the character if it exists in the line
            if (start <= end) {
                printf("%c", text[start]);
            }

            // Move to the next character in the line
            start++;
        }

        // Move to the next line
        printf("\n");
    }
}

int main() {
    char* text = "Hello, world!";
    int width = 50;

    // Convert the text to uppercase
    for (int i = 0; i < strlen(text); i++) {
        text[i] = toupper(text[i]);
    }

    // Print the ASCII art
    printASCIIArt(text, width);

    return 0;
}