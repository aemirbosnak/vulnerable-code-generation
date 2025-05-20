//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PATH_LENGTH 256
#define SAFE_FREE(p) {if(p){free(p); p=NULL;}}

char src_dir[MAX_PATH_LENGTH];
char dest_dir[MAX_PATH_LENGTH];

void sync_dir(char* src, char* dest);
void* sync_file(void* file);

int main(int argc, char* argv[])
{
    if(argc < 3){
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return -1;
    }

    strncpy(src_dir, argv[1], MAX_PATH_LENGTH);
    strncpy(dest_dir, argv[2], MAX_PATH_LENGTH);

    sync_dir(src_dir, dest_dir);

    return 0;
}

void sync_dir(char* src, char* dest)
{
    DIR* dir;
    struct dirent* dent;

    dir = opendir(src);
    if(!dir){
        printf("Error opening directory: %s. %s\n", src, strerror(errno));
        return;
    }

    mkdir(dest, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    while((dent=readdir(dir))){

        if(strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0){
            continue;
        }

        char* src_path = (char*) malloc(sizeof(char)*(strlen(src) + strlen(dent->d_name) + 2));
        snprintf(src_path, MAX_PATH_LENGTH, "%s/%s", src, dent->d_name);

        char* dest_path = (char*) malloc(sizeof(char)*(strlen(dest) + strlen(dent->d_name) + 2));
        snprintf(dest_path, MAX_PATH_LENGTH, "%s/%s", dest, dent->d_name);

        struct stat src_stat;
        if(stat(src_path, &src_stat) != 0){
            printf("Error getting file status: %s. %s\n", src_path, strerror(errno));
            SAFE_FREE(src_path);
            SAFE_FREE(dest_path);
            continue;
        }

        if(S_ISDIR(src_stat.st_mode)){
            sync_dir(src_path, dest_path);
        }
        else if(S_ISREG(src_stat.st_mode)){
            pthread_t th;
            if(pthread_create(&th, NULL, sync_file, (void*)src_path) != 0){
                printf("Error creating thread for file: %s. %s\n", src_path, strerror(errno));
                SAFE_FREE(src_path);
                SAFE_FREE(dest_path);
                continue;
            }
            pthread_detach(th);
        }

        SAFE_FREE(src_path);
        SAFE_FREE(dest_path);
    }

    closedir(dir);
}

void* sync_file(void* file)
{
    char* src_file = (char*)file;

    char* rel_path = src_file + strlen(src_dir) + 1;

    char dest_file[MAX_PATH_LENGTH];
    snprintf(dest_file, MAX_PATH_LENGTH, "%s/%s", dest_dir, rel_path);

    FILE* f_src = fopen(src_file, "rb");
    if(!f_src){
        printf("Error opening file for reading: %s. %s\n", src_file, strerror(errno));
        return NULL;
    }

    FILE* f_dest = fopen(dest_file, "wb");
    if(!f_dest){
        printf("Error opening file for writing: %s. %s\n", dest_file, strerror(errno));
        fclose(f_src);
        return NULL;
    }

    fseek(f_src, 0, SEEK_END);
    long file_size = ftell(f_src);

    fseek(f_src, 0, SEEK_SET);

    char buffer[1024];
    int bytes_read=0;
    while((bytes_read=fread(buffer, 1, 1024, f_src)) > 0){
        fwrite(buffer, 1, bytes_read, f_dest);
        file_size -= bytes_read;
    }

    if(file_size!=0){
        printf("Error writing file: %s. %s\n", dest_file, strerror(errno));
    }

    fclose(f_src);
    fclose(f_dest);

    return NULL;
}