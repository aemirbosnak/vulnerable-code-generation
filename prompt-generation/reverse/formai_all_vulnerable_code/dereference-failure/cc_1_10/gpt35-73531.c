//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>  
#include<time.h>  
#include<fcntl.h>  
#include<unistd.h>  
#include<sys/types.h>  
#include<sys/stat.h>


typedef struct Metadata {
    char *filename;
    char *modified_time;
    char *access_time;
    char *creation_time;
    char *permission;
} Metadata;

void get_metadata(char *path, Metadata *metadata);
char *get_file_permission(struct stat st);
void print_metadata(Metadata *metadata);

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <directory or file>", argv[0]);
        exit(1);
    }
    Metadata *metadata = malloc(sizeof(Metadata));
    get_metadata(argv[1], metadata);
    print_metadata(metadata);
    free(metadata);
    return 0;
}

void get_metadata(char *path, Metadata *metadata) {
    int is_folder = 0;
    struct stat st;
    if(stat(path, &st) == -1) {
        perror("stat");
        exit(1);
    }
    if(S_ISDIR(st.st_mode)) {
        is_folder = 1;
    } else if(S_ISREG(st.st_mode)) {
        is_folder = 0;
    }
    metadata -> filename = strdup(path);
    metadata -> modified_time = strdup(ctime(&st.st_mtime));
    metadata -> access_time = strdup(ctime(&st.st_atime));
    metadata -> creation_time = strdup(ctime(&st.st_ctime));
    metadata -> permission = get_file_permission(st);  
    if(is_folder) {
        DIR *dir = opendir(path);
        if(!dir) {
            perror("opendir");
            exit(1);
        }
        struct dirent *entry;
        while((entry = readdir(dir))) {
            if(strcmp(entry -> d_name, ".") == 0 || strcmp(entry -> d_name, "..") == 0) {
                continue;
            }
            char new_path[strlen(path) + strlen(entry -> d_name) + 2];
            sprintf(new_path, "%s/%s", path, entry -> d_name);
            Metadata *new_metadata = malloc(sizeof(Metadata));
            get_metadata(new_path, new_metadata);
            printf("\n");
            print_metadata(new_metadata);
            free(new_metadata -> filename);
            free(new_metadata -> modified_time);
            free(new_metadata -> access_time);
            free(new_metadata -> creation_time);
            free(new_metadata -> permission);
            free(new_metadata);        
        }
        closedir(dir);
    }
}

char *get_file_permission(struct stat st) {
    char *permission = malloc(10);
    permission[0] = (S_ISDIR(st.st_mode)) ? 'd' : '-';
    permission[1] = (st.st_mode & S_IRUSR) ? 'r' : '-';
    permission[2] = (st.st_mode & S_IWUSR) ? 'w' : '-';
    permission[3] = (st.st_mode & S_IXUSR) ? 'x' : '-';
    permission[4] = (st.st_mode & S_IRGRP) ? 'r' : '-';
    permission[5] = (st.st_mode & S_IWGRP) ? 'w' : '-';
    permission[6] = (st.st_mode & S_IXGRP) ? 'x' : '-';
    permission[7] = (st.st_mode & S_IROTH) ? 'r' : '-';
    permission[8] = (st.st_mode & S_IWOTH) ? 'w' : '-';
    permission[9] = (st.st_mode & S_IXOTH) ? 'x' : '-';
    permission[10] = '\0';
    return permission;
}

void print_metadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata -> filename);
    printf("Modified time: %s", metadata -> modified_time);
    printf("Access time: %s", metadata -> access_time);
    printf("Creation time: %s", metadata -> creation_time);
    printf("Permission: %s\n", metadata -> permission);
}