//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1000

void parse_input(char *input_buffer, char **output_buffer) {
    int i = 0;
    int j = 0;
    while (i < strlen(input_buffer)) {
        if (isdigit(input_buffer[i])) {
            char binary_digit = '0' + (input_buffer[i] - '0');
            (*output_buffer)[j] = binary_digit;
            j++;
        }
        i++;
    }
    (*output_buffer)[j] = '\0';
}

int main(int argc, char *argv[]) {
    FILE *file_in;
    FILE *file_out;
    char *input_buffer = NULL;
    char *output_buffer = NULL;
    char *filename = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    file_in = fopen(filename, "r");
    if (file_in == NULL) {
        printf("Error: could not open input file %s\n", filename);
        return 1;
    }

    input_buffer = malloc(MAX_BUFFER_SIZE);
    if (input_buffer == NULL) {
        printf("Error: could not allocate memory for input buffer\n");
        fclose(file_in);
        return 1;
    }

    output_buffer = malloc(MAX_BUFFER_SIZE);
    if (output_buffer == NULL) {
        printf("Error: could not allocate memory for output buffer\n");
        fclose(file_in);
        free(input_buffer);
        return 1;
    }

    while ((read = getline(&input_buffer, &len, file_in))!= -1) {
        parse_input(input_buffer, &output_buffer);
        fwrite(output_buffer, strlen(output_buffer), 1, file_out);
        memset(output_buffer, 0, MAX_BUFFER_SIZE);
    }

    free(input_buffer);
    free(output_buffer);
    fclose(file_in);
    fclose(file_out);

    return 0;
}