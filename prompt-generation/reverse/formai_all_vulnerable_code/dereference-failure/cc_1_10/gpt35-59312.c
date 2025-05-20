//FormAI DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to clear the input buffer
void clear_input_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

//Function to check if password is strong
int is_password_strong(char password[]) {
    int has_uppercase = 0, has_lowercase = 0, has_digit = 0;
    int len = strlen(password);

    for (int i = 0; i < len; i++) {
        if ((password[i] >= 'A' && password[i] <= 'Z')) {
            has_uppercase = 1;
        }
        if ((password[i] >= 'a' && password[i] <= 'z')) {
            has_lowercase = 1;
        }
        if ((password[i] >= '0' && password[i] <= '9')) {
            has_digit = 1;
        }
    }

    return (has_uppercase && has_lowercase && has_digit && (len >= 8));
}

int main() {
    char master_password[50], password[50], c;
    int choice, num_accounts = 0;
    char *accounts[50];
    char *passwords[50];

    printf("Welcome to Sherlock Holmes Password Manager!\n");

    //Prompting user to enter master password
    printf("\nPlease enter your master password: ");
    scanf("%s", master_password);
    clear_input_buffer();

    //Loop to ask user for input until correct master password is entered
    while (1) {
        //Prompting user to choose an option
        printf("\nPlease choose an option below:\n");
        printf("1. Add an account\n");
        printf("2. Print all accounts\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        //Switch case for each option
        switch (choice) {
            case 1:
                //Prompting user to enter account name
                printf("\nEnter the account name: ");
                accounts[num_accounts] = malloc(sizeof(char) * 50);
                scanf("%s", accounts[num_accounts]);
                clear_input_buffer();

                //Prompting user to enter password
                printf("Enter the password: ");
                while ((c = getchar()) != '\n' && c != EOF) {
                    password[strlen(password)] = c;
                }
                passwords[num_accounts] = malloc(sizeof(char) * 50);
                strcpy(passwords[num_accounts], password);

                //Checking if password is strong
                if (!is_password_strong(passwords[num_accounts])) {
                    printf("Warning: The password for %s is weak!\n", accounts[num_accounts]);
                }

                num_accounts++;
                break;

            case 2:
                //Printing all accounts and passwords
                printf("\nAll your accounts:\n");
                for (int i = 0; i < num_accounts; i++) {
                    printf("%d. %s\n", i + 1, accounts[i]);
                    printf("   Password: %s\n", passwords[i]);
                }
                break;

            case 3:
                //Freeing memory allocated to accounts and passwords
                for (int i = 0; i < num_accounts; i++) {
                    free(accounts[i]);
                    free(passwords[i]);
                }
                printf("\nGoodbye!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice, try again!\n");
        }
    }

    return 0;
}