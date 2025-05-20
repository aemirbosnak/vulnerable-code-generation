//FormAI DATASET v1.0 Category: Color Code Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 2048

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

static char *colors[] =
{
    "black",
    "red",
    "green",
    "yellow",
    "blue",
    "magenta",
    "cyan",
    "white"
};

static int colorValues[] =
{
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7
};

static char* hexChars = "0123456789ABCDEF";

// Returns the index of the given color in the colors array
int getColorIndex(char *color)
{
    int i;
    for(i=0; i<8; i++)
    {
        if(strcmp(color, colors[i]) == 0 || strcmp(color, colors[i]+1) == 0) // remove the escape character
        {
            return i;
        }
    }

    return -1;
}

// Returns the ANSI color code string for the given color index
char* getColorCode(int index)
{
    char *colorCode = (char *) calloc(1, sizeof(char) * 12);
    snprintf(colorCode, 12, "\x1b[3%dm", index);

    return colorCode;
}

// Converts a hex value to decimal
int hexToDecimal(char *hex)
{
    int decimal = 0;
    int length = strlen(hex);
    int power = 0;

    while(length--)
    {
        int c = toupper(*(hex+length));
        int value = strchr(hexChars, c) - hexChars;

        decimal += value * pow(16, power++);
    }

    return decimal;
}

// Converts a decimal value to hex
char* decimalToHex(int decimal)
{
    char buffer[16];
    sprintf(buffer, "%X\n", decimal);

    return strdup(buffer);
}

// Converts a hex color string to an ANSI color code
char* hexToANSI(char *hex)
{
    char *redHex = (char *) malloc(2);
    strncpy(redHex, hex, 2);

    char *greenHex = (char *) malloc(2);
    strncpy(greenHex, hex+2, 2);

    char *blueHex = (char *) malloc(2);
    strncpy(blueHex, hex+4, 2);

    int red = hexToDecimal(redHex);
    int green = hexToDecimal(greenHex);
    int blue = hexToDecimal(blueHex);

    free(redHex);
    free(greenHex);
    free(blueHex);

    char *colorCode = (char *) calloc(1, sizeof(char) * 15);
    snprintf(colorCode, 15, "\x1b[38;2;%d;%d;%dm", red, green, blue);

    return colorCode;
}

// Prints the color table
void printColorTable()
{
    printf("Color Table:\n");
    printf("------------\n");
    for(int i=0; i<8; i++)
    {
        printf("%-7s %sSample Text%s\n", colors[i], getColorCode(i), ANSI_COLOR_RESET);
    }
}

int main(int argc, char **argv)
{
    char *input = (char *) calloc(1, sizeof(char) * BUFFER_SIZE);

    if(argc == 1)
    {
        // No arguments provided
        printf("Color Code Converter\n");
        printf("--------------------\n");
        printf("Usage: color-convert [color-name] or [hex-color]\n\n");

        printColorTable();
    }
    else
    {
        char *color = argv[1];

        int colorIndex = getColorIndex(color);
        if(colorIndex != -1)
        {
            printf("Color: %s\n", color);
            printf("ANSI Color Code: %s\n", getColorCode(colorIndex));
        }
        else if(*color == '#')
        {
            char *ansiColorCode = hexToANSI(color+1);
            printf("Hex Color: %s\n", color);
            printf("ANSI Color Code: %s%s%s\n", ansiColorCode, color, ANSI_COLOR_RESET);

            free(ansiColorCode);
        }
        else
        {
            printf("Invalid input: %s\n", color);
        }
    }

    free(input);

    return 0;
}