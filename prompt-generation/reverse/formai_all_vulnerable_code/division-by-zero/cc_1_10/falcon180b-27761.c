//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length;
    char *password;
    int i;
    int uppercase = 0;
    int lowercase = 0;
    int numbers = 0;
    int symbols = 0;

    printf("Enter password length: ");
    scanf("%d", &length);

    srand(time(NULL));
    password = (char *)malloc(length + 1);

    for (i = 0; i < length; i++) {
        if (rand() % 4 == 0) {
            password[i] = 'A' + rand() % 26;
            uppercase = 1;
        } else if (rand() % 4 == 1) {
            password[i] = 'a' + rand() % 26;
            lowercase = 1;
        } else if (rand() % 4 == 2) {
            password[i] = '0' + rand() % 10;
            numbers = 1;
        } else {
            password[i] = "!@#$%^&*()_+-="[rand() % 16];
            symbols = 1;
        }
    }

    if (!uppercase) {
        password[rand() % length] = 'A' + rand() % 26;
        uppercase = 1;
    }

    if (!lowercase) {
        password[rand() % length] = 'a' + rand() % 26;
        lowercase = 1;
    }

    if (!numbers) {
        password[rand() % length] = '0' + rand() % 10;
        numbers = 1;
    }

    if (!symbols) {
        password[rand() % length] = "!@#$%^&*()_+-="[rand() % 16];
        symbols = 1;
    }

    printf("Generated password: %s\n", password);

    free(password);
    return 0;
}