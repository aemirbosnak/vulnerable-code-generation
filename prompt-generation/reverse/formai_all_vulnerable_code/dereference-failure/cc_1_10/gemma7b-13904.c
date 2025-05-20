//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_KEY_LENGTH 256

typedef struct Key {
    int key_length;
    unsigned char *key;
} Key;

void encrypt_file(Key *key, FILE *fp, int mode) {
    unsigned char buffer[4096];
    int read_size, written_size;
    long pos;

    switch (mode) {
    case 0:
        // Encrypt
        for (pos = 0; (read_size = fread(buffer, 1, 4096, fp)) > 0; pos += read_size) {
            for (written_size = 0; written_size < read_size; written_size++) {
                buffer[written_size] ^= key->key[pos % key->key_length];
            }
            fwrite(buffer, 1, written_size, fp);
        }
        break;
    case 1:
        // Decrypt
        for (pos = 0; (read_size = fread(buffer, 1, 4096, fp)) > 0; pos += read_size) {
            for (written_size = 0; written_size < read_size; written_size++) {
                buffer[written_size] ^= key->key[pos % key->key_length];
            }
            fwrite(buffer, 1, written_size, fp);
        }
        break;
    }
}

int main() {
    Key key;
    key.key_length = 16;
    key.key = malloc(key.key_length);
    key.key[0] = 0x12;
    key.key[1] = 0x34;
    key.key[2] = 0x56;
    key.key[3] = 0x78;
    key.key[4] = 0x9A;
    key.key[5] = 0xBC;
    key.key[6] = 0xDE;
    key.key[7] = 0xFF;

    FILE *fp = fopen("my_secret_file.txt", "r");
    encrypt_file(&key, fp, 0);
    fclose(fp);

    fp = fopen("my_secret_file.txt", "r");
    encrypt_file(&key, fp, 1);
    fclose(fp);

    return 0;
}