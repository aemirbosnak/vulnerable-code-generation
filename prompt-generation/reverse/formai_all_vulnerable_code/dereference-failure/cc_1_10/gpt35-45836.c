//FormAI DATASET v1.0 Category: File system simulation ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int file_id;
    char* file_name;
    char* file_type;
    int file_size;
} File;

File* files[50];
int num_files = 0;

void create_file() {
    File* f = (File*) malloc(sizeof(File));
    printf("\nEnter the file id: ");
    scanf("%d", &f->file_id);
    printf("Enter the file name: ");
    scanf("%s", f->file_name);
    printf("Enter the file type: ");
    scanf("%s", f->file_type);
    printf("Enter the file size: ");
    scanf("%d", &f->file_size);
    files[num_files++] = f;
}

void display_files() {
    printf("\nFile id\tFile name\tFile type\tFile size\n");
    for(int i=0; i<num_files; i++) {
        printf("%d\t%s\t\t%s\t\t%d\n", files[i]->file_id, files[i]->file_name, files[i]->file_type, files[i]->file_size);
    }
}

void delete_file() {
    int id;
    printf("\nEnter the id of the file to be deleted: ");
    scanf("%d", &id);
    int index = -1;
    for(int i=0; i<num_files; i++) {
        if(files[i]->file_id == id) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("\nFile not found!\n");
        return;
    }
    num_files--;
    free(files[index]);
    for(int i=index; i<num_files; i++) {
        files[i] = files[i+1];
    }
    printf("\nFile deleted successfully!\n");
}

int main() {
    int choice;
    while(1) {
        printf("\n1. Create a file\n2. Display all files\n3. Delete a file\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: create_file();
                    break;
            case 2: display_files();
                    break;
            case 3: delete_file();
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }
    return 0;
}