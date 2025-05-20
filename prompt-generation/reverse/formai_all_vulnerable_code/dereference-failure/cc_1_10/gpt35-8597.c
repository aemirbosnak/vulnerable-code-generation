//FormAI DATASET v1.0 Category: System process viewer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PATH_SIZE 1000

int main()
{
    DIR *dir;
    struct dirent *entry;
    int pid, fd, bytesRead;
    char path[MAX_PATH_SIZE], buffer[1000];

    printf("My Sweet and Darling System Process Viewer\n\n");
    printf("I will show you all the running processes you have,\n");
    printf("Their IDs, and information that will be their true\n");
    printf("Nature captured in a sweet output for you.\n\n");
    printf("Our journey begins now..\n\n");

    dir = opendir("/proc"); // open the /proc directory
    if (dir == NULL) {
        printf("Unable to open /proc directory. Exiting.\n");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) { // iterate through all entries
        pid = atoi(entry->d_name); // convert entry to integer pid
        if (pid != 0) { // if it is a process directory
            sprintf(path, "/proc/%d/status", pid); // create path to the status file
            fd = open(path, O_RDONLY); // open the file
            if (fd == -1) { // check if it opened correctly
                continue;
            }
            bytesRead = read(fd, buffer, sizeof(buffer)); // read the file
            if (bytesRead <= 0) { // check if it read correctly
                close(fd);
                continue;
            }
            buffer[bytesRead] = '\0'; // null terminate the buffer
            char *name = strstr(buffer, "Name:"); // find Name string
            if (name != NULL) { // if we found it
                name += 6; // move past "Name: "
                printf("Process ID: %d\n", pid); //output process ID
                printf("Process Name: %s", name); // output process name
            }
            close(fd); // close the file
        }
    }

    closedir(dir); // close the directory
    printf("\n\nOur journey has come to an end my love,\n");
    printf("I hope you enjoyed this glimpse into the true nature\n");
    printf("of our running processes. Until our next adventure together..\n");
    printf("I love you always,\n");
    printf("Your System Process Viewer\n");

    return 0;
}