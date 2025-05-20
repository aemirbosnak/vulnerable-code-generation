//Falcon2-11B DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PASSWORD_LENGTH 16

char* generate_password() {
    char* password = (char*)malloc(PASSWORD_LENGTH * sizeof(char));
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = 'a' + rand() % 26;
    }
    return password;
}

void print_password(char* password) {
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        printf("%c", password[i]);
    }
}

void save_password(char* password, char* username) {
    FILE* fp = fopen("passwords.txt", "a");
    if (fp!= NULL) {
        fprintf(fp, "%s %s\n", username, password);
        fclose(fp);
    } else {
        printf("Error opening file\n");
    }
}

void load_passwords() {
    FILE* fp = fopen("passwords.txt", "r");
    if (fp!= NULL) {
        char username[32];
        char password[32];
        while (fscanf(fp, "%s %s", username, password) == 2) {
            printf("Username: %s\n", username);
            printf("Password: %s\n", password);
        }
        fclose(fp);
    } else {
        printf("Error opening file\n");
    }
}

int main() {
    char* password = generate_password();
    print_password(password);
    printf("\n");

    char username[32];
    printf("Enter username: ");
    scanf("%s", username);
    save_password(password, username);

    printf("Password saved for %s\n", username);
    printf("Type '1' to load passwords, '2' to generate new password\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        load_passwords();
    } else if (choice == 2) {
        password = generate_password();
        print_password(password);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}