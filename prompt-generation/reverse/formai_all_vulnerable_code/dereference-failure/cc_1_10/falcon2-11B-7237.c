//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char username[50];
    char password[50];
}User;

int main(){
    User user;
    char* command;
    char email[100];
    char* recipient[10];
    char* subject[10];
    char* body[1000];
    char* attachments[10];
    char* folder[10];

    printf("Welcome to C Email Client!\n");
    printf("Please enter your username: ");
    scanf("%s", user.username);

    printf("Please enter your password: ");
    scanf("%s", user.password);

    while(1){
        printf("What would you like to do? \n\n");
        printf("1. Send an email\n");
        printf("2. Read an email\n");
        printf("3. Delete an email\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%s", &command);

        if(strcmp(command, "1") == 0){
            printf("Please enter the recipient's email address: ");
            scanf("%s", email);

            printf("Please enter the subject: ");
            scanf("%s", subject);

            printf("Please enter the body: ");
            scanf("%s", body);

            printf("Please enter the attachments: ");
            scanf("%s", attachments);

            printf("Please enter the folder: ");
            scanf("%s", folder);

            printf("Email sent successfully!\n");
        }
        else if(strcmp(command, "2") == 0){
            printf("Please enter the email address: ");
            scanf("%s", email);

            printf("Email opened successfully!\n");
        }
        else if(strcmp(command, "3") == 0){
            printf("Please enter the email address: ");
            scanf("%s", email);

            printf("Email deleted successfully!\n");
        }
        else if(strcmp(command, "4") == 0){
            printf("Exiting C Email Client...\n");
            break;
        }
        else{
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}