//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 16
#define MAX_FILE_NAME_LEN 256
#define MAX_LINE_LEN 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char key[MAX_KEY_LEN];
    FILE *fp_in;
    FILE *fp_out;
} FileEncryptor;

void init_encryptor(FileEncryptor *encryptor, char *file_name, char *key) {
    strcpy(encryptor->file_name, file_name);
    strcpy(encryptor->key, key);
    encryptor->fp_in = fopen(file_name, "r");
    encryptor->fp_out = fopen("encrypted.txt", "w");
}

void encrypt_file(FileEncryptor *encryptor) {
    char line[MAX_LINE_LEN];
    char *ptr;
    int i, j;

    while (fgets(line, MAX_LINE_LEN, encryptor->fp_in)!= NULL) {
        ptr = line;
        while (*ptr!= '\0' &&!isalpha(*ptr)) {
            ptr++;
        }
        for (i = 0; i < strlen(encryptor->key); i++) {
            for (j = 0; j < strlen(ptr); j++) {
                if (isalpha(ptr[j])) {
                    if (isupper(ptr[j])) {
                        ptr[j] = encryptor->key[i] + 'A' - 'a';
                    } else {
                        ptr[j] = encryptor->key[i] + 'a' - 'A';
                    }
                }
            }
        }
        fprintf(encryptor->fp_out, "%s\n", line);
    }

    fclose(encryptor->fp_in);
    fclose(encryptor->fp_out);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <key>\n", argv[0]);
        return 1;
    }

    FileEncryptor encryptor;
    init_encryptor(&encryptor, argv[1], argv[2]);
    encrypt_file(&encryptor);

    return 0;
}