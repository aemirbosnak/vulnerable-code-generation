//FormAI DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
// The Adventure of the Process Viewer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

#define PATH_SIZE 50
#define NAME_SIZE 100
#define BUFF_SIZE 256

struct Process {
    char pid[6];
    char name[NAME_SIZE];
    char state[2];
    char ppid[6];
};

/**
 * Function to read the process information from /proc/[pid]/stat
*/
void read_process_details(char* pid, struct Process* p) {
    char path[PATH_SIZE];
    snprintf(path, PATH_SIZE, "/proc/%s/stat", pid);

    // Open the stat file for the process
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        printf("Error: Could not open stat file for the process.\n");
        exit(EXIT_FAILURE);
    }

    char buff[BUFF_SIZE];
    int bytes_read;

    // Read the contents of the file into buff
    memset(buff, 0, BUFF_SIZE);
    bytes_read = read(fd, buff, BUFF_SIZE - 1);
    if (bytes_read == -1) {
        printf("Error: Could not read stat file for the process.\n");
        exit(EXIT_FAILURE);
    }

    close(fd);

    char* token;
    const char delim[] = " ";
    int i = 1;

    // Tokenize the buff string and extract process details
    token = strtok(buff, delim);
    while (token != NULL) {
        if (i == 1) {
            strncpy(p->pid, token, 6);
        } else if (i == 2) {
            strncpy(p->name, token, NAME_SIZE);
        } else if (i == 3) {
            strncpy(p->state, token, 2);
        } else if (i == 4) {
            strncpy(p->ppid, token, 6);
        }

        token = strtok(NULL, delim);
        i++;
    }
}

int main(int argc, char* argv[]) {
    DIR* dirp;
    struct dirent* direntp;

    printf("Welcome to the Process Viewer.\n");

    // Open the /proc directory
    dirp = opendir("/proc");
    if (dirp == NULL) {
        printf("Error: Could not open /proc directory.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nPlease wait while we retrieve the process information...\n");

    // Iterate through all the files in the /proc directory
    while ((direntp = readdir(dirp))) {
        char* name = direntp->d_name;

        // Check if the name contains only digits
        bool is_digit = true;
        for (int i = 0; i < strlen(name); i++) {
            if (!isdigit(name[i])) {
                is_digit = false;
            }
        }

        // If name is not a number, skip it
        if (!is_digit) {
            continue;
        }

        struct Process p;
        read_process_details(name, &p);

        printf("\nPID: %s\nName: %s\nState: %s\nPPID: %s\n", p.pid, p.name, p.state, p.ppid);
    }

    closedir(dirp);

    printf("\nProcess information retrieval complete.\n");

    return 0;
}