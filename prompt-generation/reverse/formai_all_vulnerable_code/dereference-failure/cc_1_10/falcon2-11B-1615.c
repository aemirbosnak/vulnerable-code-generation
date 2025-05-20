//Falcon2-11B DATASET v1.0 Category: Password management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

struct password {
    char password[MAX_PASSWORD_LENGTH];
    struct password* next;
};

int main() {
    struct password* head = NULL;
    struct password* current = NULL;

    printf("Enter the number of passwords you want to store: ");
    int num_passwords;
    scanf("%d", &num_passwords);

    if (num_passwords > MAX_PASSWORDS) {
        printf("Maximum number of passwords exceeded.\n");
        return 1;
    }

    for (int i = 0; i < num_passwords; i++) {
        char password[MAX_PASSWORD_LENGTH];
        printf("Enter password %d: ", i + 1);
        fgets(password, MAX_PASSWORD_LENGTH, stdin);
        password[strcspn(password, "\n")] = 0;

        struct password* new_password = malloc(sizeof(struct password));
        strcpy(new_password->password, password);
        new_password->next = NULL;

        if (head == NULL) {
            head = new_password;
        } else {
            current = head;
            while (current->next!= NULL) {
                current = current->next;
            }
            current->next = new_password;
        }
    }

    printf("Your passwords are: ");
    current = head;
    while (current!= NULL) {
        printf("%s ", current->password);
        current = current->next;
    }
    printf("\n");

    return 0;
}