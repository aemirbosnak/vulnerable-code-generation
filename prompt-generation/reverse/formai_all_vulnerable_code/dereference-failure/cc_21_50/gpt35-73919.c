//FormAI DATASET v1.0 Category: Password management ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_PASSWORD_LENGTH 20 /* Maximum length of password */

/* Structure to store the username and password */
struct user{
    char username[MAX_PASSWORD_LENGTH]; 
    char password[MAX_PASSWORD_LENGTH];
};

int main()
{
    int choice, i, count = 0;
    struct user *users;

    /* Dynamically allocate memory for users */
    users = (struct user*)malloc(sizeof(struct user));

    /* Loop for password management system */
    while(1)
    {
        printf("\n\n");
        printf("-----------PASSWORD MANAGEMENT SYSTEM-------------\n");
        printf("1. Create a new user account\n");
        printf("2. Display all user accounts\n");
        printf("3. Find a user account by username\n");
        printf("4. Change password of a user account\n");
        printf("5. Delete a user account\n");
        printf("6. Exit from program\n");
        printf("-------------------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: /* Create a new user account */
                    printf("\nEnter username : ");
                    scanf("%s", (users+count)->username);
                    
                    /* Password must be minimum 8 characters long */
                    printf("Enter password (min 8 characters) : ");
                    scanf("%s", (users+count)->password);
                    
                    /* Check if password is minimum 8 characters long */
                    while(strlen((users+count)->password) < 8){
                        printf("Password must be minimum 8 characters long\n");
                        printf("Enter the correct password : ");
                        scanf("%s", (users+count)->password);
                    }
                    
                    /* Increment the counter for number of users */
                    count++; 
                    /* Reallocate memory for more users */
                    users = (struct user*)realloc(users, (count+1)*sizeof(struct user));
                    break;
            
            case 2: /* Display all user accounts */
                    if(count == 0){
                        printf("\nNo users found\n");
                    }
                    else{
                        printf("\n%-20s%-20s\n", "Username", "Password");
                        for(i=0; i<count; i++){
                            printf("%-20s%-20s\n", (users+i)->username, (users+i)->password);
                        }
                    }
                    break;

            case 3: /* Find a user account by username */
                    if(count == 0){
                        printf("\nNo users found\n");
                    }
                    else{
                        char search[MAX_PASSWORD_LENGTH];
                        int flag = 0;
                        printf("\nEnter the username to search for : ");
                        scanf("%s", search);
                        for(i=0; i<count; i++){
                            if(strcmp((users+i)->username, search) == 0){
                                flag = 1;
                                printf("\n%-20s%-20s\n", "Username", "Password");
                                printf("%-20s%-20s\n", (users+i)->username, (users+i)->password);
                                break;
                            }
                        }
                        if(flag == 0){
                            printf("\nUser not found\n");
                        }
                    }
                    break;

            case 4: /* Change password of a user account */
                    if(count == 0){
                        printf("\nNo users found\n");
                    }
                    else{
                        char change[MAX_PASSWORD_LENGTH];
                        int flag = 0;
                        printf("\nEnter the username to change password : ");
                        scanf("%s", change);
                        for(i=0; i<count; i++){
                            if(strcmp((users+i)->username, change) == 0){
                                flag = 1;
                                printf("\nOld password : %s\n", (users+i)->password);
                                printf("Enter new password (min 8 characters) : ");
                                scanf("%s", (users+i)->password);
                                
                                /* Check if new password is minimum 8 characters long */
                                while(strlen((users+i)->password) < 8){
                                    printf("Password must be minimum 8 characters long\n");
                                    printf("Enter the correct password : ");
                                    scanf("%s", (users+i)->password);
                                }
                                printf("\nPassword changed successfully\n");
                                break;
                            }
                        }
                        if(flag == 0){
                            printf("\nUser not found\n");
                        }
                    }
                    break;

            case 5: /* Delete a user account */
                    if(count == 0){
                        printf("\nNo users found\n");
                    }
                    else{
                        char delete[MAX_PASSWORD_LENGTH];
                        int flag = 0;
                        printf("\nEnter the username to delete : ");
                        scanf("%s", delete);
                        for(i=0; i<count; i++){
                            if(strcmp((users+i)->username, delete) == 0){
                                flag = 1;
                                if(count == 1){ /* If only one user exists */
                                    free(users);
                                }
                                else{
                                    /* Copy the data of the last user to the deleted user */
                                    strcpy((users+i)->username, (users+count-1)->username);
                                    strcpy((users+i)->password, (users+count-1)->password);
                                    /* Reallocate memory for less users */
                                    users = (struct user*)realloc(users, (count-1)*sizeof(struct user));
                                }
                                count--;
                                printf("\nUser account deleted successfully\n");
                                break;
                            }
                        }
                        if(flag == 0){
                            printf("\nUser not found\n");
                        }
                    }
                    break;
            
            case 6: /* Exit from program */
                    free(users);
                    printf("\nExiting from program\n"); 
                    exit(0);

            default: /* Invalid choice */
                     printf("\nInvalid choice\n");
                     break;
        }
    }
    return 0;
}