//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_FILE "passwords.txt"

// Function to check if string contains only digits
int isNumeric(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    
    return 1;
}

// Function to mask password by replacing characters with asterisks
char *maskPassword(char *password)
{
    char *maskedPassword = malloc(strlen(password) + 1);
    
    for (int i = 0; i < strlen(password); i++)
    {
        maskedPassword[i] = '*';
    }
    
    maskedPassword[strlen(password)] = '\0';
    
    return maskedPassword;
}

// Function to create a new password entry
void createPassword()
{
    char label[50], password[50], line[100];
    FILE *fp = fopen(PASSWORD_FILE, "a");
    
    printf("Enter label for password: ");
    scanf("%s", label);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    fprintf(fp, "%s:%s\n", label, password);
    
    printf("Password entry created successfully!\n");
    fclose(fp);
}

// Function to retrieve an existing password by label
void retrievePassword()
{
    char label[50], password[50], line[100];
    FILE *fp = fopen(PASSWORD_FILE, "r");
    int found = 0;
    
    printf("Enter label for password: ");
    scanf("%s", label);
    
    while (fgets(line, sizeof(line), fp))
    {
        char *l = strtok(line, ":");
        char *p = strtok(NULL, "\n");
        
        if (strcmp(l, label) == 0)
        {
            found = 1;
            printf("Password for %s: %s\n", l, maskPassword(p));
            break;
        }
    }
    
    if (!found)
    {
        printf("Password entry not found!\n");
    }
    
    fclose(fp);
}

// Function to list all password labels
void listPasswords()
{
    FILE *fp = fopen(PASSWORD_FILE, "r");
    char line[100];
    
    printf("List of password labels:\n");
    
    while (fgets(line, sizeof(line), fp))
    {
        char *l = strtok(line, ":");
        printf("- %s\n", l);
    }
    
    fclose(fp);
}

int main()
{
    int choice;
    
    while (1)
    {
        printf("\nPassword Manager\n");
        printf("1. Create Password\n");
        printf("2. Retrieve Password\n");
        printf("3. List Passwords\n");
        printf("4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1)
        {
            createPassword();
        }
        else if (choice == 2)
        {
            retrievePassword();
        }
        else if (choice == 3)
        {
            listPasswords();
        }
        else if (choice == 4)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    
    return 0;
}