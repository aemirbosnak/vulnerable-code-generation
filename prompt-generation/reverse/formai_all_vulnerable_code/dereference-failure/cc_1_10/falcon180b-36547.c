//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: accurate
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX_CODE_LENGTH 1000
#define MAX_CODE_WORD_LENGTH 10

char *morse_codes[26] = {"A:.-", "B: -...", "C: -.-.", "D: -..", "E:.", "F:..-. ", "G: --.", "H:....", "I:..", "J:.---", "K: -.-", "L:.-..", "M: -- ", "N: -.", "O: ---", "P:.--. ", "Q: --.-", "R:.-. ", "S:...", "T: - ", "U:..-", "V:...-", "W:.--", "X: -..-", "Y: ", "Z: --..", "1:.----", "2:..---", "3:...--", "4:....-", "5:..... ", "6: -....", "7: --... ", "8: ---..", "9: ----. ", "0: -----"};

char *str;
int len;
char output[MAX_CODE_LENGTH];
int i, j;

void convert_to_morse_code(char *str)
{
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (isalpha(str[i]))
        {
            j = tolower(str[i]) - 'a';
            if (j >= 0 && j <= 25)
            {
                strcat(output, morse_codes[j]);
                strcat(output, " ");
            }
        }
        else if (isdigit(str[i]))
        {
            j = str[i] - '0';
            if (j >= 0 && j <= 9)
            {
                strcat(output, morse_codes[j + 26]);
                strcat(output, " ");
            }
        }
        else
        {
            strcat(output, " ");
        }
    }
}

int main()
{
    printf("Enter a text to convert to Morse code: ");
    scanf("%s", str);
    convert_to_morse_code(str);
    printf("Morse code: %s\n", output);
    return 0;
}