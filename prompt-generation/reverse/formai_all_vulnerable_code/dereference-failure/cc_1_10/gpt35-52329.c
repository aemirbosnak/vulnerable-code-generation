//FormAI DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
 
#define MAX_SIZE 1024
 
typedef struct {
    char *name;
    char *date;
} FileData;
 
void backup(char *src, char *dest) {
    DIR *dir;
    struct dirent *dp;
    struct stat sb;
    char *src_file = (char*) malloc(sizeof(char) * MAX_SIZE);
    char *dest_file = (char*) malloc(sizeof(char) * MAX_SIZE);
    char *src_path = (char*) malloc(sizeof(char) * MAX_SIZE);
    char *dest_path = (char*) malloc(sizeof(char) * MAX_SIZE);
    time_t now;
    struct tm *local;
    char date[MAX_SIZE];
    FileData *files;
    int i = 0, j = 0;
 
    dir = opendir(src);
    while ((dp = readdir(dir)) != NULL) {
        if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }
        sprintf(src_file, "%s/%s", src, dp->d_name);
        sprintf(dest_file, "%s/%s", dest, dp->d_name);
        if (stat(src_file, &sb) == -1) {
            printf("Error: Failed to access %s\n", src_file);
            continue;
        }
        if (S_ISDIR(sb.st_mode)) {
            backup(src_file, dest_file);
            continue;
        }
        now = sb.st_mtime;
        local = localtime(&now);
        strftime(date, MAX_SIZE, "%Y%m%d%H%M%S", local);
        sprintf(src_path, "%s/%s", src, dp->d_name);
        sprintf(dest_path, "%s/%s_%s", dest, dp->d_name, date);
        if (link(src_path, dest_path) == -1) {
            printf("Error: Failed to create backup for %s\n", src_file);
        } else {
            files[i].name=dp->d_name;
            files[i].date=date;
            i++;
        }
    }
    closedir(dir);
    printf("\nBackup created successfully!\n\n%s\n\n", dest);
    printf("Details:\n\n");
    for(j = 0; j < i; j++)
    {
        printf("%d. %s - %s\n", j+1, files[j].name, files[j].date);
    }   
}
 
int main() {
    char *src, *dest;
    src= "/home/user/file_folder";
    dest="/home/user/backup_folder";
    backup(src, dest);
    return 0;
}