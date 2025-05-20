//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 16
#define MAX_FILE_NAME_LEN 100
#define MAX_LINE_LEN 1000

typedef struct {
    char key[MAX_KEY_LEN];
    FILE *in;
    FILE *out;
} Encryptor;

void encrypt(Encryptor *encryptor, char *buf, int len) {
    int i = 0;
    while (i < len) {
        char c = buf[i];
        if (isalpha(c)) {
            c = (c - 'a' + encryptor->key[i % MAX_KEY_LEN]) % 26 + 'a';
        }
        fprintf(encryptor->out, "%c", c);
        i++;
    }
}

Encryptor *init_encryptor(char *key, char *in_file, char *out_file) {
    Encryptor *encryptor = malloc(sizeof(Encryptor));
    strncpy(encryptor->key, key, MAX_KEY_LEN);
    encryptor->in = fopen(in_file, "r");
    encryptor->out = fopen(out_file, "w");
    return encryptor;
}

void destroy_encryptor(Encryptor *encryptor) {
    fclose(encryptor->in);
    fclose(encryptor->out);
    free(encryptor);
}

int main(int argc, char **argv) {
    if (argc!= 5) {
        printf("Usage: %s <key> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *key = argv[1];
    char *in_file = argv[2];
    char *out_file = argv[3];

    Encryptor *encryptor = init_encryptor(key, in_file, out_file);

    char buf[MAX_LINE_LEN];
    int len;

    while ((len = fread(buf, 1, MAX_LINE_LEN, encryptor->in)) > 0) {
        encrypt(encryptor, buf, len);
    }

    destroy_encryptor(encryptor);

    return 0;
}