//GEMINI-pro DATASET v1.0 Category: Password management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct password {
    char *service;
    char *username;
    char *password;
} password_t;

password_t *create_password(char *service, char *username, char *password) {
    password_t *new_password = malloc(sizeof(password_t));
    new_password->service = strdup(service);
    new_password->username = strdup(username);
    new_password->password = strdup(password);
    return new_password;
}

void free_password(password_t *password) {
    free(password->service);
    free(password->username);
    free(password->password);
    free(password);
}

void save_password(password_t *password) {
    FILE *fp = fopen("passwords.txt", "a");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    fprintf(fp, "%s:%s:%s\n", password->service, password->username, password->password);
    fclose(fp);
}

password_t *load_password(char *service, char *username) {
    FILE *fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        char *service_line = strtok(line, ":");
        char *username_line = strtok(NULL, ":");
        char *password_line = strtok(NULL, "\n");

        if (strcmp(service_line, service) == 0 && strcmp(username_line, username) == 0) {
            password_t *password = create_password(service, username, password_line);
            fclose(fp);
            return password;
        }
    }

    fclose(fp);
    return NULL;
}

int main() {
    password_t *password = create_password("gmail", "example@gmail.com", "password");
    save_password(password);
    free_password(password);

    password = load_password("gmail", "example@gmail.com");
    printf("Service: %s\n", password->service);
    printf("Username: %s\n", password->username);
    printf("Password: %s\n", password->password);
    free_password(password);

    return 0;
}