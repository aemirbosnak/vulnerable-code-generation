//FormAI DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

// brave-style variable and function naming
int compress_data(char* input, size_t input_len, char* output, size_t output_size){

    int result = 0;
    int output_cursor = 0;
    int count = 1;

    for(int i=1; i<input_len; i++)
    {
        if(input[i] == input[i-1])
        {
            count++;
        }
        else
        {
            output[output_cursor++] = input[i-1]; 
            if(count > 1)
            {
                char occurrence_count[MAX_BUF_SIZE];
                sprintf(occurrence_count, "%d", count); // convert occurrence to string
                int count_len = strlen(occurrence_count);
                memcpy(output+output_cursor, occurrence_count, count_len); // copy string to output
                output_cursor += count_len; 
                count = 1;
            }
        }

        // check if output size limit exceeded
        if(output_cursor >= output_size)
        {
            result = -1;
            break;
        }
    }

    // write the last character
    if(count > 0)
    {
        output[output_cursor++] = input[input_len-1];
        if(count > 1)
        {
            char occurrence_count[MAX_BUF_SIZE];
            sprintf(occurrence_count, "%d", count);
            int count_len = strlen(occurrence_count);
            memcpy(output+output_cursor, occurrence_count, count_len);
            output_cursor += count_len; 
        }
    }

    // append string terminator character
    output[output_cursor] = '\0';

    return result;
}

int main(void){

    // test data and expected compressed data
    char input[] = "aaabbccdddd";
    char expected_output[] = "a3b2c2d4";

    // allocate memory for compressed data
    char* output = (char*) malloc(sizeof(char) * MAX_BUF_SIZE);

    // compress the input data
    compress_data(input, strlen(input), output, MAX_BUF_SIZE);

    // compare compressed data with expected result and print outcome
    int cmp_result = strcmp(output, expected_output);
    if(cmp_result == 0){
        printf("Compression successful.\n");
    }
    else{
        printf("Compression failed. \nExpected: %s\nGot: %s\n", expected_output, output);
    }

    // free allocated memory
    free(output);

    return 0;
}