//Falcon2-11B DATASET v1.0 Category: Password management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

char* hashPassword(const char* password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);

    char* hashString = (char*) malloc(SHA256_DIGEST_LENGTH * sizeof(char));
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hashString[i * 2], "%02x", hash[i]);
    }
    return hashString;
}

void storePassword(char* password, char* hashString) {
    // Store password and hash in a secure way (e.g., on disk)
    FILE* file = fopen("passwords.txt", "a");
    if (file!= NULL) {
        fprintf(file, "%s %s\n", password, hashString);
        fclose(file);
    }
}

void retrievePassword(char* hashString) {
    // Retrieve password from stored hash
    FILE* file = fopen("passwords.txt", "r");
    if (file!= NULL) {
        char* line;
        while ((line = fgets(line, sizeof(line), file))!= NULL) {
            char* password = strtok(line, " ");
            char* hash = strtok(NULL, " ");
            if (strcmp(hash, hashString) == 0) {
                printf("Password: %s\n", password);
                break;
            }
        }
        fclose(file);
    }
}

int main() {
    char* password;
    char* hashString;

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    hashString = hashPassword(password);
    storePassword(password, hashString);

    printf("Hash: %s\n", hashString);

    printf("Enter hash to retrieve password: ");
    fgets(hashString, sizeof(hashString), stdin);
    hashString[strcspn(hashString, "\n")] = '\0';

    retrievePassword(hashString);

    return 0;
}