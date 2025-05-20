//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include <stdio.h>
#include <string.h>

void convertToMorse(char code[], char morse[]);
void printMorse(char morse[]);

int main()
{
    char text[1000];
    char morse[5000] = "";

    printf("Enter text to convert to Morse Code: ");
    scanf("%[^\n]", text);

    for(int i = 0; i < strlen(text); i++)
    {
        char code[5] = "";

        switch(text[i])
        {
            case 'a':
            case 'A':
                strcpy(code, ".-");
                break;
            case 'b':
            case 'B':
                strcpy(code, "-...");
                break;
            case 'c':
            case 'C':
                strcpy(code, "-.-.");
                break;
            case 'd':
            case 'D':
                strcpy(code, "-..");
                break;
            case 'e':
            case 'E':
                strcpy(code, ".");
                break;
            case 'f':
            case 'F':
                strcpy(code, "..-.");
                break;
            case 'g':
            case 'G':
                strcpy(code, "--.");
                break;
            case 'h':
            case 'H':
                strcpy(code, "....");
                break;
            case 'i':
            case 'I':
                strcpy(code, "..");
                break;
            case 'j':
            case 'J':
                strcpy(code, ".---");
                break;
            case 'k':
            case 'K':
                strcpy(code, "-.-");
                break;
            case 'l':
            case 'L':
                strcpy(code, ".-..");
                break;
            case 'm':
            case 'M':
                strcpy(code, "--");
                break;
            case 'n':
            case 'N':
                strcpy(code, "-.");
                break;
            case 'o':
            case 'O':
                strcpy(code, "---");
                break;
            case 'p':
            case 'P':
                strcpy(code, ".--.");
                break;
            case 'q':
            case 'Q':
                strcpy(code, "--.-");
                break;
            case 'r':
            case 'R':
                strcpy(code, ".-.");
                break;
            case 's':
            case 'S':
                strcpy(code, "...");
                break;
            case 't':
            case 'T':
                strcpy(code, "-");
                break;
            case 'u':
            case 'U':
                strcpy(code, "..-");
                break;
            case 'v':
            case 'V':
                strcpy(code, "...-");
                break;
            case 'w':
            case 'W':
                strcpy(code, ".--");
                break;
            case 'x':
            case 'X':
                strcpy(code, "-..-");
                break;
            case 'y':
            case 'Y':
                strcpy(code, "-.--");
                break;
            case 'z':
            case 'Z':
                strcpy(code, "--..");
                break;
            case ' ':
                strcpy(code, " ");
                break;
            case '.':
                strcpy(code, ".-.-.-");
                break;
            case ',':
                strcpy(code, "--..--");
                break;
            case '?':
                strcpy(code, "..--..");
                break;
            case '!':
                strcpy(code, "-.-.--");
                break;
            default:
                printf("Invalid character: %c", text[i]);
                return 0;
        }

        strcat(morse, code);
        strcat(morse, " ");
    }

    printMorse(morse);

    return 0;
}

void convertToMorse(char code[], char morse[])
{
    strcpy(morse, ""); // Clear morse string
    
    for(int i = 0; i < strlen(code); i++)
    {
        char letter = code[i];
        char morseLetter[5] = "";
        
        switch(letter)
        {
            case 'a':
            case 'A':
                strcpy(morseLetter, ".-");
                break;
            case 'b':
            case 'B':
                strcpy(morseLetter, "-...");
                break;
            case 'c':
            case 'C':
                strcpy(morseLetter, "-.-.");
                break;
            case 'd':
            case 'D':
                strcpy(morseLetter, "-..");
                break;
            case 'e':
            case 'E':
                strcpy(morseLetter, ".");
                break;
            case 'f':
            case 'F':
                strcpy(morseLetter, "..-.");
                break;
            case 'g':
            case 'G':
                strcpy(morseLetter, "--.");
                break;
            case 'h':
            case 'H':
                strcpy(morseLetter, "....");
                break;
            case 'i':
            case 'I':
                strcpy(morseLetter, "..");
                break;
            case 'j':
            case 'J':
                strcpy(morseLetter, ".---");
                break;
            case 'k':
            case 'K':
                strcpy(morseLetter, "-.-");
                break;
            case 'l':
            case 'L':
                strcpy(morseLetter, ".-..");
                break;
            case 'm':
            case 'M':
                strcpy(morseLetter, "--");
                break;
            case 'n':
            case 'N':
                strcpy(morseLetter, "-.");
                break;
            case 'o':
            case 'O':
                strcpy(morseLetter, "---");
                break;
            case 'p':
            case 'P':
                strcpy(morseLetter, ".--.");
                break;
            case 'q':
            case 'Q':
                strcpy(morseLetter, "--.-");
                break;
            case 'r':
            case 'R':
                strcpy(morseLetter, ".-.");
                break;
            case 's':
            case 'S':
                strcpy(morseLetter, "...");
                break;
            case 't':
            case 'T':
                strcpy(morseLetter, "-");
                break;
            case 'u':
            case 'U':
                strcpy(morseLetter, "..-");
                break;
            case 'v':
            case 'V':
                strcpy(morseLetter, "...-");
                break;
            case 'w':
            case 'W':
                strcpy(morseLetter, ".--");
                break;
            case 'x':
            case 'X':
                strcpy(morseLetter, "-..-");
                break;
            case 'y':
            case 'Y':
                strcpy(morseLetter, "-.--");
                break;
            case 'z':
            case 'Z':
                strcpy(morseLetter, "--..");
                break;
            case ' ':
                strcpy(morseLetter, " ");
                break;
            case '.':
                strcpy(morseLetter, ".-.-.-");
                break;
            case ',':
                strcpy(morseLetter, "--..--");
                break;
            case '?':
                strcpy(morseLetter, "..--..");
                break;
            case '!':
                strcpy(morseLetter, "-.-.--");
                break;
            default:
                strcpy(morseLetter, "");
                break;
        }
        
        strcat(morse, morseLetter);
        strcat(morse, " ");
    }
}

void printMorse(char morse[])
{
    printf("Morse Code: ");
    printf("%s\n", morse);
    printf("Convert back to text? (y/n): ");
    
    char convertBack;
    scanf(" %c", &convertBack);
    
    if(convertBack == 'y' || convertBack == 'Y')
    {
        char code[strlen(morse)];
        convertToMorse(morse, code);
        printf("Text: %s", code);
    }
}