//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a character to ASCII art
char* charToArt(char c) {
    char* art;
    switch (c) {
        case 'A':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'B':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'C':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'D':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'E':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'F':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'G':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'H':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'I':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'J':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'K':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'L':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'M':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'N':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'O':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'P':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'Q':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'R':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'S':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'T':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'U':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'V':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'W':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'X':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'Y':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        case 'Z':
            art = " _     _  \n| |   | | \n| |__ | | \n|  __|| | \n| |   | | \n|_|   |_|";
            break;
        default:
            art = " ";
            break;
    }
    return art;
}

// Function to convert a string to ASCII art
char* stringToArt(char* str) {
    char* art = malloc(strlen(str) * 10);
    for (int i = 0; i < strlen(str); i++) {
        strcat(art, charToArt(str[i]));
        strcat(art, "\n");
    }
    return art;
}

// Function to print ASCII art to the console
void printArt(char* art) {
    printf("%s", art);
}

// Main function
int main() {
    // Get the input string from the user
    char* str = malloc(100);
    printf("Enter a string: ");
    scanf("%s", str);

    // Convert the string to ASCII art
    char* art = stringToArt(str);

    // Print the ASCII art to the console
    printArt(art);

    // Free the allocated memory
    free(str);
    free(art);

    return 0;
}