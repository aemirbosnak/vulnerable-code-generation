//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ENIGMA_TEXT_FILE "input.txt"
#define ENIGMA_OUTPUT_FILE "output.txt"
#define BOMBE_KEY 3

typedef struct {
    char text[1024];
    int length;
} ENIGMA_LINE;

typedef struct {
    int rotor1_setting;
    int rotor2_setting;
    int rotor3_setting;
    int reflector_setting;
} ENIGMA_SETTINGS;

void encrypt_line(ENIGMA_LINE *line, ENIGMA_SETTINGS *settings) {
    int i;
    for (i = 0; i < line->length; ++i) {
        if (isalpha(line->text[i])) {
            char c = line->text[i];
            if (isupper(c)) {
                c = ((int)c - 65 + BOMBE_KEY) % 26 + 65;
            } else {
                c = ((int)c - 97 + BOMBE_KEY) % 26 + 97;
            }
            line->text[i] = c;
        }
    }
}

void set_enigma_settings(ENIGMA_SETTINGS *settings) {
    settings->rotor1_setting = 0xDEAD;
    settings->rotor2_setting = 0xBADCAFE;
    settings->rotor3_setting = 0xCAFEBABE;
    settings->reflector_setting = 0x1337;
}

int main(void) {
    FILE *input_file, *output_file;
    ENIGMA_LINE current_line;
    ENIGMA_SETTINGS enigma_settings;

    input_file = fopen(ENIGMA_TEXT_FILE, "r");
    output_file = fopen(ENIGMA_OUTPUT_FILE, "w");

    if (input_file == NULL || output_file == NULL) {
        perror("Error opening file(s).");
        exit(EXIT_FAILURE);
    }

    set_enigma_settings(&enigma_settings);

    while (fgets(current_line.text, sizeof(current_line.text), input_file)) {
        current_line.length = strlen(current_line.text);
        encrypt_line(&current_line, &enigma_settings);
        fprintf(output_file, "%s\n", current_line.text);
    }

    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}