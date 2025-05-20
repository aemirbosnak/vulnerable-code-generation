//FormAI DATASET v1.0 Category: Compression algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void compress(char* input, char* output){

    FILE* in_file = fopen(input, "rb");
    FILE* out_file = fopen(output, "wb");

    if (in_file == NULL || out_file == NULL) {
        printf("Unable to open file.");
        return;
    }

    char buffer[MAX_SIZE];
    int num_bytes_read = fread(buffer, sizeof(char), MAX_SIZE, in_file);

    while (num_bytes_read != 0){
        int count = 1;
        char current = buffer[0];

        for (int i = 1; i < num_bytes_read; i++){
            if (count == 255 || buffer[i] != current){
                fwrite(&count, sizeof(char), 1, out_file);
                fwrite(&current, sizeof(char), 1, out_file);
                count = 1;
                current = buffer[i];
            }
            else{
                count++;
            }
        }

        fwrite(&count, sizeof(char), 1, out_file);
        fwrite(&current, sizeof(char), 1, out_file);

        num_bytes_read = fread(buffer, sizeof(char), MAX_SIZE, in_file);
    }

    fclose(in_file);
    fclose(out_file);

    printf("File compressed successfully.");
}

void decompress(char* input, char* output){

    FILE* in_file = fopen(input, "rb");
    FILE* out_file = fopen(output, "wb");

    if (in_file == NULL || out_file == NULL) {
        printf("Unable to open file.");
        return;
    }

    unsigned char count = 0;
    unsigned char current = 0;

    while (fread(&count, sizeof(unsigned char), 1, in_file)){
        fread(&current, sizeof(unsigned char), 1, in_file);

        for (int i = 0; i < count; i++){
            fwrite(&current, sizeof(char), 1, out_file);
        }
    }

    fclose(in_file);
    fclose(out_file);

    printf("File decompressed successfully.");
}

int main(){
    char input_file[] = "example.txt";
    char compressed_file[] = "example.bin";
    char decompressed_file[] = "example_decompressed.txt";

    compress(input_file, compressed_file);
    decompress(compressed_file, decompressed_file);

    return 0;
}