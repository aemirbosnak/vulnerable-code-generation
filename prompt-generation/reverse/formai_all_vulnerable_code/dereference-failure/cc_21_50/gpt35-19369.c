//FormAI DATASET v1.0 Category: Password management ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PASSWORD_LENGTH 30 // maximum length of a password
#define MAX_USERNAME_LENGTH 20 // maximum length of a username


typedef struct{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
}Account;


// You can add more functions if you want

int main()
{
    int num_of_accounts = 0; // total number of accounts in the system
    int choice = 0; // user's choice
    FILE* file_ptr = NULL; // pointer to file where data is stored
    char filename[] = "passwords.txt"; // file name where data is stored

    // Open the file, if it exists, in read mode
    file_ptr = fopen(filename, "r");
    
    // if file does not exist, it will be created!
    if(file_ptr == NULL)
    {
        printf("%s file does not exist. A new file will be created.\n", filename);
        file_ptr = fopen(filename, "w"); // open the file in write mode to create it
        if(file_ptr == NULL)
        {
            printf("Error: Could not create the file.\n");
            exit(1);
        }
    }
    else
    {
        // count the number of accounts in the file, then allocate memory to store the accounts
        char line[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH];
        while(fgets(line, MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH, file_ptr) != NULL)
        {
            num_of_accounts++;
        }
    }

    // Now we know the number of accounts, so we can allocate memory for them
    Account* accounts = (Account*) malloc(num_of_accounts * sizeof(Account));
    if(accounts == NULL)
    {
        printf("Error: Could not allocate memory for accounts.\n");
        exit(1);
    }

    
    
    // Read the data from the file and store it in the array
    printf("Reading data from %s...\n", filename);
    fseek(file_ptr, 0, SEEK_SET); // move cursor to start of file
    
    for(int i=0; i<num_of_accounts; i++)
    {
        char* username = accounts[i].username;
        char* password = accounts[i].password;

        fscanf(file_ptr, "%s %s", username, password);
    }

    fclose(file_ptr); // close the file
    
    

    // Main menu loop
    do
    {
        printf("What do you want to do?\n");
        printf("1) Add a new account\n");
        printf("2) Delete an account\n");
        printf("3) Change a password\n");
        printf("4) Show all accounts\n");
        printf("5) Exit\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1: // Add a new account
            {
                Account new_account;
                printf("Enter the username: ");
                scanf("%s", new_account.username);
                printf("Enter the password: ");
                scanf("%s", new_account.password);

                // Check if the username already exists
                int username_exists = 0;
                for(int i=0; i<num_of_accounts; i++)
                {
                    if(strcmp(accounts[i].username, new_account.username) == 0)
                    {
                        username_exists = 1;
                        break;
                    }
                }

                if(username_exists == 1)
                {
                    printf("Error: Username already exists in the system.\n");
                }
                else
                {
                    // Add the new account to the array
                    accounts = (Account*) realloc(accounts, (num_of_accounts + 1) * sizeof(Account));
                    if(accounts == NULL)
                    {
                        printf("Error: Could not reallocate memory for accounts.\n");
                        exit(1);
                    }

                    accounts[num_of_accounts] = new_account;
                    num_of_accounts++;

                    printf("New account added successfully!\n");

                    // Save the data to the file
                    file_ptr = fopen(filename, "a"); // open the file in append mode
                    fprintf(file_ptr, "%s %s\n", new_account.username, new_account.password);
                    fclose(file_ptr); // close the file
                }

                break;
            }
            case 2: // Delete an account
            {
                char username[MAX_USERNAME_LENGTH];
                printf("Enter the username of the account you want to delete: ");
                scanf("%s", username);

                // Search for the account with the given username
                int account_index = -1;
                for(int i=0; i<num_of_accounts; i++)
                {
                    if(strcmp(accounts[i].username, username) == 0)
                    {
                        account_index = i;
                        break;
                    }
                }

                if(account_index == -1)
                {
                    printf("Error: Account with username %s not found.\n", username);
                }
                else
                {
                    // Delete the account from the array
                    for(int i=account_index; i<num_of_accounts-1; i++)
                    {
                        accounts[i] = accounts[i+1];
                    }
                    num_of_accounts--;

                    printf("Account %s deleted successfully!\n", username);

                    // Overwrite the data in the file (since we cannot delete a line from the file)
                    file_ptr = fopen(filename, "w"); // open the file in write mode
                    for(int i=0; i<num_of_accounts; i++)
                    {
                        fprintf(file_ptr, "%s %s\n", accounts[i].username, accounts[i].password);
                    }
                    fclose(file_ptr); // close the file
                }

                break;
            }
            case 3: // Change a password
            {
                char username[MAX_USERNAME_LENGTH];
                printf("Enter the username of the account whose password you want to change: ");
                scanf("%s", username);

                // Search for the account with the given username
                int account_index = -1;
                for(int i=0; i<num_of_accounts; i++)
                {
                    if(strcmp(accounts[i].username, username) == 0)
                    {
                        account_index = i;
                        break;
                    }
                }

                if(account_index == -1)
                {
                    printf("Error: Account with username %s not found.\n", username);
                }
                else
                {
                    printf("Enter the new password: ");
                    scanf("%s", accounts[account_index].password);

                    printf("Password changed successfully for account %s.\n", username);

                    // Overwrite the data in the file
                    file_ptr = fopen(filename, "w"); // open the file in write mode
                    for(int i=0; i<num_of_accounts; i++)
                    {
                        fprintf(file_ptr, "%s %s\n", accounts[i].username, accounts[i].password);
                    }
                    fclose(file_ptr); // close the file
                }

                break;
            }
            case 4: // Show all accounts
            {
                printf("Number of accounts: %d\n", num_of_accounts);
                for(int i=0; i<num_of_accounts; i++)
                {
                    printf("%s %s\n", accounts[i].username, accounts[i].password);
                }

                break;
            }
            case 5: // Exit
            {
                printf("Exiting...\n");
                break;
            }
            default: // Invalid choice
            {
                printf("Error: Invalid choice.\n");
                break;
            }
        }
    } while(choice != 5);


    free(accounts);

    return 0;
}