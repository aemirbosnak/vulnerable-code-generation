//FormAI DATASET v1.0 Category: File Synchronizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to check if a file or directory exists
int checkExistence(char *path){
    struct stat stats;
    if(stat(path, &stats) == -1){
        return 0;
    }else{
        return 1;
    }
}

// Function to synchronize two directories
void syncDirectories(char *source, char *destination){
    DIR *dir;
    struct dirent *entry;
    char pathSource[256], pathDestination[256];
    dir = opendir(source);

    if(dir){
        while((entry = readdir(dir)) != NULL){
            if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){
                sprintf(pathSource, "%s/%s", source, entry->d_name);
                sprintf(pathDestination, "%s/%s", destination, entry->d_name);
                if(checkExistence(pathDestination) == 0){
                    // File or directory does not exist in destination
                    if(checkExistence(pathSource) == 1){
                        // File or directory exists in source
                        if(entry->d_type == DT_DIR){
                            // Directory
                            mkdir(pathDestination, 0700);
                            printf("Directory %s created in destination\n", entry->d_name);
                            syncDirectories(pathSource, pathDestination);
                        }else{
                            // File
                            FILE *fsrc = fopen(pathSource, "r");
                            FILE *fdst = fopen(pathDestination, "w");
                            char c;
                            while((c = fgetc(fsrc)) != EOF){
                                fputc(c, fdst);
                            }
                            printf("File %s copied to destination\n", entry->d_name);
                            fclose(fsrc);
                            fclose(fdst);
                        }
                    }
                }else{
                    // File or directory exists in destination
                    if(checkExistence(pathSource) == 1){
                        // File or directory exists in source
                        if(entry->d_type == DT_DIR){
                            // Directory
                            syncDirectories(pathSource, pathDestination);
                        }else{
                            // File
                            FILE *fsrc = fopen(pathSource, "r");
                            FILE *fdst = fopen(pathDestination, "r");
                            if(fsrc && fdst){
                                // Compare file modification times
                                struct stat statSrc, statDst;
                                stat(pathSource, &statSrc);
                                stat(pathDestination, &statDst);
                                if(difftime(statSrc.st_mtime, statDst.st_mtime) > 0){
                                    // Source file is newer than destination file
                                    fclose(fdst);
                                    fdst = fopen(pathDestination, "w");
                                    char c;
                                    while((c = fgetc(fsrc)) != EOF){
                                        fputc(c, fdst);
                                    }
                                    printf("File %s updated in destination\n", entry->d_name);
                                    fclose(fdst);
                                    fclose(fsrc);
                                }else{
                                    // Source file is older or equal to destination file
                                    printf("File %s is already up to date in destination\n", entry->d_name);
                                    fclose(fsrc);
                                    fclose(fdst);
                                }
                            }
                        }
                    }else{
                        // File or directory does not exist in source
                        if(entry->d_type == DT_DIR){
                            // Directory
                            printf("Directory %s removed from destination\n", entry->d_name);
                            char rmPath[256];
                            sprintf(rmPath, "rm -rf %s", pathDestination);
                            system(rmPath);
                        }else{
                            // File
                            printf("File %s removed from destination\n", entry->d_name);
                            remove(pathDestination);
                        }
                    }
                }
            }
        }
        closedir(dir);
    }
}

int main(){
    char source[256], destination[256];
    printf("Enter source directory: ");
    scanf("%s", &source);
    printf("Enter destination directory: ");
    scanf("%s", &destination);
    syncDirectories(source, destination);
    return 0;
}