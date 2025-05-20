//FormAI DATASET v1.0 Category: File Synchronizer ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

int sync_files(char* source, char* destination){
    DIR *dir;
    struct dirent *entry;
    char source_path[200], destination_path[200], source_file[200], destination_file[200], buffer[4096];
    FILE *src_file, *dst_file;
    int missing_files = 0;
    
    // Open source directory
    dir = opendir(source);
    if(dir == NULL){
        printf("\nError: Unable to open source directory %s\n", source);
        return 1;
    }
    
    // Loop through all files in directory
    while((entry = readdir(dir)) != NULL){
        strcpy(source_file, entry->d_name);
        if(strcmp(source_file, ".") == 0 || strcmp(source_file, "..") == 0){
            continue;
        }
        
        // Check if file exists in destination directory
        sprintf(destination_file, "%s/%s", destination, source_file);
        if(access(destination_file, 0) == 0){
            // Open source and destination files for reading and writing respectively
            sprintf(source_path, "%s/%s", source, source_file);
            src_file = fopen(source_path, "rb");
            dst_file = fopen(destination_file, "wb");
            
            // Read from source and write to destination
            while(fread(buffer, 1, sizeof(buffer), src_file) > 0){
                fwrite(buffer, 1, sizeof(buffer), dst_file);
            }
            
            // Close source and destination files
            fclose(src_file);
            fclose(dst_file);
            
            printf("File %s synchronized.\n", source_file);
        }
        else{
            printf("File %s does not exist in the destination directory.\n", source_file);
            missing_files++;
        }
    }
    
    if(missing_files > 0){
        printf("%d files missing in destination directory.\n", missing_files);
        return 1;
    }
    
    return 0;
}

int main(){
    char source[200], destination[200];
    int status;
    
    printf("Enter source directory path: ");
    scanf("%s", source);
    printf("Enter destination directory path: ");
    scanf("%s", destination);
    
    // Synchronize files from source to destination directory
    status = sync_files(source, destination);
    
    if(status == 0){
        printf("File synchronization successful.\n");
    }
    else{
        printf("File synchronization failed.\n");
    }
    
    return 0;
}