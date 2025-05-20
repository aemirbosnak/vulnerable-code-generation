//FormAI DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<ctype.h>
#include<string.h>
#include<errno.h>

/* Struct to store process details */
typedef struct {
    char pid[10];
    char pname[100];
    char pstate[20];
    char ppid[10];
    char puid[10];
} process;

/* Function to print column headings */
void print_header() {
    printf("%-10s%-20s%-20s%-10s%-10s\n","PID","NAME","STATE","PPID","UID");
    printf("------------------------------------------------------------\n");
}

/* Function to print process details */
void print_process(process p) {
    printf("%-10s%-20s%-20s%-10s%-10s\n",p.pid, p.pname, p.pstate, p.ppid, p.puid);
}

/* Function to retrieve process details from /proc directory */
process get_process_details(char *pid) {
    process p;
    char filename[50], c;
    FILE *fp;

    memset(filename, 0, sizeof(filename));
    sprintf(filename, "/proc/%s/stat", pid);

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file. %s\n", strerror(errno));
        exit(1);
    }

    fscanf(fp, "%s %s %s %s %s %s %s", p.pid, p.pname, p.pstate, p.ppid, p.puid);
    fclose(fp);

    return p;
}

/* Function to check if given string is a valid number */
int is_number(char *str) {
    int i;
    for(i = 0; str[i] != '\0'; i++) {
        if(!isdigit(str[i])) {
            return 0;
        }
    }

    return 1;
}

/* Main function */
int main(int argc, char *argv[]) {
    DIR *directory;
    struct dirent *entry;
    process p;

    /* If PID is provided as argument, display details of that process. Else, display details of all processes */
    if(argc > 1 && is_number(argv[1])) {
        p = get_process_details(argv[1]);
        print_header();
        print_process(p);
    } else {
        directory = opendir("/proc");

        if(directory == NULL) {
            printf("Error opening directory. %s\n", strerror(errno));
            exit(1);
        }

        print_header();

        while((entry = readdir(directory))) {
            if(is_number(entry->d_name)) {
                p = get_process_details(entry->d_name);
                print_process(p);
            }
        }

        closedir(directory);
    }

    return 0;
}