//Gemma-7B DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void inv_passwd_manager(char **passwords)
{
    system("/bin/rm -rf .pass");
    system("/bin/mkdir .pass");
    passwords = realloc(passwords, 10);
    passwords[0] = malloc(20);
    printf("Enter a strong password: ");
    gets(passwords[0]);
    system("echo $PASSWD > .pass/pass");
    system("/bin/chmod 0600 .pass/pass");
    printf("Password successfully saved.\n");
    free(passwords[0]);
}

int main()
{
    char **passwords = NULL;
    int i = 0;

    while (1)
    {
        switch (rand() % 3)
        {
            case 0:
                inv_passwd_manager(&passwords);
                break;
            case 1:
                printf("Current passwords:\n");
                for (i = 0; passwords[i] != NULL; i++)
                {
                    printf("%s\n", passwords[i]);
                }
                break;
            case 2:
                printf("Enter the index of the password you want to delete: ");
                int index = atoi(gets(NULL));
                for (i = 0; passwords[i] != NULL; i++)
                {
                    if (i == index)
                    {
                        free(passwords[i]);
                        passwords[i] = NULL;
                        printf("Password deleted.\n");
                    }
                }
                break;
            default:
                break;
        }
    }

    return 0;
}