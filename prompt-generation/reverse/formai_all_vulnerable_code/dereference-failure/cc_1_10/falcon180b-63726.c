//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32
#define MAX_FILE_LEN 1024

void encrypt_file(char* input_file, char* output_file, char* key) {
    FILE* input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    FILE* output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    char key_buf[MAX_KEY_LEN + 1] = {0};
    strncpy(key_buf, key, MAX_KEY_LEN);

    char in_buf[MAX_FILE_LEN + 1] = {0};
    char out_buf[MAX_FILE_LEN + 1] = {0};

    while (fgets(in_buf, MAX_FILE_LEN, input_fp)!= NULL) {
        int in_len = strlen(in_buf);
        int out_len = 0;

        for (int i = 0; i < in_len; i++) {
            char c = in_buf[i];
            if (isalpha(c)) {
                c = (c + key_buf[i % MAX_KEY_LEN]) % 26 + 'A';
            } else if (isdigit(c)) {
                c = c + key_buf[i % MAX_KEY_LEN];
            }

            out_buf[out_len++] = c;
        }

        fwrite(out_buf, 1, out_len, output_fp);
    }

    fclose(input_fp);
    fclose(output_fp);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        exit(1);
    }

    encrypt_file(argv[1], argv[2], argv[3]);

    printf("File encrypted successfully.\n");
    return 0;
}