//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function declarations
void printAsciiArt(char* str);
void printHorizontalLine(int width);
void printVerticalLine(int height);
void printSpace(int numSpaces);
void printCharacter(char c);

const int ART_HEIGHT = 8;

int main() 
{
    char* userInput = (char*) malloc(256 * sizeof(char));
    printf("Enter text to convert to ASCII art:\n");
    fgets(userInput, 256, stdin);
    printAsciiArt(userInput);
    free(userInput);
    return 0;
}

// function definitions
void printAsciiArt(char* str)
{
    int strLength = strlen(str);
    for (int i = 0; i < ART_HEIGHT; i++) // for each row of the ASCII art
    {
        for (int j = 0; j < strLength; j++) // for each character of the user's input string
        {
            char c = toupper(str[j]);
            if (c >= 'A' && c <= 'Z')
            {
                // letters A-Z
                int letterIndex = c - 'A';
                int rowCount = 0;
                for (int k = 0; k < 6; k++)
                {
                    if (k == 0 || k == 5) // first and last rows are horizontal lines
                    {
                        printHorizontalLine(4);
                    }
                    else if (k == 1 || k == 4) // second and fifth rows have some vertical lines
                    {
                        if (rowCount == letterIndex)
                        {
                            printCharacter(c);
                        }
                        else
                        {
                            printSpace(3);
                        }
                        printVerticalLine(1);
                    }
                    else // third and fourth rows have some horizontal lines and spaces
                    {
                        printHorizontalLine(1);
                        if (rowCount == letterIndex)
                        {
                            printCharacter(c);
                        }
                        else
                        {
                            printSpace(2);
                        }
                        printHorizontalLine(1);
                    }
                    printf("\n"); // move to next line
                    rowCount++;
                }
            }
            else if (c == ' ') // space
            {
                printSpace(4); // print four spaces
                printf("\n");
                printSpace(4);
                printf("\n");
                printSpace(4);
                printf("\n");
                printSpace(4);
                printf("\n");
                printSpace(4);
                printf("\n");
            }
            else // characters other than letters and spaces will be ignored
            {
                continue;
            }
        }
    }
}

void printHorizontalLine(int width)
{
    for (int i = 0; i < width; i++)
    {
        printf("*");
    }
}

void printVerticalLine(int height)
{
    for (int i = 0; i < height; i++)
    {
        printf("*\n");
    }
}

void printSpace(int numSpaces)
{
    for (int i = 0; i < numSpaces; i++)
    {
        printf(" ");
    }
}

void printCharacter(char c)
{
    switch(c)
    {
        case 'A':
            printf("  *  \n");
            printf(" * * \n");
            printf("*   *\n");
            printf("*****\n");
            printf("*   *\n");
            printf("*   *\n");
            break;
        case 'B':
            printf("**** \n");
            printf("*   *\n");
            printf("**** \n");
            printf("*   *\n");
            printf("**** \n");
            break;
        case 'C':
            printf(" *** \n");
            printf("*   *\n");
            printf("*    \n");
            printf("*    \n");
            printf("*   *\n");
            printf(" *** \n");
            break;
        case 'D':
            printf("**** \n");
            printf("*   *\n");
            printf("*   *\n");
            printf("*   *\n");
            printf("**** \n");
            break;
        case 'E':
            printf("*****\n");
            printf("*    \n");
            printf("***  \n");
            printf("*    \n");
            printf("*****\n");
            break;
        case 'F':
            printf("*****\n");
            printf("*    \n");
            printf("***  \n");
            printf("*    \n");
            printf("*    \n");
            break;
        case 'G':
            printf(" *** \n");
            printf("*   *\n");
            printf("*    \n");
            printf("* ** \n");
            printf("*   *\n");
            printf(" *** \n");
            break;
        case 'H':
            printf("*   *\n");
            printf("*   *\n");
            printf("*****\n");
            printf("*   *\n");
            printf("*   *\n");
            break;
        case 'I':
            printf("***\n");
            printf(" * \n");
            printf(" * \n");
            printf(" * \n");
            printf("***\n");
            break;
        case 'J':
            printf("   *\n");
            printf("   *\n");
            printf("   *\n");
            printf("*  *\n");
            printf(" ** \n");
            break;
        case 'K':
            printf("*  * \n");
            printf("* *  \n");
            printf("**   \n");
            printf("* *  \n");
            printf("*  * \n");
            break;
        case 'L':
            printf("*    \n");
            printf("*    \n");
            printf("*    \n");
            printf("*    \n");
            printf("*****\n");
            break;
        case 'M':
            printf("*   *\n");
            printf("** **\n");
            printf("* * *\n");
            printf("*   *\n");
            printf("*   *\n");
            break;
        case 'N':
            printf("*   *\n");
            printf("**  *\n");
            printf("* * *\n");
            printf("*  **\n");
            printf("*   *\n");
            break;
        case 'O':
            printf(" *** \n");
            printf("*   *\n");
            printf("*   *\n");
            printf("*   *\n");
            printf(" *** \n");
            break;
        case 'P':
            printf("**** \n");
            printf("*   *\n");
            printf("**** \n");
            printf("*    \n");
            printf("*    \n");
            break;
        case 'Q':
            printf(" *** \n");
            printf("*   *\n");
            printf("*   *\n");
            printf("* * *\n");
            printf(" ***+\n");
            break;
        case 'R':
            printf("**** \n");
            printf("*   *\n");
            printf("**** \n");
            printf("* *  \n");
            printf("*  * \n");
            break;
        case 'S':
            printf(" *** \n");
            printf("*    \n");
            printf(" *** \n");
            printf("    *\n");
            printf(" *** \n");
            break;
        case 'T':
            printf("*****\n");
            printf("  *  \n");
            printf("  *  \n");
            printf("  *  \n");
            printf("  *  \n");
            break;
        case 'U':
            printf("*   *\n");
            printf("*   *\n");
            printf("*   *\n");
            printf("*   *\n");
            printf(" *** \n");
            break;
        case 'V':
            printf("*   *\n");
            printf("*   *\n");
            printf("*   *\n");
            printf(" * * \n");
            printf("  *  \n");
            break;
        case 'W':
            printf("*   *\n");
            printf("*   *\n");
            printf("*   *\n");
            printf("* * *\n");
            printf("** **\n");
            break;
        case 'X':
            printf("*   *\n");
            printf(" * * \n");
            printf("  *  \n");
            printf(" * * \n");
            printf("*   *\n");
            break;
        case 'Y':
            printf("*   *\n");
            printf("*   *\n");
            printf(" *** \n");
            printf("  *  \n");
            printf("  *  \n");
            break;
        case 'Z':
            printf("*****\n");
            printf("   * \n");
            printf("  *  \n");
            printf(" *   \n");
            printf("*****\n");
            break;
        default:
            break;
    }
}