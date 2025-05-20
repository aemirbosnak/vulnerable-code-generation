//FormAI DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
/*Enter Romeo*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Password {
    char service[30];
    char username[20];
    char password[30];
};

int main() {
    int choice, i, j, k;
    int flag = 0;
    char option;
    char master_password[30], confirm_password[30];
    struct Password passwords[50];
    FILE *f;

    printf("\nOh sweet Juliet, what's your choice?\n");
    printf("Enter '1' to create a new password and '2' to view all passwords: ");
    scanf("%d", &choice);
    printf("\n");

    switch(choice) {
        case 1:
            printf("Gentle Romeo, please enter your master password: ");
            scanf("%s", master_password);
            printf("\n");

            printf("Romeo, please confirm your master password: ");
            scanf("%s", confirm_password);
            printf("\n");

            if(strcmp(master_password, confirm_password) == 0) {
                printf("A match made in heaven! Password approved! Onward, Romeo!\n\n");
                flag = 1;
            }
            else {
                printf("These passwords do not match. A poisoned chalice indeed.\n\n");
                flag = 0;
            }

            if(flag == 1) {
                f = fopen("passwords.txt", "a");

                printf("Seductive Romeo, please enter the service name: ");
                scanf("%s", passwords[i].service);
                printf("\n");

                printf("Intense Romeo, please enter the username: ");
                scanf("%s", passwords[i].username);
                printf("\n");

                printf("Dear Romeo, please enter the password: ");
                scanf("%s", passwords[i].password);
                printf("\n");

                fprintf(f, "%s %s %s\n", passwords[i].service, passwords[i].username, passwords[i].password);
                printf("A love letter with %s, %s, %s written on it has been saved into your heart, Romeo.\n\n", passwords[i].service, passwords[i].username, passwords[i].password);

                fclose(f);
            }
            else {
                printf("Alack, Romeo. You must go back and try again.\n\n");
            }
            break;

        case 2:
            printf("Juliet, please enter the master password: ");
            scanf("%s", master_password);
            printf("\n");

            f = fopen("passwords.txt", "r");
            if(f == NULL) {
                printf("There are no passwords saved in the heart of Romeo.\n\n");
            }
            else {
                while(fscanf(f, "%s %s %s", passwords[i].service, passwords[i].username, passwords[i].password) != EOF) {
                    if(strcmp(master_password, passwords[i].password) == 0) {

                        printf("A vault has been found in Romeo's heart: %s %s %s\n\n", passwords[i].service, passwords[i].username, passwords[i].password);
                    }
                    else {
                        printf("The password to unlock this heart is not the key. Too bad, so sad, Juliet.\n\n");
                    }
                }

                fclose(f);
            }
            break;

        default:
            printf("The moon hath gone down, Romeo. An error has occurred.\n\n");
            break;
    }

    printf("Would you, sweet Juliet, like to try again? (y/n) ");
    scanf(" %c", &option);
    printf("\n");

    if(toupper(option) == 'Y') {
        main();
    }
    else {
        printf("Goodnight, my sweet.\n\n");
    }

    return 0;
}
/*Exeunt*/