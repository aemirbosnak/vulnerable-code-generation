//Falcon-180B DATASET v1.0 Category: Password management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

struct password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void generate_password(char *password, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charset_length = strlen(charset);

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_length];
    }

    password[length] = '\0';
}

int compare_passwords(const void *a, const void *b) {
    struct password *p1 = (struct password *)a;
    struct password *p2 = (struct password *)b;

    return strcmp(p1->name, p2->name);
}

int main() {
    int num_passwords;
    printf("Enter the number of passwords you want to generate: ");
    scanf("%d", &num_passwords);

    struct password passwords[num_passwords];

    for (int i = 0; i < num_passwords; i++) {
        printf("Enter the name for password %d: ", i + 1);
        scanf("%s", passwords[i].name);

        int password_length;
        printf("Enter the length of the password for %s: ", passwords[i].name);
        scanf("%d", &password_length);

        generate_password(passwords[i].password, password_length);
    }

    qsort(passwords, num_passwords, sizeof(struct password), compare_passwords);

    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }

    return 0;
}