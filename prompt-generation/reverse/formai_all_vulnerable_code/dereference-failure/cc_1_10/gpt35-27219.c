//FormAI DATASET v1.0 Category: System process viewer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PID_LENGTH 10

struct process {
    char pid[MAX_PID_LENGTH];
    char name[255];
    char state[32];
};

int is_number(char *string) {
    for(int i = 0; i < strlen(string); i++) {
        if(!isdigit(string[i]))
            return 0;
    }
    return 1;
}

void parse_process_info(FILE *file, struct process *proc) {
    char line[1024];
    char column[255];
    int i = 0, j = 0;

    fgets(line, sizeof(line), file); // Skip first line header of the file

    while(fgets(line, sizeof(line), file)) {
        i = 0; // Reset column index
        j = 0; // Reset line index

        while(line[j] != '\n') {
            if(line[j] != ' ') {
                column[i] = line[j];
                i++;
            } else {
                column[i] = '\0';
                i = 0;

                // Set corresponding struct property according to column order
                if(j == 0)
                    strcpy(proc->pid, column);
                else if(j == 1)
                    strcpy(proc->name, column);
                else if(j == 2)
                    strcpy(proc->state, column);
            }
            j++;
        }
    }
}

void display_process_list() {
    DIR *dir;
    struct dirent *ent;
    char path[64];
    FILE *file;
    struct process proc;

    printf("%5s %20s %s\n", "PID", "NAME", "STATE");
    printf("------------------------------------------------\n");

    if((dir = opendir("/proc")) != NULL) {
        while((ent = readdir(dir)) != NULL) {
            // Check if the content of the directory is a directory with a numeric name (a process id)
            if(is_number(ent->d_name)) {
                sprintf(path, "/proc/%s/status", ent->d_name);

                if((file = fopen(path, "r")) != NULL) {
                    // If file is opened, populate process struct with relevant information
                    memset(&proc, 0, sizeof(struct process));
                    parse_process_info(file, &proc);

                    printf("%5s %20s %s\n", proc.pid, proc.name, proc.state);

                    fclose(file);
                }
            }
        }
        closedir(dir);
    } else {
        printf("Unable to open /proc\n");
    }
}

int main() {
    display_process_list();
    return 0;
}