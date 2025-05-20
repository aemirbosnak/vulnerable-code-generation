//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: medieval
#include <stdio.h>
#include <string.h>

// Function to generate ASCII art of a given text in medieval style
void generateArt(char* text) {
    // Initialize an array of strings to store the art for each character
    char* art[26] = {
        "  /\\  ",
        " /  \\ ",
        "/    \\",
        "|    |",
        "|    |",
        "|    |",
        "|____|",
        "      ",
        "  ___ ",
        " / _ \\",
        "| | | |",
        "| | | |",
        "| |_| |",
        " \\___/ ",
        "      ",
        " __   ",
        "/  \\  ",
        "| () |",
        "| || |",
        "| |/ |",
        "|_/\\_|",
        "      ",
        " __   ",
        "/  \\  ",
        "|\\/| |",
        "|  | |",
        "|  | |",
        "|  |_|",
    };

    // Convert the text to uppercase
    int n = strlen(text);
    for (int i = 0; i < n; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] - 'a' + 'A';
        }
    }

    // Loop through the characters of the input text and print the corresponding ASCII art
    for (int i = 0; i < n; i++) {
        // Check if the character is an uppercase letter
        if (text[i] >= 'A' && text[i] <= 'Z') {
            // Calculate the index of the character in the art array
            int index = text[i] - 'A';
            // Print the corresponding ASCII art
            for (int j = 0; j < 7; j++) {
                for (int k = 0; k < strlen(art[index]); k++) {
                    if (art[index][k] == '|') {
                        printf("|    |");
                    } else {
                        printf("%c", art[index][k]);
                    }
                }
                printf("\n");
            }
            printf("\n");
        } else {
            // Print a space for non-alphabetic characters
            printf("       \n");
        }
    }
}

int main() {
    // Test the generateArt function with some sample input
    char* text = "Hello, World!";
    generateArt(text);

    return 0;
}