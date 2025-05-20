//FormAI DATASET v1.0 Category: File system simulation ; Style: minimalist
#include <stdio.h>
#include <string.h>

# define MAX_FILES 10
# define MAX_NAME_LENGTH 50
# define MAX_FILE_SIZE 500

struct file {
    char name[MAX_NAME_LENGTH];
    char content[MAX_FILE_SIZE];  //Content of the file
    int size;                     //Size of the file
};

struct directory {
    char name[MAX_NAME_LENGTH];
    struct file files[MAX_FILES];
    int num_files;                //Number of files in the directory
};

int main() {
    struct directory root;
    strcpy(root.name, "root");
    root.num_files = 0;

    //Creating a file in root
    struct file file_1;
    strcpy(file_1.name, "file_1.txt");
    strcpy(file_1.content, "This is the content of file_1");
    file_1.size = strlen(file_1.content) + 1;
    root.files[0] = file_1;
    root.num_files++;

    //Creating a directory in root
    struct directory dir_1;
    strcpy(dir_1.name, "dir_1");
    dir_1.num_files = 0;

    //Creating a file in dir_1
    struct file file_2;
    strcpy(file_2.name, "file_2.txt");
    strcpy(file_2.content, "This is the content of file_2");
    file_2.size = strlen(file_2.content) + 1;
    dir_1.files[0] = file_2;
    dir_1.num_files++;

    //Adding dir_1 to root
    root.files[1] = *(struct file *)(&dir_1);
    root.num_files++;

    //Printing the files in root
    printf("Files in root:\n");
    for(int i = 0; i < root.num_files; ++i){
        printf("%s\n", root.files[i].name);
    }

    //Printing the files in dir_1
    printf("\nFiles in dir_1:\n");
    struct directory *p_dir = (struct directory *)(&root.files[1]); //type cast to directory struct
    for(int i = 0; i < p_dir->num_files; ++i){
        printf("%s\n", p_dir->files[i].name);
    }

    return 0;
}