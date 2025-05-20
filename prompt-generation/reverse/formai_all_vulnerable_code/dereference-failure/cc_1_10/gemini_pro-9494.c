//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 0

typedef struct {
    char *key;
    int keylen;
} EncryptionKey;

typedef struct {
    EncryptionKey key;
    int mode;
} EncryptionConfiguration;

void print_usage() {
    printf("Usage: enc [-e | -d] -k <keyfile> -i <inputfile> -o <outputfile>\n");
    printf("Options:\n");
    printf("    -e: Encrypt the input file using the key\n");
    printf("    -d: Decrypt the input file using the key\n");
    printf("    -k: Specify the key file to use for encryption or decryption\n");
    printf("    -i: Specify the input file to encrypt or decrypt\n");
    printf("    -o: Specify the output file to store the encrypted or decrypted data\n");
}

int read_input_file(char *filepath, char **buffer) {
    FILE *file = fopen(filepath, "rb");

    if (file == NULL) {
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    *buffer = malloc(filesize + 1);
    (*buffer)[filesize] = '\0';

    fread(*buffer, filesize, 1, file);

    fclose(file);

    return 0;
}

int write_output_file(char *filepath, char *buffer) {
    FILE *file = fopen(filepath, "wb");

    if (file == NULL) {
        return 1;
    }

    fwrite(buffer, strlen(buffer), 1, file);

    fclose(file);

    return 0;
}

int encrypt_decrypt(EncryptionConfiguration config, char *buffer) {
    int i, j;
    int keylen = config.key.keylen;
    char *key = config.key.key;
    int mode = config.mode;

    for (i = 0; i < strlen(buffer); i++) {
        for (j = 0; j < keylen; j++) {
            if (mode == ENCRYPT) {
                buffer[i] ^= key[j];
            } else if (mode == DECRYPT) {
                buffer[i] ^= key[(keylen - 1) - j];
            }
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    EncryptionConfiguration config = {0};
    char *inputfile = NULL;
    char *outputfile = NULL;
    int i;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0) {
            config.mode = ENCRYPT;
        } else if (strcmp(argv[i], "-d") == 0) {
            config.mode = DECRYPT;
        } else if (strcmp(argv[i], "-k") == 0) {
            i++;
            if (i < argc) {
                config.key.key = argv[i];
                config.key.keylen = strlen(config.key.key);
            }
        } else if (strcmp(argv[i], "-i") == 0) {
            i++;
            if (i < argc) {
                inputfile = argv[i];
            }
        } else if (strcmp(argv[i], "-o") == 0) {
            i++;
            if (i < argc) {
                outputfile = argv[i];
            }
        } else {
            print_usage();
            return 1;
        }
    }

    if (config.key.key == NULL || inputfile == NULL || outputfile == NULL) {
        print_usage();
        return 1;
    }

    char *buffer = NULL;

    if (read_input_file(inputfile, &buffer) != 0) {
        printf("Error: Could not read input file\n");
        return 1;
    }

    if (encrypt_decrypt(config, buffer) != 0) {
        printf("Error: Could not encrypt or decrypt the data\n");
        return 1;
    }

    if (write_output_file(outputfile, buffer) != 0) {
        printf("Error: Could not write output file\n");
        return 1;
    }

    printf("Encryption or decryption successful!\n");

    free(buffer);

    return 0;
}