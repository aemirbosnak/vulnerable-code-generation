//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256

typedef struct file {
    char name[MAX_FILENAME_LEN];
    int size;
    struct file* next;
} File;

void add_file(File** head_ref, char* name, int size) {
    File* new_file = (File*)malloc(sizeof(File));
    strncpy(new_file->name, name, MAX_FILENAME_LEN);
    new_file->size = size;
    new_file->next = *head_ref;
    *head_ref = new_file;
}

void free_list(File** head_ref) {
    File* current = *head_ref;
    while(current != NULL) {
        File* temp = current;
        current = current->next;
        free(temp);
    }
    *head_ref = NULL;
}

int get_num_files(File* head) {
    int count = 0;
    File* current = head;
    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void print_files(File* head) {
    printf("============================================================\n");
    printf("FILENAME                             SIZE\n");
    printf("============================================================\n");
    File* current = head;
    while(current != NULL) {
        printf("%-36s%10d bytes\n", current->name, current->size);
        current = current->next;
    }
    printf("============================================================\n");
}

int main() {
    int total_size = 0;
    char filename[MAX_FILENAME_LEN];
    File* head = NULL;
    
    add_file(&head, "net_hack.exe", 154516);
    add_file(&head, "cyber_revenge.doc", 350521);
    add_file(&head, "hack_and_slash.mp4", 987654321);
    add_file(&head, "haiku.txt", 42);
    
    printf("WELCOME TO THE C DISK SPACE ANALYZER\n");
    printf("==================================\n");
    printf("Scanning disk...\n");
    printf("Found %d files on disk.\n\n", get_num_files(head));
    
    print_files(head);
    
    File* current = head;
    while(current != NULL) {
        total_size += current->size;
        current = current->next;
    }
  
    printf("Total disk size: %d bytes\n", total_size);
    free_list(&head);
    return 0;
}