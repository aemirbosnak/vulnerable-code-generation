//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length = 0;
    char *password = NULL;
    int i = 0;
    int choice = 0;
    srand(time(NULL));

    printf("Password Generator\n");
    printf("=================\n");
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    password = (char *) malloc(length * sizeof(char));

    printf("Password should contain:\n");
    printf("1. Uppercase letters\n");
    printf("2. Lowercase letters\n");
    printf("3. Digits\n");
    printf("4. Special characters\n");

    printf("Choose the type of characters: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (i = 0; i < length; i++) {
                password[i] = rand() % 26 + 'A';
            }
            break;
        case 2:
            for (i = 0; i < length; i++) {
                password[i] = rand() % 26 + 'a';
            }
            break;
        case 3:
            for (i = 0; i < length; i++) {
                password[i] = rand() % 10 + '0';
            }
            break;
        case 4:
            for (i = 0; i < length; i++) {
                password[i] = rand() % 16 + '!';
            }
            break;
        default:
            printf("Invalid choice!\n");
            exit(1);
    }

    printf("Password: %s\n", password);
    return 0;
}