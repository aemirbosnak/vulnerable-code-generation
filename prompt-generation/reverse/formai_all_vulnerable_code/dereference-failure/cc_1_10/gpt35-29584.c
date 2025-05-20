//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

long long int totalSize = 0; // Global variable to keep track of total disk space used

void analyzeDisk(char* path) { // Function to analyze disk space used by a file/directory
    
    struct stat st;
    stat(path, &st); // Get information about the path provided
    long long int size = st.st_size; // Get the size of the file/directory
    
    if(S_ISDIR(st.st_mode)) { // If the path is a directory
        
        DIR* dir = opendir(path); // Open the directory
        
        if(!dir) { // If cannot open directory
            printf("Cannot open directory: %s\n", path);
            return;
        }
        
        struct dirent* entry; // Entry to a file inside the directory
        
        while((entry = readdir(dir)) != NULL) { // Iterate over all files inside directory
            
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) { // Ignore current and parent directories
                continue;
            }
            
            char nextPath[1000]; // Path of next file/directory to analyze
            sprintf(nextPath, "%s/%s", path, entry->d_name); // Construct path of next file/directory
            analyzeDisk(nextPath); // Analyze the disk space used by that file/directory
        }
        
        closedir(dir); // Close the directory
    }
    
    totalSize += size; // Add the size of the file/directory to the total disk space used
}

int main() {
    
    char path[1000]; // Path of file/directory to analyze
    printf("Enter the path of the file/directory to analyze: ");
    scanf("%s", path);
    
    analyzeDisk(path); // Analyze the disk space used by the file/directory
    
    printf("\nTotal disk space used by file/directory: %lld bytes\n", totalSize);
    return 0;
}