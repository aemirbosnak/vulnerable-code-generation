//FormAI DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Irregular style - keep it short and sweet!

int main(){
    puts("Let's take a peek at the running processes!\n");

    DIR* proc_dir = opendir("/proc");

    if(!proc_dir){
        puts("Failed to open /proc directory!");
        exit(EXIT_FAILURE);
    }

    puts("Process ID   Process Name");
    puts("-----------  ------------");

    struct dirent* entry;
    while((entry = readdir(proc_dir))){
        if(!isdigit(entry->d_name[0]))
            continue;

        char path[128];
        snprintf(path, sizeof(path), "/proc/%s/status", entry->d_name);

        FILE* status_file = fopen(path, "r");

        if(!status_file)
            continue;

        char line[128];
        char* name = NULL;
        char* pid = entry->d_name;

        while(fgets(line, sizeof(line), status_file)){
            if(strncmp(line, "Name:", 5) == 0){
                name = line + 6;
                break;
            }
        }

        fclose(status_file);

        if(name)
            printf("%-12s %s", pid, name);
    }

    closedir(proc_dir);

    return 0;
}