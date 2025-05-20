//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <string.h>

char* textToMorse(char s[]) {
    char* morse;
    int len = strlen(s); 
    int i, j;

    morse = (char*)malloc(len * 10 * sizeof(char)); // allocating memory for the morse string
    
    for (i = 0; i < len; i++) {
        switch(s[i]) {
            case 'a':
            case 'A':
                strcat(morse, ".- ");
                break;
            case 'b':
            case 'B':
                strcat(morse, "-... ");
                break;
            case 'c':
            case 'C':
                strcat(morse, "-.-. ");
                break;
            case 'd':
            case 'D':
                strcat(morse, "-.. ");
                break;
            case 'e':
            case 'E':
                strcat(morse, ". ");
                break;
            case 'f':
            case 'F':
                strcat(morse, "..-. ");
                break;
            case 'g':
            case 'G':
                strcat(morse, "--. ");
                break;
            case 'h':
            case 'H':
                strcat(morse, ".... ");
                break;
            case 'i':
            case 'I':
                strcat(morse, ".. ");
                break;
            case 'j':
            case 'J':
                strcat(morse, ".--- ");
                break;
            case 'k':
            case 'K':
                strcat(morse, "-.- ");
                break;
            case 'l':
            case 'L':
                strcat(morse, ".-.. ");
                break;
            case 'm':
            case 'M':
                strcat(morse, "-- ");
                break;
            case 'n':
            case 'N':
                strcat(morse, "-. ");
                break;
            case 'o':
            case 'O':
                strcat(morse, "--- ");
                break;
            case 'p':
            case 'P':
                strcat(morse, ".--. ");
                break;
            case 'q':
            case 'Q':
                strcat(morse, "--.- ");
                break;
            case 'r':
            case 'R':
                strcat(morse, ".-. ");
                break;
            case 's':
            case 'S':
                strcat(morse, "... ");
                break;
            case 't':
            case 'T':
                strcat(morse, "- ");
                break;
            case 'u':
            case 'U':
                strcat(morse, "..- ");
                break;
            case 'v':
            case 'V':
                strcat(morse, "...- ");
                break;
            case 'w':
            case 'W':
                strcat(morse, ".-- ");
                break;
            case 'x':
            case 'X':
                strcat(morse, "-..- ");
                break;
            case 'y': 
            case 'Y':
                strcat(morse, "-.-- ");
                break;
            case 'z':
            case 'Z':
                strcat(morse, "--.. ");
                break;
            case ' ':
                strcat(morse, "/ ");
                break;
            default:
                printf("Invalid input '%c'!", s[i]);
                break;
        }
    }
    return morse;
}

int main() {
    char text[101];
    printf("Enter the text you want to convert to Morse Code (max 100 characters):\n");
    fgets(text, 101, stdin); // getting user input
    text[strcspn(text, "\n")] = 0; // removing the newline character at the end of the input string

    char* morse = textToMorse(text);
    printf("\nMorse Code:\n%s", morse);

    free(morse); // deallocating the memory used by the morse string

    return 0;
}