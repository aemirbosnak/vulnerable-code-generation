//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("clear");
    printf("Welcome to the C Online Examination System!\n");
    printf("Please select an option:\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            system("clear");
            printf("Please provide your first name:");
            char firstName[20];
            scanf("%s", firstName);

            printf("Please provide your last name:");
            char lastName[20];
            scanf("%s", lastName);

            printf("Please provide your email address:");
            char email[50];
            scanf("%s", email);

            printf("Please provide your password:");
            char password[20];
            scanf("%s", password);

            FILE *file = fopen("students.txt", "a");
            fprintf(file, "%s %s %s %s %s\n", firstName, lastName, email, password, "active");
            fclose(file);
            system("clear");
            printf("Thank you for registering! Please login with your credentials.\n");
            break;

        case 2:
            system("clear");
            printf("Please provide your email address:");
            char email2[50];
            scanf("%s", email2);

            printf("Please provide your password:");
            char password2[20];
            scanf("%s", password2);

            FILE *file2 = fopen("students.txt", "r");
            char line[100];
            int found = 0;
            while (fgets(line, 100, file2) != NULL)
            {
                char email3[50];
                char password3[20];
                char status[20];

                strcpy(email3, line);
                strcpy(password3, line + 50);
                strcpy(status, line + 100);

                if (strcmp(email2, email3) == 0 && strcmp(password2, password3) == 0)
                {
                    found = 1;
                    system("clear");
                    printf("Welcome, %s %s!\n", firstName, lastName);
                    break;
                }
            }

            if (!found)
            {
                system("clear");
                printf("Invalid email address or password.\n");
            }
            fclose(file2);
            break;

        case 3:
            system("clear");
            printf("Thank you for using the C Online Examination System. Goodbye!\n");
            break;
    }

    return 0;
}