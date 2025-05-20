//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_ART_SIZE 10000

int main() {
    /* Initialize variables */
    char input[MAX_LINE_LENGTH];
    char output[MAX_ART_SIZE];
    int i, j, index;

    /* Print header */
    printf("Enter text to convert to ASCII art:\n");

    /* Read input */
    fgets(input, MAX_LINE_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;

    /* Convert input to ASCII art */
    strcpy(output, "");
    for (i = 0; i < strlen(input); i++) {
        /* Determine ASCII value of character */
        int ascii = (int)input[i];

        /* Convert ASCII value to art */
        char art[5][5];
        if (ascii == 32) {
            /* Space */
            strcpy(art[0], "     ");
            strcpy(art[1], "     ");
            strcpy(art[2], "     ");
            strcpy(art[3], "     ");
            strcpy(art[4], "     ");
        } else if (ascii >= 65 && ascii <= 90) {
            /* Capital letter */
            index = ascii - 65;
            strcpy(art[0], "  _  ");
            strcpy(art[1], " / \\ ");
            strcpy(art[2], "|   |");
            strcpy(art[3], "|   |");
            strcpy(art[4], "|___|");
            /* Add letter to output */
            for (j = 0; j < 5; j++) {
                output[strlen(output)] = art[j][index];
                output[strlen(output)] = art[j][index+1];
                output[strlen(output)] = art[j][index+2];
                output[strlen(output)] = art[j][index+3];
                output[strlen(output)] = '\n';
            }
        } else {
            /* Unsupported character */
            printf("Unsupported character: %c\n", input[i]);
            return 1;
        }
    }

    /* Print output */
    printf("\nASCII art:\n%s", output);

    return 0;
}