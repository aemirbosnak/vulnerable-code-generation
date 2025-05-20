//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 64
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_SIZE];
    int size;
} File;

int main() {
    char choice;
    File file_system[10];
    int num_files = 0;

    do {
        system("clear");
        printf("Welcome to File System Simulator\n");
        printf("1. Create File\n2. Open File\n3. Edit File\n4. Delete File\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_files < 10) {
                    printf("Enter file name: ");
                    scanf("%s", file_system[num_files].name);
                    printf("Enter file content: ");
                    scanf("%[^\n]", file_system[num_files].content);
                    file_system[num_files].size = strlen(file_system[num_files].content);
                    num_files++;
                    printf("File created successfully\n");
                } else {
                    printf("Maximum number of files reached\n");
                }
                break;
            case '2':
                printf("Enter file name: ");
                scanf("%s", file_system[num_files-1].name);
                printf("File content:\n%s\n", file_system[num_files-1].content);
                break;
            case '3':
                printf("Enter file name: ");
                scanf("%s", file_system[num_files-1].name);
                printf("Enter new content: ");
                scanf("%[^\n]", file_system[num_files-1].content);
                file_system[num_files-1].size = strlen(file_system[num_files-1].content);
                printf("File edited successfully\n");
                break;
            case '4':
                printf("Enter file name: ");
                scanf("%s", file_system[num_files-1].name);
                printf("File deleted successfully\n");
                num_files--;
                break;
            case '5':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while(choice!= '5');

    return 0;
}