//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    system("clear");
    printf("Welcome to the C Online Examination System!\n");
    printf("Please select an option:\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            system("clear");
            printf("Enter your first name:");
            char fname[20];
            scanf("%s", fname);

            printf("Enter your last name:");
            char lname[20];
            scanf("%s", lname);

            printf("Enter your email address:");
            char email[50];
            scanf("%s", email);

            printf("Enter your password:");
            char password[20];
            scanf("%s", password);

            FILE *fp = fopen("users.txt", "a");
            fprintf(fp, "%s, %s, %s, %s\n", fname, lname, email, password);
            fclose(fp);

            system("clear");
            printf("Registration successful!\n");
            break;

        case 2:
            system("clear");
            printf("Enter your email address:");
            char email2[50];
            scanf("%s", email2);

            printf("Enter your password:");
            char password2[20];
            scanf("%s", password2);

            FILE *fp2 = fopen("users.txt", "r");
            char line[100];
            int found = 0;

            while (fgets(line, 100, fp2) != NULL) {
                char *email_p = strchr(line, ",");
                char *password_p = strchr(line, ",") + 1;

                if (strcmp(email_p, email2) == 0 && strcmp(password_p, password2) == 0) {
                    found = 1;
                    break;
                }
            }

            fclose(fp2);

            if (found) {
                system("clear");
                printf("Login successful!\n");
            } else {
                system("clear");
                printf("Invalid email or password.\n");
            }
            break;

        case 3:
            system("clear");
            printf("Thank you for using the C Online Examination System.\n");
            break;

        default:
            system("clear");
            printf("Invalid choice.\n");
    }

    return;
}