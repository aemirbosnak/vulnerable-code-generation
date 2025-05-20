//FormAI DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
// "The Case of the Mysterious Processes"

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define PROC_PATH "/proc"
#define MAX_PID_LENGTH 10

void print_process_info(char* pid) {
    char path[50];
    strcpy(path, PROC_PATH);
    strcat(path, "/");
    strcat(path, pid);
    strcat(path, "/stat");

    FILE* file = fopen(path, "r");
    if (file) {
        char name[30];
        char state;
        fscanf(file, "%s %*s %c", name, &state);
        printf("%-10s %c\n", name, state);
        fclose(file);
    }
}

void print_process_tree(char* pid, int level) {
    int i;
    for (i=0; i<level; i++)
        printf("| ");

    printf("+--");
    print_process_info(pid);

    char path[50], sub_pid[MAX_PID_LENGTH+1];
    DIR* dir = opendir(PROC_PATH);
    struct dirent* entry;

    if (dir) {
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_type == DT_DIR) {
                if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                    continue;

                if (isdigit(entry->d_name[0])) {
                    strcpy(sub_pid, entry->d_name);
                    strcpy(path, PROC_PATH);
                    strcat(path, "/");
                    strcat(path, sub_pid);
                    strcat(path, "/stat");

                    FILE* file = fopen(path, "r");
                    if (file) {
                        char ppid[MAX_PID_LENGTH+1];
                        char name[30];
                        char state;
                        fscanf(file, "%*s %s %*s", ppid);
                        fclose(file);

                        if (strcmp(ppid, pid) == 0)
                            print_process_tree(sub_pid, level+1);
                    }
                }
            }
        }
    }
    closedir(dir);
}

int main(int argc, char* argv[]) {
    printf("The Case of the Mysterious Processes\n");
    printf("------------------------------------\n");

    DIR* dir = opendir(PROC_PATH);
    struct dirent* entry;

    if (dir) {
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_type == DT_DIR) {
                if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                    continue;

                if (isdigit(entry->d_name[0])) {
                    print_process_tree(entry->d_name, 0);
                }
            }
        }
    }
    closedir(dir);

    return 0;
}