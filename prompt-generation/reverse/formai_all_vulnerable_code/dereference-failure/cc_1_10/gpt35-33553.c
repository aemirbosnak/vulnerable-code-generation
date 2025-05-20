//FormAI DATASET v1.0 Category: Compression algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void compress(char *input_path, char *output_path){
    FILE *input_file = fopen(input_path, "r");
    FILE *output_file = fopen(output_path, "w");

    if (!input_file || !output_file){
        printf("Error opening input/output file.");
        return;
    }

    char prev_char = fgetc(input_file);
    char curr_char;
    int count = 1;

    while ((curr_char = fgetc(input_file)) != EOF){
        if (curr_char == prev_char){
            count++;
        }
        else{
            if (count == 1){
                fputc(prev_char, output_file);
            }
            else{
                fprintf(output_file, "%d%c", count, prev_char);
            }
            prev_char = curr_char;
            count = 1;
        }
    }

    if (count == 1){
        fputc(prev_char, output_file);
    }
    else{
        fprintf(output_file, "%d%c", count, prev_char);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(){
    char *input_path = "input.txt";
    char *output_path = "output.txt";
    compress(input_path, output_path);
    return 0;
}