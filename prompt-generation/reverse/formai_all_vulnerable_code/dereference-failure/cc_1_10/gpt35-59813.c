//FormAI DATASET v1.0 Category: Password management ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to add a new password
void addPassword(char *username, char *password, char **usernameArr, char **passwordArr, int *size)
{
    // Reallocating memory to increase size of arrays
    *size += 1;
    usernameArr = (char **)realloc(usernameArr, (*size) * sizeof(char *));
    passwordArr = (char **)realloc(passwordArr, (*size) * sizeof(char *));
    usernameArr[*size - 1] = (char *)malloc(strlen(username) * sizeof(char));
    passwordArr[*size - 1] = (char *)malloc(strlen(password) * sizeof(char));

    // Copying username and password to the arrays
    strcpy(usernameArr[*size - 1], username);
    strcpy(passwordArr[*size - 1], password);

    // Printing confirmation message
    printf("\nNew password added successfully!\n");
}

// Function to display all passwords
void displayAllPasswords(char **usernameArr, char **passwordArr, int size)
{
    // Checking if any passwords are stored
    if(size == 0)
    {
        printf("\nNo passwords stored yet!\n");
        return;
    }

    // Displaying all passwords
    printf("\nAll saved passwords:\n");
    for(int i=0; i<size; i++)
    {
        printf("Username: %s   Password: %s\n", usernameArr[i], passwordArr[i]);
    }
}

// Function to check if given username exists in the array
int checkIfUsernameExists(char *username, char **usernameArr, int size)
{
    // Checking if any passwords are stored
    if(size == 0)
    {
        return 0;
    }

    // Checking all usernames in the array
    for(int i=0; i<size; i++)
    {
        if(strcmp(usernameArr[i], username) == 0)
        {
            // Username exists
            return 1;
        }
    }

    // Username does not exist
    return 0;
}

// Function to search for a specific password based on username
void searchPassword(char *username, char **usernameArr, char **passwordArr, int size)
{
    // Checking if any passwords are stored
    if(size == 0)
    {
        printf("\nNo passwords stored yet!\n");
        return;
    }

    // Checking if given username exists in the array
    if(checkIfUsernameExists(username, usernameArr, size) == 0)
    {
        printf("\nNo password stored for the given username!\n");
        return;
    }

    // Displaying password for given username
    for(int i=0; i<size; i++)
    {
        if(strcmp(usernameArr[i], username) == 0)
        {
            printf("\nPassword for the given username: %s\n", passwordArr[i]);
            break;
        }
    }
}

// Function to remove a specific password based on username
void removePassword(char *username, char **usernameArr, char **passwordArr, int *size)
{
    // Checking if any passwords are stored
    if(*size == 0)
    {
        printf("\nNo passwords stored yet!\n");
        return;
    }

    // Checking if given username exists in the array
    int indexToDelete = -1;
    for(int i=0; i<*size; i++)
    {
        if(strcmp(usernameArr[i], username) == 0)
        {
            // Username exists, storing index of password to delete
            indexToDelete = i;
            break;
        }
    }

    if(indexToDelete == -1)
    {
        printf("\nNo password stored for the given username!\n");
        return;
    }

    // Removing username and password from the array
    for(int i=indexToDelete; i<(*size)-1; i++)
    {
        strcpy(usernameArr[i], usernameArr[i+1]);
        strcpy(passwordArr[i], passwordArr[i+1]);
    }
    *size -= 1;

    // Reallocating memory to decrease size of arrays
    usernameArr = (char **)realloc(usernameArr, (*size) * sizeof(char *));
    passwordArr = (char **)realloc(passwordArr, (*size) * sizeof(char *));

    // Printing confirmation message
    printf("\nPassword for the given username deleted successfully!\n");
}

int main()
{
    // Initializing variables
    char option;
    char *username;
    char *password;
    char **usernameArr = NULL;
    char **passwordArr = NULL;
    int size = 0;

    do
    {
        // Displaying menu
        printf("\nPassword Manager:\n");
        printf("1. Add a new password\n");
        printf("2. Display all passwords\n");
        printf("3. Search for a specific password\n");
        printf("4. Remove a specific password\n");
        printf("5. Exit\n");
        printf("Enter your choice (1/2/3/4/5): ");
        scanf(" %c", &option);

        switch(option)
        {
            case '1':
                // Adding new password
                username = (char *)malloc(50 * sizeof(char));
                password = (char *)malloc(50 * sizeof(char));
                printf("\nEnter the username: ");
                scanf(" %[^\n]s", username);
                printf("Enter the password: ");
                scanf(" %[^\n]s", password);
                addPassword(username, password, usernameArr, passwordArr, &size);
                break;

            case '2':
                // Displaying all passwords
                displayAllPasswords(usernameArr, passwordArr, size);
                break;

            case '3':
                // Searching for a specific password
                username = (char *)malloc(50 * sizeof(char));
                printf("\nEnter the username to search for: ");
                scanf(" %[^\n]s", username);
                searchPassword(username, usernameArr, passwordArr, size);
                break;

            case '4':
                // Removing a specific password
                username = (char *)malloc(50 * sizeof(char));
                printf("\nEnter the username to remove password for: ");
                scanf(" %[^\n]s", username);
                removePassword(username, usernameArr, passwordArr, &size);
                break;

            case '5':
                // Exiting the program
                printf("\nThank you for using Password Manager!\n");
                break;

            default:
                // Invalid option
                printf("\nInvalid option! Please enter a valid option (1/2/3/4/5).\n");
        }
    } while(option != '5');

    return 0;
}