//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to store password information
struct password {
    char *username;
    char *password;
    int age;
};

// Function to generate a random password
void generate_password(struct password *password) {
    int len = 10; // password length
    char pass[len];
    for (int i = 0; i < len; i++) {
        pass[i] = 'a' + (rand() % 26);
    }
    password->password = pass;
}

// Function to check if a password is valid
int check_password(struct password *password, char *input) {
    int len = strlen(password->password);
    if (len != strlen(input)) {
        return 0; // passwords don't match
    }
    for (int i = 0; i < len; i++) {
        if (password->password[i] != input[i]) {
            return 0; // passwords don't match
        }
    }
    return 1; // passwords match
}

// Function to store and retrieve passwords
void store_password(struct password *password, char *username) {
    password->username = username;
    generate_password(password);
    // save password in a file
    FILE *fp = fopen("passwords.dat", "w");
    fprintf(fp, "%s:%s:%d\n", username, password->password, password->age);
    fclose(fp);
}

struct password *get_password(char *username) {
    struct password password;
    // read password from file
    FILE *fp = fopen("passwords.dat", "r");
    char line[100];
    fgets(line, 100, fp);
    sscanf(line, "%s:%s:%d", username, password.password, &password.age);
    fclose(fp);
    return &password;
}

int main() {
    struct password password;
    store_password(&password, "john");
    store_password(&password, "jane");

    // retrieve passwords
    struct password *john = get_password("john");
    struct password *jane = get_password("jane");

    // check if passwords are valid
    if (check_password(john, "hello")) {
        printf("John's password is correct!\n");
    } else {
        printf("John's password is incorrect.\n");
    }

    if (check_password(jane, "world")) {
        printf("Jane's password is correct!\n");
    } else {
        printf("Jane's password is incorrect.\n");
    }

    // change passwords
    generate_password(&password);
    store_password(&password, "john");
    store_password(&password, "jane");

    return 0;
}