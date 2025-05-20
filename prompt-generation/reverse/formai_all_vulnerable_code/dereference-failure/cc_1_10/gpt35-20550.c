//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

void analyze(char* ); //Function to analyze disk space

int main()
{
    char path[200];
    printf("Welcome to the hilarious Disk Space Analyzer!\n");
    printf("Enter the path to a directory you want analyzed: ");
    scanf("%s", path);
    analyze(path);
    printf("\n\nAt the end of the day, aren't we all just folders trying to find our place in this world?\n");
    return 0;
}

void analyze(char* path){
    DIR* dir; //Directory pointer
    struct dirent* ent; //Directory entry pointer
    long long total_size=0; //Total size of directory in bytes
    dir = opendir(path); //Open directory
    if(dir != NULL){
        while((ent = readdir(dir))!=NULL){ //Read directory entry
            if(ent->d_type == DT_DIR){ //Check if it's a directory
                if(strcmp(ent->d_name, ".")!=0 && strcmp(ent->d_name, "..")!=0){ //Ignore self and parent directories
                    char* subdir = malloc(strlen(path) + strlen(ent->d_name) + 2); //Allocate memory for the subdirectory
                    sprintf(subdir, "%s/%s", path, ent->d_name); //Create the path to the subdirectory
                    analyze(subdir); //Analyze the subdirectory
                    free(subdir); //Free memory
                }
            }else{ //If it's a file
                char* filepath = malloc(strlen(path) + strlen(ent->d_name) + 2); //Allocate memory for the file path
                sprintf(filepath, "%s/%s", path, ent->d_name); //Create the file path
                FILE* file = fopen(filepath, "rb"); //Open the file
                if(file){ //If file exists
                    fseek(file, 0, SEEK_END); //Move file pointer to end of file
                    long long size = ftell(file); //Get size of file
                    printf("%s: %lld bytes\n", filepath, size); //Print file size
                    total_size+=size; //Add file size to total size
                    fclose(file); //Close file
                }else{
                    printf("Error opening file: %s\n", filepath);
                }
                free(filepath); //Free memory
            }
        }
        closedir(dir); //Close directory
    }else{
        printf("Error opening directory: %s\n", path);
    }
    printf("Total size of directory: %lld bytes\n", total_size); //Print total size of directory
}