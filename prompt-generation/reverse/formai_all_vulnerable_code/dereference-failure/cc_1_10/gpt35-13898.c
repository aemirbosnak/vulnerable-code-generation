//FormAI DATASET v1.0 Category: System process viewer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

/* This function prints the process information */
void print_proc_info(char* pid) {
    char path[1024], line[1024];
    FILE* fp;
    
    /* Get command line */
    sprintf(path, "/proc/%s/cmdline", pid);
    fp = fopen(path, "r");
    if (fp != NULL) {
        fread(line, sizeof(line), 1, fp);
        fclose(fp);
        printf("%-8s", line);
    }
    
    /* Get process status */
    sprintf(path, "/proc/%s/status", pid);
    fp = fopen(path, "r");
    if (fp != NULL) {
        char* vmsize = NULL;
        while (fgets(line, sizeof(line), fp)) {
            if (strncmp(line, "VmSize:", 7) == 0) {
                vmsize = line + 7;
                break;
            }
        }
        fclose(fp);
        if (vmsize != NULL) {
            printf("%-18s", vmsize);
        }
    }
    
    /* Get process state */
    sprintf(path, "/proc/%s/stat", pid);
    fp = fopen(path, "r");
    if (fp != NULL) {
        char state;
        fscanf(fp, "%*s %*s %c", &state);
        fclose(fp);
        printf("%c\n", state);
    }
}

/* This function prints the header row */
void print_header() {
    printf("%-8s%-18s%s\n", "COMMAND", "MEMORY", "STATE");
}

/* This function reads the process directories inside /proc */
void read_proc() {
    DIR* dp;
    struct dirent* dirp;
    char *pid;
    dp = opendir("/proc/");
    if (dp != NULL) {
        print_header();
        while ((dirp = readdir(dp)) != NULL) {
            /* Check if directory name is a number (process ID) */
            if (isdigit(dirp->d_name[0])) {
                pid = dirp->d_name;
                print_proc_info(pid);
            }
        }
        closedir(dp);
    } else {
        perror("Couldn't open the directory");
    }
}

int main() {
    read_proc();
    return 0;
}