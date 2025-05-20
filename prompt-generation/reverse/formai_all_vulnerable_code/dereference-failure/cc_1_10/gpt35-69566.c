//FormAI DATASET v1.0 Category: System process viewer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define PROC_DIRECTORY "/proc/"

// define a struct to hold process information
struct proc_info {
    char name[20];
    int pid;
    int ppid;
    long unsigned int rss;
};

int count_lines(char *filename);
int is_number(char *str);
void get_proc_info(int pid, struct proc_info *info);
void print_proc_info(struct proc_info *info);

int main() {
    DIR *dp;
    struct dirent *dirp;
    char filename[100];
    FILE *fp;
    char line[512];
    int pid_count = 0, zombie_count = 0;
    long unsigned int total_rss = 0;
    struct proc_info proc;

    // open the proc directory
    if ((dp = opendir(PROC_DIRECTORY)) == NULL) {
        printf("Error: could not open proc directory\n");
        return 1;
    }

    // read each directory entry and collect process information
    while ((dirp = readdir(dp)) != NULL) {
        if (!is_number(dirp->d_name)) {
            continue;
        }

        // get the process information
        int pid = atoi(dirp->d_name);
        get_proc_info(pid, &proc);

        // add up total rss and increment counts
        if (proc.pid != -1) {
            total_rss += proc.rss;
            pid_count++;
            if (proc.ppid == 1) {
                zombie_count++;
            }
        }
    }

    // print out statistics
    printf("Total number of processes: %d\n", pid_count);
    printf("Number of zombie processes: %d\n", zombie_count);
    printf("Average RSS: %ld\n", total_rss / pid_count);

    // close the proc directory and exit
    closedir(dp);
    return 0;
}

/*
 * Counts the number of lines in a file. Assumes that the file only contains
 * ASCII characters and that each line is terminated by a newline character.
 */
int count_lines(char *filename) {
    FILE *fp;
    char ch;
    int lines = 0;

    if ((fp = fopen(filename, "r")) == NULL) {
        return -1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }

    fclose(fp);
    return lines;
}

/*
 * Returns true if the given string can be converted to an integer.
 */
int is_number(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

/*
 * Retrieves process information for the given pid and stores it in the given
 * proc_info struct. Returns 0 on success, or -1 if an error occurred.
 */
void get_proc_info(int pid, struct proc_info *info) {
    char filename[100];
    FILE *fp;
    char line[512];

    // initialize info
    info->pid = pid;
    info->ppid = -1;
    info->rss = 0;
    strcpy(info->name, "UNKNOWN");

    // construct the filename for this process
    sprintf(filename, PROC_DIRECTORY "%d/stat", pid);

    // open the stat file for this process
    if ((fp = fopen(filename, "r")) == NULL) {
        return;
    }

    // read the first line, which contains the process name and other info
    if (fgets(line, 512, fp) == NULL) {
        fclose(fp);
        return;
    }

    // parse the line to get the process name and parent pid
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        i++;
        if (i == 2) {
            strcpy(info->name, token + 1);
        } else if (i == 4) {
            info->ppid = atoi(token);
        } else if (i == 24) {
            info->rss = atol(token) * getpagesize();
        }
        token = strtok(NULL, " ");
    }

    fclose(fp);
}

/*
 * Prints the given process information to stdout.
 */
void print_proc_info(struct proc_info *info) {
    printf("%20s: %d\n", "PID", info->pid);
    printf("%20s: %d\n", "PPID", info->ppid);
    printf("%20s: %s\n", "NAME", info->name);
    printf("%20s: %lu\n", "RSS", info->rss);
    printf("\n");
}