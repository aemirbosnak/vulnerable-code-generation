//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 5000

int main(int argc, char** argv) {
    char* input_file_path = argv[1]; // input file path
    char* output_file_path = argv[2]; // output file path
    char* watermark_string = argv[3]; // watermark string

    FILE* input_file = fopen(input_file_path, "r"); // read input file
    if (input_file == NULL) {
        printf("Error: Input file not found.\n");
        return -1;
    }

    fseek(input_file, 0, SEEK_END);
    int input_file_size = ftell(input_file);
    rewind(input_file);
    
    char* input_buffer = (char*)malloc(input_file_size+1); // allocate memory for input buffer
    fread(input_buffer, sizeof(char), input_file_size, input_file);
    fclose(input_file);
    input_buffer[input_file_size] = '\0';

    int len_of_input_buffer = strlen(input_buffer); // get length of input buffer
    int len_of_watermark_string = strlen(watermark_string); // get length of watermark string

    int pos1 = len_of_input_buffer/4;
    int pos2 = pos1 * 2; 
    int pos3 = pos1 * 3; 

    char* output_buffer = (char*)malloc((input_file_size+len_of_watermark_string)*sizeof(char)); // allocate memory for output buffer

    strncpy(output_buffer, input_buffer, pos1); // copy first section of input buffer to output buffer
    strncat(output_buffer, watermark_string, len_of_watermark_string); // add watermark string to output buffer
    strncat(output_buffer, &input_buffer[pos1], pos2-pos1); // copy second section of input buffer to output buffer
    strncat(output_buffer, watermark_string, len_of_watermark_string); // add watermark string to output buffer
    strncat(output_buffer, &input_buffer[pos2], pos3-pos2); // copy third section of input buffer to output buffer
    strncat(output_buffer, watermark_string, len_of_watermark_string); // add watermark string to output buffer
    strncat(output_buffer, &input_buffer[pos3], len_of_input_buffer-pos3); // copy fourth section of input buffer to output buffer

    FILE* output_file = fopen(output_file_path, "wb"); // write output file
    fwrite(output_buffer, sizeof(char), strlen(output_buffer), output_file);
    fclose(output_file);

    free(input_buffer);
    free(output_buffer);

    printf("Digital watermarking complete.\n");

    return 0;
}