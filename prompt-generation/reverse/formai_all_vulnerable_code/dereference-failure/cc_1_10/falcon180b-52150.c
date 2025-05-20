//Falcon-180B DATASET v1.0 Category: Password management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    int num_passwords = 0;
    Password passwords[MAX_PASSWORDS];
    FILE *passwords_file;
    char line[100];
    char *token;

    passwords_file = fopen("passwords.txt", "r");
    if (passwords_file == NULL) {
        printf("No passwords found.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), passwords_file)!= NULL) {
        token = strtok(line, ",");
        strcpy(passwords[num_passwords].username, token);
        token = strtok(NULL, ",");
        strcpy(passwords[num_passwords].password, token);
        num_passwords++;
    }

    fclose(passwords_file);

    printf("Enter a username: ");
    scanf("%s", passwords[0].username);

    printf("Enter a password: ");
    scanf("%s", passwords[0].password);

    passwords_file = fopen("passwords.txt", "w");
    if (passwords_file == NULL) {
        printf("Error writing to file.\n");
        return 1;
    }

    for (int i = 0; i < num_passwords; i++) {
        fprintf(passwords_file, "%s,%s\n", passwords[i].username, passwords[i].password);
    }

    fclose(passwords_file);

    printf("Password saved.\n");

    return 0;
}