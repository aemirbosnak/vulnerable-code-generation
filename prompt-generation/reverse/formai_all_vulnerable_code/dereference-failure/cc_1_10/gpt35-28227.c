//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct{
    long long totalSize; // size of all files and subdirectories combined
    char name[PATH_MAX+1]; // name of directory or file
} FileInfo;

/*
* Recursively calculates total size of all files and directories within a given path
* and stores it in an array of type FileInfo.
*/
int calculateDirectorySize(char* path, FileInfo* info, int index){
    DIR* dir;
    struct dirent* entry;
    struct stat fileStats;
    char curPath[PATH_MAX+1];
    int i = index;

    // Open directory
    if((dir = opendir(path)) != NULL){
        // Iterate through directory entries
        while((entry = readdir(dir)) != NULL){
            // Ignore parent and current directory entries
            if(strcmp(entry->d_name,".") != 0 && strcmp(entry->d_name,"..") != 0){
                // Create full path to current entry
                snprintf(curPath, PATH_MAX+1, "%s/%s", path, entry->d_name);

                // Get file/directory statistics
                if(lstat(curPath, &fileStats) == 0){
                    // If entry is a file
                    if(S_ISREG(fileStats.st_mode)){
                        info[i].totalSize = fileStats.st_size;
                        strncpy(info[i].name, curPath, PATH_MAX);
                        i++;
                    }
                    // If entry is a directory
                    else if(S_ISDIR(fileStats.st_mode)){
                        FileInfo subdirInfo;
                        subdirInfo.totalSize = 0;
                        strncpy(subdirInfo.name, curPath, PATH_MAX);
                        i = calculateDirectorySize(curPath, &subdirInfo, i+1);
                        info[i] = subdirInfo;
                        i++;
                    }
                }
                // Error reading file/directory stats
                else{
                    printf("Error reading file stats for %s\n", curPath);
                }
            }
        }
        // Close directory
        closedir(dir);
    }
    // Error opening directory
    else{
        printf("Error opening directory %s\n", path);
    }

    return i;
}

/*
* Print directory size information that is stored in the array of type FileInfo.
*/
void printDirectorySizeInfo(FileInfo* info, int size){
    for(int i=0; i<size; i++){
        printf("%lld\t%s\n", info[i].totalSize, info[i].name);
    }
}

int main(int argc, char** argv){
    // Check if path was provided as command line argument
    if(argc > 1){
        FileInfo rootInfo;
        rootInfo.totalSize = 0;
        strncpy(rootInfo.name, argv[1], PATH_MAX);

        FileInfo* fileInfoList = calloc(100, sizeof(FileInfo));
        fileInfoList[0] = rootInfo;
        int size = calculateDirectorySize(argv[1], fileInfoList, 1);
        printDirectorySizeInfo(fileInfoList, size);
        
        free(fileInfoList);
    }
    else{
        printf("Please provide a path to calculate size of\n");
        return 1;
    }

    return 0;
}