//FormAI DATASET v1.0 Category: System process viewer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define PROC_PATH "/proc"

int main()
{
    printf("Welcome to the Cyberpunk Process Viewer!\n\n");

    while(1)
    {
        // Open the /proc directory
        DIR *dir = opendir(PROC_PATH);

        if(dir == NULL)
        {
            printf("Error: Could not open /proc directory.\n");
            exit(1);
        }

        // Read the contents of the directory
        struct dirent *entry;
        while((entry = readdir(dir)) != NULL)
        {
            // Check if the entry is a directory and is named with only digits
            if(entry->d_type == DT_DIR && isdigit(entry->d_name[0]))
            {
                // Open the cmdline file for the process
                char file_path[128];
                sprintf(file_path, "%s/%s/cmdline", PROC_PATH, entry->d_name);
                FILE *file = fopen(file_path, "r");
                if(file)
                {
                    // Read the contents of the file (the command used to launch the process)
                    char cmd[256];
                    fgets(cmd, sizeof(cmd), file);
                    fclose(file);

                    // Print the process information in a Cyberpunk style
                    printf("\033[1;32m %-10s \033[0m", entry->d_name);
                    printf("\033[1;31m%-30s \033[0m", cmd);
                    printf("\033[1;36m%s \033[0m\n", "████████████████████████████████████████████████████████");

                }
            }
        }

        closedir(dir);

        // Clear the console and wait for 1 second before refreshing the process list
        system("clear");
        sleep(1);
    }

    return 0;
}