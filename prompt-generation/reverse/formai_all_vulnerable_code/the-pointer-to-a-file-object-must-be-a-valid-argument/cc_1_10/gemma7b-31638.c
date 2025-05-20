//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    system("clear");
    printf("Welcome to the C Online Examination System!\n");
    printf("Please select an option:\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");

    char choice;
    scanf(" %c", &choice);

    switch (choice)
    {
        case '1':
            printf("Enter your name:");
            char name[20];
            scanf(" %s", name);

            printf("Enter your email address:");
            char email[50];
            scanf(" %s", email);

            printf("Enter your password:");
            char password[20];
            scanf(" %s", password);

            FILE *fp;
            fp = fopen("users.txt", "a");
            fprintf(fp, "%s, %s, %s\n", name, email, password);
            fclose(fp);

            printf("Registration successful!\n");
            break;

        case '2':
            printf("Enter your email address:");
            char email2[50];
            scanf(" %s", email2);

            printf("Enter your password:");
            char password2[20];
            scanf(" %s", password2);

            FILE *fp2;
            fp2 = fopen("users.txt", "r");
            char line[255];
            int found = 0;

            while (fgets(line, 255, fp2) != NULL)
            {
                char *name2 = strchr(line, ',');
                char *email3 = strchr(line, ',');
                char *password3 = strchr(line, '\n');

                if (strcmp(email2, email3) == 0 && strcmp(password2, password3) == 0)
                {
                    found = 1;
                    break;
                }
            }

            fclose(fp2);

            if (found)
            {
                printf("Login successful!\n");
            }
            else
            {
                printf("Invalid email or password.\n");
            }
            break;

        case '3':
            printf("Thank you for using the C Online Examination System.\n");
            break;

        default:
            printf("Invalid input.\n");
    }

    system("pause");
}