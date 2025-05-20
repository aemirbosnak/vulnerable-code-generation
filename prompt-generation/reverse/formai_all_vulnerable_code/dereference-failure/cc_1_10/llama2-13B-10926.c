//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 5

struct password {
    char *name;
    char *password;
};

int main() {
    struct password passwords[MAX_PASSWORDS];
    int i, j;

    // Initialize passwords
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = "Love";
        passwords[i].password = "123456";
    }

    // Add new passwords
    printf("Enter your love's name: ");
    scanf("%s", &passwords[0].name);
    printf("Enter your love's password: ");
    scanf("%s", &passwords[0].password);

    for (i = 1; i < MAX_PASSWORDS; i++) {
        printf("Add another love? (y/n): ");
        scanf(" %c", &j);
        if (j == 'y') {
            printf("Enter your love's name: ");
            scanf("%s", &passwords[i].name);
            printf("Enter your love's password: ");
            scanf("%s", &passwords[i].password);
        }
    }

    // Check passwords
    for (i = 0; i < MAX_PASSWORDS; i++) {
        printf("My love, do you remember our password? ");
        if (strcmp(passwords[i].password, "123456") == 0) {
            printf("You remembered! 😍\n");
        } else {
            printf("Oh no! 😔 It seems you forgot our password...\n");
        }
    }

    return 0;
}