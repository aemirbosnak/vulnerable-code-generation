//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "---", ".-.-.-", "--..--", "..--.."
};

// Character to Morse code conversion function
char *to_morse(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    } else if (c >= 'A' && c <= 'Z') {
        return morse_table[c - 'A'];
    } else if (c == '0') {
        return "-----";
    } else if (c == '1') {
        return ".----";
    } else if (c == '2') {
        return "..---";
    } else if (c == '3') {
        return "...--";
    } else if (c == '4') {
        return "....-";
    } else if (c == '5') {
        return ".....";
    } else if (c == '6') {
        return "-....";
    } else if (c == '7') {
        return "--...";
    } else if (c == '8') {
        return "---..";
    } else if (c == '9') {
        return "----.";
    } else if (c == ' ') {
        return " ";
    } else {
        return "";
    }
}

// Morse code to character conversion function
char to_char(char *morse) {
    for (int i = 0; i < 26; i++) {
        if (strcmp(morse, morse_table[i]) == 0) {
            return 'a' + i;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (strcmp(morse, morse_table[i + 26]) == 0) {
            return 'A' + i;
        }
    }
    if (strcmp(morse, "-----") == 0) {
        return '0';
    } else if (strcmp(morse, ".----") == 0) {
        return '1';
    } else if (strcmp(morse, "..---") == 0) {
        return '2';
    } else if (strcmp(morse, "...--") == 0) {
        return '3';
    } else if (strcmp(morse, "....-") == 0) {
        return '4';
    } else if (strcmp(morse, ".....") == 0) {
        return '5';
    } else if (strcmp(morse, "-....") == 0) {
        return '6';
    } else if (strcmp(morse, "--...") == 0) {
        return '7';
    } else if (strcmp(morse, "---..") == 0) {
        return '8';
    } else if (strcmp(morse, "----.") == 0) {
        return '9';
    } else if (strcmp(morse, " ") == 0) {
        return ' ';
    } else {
        return '\0';
    }
}

// Morse code to text conversion function
char *to_text(char *morse) {
    char *text = malloc(strlen(morse) + 1);
    int i = 0;
    int j = 0;
    while (morse[i] != '\0') {
        if (morse[i] == ' ') {
            text[j++] = ' ';
        } else {
            char *c = malloc(4);
            int k = 0;
            while (morse[i] != ' ' && morse[i] != '\0') {
                c[k++] = morse[i++];
            }
            c[k] = '\0';
            text[j++] = to_char(c);
            free(c);
        }
        i++;
    }
    text[j] = '\0';
    return text;
}

// Text to Morse code conversion function
char *to_morse_code(char *text) {
    char *morse = malloc(strlen(text) * 5 + 1);
    int i = 0;
    int j = 0;
    while (text[i] != '\0') {
        char *m = to_morse(text[i]);
        int k = 0;
        while (m[k] != '\0') {
            morse[j++] = m[k++];
        }
        morse[j++] = ' ';
        i++;
    }
    morse[j] = '\0';
    return morse;
}

int main() {
    // Get the input text from the user
    char *text = malloc(100);
    printf("Enter the text to be converted to Morse code: ");
    scanf("%s", text);

    // Convert the text to Morse code
    char *morse = to_morse_code(text);

    // Print the Morse code
    printf("Morse code: %s\n", morse);

    // Convert the Morse code back to text
    char *text_back = to_text(morse);

    // Print the converted text
    printf("Text back: %s\n", text_back);

    // Free the allocated memory
    free(text);
    free(morse);
    free(text_back);

    return 0;
}