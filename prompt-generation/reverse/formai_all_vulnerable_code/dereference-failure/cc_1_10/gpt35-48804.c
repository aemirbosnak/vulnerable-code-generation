//FormAI DATASET v1.0 Category: File Synchronizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

void copy_file(const char *source_path, const char *dest_path){
    int source_fd = open(source_path,O_RDONLY);
    struct stat source_stat;
    fstat(source_fd,&source_stat);
    int dest_fd = creat(dest_path,source_stat.st_mode);
    char buffer[BUFSIZ];
    ssize_t read_count;
    while((read_count = read(source_fd,buffer,sizeof(buffer)))>0){
        write(dest_fd,buffer,read_count);
    }
    close(source_fd);
    close(dest_fd);
    printf("Copied %s to %s\n",source_path,dest_path);
}

void sync_files(const char *source_path, const char *dest_path){
    DIR *source_dir = opendir(source_path);
    DIR *dest_dir = opendir(dest_path);
    struct dirent *source_entry;
    struct dirent *dest_entry;
    while((source_entry = readdir(source_dir)) != NULL){
        char *file_name = source_entry->d_name;
        if(strcmp(file_name,".") == 0 || strcmp(file_name,"..") == 0){
            continue;
        }
        char source_file[PATH_MAX];
        char dest_file[PATH_MAX];
        sprintf(source_file,"%s/%s",source_path,file_name);
        sprintf(dest_file,"%s/%s",dest_path,file_name);
        struct stat source_stat;
        stat(source_file,&source_stat);
        if(S_ISDIR(source_stat.st_mode)){
            DIR *sub_source_dir = opendir(source_file);
            DIR *sub_dest_dir = opendir(dest_file);
            if(sub_dest_dir == NULL){
                mkdir(dest_file, source_stat.st_mode);
                printf("Created directory %s\n",dest_file);
            }
            sync_files(source_file, dest_file);
            closedir(sub_source_dir);
            closedir(sub_dest_dir);
            continue;
        }
        dest_entry = NULL;
        while((dest_entry = readdir(dest_dir)) != NULL){
            if(strcmp(dest_entry->d_name,file_name) == 0){
                break;
            }
        }
        if(dest_entry == NULL){
            copy_file(source_file, dest_file);
        }
        else{
            char dest_file_full[PATH_MAX];
            sprintf(dest_file_full,"%s/%s",dest_path, dest_entry->d_name);
            struct stat dest_stat;
            stat(dest_file_full,&dest_stat);
            if(dest_entry->d_type != source_entry->d_type || source_stat.st_mtime > dest_stat.st_mtime){
                copy_file(source_file, dest_file_full);
            }
        }
        rewinddir(dest_dir);
    }
    closedir(source_dir);
    closedir(dest_dir);
}

int main(int argc, char *argv[]){
    if(argc < 3){
        fprintf(stderr, "Usage: %s source_dir dest_dir\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const char *source_path = argv[1];
    const char *dest_path = argv[2];
    printf("Synchronizing %s with %s\n",source_path,dest_path);
    sync_files(source_path,dest_path);
    printf("Done synchronizing\n");
    return 0;
}