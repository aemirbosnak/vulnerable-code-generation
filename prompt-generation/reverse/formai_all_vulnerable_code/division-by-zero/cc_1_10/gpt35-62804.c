//FormAI DATASET v1.0 Category: File Encyptor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_KEY_LENGTH 32

void encrypt_file(char *filename, char *key);
void decrypt_file(char *filename, char *key);

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char key[MAX_KEY_LENGTH];
    int choice;

    printf("Welcome to the file encryptor!\n");

    while(1) {
        printf("\nPlease choose an option:\n");
        printf("1. Encrypt a file\n");
        printf("2. Decrypt a file\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the filename to encrypt: ");
                scanf("%s", filename);
                printf("Enter the key: ");
                scanf("%s", key);
                encrypt_file(filename, key);
                break;
            case 2:
                printf("Enter the filename to decrypt: ");
                scanf("%s", filename);
                printf("Enter the key: ");
                scanf("%s", key);
                decrypt_file(filename, key);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}

void encrypt_file(char *filename, char *key) {
    FILE *fp_in, *fp_out;
    char ch;
    int key_index = 0;

    fp_in = fopen(filename, "r");
    if(fp_in == NULL) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char out_filename[MAX_FILENAME_LENGTH+5];
    sprintf(out_filename, "%s.enc", filename);
    fp_out = fopen(out_filename, "w");

    while((ch = fgetc(fp_in)) != EOF) {
        ch ^= key[key_index];
        fprintf(fp_out, "%c", ch);
        key_index = (key_index + 1) % strlen(key);
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("File %s encrypted and saved to %s\n", filename, out_filename);
}

void decrypt_file(char *filename, char *key) {
    FILE *fp_in, *fp_out;
    char ch;
    int key_index = 0;

    fp_in = fopen(filename, "r");
    if(fp_in == NULL) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char out_filename[MAX_FILENAME_LENGTH-4];
    strncpy(out_filename, filename, strlen(filename)-4);
    out_filename[strlen(filename)-4] = '\0';

    fp_out = fopen(out_filename, "w");

    while((ch = fgetc(fp_in)) != EOF) {
        ch ^= key[key_index];
        fprintf(fp_out, "%c", ch);
        key_index = (key_index + 1) % strlen(key);
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("File %s decrypted and saved to %s\n", filename, out_filename);
}