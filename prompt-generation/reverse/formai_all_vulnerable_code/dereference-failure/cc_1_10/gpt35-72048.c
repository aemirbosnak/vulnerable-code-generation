//FormAI DATASET v1.0 Category: File Synchronizer ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void sync_files(char *dir1, char *dir2);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: ./sync [directory 1] [directory 2]\n");
        return 1;
    }
    sync_files(argv[1], argv[2]);
    return 0;
}

void sync_files(char *dir1, char *dir2) {
    DIR *d1 = opendir(dir1);
    DIR *d2 = opendir(dir2);
    if(d1==NULL || d2==NULL) {
        printf("Error: Could not open directories.\n");
    }
    
    struct dirent *dir_1, *dir_2;
    struct stat file_info_1, file_info_2;
    while((dir_1=readdir(d1)) != NULL) {
        // Skip hidden files
        if(dir_1->d_name[0] == '.') {
            continue;
        }
        char path1[100], path2[100];
        sprintf(path1, "%s/%s", dir1, dir_1->d_name);
        sprintf(path2, "%s/%s", dir2, dir_1->d_name);
        
        stat(path1, &file_info_1);
        // If file exists in dir 2, compare modified times
        if((dir_2 = opendir(dir2)) != NULL) {
            while((dir_2=readdir(d2)) != NULL) {
                if(strcmp(dir_1->d_name, dir_2->d_name) == 0) {
                    stat(path2, &file_info_2);
                    if(file_info_1.st_mtime > file_info_2.st_mtime) {
                        // If file in dir 1 is more recent, copy to dir 2
                        FILE *fp1 = fopen(path1, "r");
                        FILE *fp2 = fopen(path2, "w");
                        if(fp1==NULL || fp2==NULL) {
                            printf("Error: Could not open file.\n");
                            return;
                        }
                        char c;
                        while((c=fgetc(fp1)) != EOF) {
                            fputc(c, fp2);
                        }
                        fclose(fp1);
                        fclose(fp2);
                        printf("Updated file: %s\n", path2);
                    }
                    else if(file_info_2.st_mtime > file_info_1.st_mtime) {
                        // If file in dir 2 is more recent, copy to dir 1
                        FILE *fp1 = fopen(path1, "w");
                        FILE *fp2 = fopen(path2, "r");
                        if(fp1==NULL || fp2==NULL) {
                            printf("Error: Could not open file.\n");
                            return;
                        }
                        char c;
                        while((c=fgetc(fp2)) != EOF) {
                            fputc(c, fp1);
                        }
                        fclose(fp1);
                        fclose(fp2);
                        printf("Updated file: %s\n", path1);
                    }
                    break;
                }
            }
        }
        else {
            printf("Error: Could not open directory 2.\n");
            return;
        }
        closedir(dir_2);
    }
    closedir(d1);
    closedir(d2);
    printf("Sync complete.\n");
}