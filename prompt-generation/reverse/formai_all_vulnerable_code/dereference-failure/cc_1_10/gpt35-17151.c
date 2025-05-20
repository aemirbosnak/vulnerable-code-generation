//FormAI DATASET v1.0 Category: File Encyptor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

void encrypt(char *input_file, char *output_file, char *key) {
    FILE *fp1, *fp2;
    int keylen = strlen(key), i = 0, j = 0, c;

    fp1 = fopen(input_file, "r");
    fp2 = fopen(output_file, "w");

    while ((c = fgetc(fp1)) != EOF) {
        fputc(c ^ key[j], fp2);
        i++;
        j = (j + 1) % keylen;
    }

    fclose(fp1);
    fclose(fp2);

    printf("File Encrypted Successfully...\n");
}

void decrypt(char *input_file, char *output_file, char *key) {
    encrypt(input_file, output_file, key);
}

int main(int argc, char *argv[]) {
    char *input_file = NULL, *output_file = NULL, *key = NULL;
    int encrypt_flag = 0, decrypt_flag = 0;

    for(int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            input_file = argv[++i];
        }

        if (strcmp(argv[i], "-o") == 0) {
            output_file = argv[++i];
        }

        if (strcmp(argv[i], "-k") == 0) {
            key = argv[++i];
        }

        if (strcmp(argv[i], "-e") == 0) {
            encrypt_flag = 1;
        }

        if (strcmp(argv[i], "-d") == 0) {
            decrypt_flag = 1;
        }
    }

    if (!input_file || !output_file || !key) {
        printf("Usage: %s -i <input_file> -o <output_file> -k <key>\n", argv[0]);
        exit(1);
    }

    if (!encrypt_flag && !decrypt_flag) {
        printf("Either -e or -d flag is required\n");
        exit(1);
    }

    if (encrypt_flag && decrypt_flag) {
        printf("Cannot use both -e and -d flags at a time\n");
        exit(1);
    }

    if (encrypt_flag) {
        encrypt(input_file, output_file, key);
    } else {
        decrypt(input_file, output_file, key);
    }

    return 0;
}