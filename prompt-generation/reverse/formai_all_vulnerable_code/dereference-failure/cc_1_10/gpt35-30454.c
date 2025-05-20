//FormAI DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption algorithm
void encrypt(char *text, int shift) {
    int len = strlen(text);
    for(int i=0; i<len; i++) {
        if(text[i]>='a' && text[i]<='z') {
            text[i] = ((text[i] + shift - 'a') % 26) + 'a';
        } else if(text[i]>='A' && text[i]<='Z') {
            text[i] = ((text[i] + shift - 'A') % 26) + 'A';
        }
    }
}

// File Encryption function
void encrypt_file(char *filename, int shift) {
    FILE *fp = fopen(filename, "r+");
    if(fp==NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    // Calculate file size
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Read file contents into buffer
    char *buffer = (char*) malloc(size+1);
    fread(buffer, size, 1, fp);
    fclose(fp);

    // Encrypt buffer
    encrypt(buffer, shift);

    // Write encrypted contents back to file
    fp = fopen(filename, "w");
    fwrite(buffer, size, 1, fp);
    fclose(fp);

    free(buffer);
}

int main() {
    char filename[100];
    int shift;

    // Get filename and shift value from user
    printf("Enter filename to encrypt: ");
    scanf("%s", filename);
    printf("Enter shift value: ");
    scanf("%d", &shift);

    // Encrypt file
    encrypt_file(filename, shift);

    printf("File %s encrypted successfully.\n", filename);
    return 0;
}