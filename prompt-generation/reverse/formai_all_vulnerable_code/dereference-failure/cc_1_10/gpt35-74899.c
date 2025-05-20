//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>

// function to get size of a file or directory
int getSize(char path[]){
    struct stat st;
    int size = 0;
    if(stat(path, &st)==0){
        if(S_ISREG(st.st_mode)){        // check if file
            size = st.st_size;
        }else if(S_ISDIR(st.st_mode)){  // check if directory
            DIR *dir;
            struct dirent *entry;
            if((dir = opendir(path))!=NULL){
                while((entry = readdir(dir))!=NULL){
                    // recursive call to get size of files inside directory
                    char new_path[512];
                    if(strcmp(entry->d_name,".")!=0 && strcmp(entry->d_name,"..")!=0){
                        sprintf(new_path,"%s/%s", path, entry->d_name);
                        size += getSize(new_path);
                    }
                }
                closedir(dir);
            }
        }
    }
    return size;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s <path>", argv[0]);
        exit(1);
    }
    char path[512];
    strcpy(path, argv[1]);

    // check if path is a directory or file
    struct stat st;
    if(stat(path, &st)!=0){
        printf("Invalid path!\n");
        exit(1);
    }else if(S_ISREG(st.st_mode)){      // if file
        printf("%s size is %d bytes\n", path, st.st_size);
    }else if(S_ISDIR(st.st_mode)){      // if directory
        int size = getSize(path);
        printf("%s size is %d bytes\n", path, size);
    }
    return 0;
}