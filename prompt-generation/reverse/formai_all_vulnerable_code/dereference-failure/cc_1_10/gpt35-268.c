//FormAI DATASET v1.0 Category: File system simulation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int inode_number;
    char filename[10];
}inode;

int main(){
    printf("Surprise!!! Welcome to the C File System Simulation Program. \n\n");

    // Initializing File System 
    int no_of_files = 0;
    inode* files=(inode*)malloc(sizeof(inode)*50);

    //Adding some files
    strcpy(files[no_of_files].filename, "file1.txt");
    files[no_of_files].inode_number = no_of_files++;
    strcpy(files[no_of_files].filename, "file2.txt");
    files[no_of_files].inode_number = no_of_files++;
    strcpy(files[no_of_files].filename, "file3.txt");
    files[no_of_files].inode_number = no_of_files++;
    strcpy(files[no_of_files].filename, "file4.txt");
    files[no_of_files].inode_number = no_of_files++;

    printf("Number of files in the file system: %d \n", no_of_files);

    // Trying to add a new file but there's not enough space!
    if(no_of_files==50){
        printf("Uh oh! The file system is full. Sorry, we can't add any more files. \n");
    }

    // Trying to search a file that doesn't exist yet
    int i;
    char search_file[10];
    strcpy(search_file, "file5.txt");
    for(i=0;i<no_of_files;i++){
        if(strcmp(search_file, files[i].filename)==0){
            printf("Yay! File found at inode number: %d \n", files[i].inode_number);
            break;
        }
    }
    if(i==no_of_files){
        printf("Oops! File not found in the file system. \n");
    }

    // Deleting a file
    printf("\nDeleting file with inode number 2. \n");
    for(i=0;i<no_of_files;i++){
        if(files[i].inode_number==2){
            no_of_files--;
            for(int j=i; j<no_of_files; j++){
                files[j] = files[j+1];
            }
            break;
        }
    }
    printf("File Deleted. Current number of files: %d \n", no_of_files);

    // Adding a new file
    strcpy(files[no_of_files].filename, "file5.txt");
    files[no_of_files].inode_number = no_of_files++;
    printf("\nAdded new file, number of files in the file system now: %d \n", no_of_files);

    //Listing all files in the file system
    printf("\nThe files in the file system are: \n");
    for(i=0;i<no_of_files;i++){
        printf("%s \n", files[i].filename);
    }

    // Freeing memory
    free(files);
    printf("\nThank you for using the C File System Simulation Program. \n");

    return 0;
}