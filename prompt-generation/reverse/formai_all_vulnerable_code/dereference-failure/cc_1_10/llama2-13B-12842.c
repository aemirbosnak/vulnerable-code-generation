//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PASSWORD_MAX_LENGTH 20
#define CHAR_ARRAY_SIZE 10

typedef struct {
    char *password;
    int length;
} password_t;

password_t passwords[CHAR_ARRAY_SIZE];
int current_password = 0;

void generate_password(void) {
    int i, j;
    char c;

    for (i = 0; i < PASSWORD_MAX_LENGTH; i++) {
        c = 'a' + (rand() % 26);
        passwords[current_password].password[i] = c;
    }

    passwords[current_password].length = i;
    current_password++;
}

void print_password(void) {
    int i;

    printf("Password: ");
    for (i = 0; i < passwords[current_password - 1].length; i++) {
        printf("%c", passwords[current_password - 1].password[i]);
    }
    printf("\n");
}

int main(void) {
    generate_password();
    print_password();

    int choice;
    do {
        printf("Choose an option (1 for generate, 2 for print, 3 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generate_password();
                break;
            case 2:
                print_password();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid input! Try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}