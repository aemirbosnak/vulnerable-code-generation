//Falcon2-11B DATASET v1.0 Category: Password management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random password
char* generate_password(int length) {
    static char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char* password = (char*) malloc(length + 1);
    password[length] = '\0';
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        password[i] = chars[rand() % (sizeof(chars) - 1)];
    }
    return password;
}

// Function to store a password
void store_password(char* password, char* username) {
    FILE* fp = fopen("passwords.txt", "a");
    fprintf(fp, "%s\n", password);
    fclose(fp);
}

// Function to retrieve a password
char* retrieve_password(char* username) {
    FILE* fp = fopen("passwords.txt", "r");
    char* password = (char*) malloc(sizeof(char) * 8);
    char* line = (char*) malloc(sizeof(char) * 8);
    while (fgets(line, sizeof(char) * 8, fp)!= NULL) {
        if (strstr(line, username)) {
            strcpy(password, line);
            break;
        }
    }
    fclose(fp);
    return password;
}

// Function to delete a password
void delete_password(char* username) {
    FILE* fp = fopen("passwords.txt", "r+");
    char* line = (char*) malloc(sizeof(char) * 8);
    while (fgets(line, sizeof(char) * 8, fp)!= NULL) {
        if (strstr(line, username)) {
            fseek(fp, 0, SEEK_SET);
            fputs(line, fp);
            break;
        }
    }
    fclose(fp);
}

int main() {
    char* password = generate_password(8);
    printf("Your password is: %s\n", password);
    char* username = "JohnDoe";
    store_password(password, username);
    char* retrieved_password = retrieve_password(username);
    printf("Retrieved password: %s\n", retrieved_password);
    delete_password(username);
    return 0;
}