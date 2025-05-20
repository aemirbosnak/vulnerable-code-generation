//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* c_to_morse_code(char c);
char* convert_to_morse_code(char* s);

int main() {
    char input_str[100];
    printf("Enter a string to convert to Morse code:\n");
    fgets(input_str, 100, stdin);

    // Remove newline character at the end of input string
    input_str[strcspn(input_str, "\n")] = '\0';

    char* output_str = convert_to_morse_code(input_str);

    printf("Morse code: %s\n", output_str);

    return 0;
}

char* convert_to_morse_code(char* s) {
    // Morse code lookup table
    const char* morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    // Allocate enough memory to store the Morse code string
    char* morse_code_str = (char*)malloc(strlen(s) * 5 + 1);

    for (int i = 0; i < strlen(s); i++) {
        char c = toupper(s[i]);

        // Append space if previous character was not a space
        if (i > 0 && s[i-1] != ' ') {
            strcat(morse_code_str, " ");
        }

        if (c == ' ') {
            strcat(morse_code_str, " /");
        } else {
            char* morse_code_char = c_to_morse_code(c);
            strcat(morse_code_str, morse_code_char);
        }
    }

    return morse_code_str;
}

char* c_to_morse_code(char c) {
    // Morse code lookup table
    const char* morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    if (isalpha(c)) {
        return (char*)morse_code[c - 'A'];
    } else if (isdigit(c)) {
        return (char*)morse_code[c - '0' + 26];
    } else {
        switch (c) {
            case '.': return (char*)morse_code[36];
            case ',': return (char*)morse_code[37];
            case '?': return (char*)morse_code[38];
            case '\'': return (char*)morse_code[39];
            case '!': return (char*)morse_code[40];
            case '/': return (char*)morse_code[41];
            case '(': return (char*)morse_code[42];
            case ')': return (char*)morse_code[43];
            case '&': return (char*)morse_code[44];
            case ':': return (char*)morse_code[45];
            case ';': return (char*)morse_code[46];
            case '=': return (char*)morse_code[47];
            case '+': return (char*)morse_code[48];
            case '-': return (char*)morse_code[49];
            case '_': return (char*)morse_code[50];
            case '\"': return (char*)morse_code[51];
            case '$': return (char*)morse_code[52];
            case '@': return (char*)morse_code[53];
            default: return "";
        }
    }
}