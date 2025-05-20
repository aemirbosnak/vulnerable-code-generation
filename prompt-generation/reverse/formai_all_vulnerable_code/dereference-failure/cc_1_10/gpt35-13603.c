//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Initializing program variables
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    char* keywords[] = {"root", "sudo", "shutdown", "halt", "reboot"};
    int match_found = 0;

    // Welcome message
    printf("\n   Welcome to Intrusion Detection System\n\n");

    while (1)
    {
        // Input prompt
        printf(">> ");
        read = getline(&line, &len, stdin);

        // Parsing input
        for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++)
        {
            if (strstr(line, keywords[i]) != NULL)
            {
                match_found = 1;
                break;
            }
        }

        // Match found message
        if (match_found)
        {
            printf("!!! Intrusion detected !!!\n\n");

            // Writing to system log
            FILE* fp;
            fp = fopen("/var/log/intrusion_log", "a");
            fprintf(fp, "%s", line);
            fclose(fp);

            // Sending email notification
            system("mail -s \"Intrusion detected\" admin@example.com < /var/log/intrusion_log");

            // Exiting program
            exit(0);
        }

        // Match not found message
        printf("Permission granted.\n");
        printf("--------------------\n");
    }

    // Freeing memory
    if (line)
        free(line);

    return 0;
}