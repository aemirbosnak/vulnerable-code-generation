//FormAI DATASET v1.0 Category: System process viewer ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<dirent.h>
#include<ctype.h>

void display_processes(char *process_dir) {
    DIR *dirp;
    struct dirent *entry; // dirent holds an inode number and a name
    if (((dirp = opendir(process_dir)) == NULL)) {
        printf("Could not open directory: %s\n", process_dir);
        exit(1);
    }
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                         |\n");
    printf("|   Pid   |  Process Name   | Status  |   Owner User   | Memory (Resident) |\n");
    printf("|_________|________________|________|________________|___________________|\n");
    while ((entry = readdir(dirp))) {
        if(isdigit(*entry->d_name)) { // If the first character is a digit, then it's a process
            char filename[100], status[20], owner[30], tmp[100];
            char mem[20] = "0";
            int fd;
            sprintf(filename, "%s/%s/status", process_dir, entry->d_name); // Grab the status file for this process
            if ((fd = open(filename, O_RDONLY))<0) {
                printf("Error reading %s\n", filename);
                continue;
            }
            read(fd, tmp, 100);
            sscanf(tmp, "%s %s\n", tmp, status);
            if ((fd = open(filename, O_RDONLY))<0) {
                printf("Error reading %s\n", filename);
                continue;
            }
            while(read(fd, tmp, 100)) {
                sscanf(tmp, "%s", tmp);
                if (strcmp(tmp, "Uid:") == 0) {
                    sscanf(tmp, "%s %s\n", tmp, owner);
                }
                if (strcmp(tmp, "VmRSS:") == 0) {
                    sscanf(tmp, "%s %s\n", tmp, mem);
                }
            }
            printf("| %-7s| %-16s| %-8s| %-16s| %-19s|\n", entry->d_name, entry->d_name, status, owner, mem);
        }
    }
    printf("|_________|________________|________|________________|___________________|\n");
}

int main(int argc, char **argv) {
    display_processes("/proc");
    return 0;
}