//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

//Defining the function that will be used to scan files
void scanFile(char* filePath);

//Main function
int main(int argc, char* argv[]) {

    //Checking if the path is passed as argument
    if (argc < 2) {
        printf("Path not provided as argument.\n");
        exit(0);
    }

    //Creating a pointer for directory structure
    DIR* directory;
    struct dirent* files;

    //Opening the specified directory
    directory = opendir(argv[1]);

    //Checking if directory successfully opened
    if(directory == NULL) {
        printf("Could not open directory.\n");
        exit(0);
    }

    //Loop through each file in directory
    while ((files = readdir(directory)) != NULL) {
        //Checking if file is a regular file and not a directory
        if(files->d_type == DT_REG) {
            //Creating the complete file path by concatenating directory and file name
            char filePath[strlen(argv[1])+strlen(files->d_name)+2];
            strcpy(filePath, argv[1]);
            strcat(filePath, "/");
            strcat(filePath, files->d_name);

            //Scanning the file for viruses
            scanFile(filePath);
        }
    }
    //Closing the directory
    closedir(directory);
    //Returning 0 from main
    return 0;
}

//Function to scan a file for viruses
void scanFile(char* filePath) {
    FILE* file;
    char buffer[1024];
    int virusFound = 0;

    //Opening the file
    file = fopen(filePath, "r");

    //Checking if file successfully opened
    if(file == NULL) {
        printf("Unable to open: %s\n", filePath);
        return;
    }

    //Reading the file in chunks of 1024 bytes
    while(fread(buffer, 1, 1024, file) == 1024) {
        //Checking if the file contains virus signatures
        if(strstr(buffer, "virus1") != NULL || strstr(buffer, "virus2") != NULL) {
            printf("%s is infected with virus.\n", filePath);
            virusFound = 1;
            break;
        }
    }
    //Closing the file
    fclose(file);

    //Printing message if virus not found
    if(!virusFound) {
        printf("%s is clean.\n", filePath);
    }
}