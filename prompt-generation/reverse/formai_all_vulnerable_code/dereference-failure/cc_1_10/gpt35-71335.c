//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 100

struct directory {
    char path[MAX_PATH_LENGTH];
    int size;
};

struct node {
    struct directory dir;
    struct node* next;
};

void swap(struct directory* dir1, struct directory* dir2) {
    struct directory temp = *dir1;
    *dir1 = *dir2;
    *dir2 = temp;
}

void sort(struct directory dirs[], int num_dirs) {
    int i, j;
    for (i = 0; i < num_dirs-1; i++) {
        for (j = i+1; j < num_dirs; j++) {
            if (dirs[i].size < dirs[j].size) {
                swap(&dirs[i], &dirs[j]);
            }
        }
    }
}

void print_directory(struct directory dir) {
    printf("%s %d KB\n", dir.path, dir.size);
}

void print_top_directories(struct node* head, int n) {
    int num_directories = 0;
    struct directory dirs[n];
    
    while (head != NULL && num_directories < n) {
        dirs[num_directories] = head->dir;
        head = head->next;
        num_directories++;
    }
    
    sort(dirs, num_directories);
    
    int i;
    for (i = 0; i < num_directories; i++) {
        print_directory(dirs[i]);
    }
}

int main() {
    // get directory path from user
    char path[MAX_PATH_LENGTH];
    printf("Enter directory path: ");
    fgets(path, MAX_PATH_LENGTH, stdin);
    path[strcspn(path, "\n")] = '\0'; // remove newline
    
    // use du command to get directory sizes
    char command[MAX_PATH_LENGTH + 10] = "du -k ";
    strcat(command, path);
    FILE* fp = popen(command, "r");
    
    if (fp == NULL) {
        printf("Error: unable to execute command\n");
        return 1;
    }
    
    // parse output of du command and create linked list of directories
    struct node* head = NULL;
    char line[MAX_PATH_LENGTH + 20];
    while (fgets(line, sizeof(line), fp) != NULL) {
        struct node* temp = (struct node*) malloc(sizeof(struct node));
        sscanf(line, "%d %[^\n]s", &temp->dir.size, temp->dir.path);
        
        if (head == NULL) {
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }
    pclose(fp);
    
    // print top 10 directories by size
    printf("\n\nTop 10 directories by size:\n");
    print_top_directories(head, 10);
    
    // free memory allocated for linked list of directories
    while (head != NULL) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}