//FormAI DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PASSWORD_LENGTH 16

char* generate_password();
void encrypt_password(char* password);
void decrypt_password(char* password);

int main() {
    char* password = generate_password();
    printf("Password generated: %s\n",password);
    encrypt_password(password);
    printf("Password encrypted: %s\n",password);
    decrypt_password(password);
    printf("Password decrypted: %s\n",password);
    free(password);
    return 0;
}

char* generate_password() {
    char* password = (char*) malloc(sizeof(char) * PASSWORD_LENGTH);
    int upper = 65; // ASCII code for 'A'
    int lower = 97; // ASCII code for 'a'
    int digit = 48; // ASCII code for '0'
    for (int i=0; i<PASSWORD_LENGTH; i++) {
        int type = rand()%3;
        if (type == 0) { // uppercase letter
            password[i] = (char) (upper + rand()%26);
        } else if (type == 1) { // lowercase letter
            password[i] = (char) (lower + rand()%26);
        } else { // digit
            password[i] = (char) (digit + rand()%10);
        }
    }
    return password;
}

void encrypt_password(char* password) {
    int length = strlen(password);
    for (int i=0; i<length; i++) {
        password[i] = password[i] + (char) pow(-1,i+1);
    }
}

void decrypt_password(char* password) {
    int length = strlen(password);
    for (int i=0; i<length; i++) {
        password[i] = password[i] - (char) pow(-1,i+1);
    }
}