//Gemma-7B DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define PASSWORD_FILE "/tmp/passwords.txt"

void usage(char **argv)
{
    fprintf(stderr, "Usage: %s [command] [options]\n", argv[0]);
    fprintf(stderr, "Commands:\n");
    fprintf(stderr, "  add: Add a new password.\n");
    fprintf(stderr, "  list: List all passwords.\n");
    fprintf(stderr, "  edit: Edit a password.\n");
    fprintf(stderr, "  del: Delete a password.\n");
    fprintf(stderr, "  help: Show this help message.\n");
    exit(1);
}

int main(int argc, char **argv)
{
    char cmd;
    char password[256];
    FILE *fp;
    int i = 0;

    if (argc < 2)
    {
        usage(argv);
    }

    cmd = argv[1][0];

    switch (cmd)
    {
        case 'a':
            fprintf(stderr, "Enter a new password: ");
            fgets(password, 256, stdin);
            password[strcspn(password, "\n")] = '\0';

            fp = fopen(PASSWORD_FILE, "a");
            fprintf(fp, "%s\n", password);
            fclose(fp);

            fprintf(stderr, "Password added.\n");
            break;

        case 'l':
            fp = fopen(PASSWORD_FILE, "r");
            while (fgets(password, 256, fp) != NULL)
            {
                fprintf(stderr, "%s\n", password);
            }
            fclose(fp);
            break;

        case 'e':
            fprintf(stderr, "Enter the password you want to edit: ");
            fgets(password, 256, stdin);
            password[strcspn(password, "\n")] = '\0';

            fp = fopen(PASSWORD_FILE, "r");
            while (fgets(password, 256, fp) != NULL)
            {
                if (strcmp(password, argv[2]) == 0)
                {
                    fprintf(stderr, "Enter the new password: ");
                    fgets(password, 256, stdin);
                    password[strcspn(password, "\n")] = '\0';

                    fp = fopen(PASSWORD_FILE, "w");
                    i = 0;
                    while (fgets(password, 256, fp) != NULL)
                    {
                        if (i++ == 0)
                        {
                            fprintf(fp, "%s\n", password);
                        }
                        else
                        {
                            fprintf(fp, "%s\n", password);
                        }
                    }
                    fclose(fp);

                    fprintf(stderr, "Password edited.\n");
                    break;
                }
            }
            fclose(fp);
            break;

        case 'd':
            fprintf(stderr, "Enter the password you want to delete: ");
            fgets(password, 256, stdin);
            password[strcspn(password, "\n")] = '\0';

            fp = fopen(PASSWORD_FILE, "r");
            while (fgets(password, 256, fp) != NULL)
            {
                if (strcmp(password, argv[2]) == 0)
                {
                    fp = fopen(PASSWORD_FILE, "w");
                    i = 0;
                    while (fgets(password, 256, fp) != NULL)
                    {
                        if (i++ == 0)
                        {
                            // Do not output the password that is being deleted
                        }
                        else
                        {
                            fprintf(fp, "%s\n", password);
                        }
                    }
                    fclose(fp);

                    fprintf(stderr, "Password deleted.\n");
                    break;
                }
            }
            fclose(fp);
            break;

        case 'h':
            usage(argv);
            break;

        default:
            fprintf(stderr, "Invalid command.\n");
            break;
    }

    return 0;
}