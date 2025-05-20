//FormAI DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input_file, char *output_file, int shift);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s input_file output_file shift\n", argv[0]);
        exit(1);
    }
    
    char *input_file = argv[1];
    char *output_file = argv[2];
    int shift = atoi(argv[3]);
    
    encrypt(input_file, output_file, shift);
    
    printf("File encrypted successfully!\n");
    
    return 0;
}

void encrypt(char *input_file, char *output_file, int shift) {
    FILE *in_file = fopen(input_file, "r");
    if (!in_file) {
        printf("Error opening input file\n");
        exit(1);
    }
    
    FILE *out_file = fopen(output_file, "w");
    if (!out_file) {
        printf("Error opening output file\n");
        exit(1);
    }
    
    char ch;
    while ((ch = fgetc(in_file)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        fputc(ch, out_file);
    }
    
    fclose(in_file);
    fclose(out_file);
}