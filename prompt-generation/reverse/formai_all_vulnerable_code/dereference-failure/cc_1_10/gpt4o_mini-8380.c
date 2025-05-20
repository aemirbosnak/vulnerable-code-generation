//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

void declareProcess(char *name, int pid, char *state) {
    printf("O wondrous being! Behold thy majesty!\n");
    printf("%s, the noble process, with PID %d, dost reside in\n", name, pid);
    printf("The realm of %s, a state of %s!\n\n", name, state);
}

void listProcesses() {
    DIR *dir;
    struct dirent *entry;
    char path[1024];
    
    printf("In fair Verona where we lay our scene,\n");
    printf("We shall delve into the mysteries of the wretched processes...\n\n");
    
    // Open the /proc directory where processes information is available
    if ((dir = opendir("/proc")) == NULL) {
        perror("Could not open /proc directory");
        return;
    }

    // Read each entry in the /proc directory
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a numeric PID
        if (atoi(entry->d_name) > 0) {
            // Construct the path to the status file
            snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
            FILE *fp = fopen(path, "r");
            if (fp) {
                int pid;
                char comm[256], state[256];

                // Read the PID, command name and state from the file
                fscanf(fp, "%d %s %s", &pid, comm, state);
                fclose(fp);
                
                // Remove parentheses from command name (if any)
                for (int i = 0; comm[i]; i++) {
                    if (comm[i] == '(') {
                        comm[i] = '\0';
                    }
                }
                
                // Call the declaration function
                declareProcess(comm, pid, state);
            }
        }
    }

    closedir(dir);
}

int main() {
    printf("Romeo and Juliet: A Process Viewing\n");
    printf("-----------------------------------\n");
    
    listProcesses();

    printf("A tribute to thee, sweet process!\n");
    printf("For in this digital realm, thou art eternal.\n");
    
    return 0;
}