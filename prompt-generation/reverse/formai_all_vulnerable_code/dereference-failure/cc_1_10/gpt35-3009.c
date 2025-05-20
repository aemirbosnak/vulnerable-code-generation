//FormAI DATASET v1.0 Category: File Synchronizer ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_NAME_LEN 30
#define MAX_FILE_SIZE 1024
#define MAX_SYNC_FOLDERS 10

typedef struct {
    char *file_name;
    int file_size;
} file;

typedef struct {
    char *folder_name;
    file *files;
    int num_files;
} folder;

typedef struct {
    folder *folders[MAX_SYNC_FOLDERS];
    int num_folders;
} sync_folders;

void sync_files(sync_folders *sync_f) {
    int i, j, k, l;
    for(i=0; i < sync_f->num_folders; i++) {
        for(j=0; j < sync_f->folders[i]->num_files; j++) {
            for(k=0; k < sync_f->num_folders; k++) {
                if(i != k) {
                    folder *from_folder = sync_f->folders[i];
                    folder *to_folder = sync_f->folders[k];
                    int found = 0;
                    for(l=0; l < to_folder->num_files; l++) {
                        if(strcmp(to_folder->files[l].file_name, from_folder->files[j].file_name) == 0) {
                            found = 1;
                            if(to_folder->files[l].file_size != from_folder->files[j].file_size) {
                                printf("Updating file %s in %s from %s\n", to_folder->files[l].file_name, to_folder->folder_name, from_folder->folder_name);
                                to_folder->files[l].file_size = from_folder->files[j].file_size;
                            }
                            break;
                        }
                    }
                    if(!found) {
                        printf("Copying file %s from %s to %s\n", from_folder->files[j].file_name, from_folder->folder_name, to_folder->folder_name);
                        file *new_file = malloc(sizeof(file));
                        new_file->file_name = strdup(from_folder->files[j].file_name);
                        new_file->file_size = from_folder->files[j].file_size;
                        to_folder->files = realloc(to_folder->files, (to_folder->num_files+1)*sizeof(file));
                        to_folder->files[to_folder->num_files] = *new_file;
                        to_folder->num_files++;
                    }
                }
            }
        }
    }
}

void print_folder(folder *f) {
    printf("Folder %s contains:\n", f->folder_name);
    int i;
    for(i=0; i < f->num_files; i++) {
        printf("\tFile %s, size %d bytes\n", f->files[i].file_name, f->files[i].file_size);
    }
}

void print_sync_folders(sync_folders *sync_f) {
    int i;
    for(i=0; i < sync_f->num_folders; i++) {
        print_folder(sync_f->folders[i]);
    }
}

int main() {
    sync_folders *my_sync = malloc(sizeof(sync_folders));
    folder *folder1 = malloc(sizeof(folder));
    folder1->folder_name = strdup("Folder1");
    folder *folder2 = malloc(sizeof(folder));
    folder2->folder_name = strdup("Folder2");
    file *file1 = malloc(sizeof(file));
    file1->file_name = strdup("File1.txt");
    file1->file_size = 1024;
    file *file2 = malloc(sizeof(file));
    file2->file_name = strdup("File2.txt");
    file2->file_size = 512;
    folder1->files = malloc(2*sizeof(file));
    folder1->files[0] = *file1;
    folder1->files[1] = *file2;
    folder1->num_files = 2;
    file *file3 = malloc(sizeof(file));
    file3->file_name = strdup("File1.txt");
    file3->file_size = 512;
    folder2->files = malloc(sizeof(file));
    folder2->files[0] = *file3;
    folder2->num_files = 1;
    my_sync->folders[0] = folder1;
    my_sync->folders[1] = folder2;
    my_sync->num_folders = 2;
    printf("Before synchronization:\n");
    print_sync_folders(my_sync);
    sync_files(my_sync);
    printf("After synchronization:\n");
    print_sync_folders(my_sync);
    return 0;
}