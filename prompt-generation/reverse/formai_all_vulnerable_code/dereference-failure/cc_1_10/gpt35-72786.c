//FormAI DATASET v1.0 Category: System process viewer ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int getProcessCount(){
    DIR *dir;
    struct dirent *entry;
    dir = opendir("/proc");
    if (dir == NULL){
        printf("Error opening process directory!");
        return -1;
    }
    int count = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char *pid = entry->d_name;
            while (*pid) {
                if (*pid < '0' || *pid > '9') {
                    break;
                } else {
                    pid++;
                }
            }
            if (*pid == '\0') {
                count++;
            }
        }
    }
    closedir(dir);
    return count;
}

void printProcessInfo(char* pid){
    char filename[50], status_file[50], proc_name[50], state;
    FILE *fp;

    sprintf(filename, "/proc/%s/stat", pid);
    sprintf(status_file, "/proc/%s/status", pid);

    fp = fopen(filename, "r");

    if(fp==NULL){
        printf("\nError opening file! %s",filename);
        return;
    }

    fscanf(fp, "%s %s %c", pid, proc_name, &state);

    fclose(fp);

    fp = fopen(status_file, "r");

    if(fp==NULL){
        printf("\nError opening file! %s",status_file);
        return;
    }

    char line[256], *vm_peak, *vm_size;
    while(fgets(line, sizeof(line), fp)){
        if(strncmp(line,"VmSize:",7)==0){
            strtok(line,"\t\n");
            vm_size = strtok(NULL,"\t\n");
        }
        if(strncmp(line,"VmPeak:",7)==0){
            strtok(line,"\t\n");
            vm_peak = strtok(NULL,"\t\n");
        }
    }

    fclose(fp);

    printf("%-7s %-20s %-10c %-10s %-10s\n", pid, proc_name, state, vm_size, vm_peak);
}

void printHeader(){
    printf("%-7s %-20s %-10s %-10s %-10s\n", "PID", "Name", "State", "VM Size", "VM Peak");
}

int main(){
    int processCount = getProcessCount();
    if(processCount==-1){
        return -1;
    }
    printHeader();
    DIR *dir;
    struct dirent *entry;
    dir = opendir("/proc");
    if (dir == NULL){
        printf("Error opening process directory!");
        return -1;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char *pid = entry->d_name;
            while (*pid) {
                if (*pid < '0' || *pid > '9') {
                    break;
                } else {
                    pid++;
                }
            }
            if (*pid == '\0') {
                printProcessInfo(entry->d_name);
            }
        }
    }
    closedir(dir);
    return 0;
}