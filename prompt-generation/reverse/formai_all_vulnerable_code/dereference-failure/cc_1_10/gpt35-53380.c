//FormAI DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <openssl/evp.h>

// Constants
#define MAX_PASSWORD_LENGTH 32
#define MAX_USERNAME_LENGTH 16
#define MAX_INPUT_LENGTH 256

// Data structure for holding password information
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_entry;

// Function declarations
void menu();
void add_password();
void view_passwords();
void authenticate();

// Global variables
password_entry *passwords;
int num_passwords = 0;

// Encryption key and salt for the encrypted password file
unsigned char *key = "myPassword";
unsigned char *salt = "mySalt";

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("Password Manager\n");
        printf("-----------------\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Authenticate\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                authenticate();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Choice. Try Again.\n");
                break;
        }
    } while (choice != 4);
}

void add_password() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    if (strlen(username) > MAX_USERNAME_LENGTH || strlen(password) > MAX_PASSWORD_LENGTH) {
        printf("Invalid username or password length.\n");
        return;
    }
    // Add new password entry to the array and increment count
    strncpy(passwords[num_passwords].username, username, MAX_USERNAME_LENGTH);
    strncpy(passwords[num_passwords].password, password, MAX_PASSWORD_LENGTH);
    num_passwords++;
    printf("Password added successfully.\n");
}

void view_passwords() {
    printf("Passwords\n");
    printf("---------\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

void authenticate() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    if (strlen(username) > MAX_USERNAME_LENGTH || strlen(password) > MAX_PASSWORD_LENGTH) {
        printf("Invalid username or password length.\n");
        return;
    }
    // Open and decrypt password file
    FILE *fp = fopen("passwords.dat", "rb");
    if (fp == NULL) {
        printf("Unable to open passwords file.\n");
        return;
    }
    // Read file size and allocate memory for encrypted data
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    unsigned char *encrypted_data = malloc(file_size);
    // Read encrypted data from file
    fread(encrypted_data, 1, file_size, fp);
    fclose(fp);
    // Set up decryption context
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, salt);
    // Allocate memory for decrypted data
    unsigned char *decrypted_data = malloc(file_size + EVP_CIPHER_block_size(EVP_aes_256_cbc()));
    int bytes_written;
    // Decrypt data
    EVP_DecryptUpdate(ctx, decrypted_data, &bytes_written, encrypted_data, file_size);
    int remaining_bytes;
    EVP_DecryptFinal_ex(ctx, decrypted_data + bytes_written, &remaining_bytes);
    // Clean up context
    EVP_CIPHER_CTX_free(ctx);
    // Look for matching username and password combination
    int found = 0;
    unsigned char *p = decrypted_data;
    for (int i = 0; i < num_passwords; i++) {
        if (strncmp(passwords[i].username, p, MAX_USERNAME_LENGTH) == 0 &&
            strncmp(passwords[i].password, p + MAX_USERNAME_LENGTH, MAX_PASSWORD_LENGTH) == 0) {
            found = 1;
            break;
        }
        p += MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH;
    }
    // Clean up memory
    free(encrypted_data);
    free(decrypted_data);
    if (found) {
        printf("Login successful.\n");
    } else {
        printf("Login failed.\n");
    }
}