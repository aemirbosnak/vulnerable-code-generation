//GEMINI-pro DATASET v1.0 Category: System administration ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

int main()
{
    // Watson, let us embark on a digital investigation.
    printf("Good evening, Watson. I have received a request for assistance from the Yard.\n");

    // We must investigate a particular directory.
    char *directory = "/var/log";
    printf("The directory in question is %s.\n", directory);

    // Open the directory and list its contents.
    DIR *dir = opendir(directory);
    printf("Scanning the directory for clues...\n");

    // We must examine each file meticulously.
    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL)
    {
        // Is this file relevant to our inquiry?
        if (strstr(ent->d_name, "error"))
        {
            printf("Aha! A potential suspect: %s\n", ent->d_name);

            // Let us scrutinize its contents.
            FILE *file = fopen(ent->d_name, "r");
            char line[1024];
            while (fgets(line, sizeof(line), file))
            {
                // Any suspicious patterns in this line?
                if (strstr(line, "failed") || strstr(line, "error"))
                {
                    printf("Elementary, my dear Watson! This line implicates the file:\n%s\n", line);
                }
            }
            fclose(file);
        }
    }
    closedir(dir);

    // Our investigation has led us to a prime suspect.
    printf("The culprit appears to be a system component responsible for %s.\n", directory);

    // Let us inform our client and offer our deductions.
    printf("Watson, draft a report detailing our findings to Inspector Lestrade.\n");

    // The case is closed, but our quest for knowledge continues.
    printf("Until next time, Watson. The game is afoot!\n");

    return 0;
}