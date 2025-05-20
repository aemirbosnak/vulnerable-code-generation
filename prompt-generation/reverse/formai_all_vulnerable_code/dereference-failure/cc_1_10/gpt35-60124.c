//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *alphabet[] = {
    "  _   _      _ _     _ _            _        ",
    " | | | | ___| | |   (_) |_ ___   __| |_   _  ",
    " | |_| |/ _ \\ | |   | | __/ _ \\ / _` | | | | ",
    " |  _  |  __/ | |___| | || (_) | (_| | |_| | ",
    " |_| |_|\\___|_|_____|_|\\__\\___/ \\__,_|\\__, | ",
    "                                       |___/  "
};

void convertToASCII(char *text);
void printArt(char *text);

int main()
{
    char input[50];
    
    printf("Enter text: ");
    fgets(input, 50, stdin);
    
    input[strcspn(input, "\n")] = '\0'; // remove newline character from input
    
    convertToASCII(input);
    
    printArt(input);
    
    return 0;
}

void convertToASCII(char *text)
{
    int length = strlen(text);
    int i;
    
    for(i = 0; i < length; i++)
    {
        text[i] = text[i] + rand() % 10; // add random number between 0 and 9 to each character
    }
}

void printArt(char *text)
{
    int length = strlen(text);
    int i, j;
    
    srand(time(NULL)); // set random seed based on current time
    
    for(i = 0; i < 6; i++)
    {
        for(j = 0; j < length; j++)
        {
            int letterIndex = (int)text[j] % 6; // get index of letter in alphabet array
            
            printf("%c", alphabet[i][letterIndex]);
        }
        printf("\n");
    }
}