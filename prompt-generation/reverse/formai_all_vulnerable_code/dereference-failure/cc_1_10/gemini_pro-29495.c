//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-.-.-", "---.", "--.-.",
    "....-", "--..--", ".----", "..---", "...--", "....-", ".....", "-....",
    "--...", "---..", "----.", "-----"
};

// Convert a character to Morse code
char *char_to_morse(char c) {
    if (c >= 'A' && c <= 'Z') {
        c -= 'A';
    } else if (c >= 'a' && c <= 'z') {
        c -= 'a';
    } else if (c >= '0' && c <= '9') {
        c += 7;
    }
    return morse_table[c];
}

// Convert a string to Morse code
char *string_to_morse(char *s) {
    int len = strlen(s);
    char *morse = malloc(len * 5);

    for (int i = 0; i < len; i++) {
        strcat(morse, char_to_morse(s[i]));
        strcat(morse, " ");
    }

    return morse;
}

// Print the Morse code for a string
void print_morse(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == ' ') {
            printf(" ");
        } else if (s[i] == '.' || s[i] == '-') {
            printf("%c", s[i]);
        }
        i++;
    }
    printf("\n");
}

int main() {
    // Get the input string
    char *s = malloc(100);
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", s);

    // Convert the string to Morse code
    char *morse = string_to_morse(s);

    // Print the Morse code
    printf("The Morse code for \"%s\" is: ", s);
    print_morse(morse);

    // Free the allocated memory
    free(s);
    free(morse);

    return 0;
}