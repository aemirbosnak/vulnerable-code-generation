//FormAI DATASET v1.0 Category: System process viewer ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>

int is_pid(char* filename){
    for(int i=0; i<strlen(filename); i++){
        if(!isdigit(filename[i])){
            return 0;
        }
    }
    return 1;
}

void print_proc_info(char* pid){
    char path[100];
    sprintf(path, "/proc/%s/stat", pid);
    FILE* stat_file = fopen(path, "r");
    char comm[100], state, ppid[10];
    fscanf(stat_file, "%s %*s %c %s", comm, &state, ppid);
    fclose(stat_file);
    printf("%s\t%c\t%s\n", pid, state, ppid);
}

void process_dir(char* dirname){
    DIR* dir = opendir(dirname);
    struct dirent* dir_entry;
    
    if(dir == NULL){
        return;
    }
    
    while((dir_entry = readdir(dir)) != NULL){
        char* name = dir_entry->d_name;
        if(is_pid(name)){
            print_proc_info(name);
        }
        else if(strcmp(name, ".") != 0 && strcmp(name, "..") != 0){
            char path[100];
            sprintf(path, "%s/%s", dirname, name);
            process_dir(path);
        }
    }
    closedir(dir);
}

int main(){
    char dirname[] = "/proc";
    process_dir(dirname);
    return 0;
}