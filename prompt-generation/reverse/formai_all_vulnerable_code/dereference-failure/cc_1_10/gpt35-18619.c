//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: curious
#include <stdio.h>
#include <string.h>

// Define morse code for each English character
const char* morse_codes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " ", "/", "", ""};
const char* english_chars[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " ", "/", "", ""};

// Function to convert a string to morse code
void convert_to_morse_code(char* input_string)
{
    // Get the length of the input string
    int input_string_length = strlen(input_string);
    
    // Loop through each character in the input string
    for(int i=0; i<input_string_length; i++)
    {
        // Get the index of the current character in the english_chars array
        int english_char_index = -1;
        for(int j=0; j<sizeof(english_chars)/sizeof(english_chars[0]); j++)
        {
            if(strcmp(english_chars[j], input_string[i])==0)
            {
                english_char_index = j;
                break;
            }
        }
        
        // Print out the morse code for the current character
        printf("%s ", morse_codes[english_char_index]);
    }
}

int main()
{
    // Welcome message
    printf("Welcome to the Text to Morse Code converter!\n");
    
    // Get user input
    char input_string[100];
    printf("Please enter the text you want to convert to Morse Code: ");
    fgets(input_string, 100, stdin);
    input_string[strcspn(input_string, "\n")] = 0;
    
    // Convert input string to morse code
    printf("Morse Code: ");
    convert_to_morse_code(input_string);
    printf("\n");
    
    // Goodbye message
    printf("Thanks for using the Text to Morse Code converter!\n");
    
    return 0;
}