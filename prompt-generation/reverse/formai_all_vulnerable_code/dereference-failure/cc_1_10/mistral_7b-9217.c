//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

void convert_to_c(char *input, char *output) {
    int i = 0, j = 0;
    while (input[i] != '\0') {
        if (isalpha(input[i])) {
            output[j] = toupper(input[i]);
            j++;
        } else if (input[i] == '+') {
            output[j] = '\'' + rand() % 128;
            j++;
        } else if (input[i] == '-') {
            output[j] = '~' + rand() % 128;
            j++;
        } else if (input[i] == ' ') {
            output[j] = '\t';
            j++;
        } else if (input[i] == '=') {
            output[j] = '=';
            output[j+1] = '=';
            j += 2;
        } else {
            output[j] = input[i];
            j++;
        }
        i++;
    }
    output[j] = '\0';
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input_string> <output_string>\n", argv[0]);
        return 1;
    }

    char input_str[MAX_LEN], output_str[MAX_LEN];
    strcpy(input_str, argv[1]);
    char *output_ptr = output_str;

    convert_to_c(argv[1], output_str);

    printf("Input String: %s\n", input_str);
    printf("Output String: %s\n", output_str);

    return 0;
}