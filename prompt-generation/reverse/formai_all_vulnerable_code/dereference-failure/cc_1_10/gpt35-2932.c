//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};

char* convert_to_morse(char* input);

void print_usage(char* program_name) {
    printf("Usage: %s [STRING]\n", program_name);
    printf("\n");
    printf("STRING: The string to encode to Morse code.\n");
}

int main(int argc, char** argv) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }
    
    char* input = argv[1];
    char* morse_output = convert_to_morse(input);
    printf("%s\n", morse_output);
    
    free(morse_output);
    return 0;
}

char* convert_to_morse(char* input) {
    size_t input_length = strlen(input);
    char* morse_output = calloc(5 * input_length + 1, sizeof(char));
    
    for (int i = 0; i < input_length; i++) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            strcat(morse_output, morse[c - 'a']);
        } else if (c >= 'A' && c <= 'Z') {
            strcat(morse_output, morse[c - 'A']);
        } else if (c >= '0' && c <= '9') {
            strcat(morse_output, morse[26 + c - '0']);
        } else if (c == ' ') {
            strcat(morse_output, morse[26]);
        } else {
            printf("Invalid input: %c\n", c);
        }
        strcat(morse_output, " ");
    }
    
    return morse_output;
}