//Falcon2-11B DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct password_t {
    char* password;
    int length;
};

struct password_t* create_password(char* password, int length) {
    struct password_t* new_password = (struct password_t*) malloc(sizeof(struct password_t));
    if (new_password == NULL) {
        perror("malloc error");
        exit(1);
    }
    new_password->password = strdup(password);
    if (new_password->password == NULL) {
        perror("strdup error");
        exit(1);
    }
    new_password->length = length;
    return new_password;
}

void print_password(struct password_t* password) {
    printf("%s\n", password->password);
}

void save_password(struct password_t* password) {
    FILE* file = fopen("passwords.txt", "a");
    if (file == NULL) {
        perror("fopen error");
        exit(1);
    }
    fprintf(file, "%s\n", password->password);
    fclose(file);
}

void delete_password(struct password_t* password) {
    free(password->password);
    free(password);
}

int main() {
    struct password_t* password = create_password("password123", 10);
    printf("New password: %s\n", password->password);
    print_password(password);
    save_password(password);
    delete_password(password);
    return 0;
}