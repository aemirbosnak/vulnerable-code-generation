//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *input_file, char *output_file);

int main(int argc, char **argv){
    if(argc != 3){
        printf("Usage: ./compress <input_file> <output_file>\n");
        return 0;
    }
    compress(argv[1], argv[2]);
    return 0;
}

void compress(char *input_file, char *output_file){
    FILE *fp_in, *fp_out;
    fp_in = fopen(input_file, "r");
    if(fp_in == NULL){
        printf("Error opening input file.\n");
        return;
    }
    fp_out = fopen(output_file, "w");
    if(fp_out == NULL){
        printf("Error opening output file.\n");
        return;
    }

    /* read input file */
    fseek(fp_in, 0, SEEK_END);
    unsigned int input_size = ftell(fp_in);
    rewind(fp_in);
    char *input = malloc(input_size * sizeof(char));
    int n = fread(input, sizeof(char), input_size, fp_in);
    if(n != input_size){
        printf("Error reading input file.\n");
        return;
    }

    /* compress data */
    char *compressed = malloc((input_size + 1) * sizeof(char));
    int c_len = 0;
    char c;
    int count = 1;
    for(int i=1; i<input_size; ++i){
        if(input[i] == input[i-1]){
            ++count;
        }
        else{
            compressed[c_len++] = input[i-1];
            c = count + '0';
            compressed[c_len++] = c;
            count = 1;
        }
    }
    /* write compressed data to output file */
    fwrite(compressed, sizeof(char), c_len, fp_out);

    /* free memory and close files */
    free(input);
    free(compressed);
    fclose(fp_in);
    fclose(fp_out);
}