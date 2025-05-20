//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define BLOCK_SIZE 1024
#define MAX_DEPTH 1000

typedef struct node {
    char path[MAX_DEPTH];
    long long size;
    struct node *next;
} Node;

void add_node(Node **head, const char *path, long long size) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->path, path);
    new_node->size = size;
    new_node->next = *head;
    *head = new_node;
}

void print_nodes(Node *head) {
    while (head!= NULL) {
        printf("%s (%lld bytes)\n", head->path, head->size);
        head = head->next;
    }
}

void free_nodes(Node *head) {
    while (head!= NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

long long get_folder_size(const char *path) {
    long long size = 0;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }
    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char subpath[MAX_DEPTH];
            strcpy(subpath, path);
            strcat(subpath, "/");
            strcat(subpath, ent->d_name);
            size += get_folder_size(subpath);
        } else {
            struct stat st;
            stat(ent->d_name, &st);
            size += st.st_size;
        }
    }
    closedir(dir);
    return size;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [path]\n", argv[0]);
        return 1;
    }
    char path[MAX_DEPTH];
    strcpy(path, argv[1]);
    long long size = get_folder_size(path);
    printf("Total size of '%s': %lld bytes\n", path, size);
    Node *head = NULL;
    add_node(&head, path, size);
    print_nodes(head);
    free_nodes(head);
    return 0;
}