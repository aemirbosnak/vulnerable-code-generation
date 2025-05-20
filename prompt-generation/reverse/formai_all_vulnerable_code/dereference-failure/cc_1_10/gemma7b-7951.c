//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char input_buffer[MAX_BUFFER_SIZE];
    int input_length = 0;
    char output_buffer[MAX_BUFFER_SIZE];
    int output_length = 0;
    char* p_input = NULL;
    char* p_output = NULL;
    int i = 0;
    int is_hex = 0;

    printf("Enter a string: ");
    getline(input_buffer, MAX_BUFFER_SIZE, stdin);

    input_length = strlen(input_buffer);

    p_input = malloc(input_length + 1);
    memcpy(p_input, input_buffer, input_length);
    p_input[input_length] = '\0';

    for (i = 0; i < input_length; i++)
    {
        if (p_input[i] >= 'a' && p_input[i] <= 'f')
        {
            is_hex = 1;
        }
    }

    if (is_hex)
    {
        output_length = snprintf(output_buffer, MAX_BUFFER_SIZE, "The input string is hexadecimal: %s", p_input);
    }
    else
    {
        output_length = snprintf(output_buffer, MAX_BUFFER_SIZE, "The input string is not hexadecimal: %s", p_input);
    }

    p_output = malloc(output_length + 1);
    memcpy(p_output, output_buffer, output_length);
    p_output[output_length] = '\0';

    printf("%s\n", p_output);

    free(p_input);
    free(p_output);

    return 0;
}