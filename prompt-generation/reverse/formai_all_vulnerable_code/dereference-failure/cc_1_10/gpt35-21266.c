//FormAI DATASET v1.0 Category: System process viewer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// function to format the output of process information
void format_output(char *pid, char *pname, char *ppath) {
    printf("| %-10s | %-25s | %-40s |\n", pid, pname, ppath);
}

int main(int argc, char **argv) {
    DIR *dp; // directory pointer
    struct dirent *entry; // pointer to directory entry
    char pid[10], pname[50], ppath[50], filename[50], buf[1024]; // variables to store process information
    FILE *fp; // file pointer
    
    // open the /proc directory
    dp = opendir("/proc");
    if (dp == NULL) {
        printf("Error opening /proc directory\n");
        exit(1);
    }
    
    printf("==================================================================================\n");
    printf("| PID        | PROCESS NAME             | PATH                                   |\n");
    printf("==================================================================================\n");
    
    // loop through each directory entry in /proc
    while ((entry = readdir(dp)) != NULL) {
        
        // check if this entry is a directory and named with a number (which indicates it's a process)
        if (entry->d_type == DT_DIR && strtol(entry->d_name, NULL, 10)) {
            
            // read the process name from the /proc/[pid]/comm file
            sprintf(filename, "/proc/%s/comm", entry->d_name);
            fp = fopen(filename, "r");
            if (fp != NULL) {
                fgets(pname, 50, fp);
                fclose(fp);
                
                // remove newline character from the end of the process name
                pname[strlen(pname)-1] = '\0';
            }
            else {
                strcpy(pname, "unknown");
            }
            
            // read the process path from the /proc/[pid]/exe file
            sprintf(filename, "/proc/%s/exe", entry->d_name);
            memset(buf, 0, sizeof(buf)); // clear the buffer before reading
            readlink(filename, buf, sizeof(buf));
            strcpy(ppath, buf);
            
            // get the PID of the process
            strcpy(pid, entry->d_name);
            
            // format the output and print it to the console
            format_output(pid, pname, ppath);
        }
    }
    
    // close the /proc directory
    closedir(dp);
    
    printf("==================================================================================\n");
    
    return 0;
}