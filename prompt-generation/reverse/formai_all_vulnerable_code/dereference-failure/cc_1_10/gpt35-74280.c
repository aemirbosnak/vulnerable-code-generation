//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Alan Touring
// This program converts user inputted text into Morse code
// The Morse code is outputted as a series of beeps and pauses


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// Define Morse code equivalents for the alphabet and numbers
const char *morse_table[] =
{
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

int main()
{
    char *text;
    int text_len, i;

    // Prompt user for text input
    printf("Enter the text to be converted into Morse code: ");
    fgets(text, 100, stdin);

    // Determine length of user input
    text_len = strlen(text);

    // Loop through each character in the user inputted text
    for(i=0; i<text_len-1; i++)
    {
        // Convert uppercase letters to their Morse code equivalents
        if(isupper(text[i]))
        {
            printf("%s ", morse_table[text[i]-'A']);
        }
        // Convert lowercase letters to their Morse code equivalents
        else if(islower(text[i]))
        {
            printf("%s ", morse_table[text[i]-'a']);
        }
        // Convert digits to their Morse code equivalents
        else if(isdigit(text[i]))
        {
            printf("%s ", morse_table[text[i]-'0'+26]);
        }
        // Ignore any other characters
        else
        {
            continue;
        }

        // Output a beep to represent a dot
        printf("\a");

        // Wait for a short amount of time between dots and dashes
        usleep(30000);

        // Output a pause to represent a dash
        if(text[i+1] != ' ')
        {
            printf("\n");
            usleep(100000);
        }
    }

    return 0;
}