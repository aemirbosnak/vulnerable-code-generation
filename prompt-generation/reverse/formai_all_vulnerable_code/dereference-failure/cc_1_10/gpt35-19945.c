//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Ada Lovelace
/* This program demonstrates a unique implementation of converting text into Morse code in an Ada Lovelace style. 
 * Created by [Your Name], on [Current Date]
 */

#include <stdio.h>
#include <string.h>

// Define the Morse code mappings for the letters and digits
const char * morse_code[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--..", // Z
    "-----",// 0
    ".----",// 1
    "..---",// 2
    "...--",// 3
    "....-",// 4
    ".....",// 5
    "-....",// 6
    "--...",// 7
    "---..",// 8
    "----." // 9
};

// Function to convert a single character to Morse code
void char_to_morse(const char c, char * morse)
{
    // Check if the character is a letter or digit
    if(isalpha(c))
    {
        // Get the index of the character in the Morse code array
        int index = toupper(c) - 'A';
        
        // Copy the Morse code for the character to the output string
        if(index >= 0 && index < 26)
        {
            strcpy(morse, morse_code[index]);
        }
    }
    else if(isdigit(c))
    {
        // Get the index of the digit in the Morse code array
        int index = c - '0' + 26;
        
        // Copy the Morse code for the digit to the output string
        if(index >= 26 && index < 36)
        {
            strcpy(morse, morse_code[index]);
        }
    }
}

// Function to convert a text string to Morse code
void text_to_morse(const char * text, char * morse)
{
    // Loop through each character in the input string
    for(int i = 0; i < strlen(text); i++)
    {
        // Convert the character to Morse code and append it to the output string
        char morse_char[8] = {0};
        char_to_morse(text[i], morse_char);
        strcat(morse, morse_char);
        
        // Add a space between each letter
        if(i < strlen(text) - 1)
        {
            strcat(morse, " ");
        }
    }
}

int main()
{
    // Get the input text from the user
    printf("Enter a text string: ");
    char text[100] = {0};
    fgets(text, sizeof(text), stdin);
    
    // Convert the text to Morse code and display the result
    char morse[500] = {0};
    text_to_morse(text, morse);
    printf("Morse code: %s\n", morse);
    
    return 0;
}