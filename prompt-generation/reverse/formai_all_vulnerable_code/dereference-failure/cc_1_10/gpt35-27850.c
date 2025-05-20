//FormAI DATASET v1.0 Category: File Backup System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_FILENAME_LEN 256
#define MAX_FILENUM 1024

const char* BACKUP_DIR = "./cfile_backups/";

typedef struct{
    char filename[MAX_FILENAME_LEN];
    time_t mod_time;
} fileInfo;

void backupFile(const char* filepath){
    char* filename = strrchr(filepath, '/') + 1;
    char destpath[MAX_FILENAME_LEN + 64];
    sprintf(destpath, "%s%s_backup_%ld.c", BACKUP_DIR, filename, time(NULL));
    FILE* src = fopen(filepath, "r");
    FILE* dest = fopen(destpath, "w");
    if(src == NULL || dest == NULL){
        printf("Failed to backup file: %s!\n", filename);
        return;
    }
    int c;
    while((c = fgetc(src)) != EOF) fputc(c, dest);
    fclose(src);
    fclose(dest);
    printf("Successfully backed up file: %s\n", filename);
}

int compareFileInfo(const void* info1, const void* info2){
    fileInfo* p1 = (fileInfo*) info1;
    fileInfo* p2 = (fileInfo*) info2;
    return p2->mod_time - p1->mod_time;
}

int main(int argc, char* argv[]){
    struct dirent* entry;
    DIR* dir;
    char filepath[MAX_FILENAME_LEN];
    fileInfo files[MAX_FILENUM];
    int fileCount = 0;

    if(argc < 2){
        printf("Please specify the directory to backup.\n");
        return 0;
    }
    dir = opendir(argv[1]);
    if(dir == NULL){
        printf("Failed to open directory: %s\n", argv[1]);
        return 0;
    }

    struct stat st;

    while((entry = readdir(dir)) != NULL){
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        sprintf(filepath, "%s/%s", argv[1], entry->d_name);
        if(stat(filepath, &st) == -1){
            printf("Failed to stat file: %s\n", filepath);
            continue;
        }
        if(S_ISREG(st.st_mode) && strstr(entry->d_name, ".c") != NULL){
            strcpy(files[fileCount].filename, filepath);
            files[fileCount].mod_time = st.st_mtime;
            fileCount++;
        }
    }
    closedir(dir);

    qsort(files, fileCount, sizeof(fileInfo), compareFileInfo);

    for(int i = 0; i < fileCount && i < 10; i++){
        backupFile(files[i].filename);
    }

    return 0;
}