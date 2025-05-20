//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to translate C Cat Language
char* translateCcat(char* input) {
    int input_len = strlen(input);
    char* output = (char*)malloc(sizeof(char) * (input_len + 1));
    int i, j = 0;

    for (i = 0; i < input_len; i++) {
        if (input[i] == 'c' || input[i] == 'C') {
            output[j] = 'm';
            output[j+1] = 'e';
            j += 2;
        } else if (input[i] == 'a' || input[i] == 'A') {
            output[j] = 'p';
            output[j+1] = 'u';
            j += 2;
        } else if (input[i] == 't' || input[i] == 'T') {
            output[j] = 's';
            output[j+1] = 'h';
            output[j+2] = 'e';
            output[j+3] = 'k';
            j += 4;
        } else if (input[i] == 'f' || input[i] == 'F') {
            output[j] = 'b';
            output[j+1] = 'o';
            output[j+2] = 'u';
            output[j+3] = 'l';
            output[j+4] = 'd';
            j += 5;
        } else {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';

    return output;
}

// Main function
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <C Cat Language input>\n", argv[0]);
        return 1;
    }
    char* input = argv[1];
    char* output = translateCcat(input);
    printf("Translation: %s\n", output);
    free(output);

    return 0;
}