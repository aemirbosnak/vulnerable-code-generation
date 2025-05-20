//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *keygen(int len) {
    char *key = malloc(len + 1);
    for (int i = 0; i < len; i++) { key[i] = rand() % 256; }
    key[len] = '\0';
    return key;
}

char *encrypt(char *plaintext, char *key) {
    int pt_len = strlen(plaintext);
    int key_len = strlen(key);
    char *ciphertext = malloc(pt_len + 1);
    for (int i = 0; i < pt_len; i++) { ciphertext[i] = plaintext[i] ^ key[i % key_len]; }
    ciphertext[pt_len] = '\0';
    return ciphertext;
}

char *decrypt(char *ciphertext, char *key) {
    int ct_len = strlen(ciphertext);
    int key_len = strlen(key);
    char *plaintext = malloc(ct_len + 1);
    for (int i = 0; i < ct_len; i++) { plaintext[i] = ciphertext[i] ^ key[i % key_len]; }
    plaintext[ct_len] = '\0';
    return plaintext;
}

void print_usage() {
    printf("Usage: encrypt [-k key_file] plaintext\n");
    printf("Usage: decrypt [-k key_file] ciphertext\n");
    printf("Options:\n");
    printf("  -k key_file   Use the specified key file.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) { print_usage(); return 1; }

    char *key_file = NULL;
    char *plaintext = NULL;
    char *ciphertext = NULL;
    char *key = NULL;

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-k")) {
            if (++i >= argc) { print_usage(); return 1; }
            key_file = argv[i];
        } else {
            if (plaintext) { ciphertext = argv[i]; }
            else { plaintext = argv[i]; }
        }
    }

    if (!key_file) { key = keygen(16); }
    else {
        FILE *fp = fopen(key_file, "r");
        if (!fp) { perror("fopen"); return 1; }
        fseek(fp, 0, SEEK_END);
        int key_len = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        key = malloc(key_len + 1);
        fread(key, 1, key_len, fp);
        key[key_len] = '\0';
        fclose(fp);
    }

    if (ciphertext) { plaintext = decrypt(ciphertext, key); }
    else { ciphertext = encrypt(plaintext, key); }

    printf("%s\n", ciphertext ? ciphertext : plaintext);
    return 0;
}