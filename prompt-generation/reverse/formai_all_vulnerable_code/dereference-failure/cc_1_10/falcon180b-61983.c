//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <crypt.h>

void generate_salt(char* salt) {
    int i;
    for (i = 0; i < 8; i++) {
        salt[i] = (char) rand() % 62 + 'A';
    }
    salt[8] = '\0';
}

int main() {
    char filename[100];
    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long int filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*) malloc(filesize + 1);
    fread(buffer, filesize, 1, file);
    fclose(file);

    char salt[9];
    generate_salt(salt);

    char* encrypted_buffer = (char*) malloc(filesize + 1);
    memset(encrypted_buffer, 0, filesize + 1);

    int i = 0;
    while (i < filesize) {
        char c = tolower(buffer[i]);
        if (isalpha(c)) {
            c = (c - 97 + 13) % 26 + 97;
        }
        encrypted_buffer[i] = c;
        i++;
    }

    char* encrypted_file = (char*) malloc(strlen(filename) + 5);
    strcpy(encrypted_file, filename);
    strcat(encrypted_file, ".enc");

    FILE* encrypted_file_ptr = fopen(encrypted_file, "w");
    if (encrypted_file_ptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(encrypted_file_ptr, "%s\n", salt);
    fwrite(encrypted_buffer, filesize, 1, encrypted_file_ptr);
    fclose(encrypted_file_ptr);

    printf("File encrypted successfully.\n");
    return 0;
}