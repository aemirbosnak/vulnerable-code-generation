//FormAI DATASET v1.0 Category: Color Code Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* hexToRGB(char* str);
void validateHex(char* str);
char* toUpper(char* str);

// Driver code
int main()
{
    char* hexCode = "#FFA500";
    printf("Hex Code: %s\n", hexCode);
    char* rgbCode = hexToRGB(hexCode);
    printf("RGB Code: %s\n", rgbCode);
    free(rgbCode);
    return 0;
}

// Function to convert Hex color code to RGB color code
char* hexToRGB(char* str)
{
    validateHex(str);

    char* hex = str + 1;
    char* r = (char*)malloc(3 * sizeof(char));
    char* g = (char*)malloc(3 * sizeof(char));
    char* b = (char*)malloc(3 * sizeof(char));

    strncpy(r, hex, 2);
    strncpy(g, hex + 2, 2);
    strncpy(b, hex + 4, 2);

    int red = strtol(r, NULL, 16);
    int green = strtol(g, NULL, 16);
    int blue = strtol(b, NULL, 16);

    char* rgb = (char*)malloc(12 * sizeof(char));
    sprintf(rgb, "RGB(%d,%d,%d)", red, green, blue);
    free(r);
    free(g);
    free(b);
    return rgb;
}

// Function to validate Hex color code
void validateHex(char* str)
{
    int len = strlen(str);
    if (len != 7)
    {
        printf("Error: Invalid Hex Code!");
        exit(0);
    }
    if (str[0] != '#')
    {
        printf("Error: Invalid Hex Code!");
        exit(0);
    }
    for (int i = 1; i < len; i++)
    {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F')))
        {
            printf("Error: Invalid Hex Code!");
            exit(0);
        }
    }
}

// Function to convert a string to uppercase
char* toUpper(char* str)
{
    int len = strlen(str);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            result[i] = str[i] - 32;
        }
        else
        {
            result[i] = str[i];
        }
    }
    result[len] = '\0';
    return result;
}