//FormAI DATASET v1.0 Category: File Backup System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pthread.h>

#define MAX_BACKUPS 5 // maximum number of backups allowed
#define BACKUP_INTERVAL 60 // backup interval in seconds
#define FILE_BUFFER_SIZE 1024 // file buffer size in bytes
#define MAX_PATH_LENGTH 256 // maximum path length

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// function to create a new backup directory
void create_backup_directory(char *backup_dir) {
    time_t rawtime;
    struct tm *timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    sprintf(backup_dir, "backup_%04d%02d%02d_%02d%02d%02d",
            timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    
    if(mkdir(backup_dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1) {
        printf("Failed to create backup directory %s\n", backup_dir);
        exit(1);
    }
}

// function to copy a file to a backup directory
void copy_file(char *filename, char *backup_dir) {
    char source_path[MAX_PATH_LENGTH], backup_path[MAX_PATH_LENGTH];
    sprintf(source_path, "./%s", filename);
    sprintf(backup_path, "./%s/%s", backup_dir, filename);
    
    FILE *source_file, *backup_file;
    source_file = fopen(source_path, "r");
    backup_file = fopen(backup_path, "w");
    
    if(!source_file || !backup_file) {
        printf("Failed to open file %s or %s\n", source_path, backup_path);
        exit(1);
    }
    
    char buffer[FILE_BUFFER_SIZE];
    int read_count;
    while((read_count = fread(buffer, sizeof(char), FILE_BUFFER_SIZE, source_file)) > 0) {
        fwrite(buffer, sizeof(char), read_count, backup_file);
    }
    
    fclose(source_file);
    fclose(backup_file);
}

// function to delete the oldest backup directory
void delete_oldest_backup() {
    DIR *dir;
    char oldest_backup[MAX_PATH_LENGTH];
    time_t oldest_time;
    struct dirent *entry;
    struct stat st;
    
    dir = opendir(".");
    if(!dir) {
        printf("Failed to open current directory\n");
        exit(1);
    }
    
    oldest_time = time(NULL);
    while((entry = readdir(dir))) {
        if(entry->d_type == DT_DIR && strncmp(entry->d_name, "backup_", 7) == 0) {
            stat(entry->d_name, &st);
            if(st.st_mtime < oldest_time) {
                oldest_time = st.st_mtime;
                strcpy(oldest_backup, entry->d_name);
            }
        }
    }
    
    if(strlen(oldest_backup) > 0) {
        printf("Deleting oldest backup %s\n", oldest_backup);
        char command[MAX_PATH_LENGTH + 10];
        sprintf(command, "rm -r %s", oldest_backup);
        system(command);
    }
    
    closedir(dir);
}

// function to perform backup
void perform_backup() {
    pthread_mutex_lock(&mutex);
    
    // check if maximum number of backups has been exceeded
    DIR *dir;
    int backup_count = 0;
    struct dirent *entry;
    
    dir = opendir(".");
    if(!dir) {
        printf("Failed to open current directory\n");
        exit(1);
    }
    
    while((entry = readdir(dir))) {
        if(entry->d_type == DT_DIR && strncmp(entry->d_name, "backup_", 7) == 0) {
            backup_count++;
        }
    }
    
    if(backup_count >= MAX_BACKUPS) {
        delete_oldest_backup();
    }
    
    // create new backup directory
    char backup_dir[MAX_PATH_LENGTH];
    create_backup_directory(backup_dir);
    
    // copy all files in current directory to backup directory
    dir = opendir(".");
    if(!dir) {
        printf("Failed to open current directory\n");
        exit(1);
    }
    
    while((entry = readdir(dir))) {
        if(entry->d_type == DT_REG) {
            copy_file(entry->d_name, backup_dir);
        }
    }
    
    closedir(dir);
    
    printf("Backup completed at %s\n", backup_dir);
    
    pthread_mutex_unlock(&mutex);
}

int main() {
    while(1) {
        perform_backup();
        sleep(BACKUP_INTERVAL);
    }
    
    return 0;
}