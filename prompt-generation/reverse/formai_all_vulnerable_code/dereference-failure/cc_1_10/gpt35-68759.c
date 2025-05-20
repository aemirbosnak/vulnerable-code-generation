//FormAI DATASET v1.0 Category: File Encyptor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "KNU"

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_file_path[100], output_file_path[100];
    char keyword[4] = KEY;
    char data[128];
    int i, j = 0, len_keyword;
    
    if (argc < 3) {
        printf("\nUsage: %s input_file_path output_file_path\n", argv[0]);
        exit(0);
    }
    
    strcpy(input_file_path, argv[1]);
    strcpy(output_file_path, argv[2]);
    
    input_file = fopen(input_file_path, "rb");
    output_file = fopen(output_file_path, "wb");
    
    if (input_file == NULL) {
        printf("\nError: Could not open file %s", input_file_path);
        exit(1);
    }
    
    if (output_file == NULL) {
        printf("\nError: Could not create file %s", output_file_path);
        exit(1);
    }
    
    len_keyword = strlen(keyword);
    
    while (!feof(input_file)) {
        fread(data, 1, 128, input_file);
        for (i = 0; i < 128; i++) {
            data[i] ^= keyword[j];
            j = (j + 1) % len_keyword;
        }
        fwrite(data, 1, 128, output_file);
    }
    
    printf("\nEncryption finished.\n");
    
    fclose(input_file);
    fclose(output_file);
    
    return 0;
}