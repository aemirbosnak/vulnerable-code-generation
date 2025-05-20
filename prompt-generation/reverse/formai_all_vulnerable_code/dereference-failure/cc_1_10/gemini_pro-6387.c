//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
    ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----.", "-----", ".-.-.-", "--..--", ".----.",
    "..--..", "...--.", "....-.", ".....-", "-....-", "--...--", "---..-", "----.-",
    "-----.", ".-.-.-", "-...-", "-..--", "-.--.", "-.--.-", "..--.-", "...-..-",
    "....-.", ".....-", "-....-", "--...--", "---..-"
};

// Convert a character to Morse code
char *char_to_morse(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        c = c - 'a' + 'A';
    }
    if (c >= 'A' && c <= 'Z')
    {
        return morse_table[c - 'A'];
    }
    else if (c >= '0' && c <= '9')
    {
        return morse_table[c - '0' + 26];
    }
    else if (c == ' ')
    {
        return " ";
    }
    else
    {
        return "?";
    }
}

// Convert a string to Morse code
char *string_to_morse(char *s)
{
    char *morse_code = malloc(strlen(s) * 5 + 1);
    int i;
    int j;
    int k;
    for (i = 0; i < strlen(s); i++)
    {
        char *morse_char = char_to_morse(s[i]);
        for (j = 0; j < strlen(morse_char); j++)
        {
            morse_code[k++] = morse_char[j];
            morse_code[k++] = ' ';
        }
    }
    morse_code[k] = '\0';
    return morse_code;
}

// Print Morse code
void print_morse_code(char *morse_code)
{
    int i;
    for (i = 0; i < strlen(morse_code); i++)
    {
        if (morse_code[i] == ' ')
        {
            printf(" ");
        }
        else if (morse_code[i] == '.')
        {
            printf("·");  
        }
        else if (morse_code[i] == '-')
        {
            printf("-");
        }
    }
    printf("\n");
}

// Main function
int main()
{
    char *s = "Hello World!";
    char *morse_code = string_to_morse(s);
    print_morse_code(morse_code);
    free(morse_code);
    return 0;
}