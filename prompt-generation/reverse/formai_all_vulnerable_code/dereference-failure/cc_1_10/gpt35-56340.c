//FormAI DATASET v1.0 Category: System process viewer ; Style: relaxed
#include <stdio.h> 
#include <dirent.h> 
#include <string.h> 
#include <ctype.h> 

void process_viewer() {
    DIR* dir;
    char path[50];
    struct dirent* ent;
    char buf[1024],* tmp = NULL;

    // Open the /proc directory 
    dir = opendir("/proc");

    if (!dir) {
        printf("Oops! Unable to open /proc directory\n");
        return;
    }
    
    printf("PID\t Command\n");
    printf("----------------------------------------\n");

    // Walk through the directories in the /proc directory 
    while ((ent = readdir(dir)) != NULL) {
        // If not a directory, skip 
        if (!isdigit(*ent -> d_name)) {
            continue;
        }

        // Open the /proc/[pid]/cmdline file 
        sprintf(path, "/proc/%s/cmdline", ent -> d_name);
        FILE* fp = fopen(path, "r");
        if (fp != NULL) {
            // Read the contents of cmdline file 
            fgets(buf, sizeof(buf), fp);
            fclose(fp);

            // Replace all '\0' by ' ' to give space separated command line arguments 
            for (tmp = buf; *tmp; tmp++) {
                if (*tmp == '\0') {
                    *tmp = ' ';
                }
            }
            // Print PID and Command 
            printf("%s\t %s\n", ent -> d_name, buf);
        }
    }
    // Close directory 
    closedir(dir);
}

int main() {
    process_viewer();
    return 0;
}