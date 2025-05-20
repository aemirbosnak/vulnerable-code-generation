//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: unmistakable
#include <stdio.h>
#include <string.h>

void toMorse(char input[]);
void playMorse(char output[]);

int main()
{
    char input[100];
    printf("Enter text to convert to Morse Code: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; //removes newline characters

    toMorse(input); //converts input text to Morse code
    printf("\n");

    return 0;
}

void toMorse(char input[])
{
    char* morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", " "}; //array containing Morse code for each letter and symbol
    char output[1000] = ""; //initialize output string to hold converted Morse code

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z') //converts lowercase letters to Morse code
        {
            strcat(output, morse[input[i] - 'a']);
        }
        else if (input[i] >= 'A' && input[i] <= 'Z') //converts uppercase letters to Morse code
        {
            strcat(output, morse[input[i] - 'A']);
        }
        else if (input[i] >= '0' && input[i] <= '9') //converts numbers to Morse code
        {
            strcat(output, morse[input[i] - '0' + 26]);
        }
        else if (input[i] == ' ') //adds space to Morse code
        {
            strcat(output, morse[27]);
        }
        else //adds slash for unsupported characters 
        {
            strcat(output, morse[26]);
        }
        strcat(output, " "); //adds space in between each Morse code symbol
    }

    printf("Morse Code: %s", output); //prints converted Morse code
    playMorse(output); //plays back the Morse code as sound
}

void playMorse(char output[])
{
    for (int i = 0; i < strlen(output); i++)
    {
        if (output[i] == '-') //plays a long beep for each dash
        {
            printf("Beep ");
        }
        else if (output[i] == '.') //plays a short beep for each dot
        {
            printf("Boop ");
        }
        else if (output[i] == '/') //pauses for each space
        {
            printf("...");
        }
        else //ignores spaces between symbols
        {
            continue;
        }
        printf("\n"); //adds new line after each beep or pause
    }
}