//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <string.h>

// Function to encrypt a file using rotation cipher
void encrypt(char *fileName, int key) {
    // Open the file in read mode
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Read the contents of the file
    fseek(fp, 0, SEEK_END);
    long length = ftell(fp);
    rewind(fp);
    char buffer[length + 1];
    fread(buffer, sizeof(char), length, fp);

    // Close the file
    fclose(fp);

    // Encrypt the file
    for (int i = 0; i < length; i++) {
        if (buffer[i] >= 'a' && buffer[i] <= 'z') {
            buffer[i] += key;
            if (buffer[i] > 'z') {
                buffer[i] -= 26;
            }
        } else if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
            buffer[i] += key;
            if (buffer[i] > 'Z') {
                buffer[i] -= 26;
            }
        }
    }

    // Write the encrypted file
    fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fwrite(buffer, sizeof(char), length, fp);
    fclose(fp);
}

int main() {
    // Get file name and key value from user
    char fileName[100];
    int key;
    printf("Enter file name: ");
    scanf("%s", fileName);
    printf("Enter key value: ");
    scanf("%d", &key);

    // Encrypt the file
    encrypt(fileName, key);

    // Print a message to indicate that the file has been encrypted
    printf("File %s encrypted!\n", fileName);

    return 0;
}