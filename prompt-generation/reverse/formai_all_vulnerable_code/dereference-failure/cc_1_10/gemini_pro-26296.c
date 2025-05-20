//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

// Linus Torvalds style
#define FOR_EACH(var, list) for (var = list; var != NULL; var = var->next)
#define LIST_APPEND(list, item) do { item->next = list; list = item; } while (0)
#define LIST_REMOVE(list, item) do { list = item->next; free(item); } while (0)
#define ALLOC(type) malloc(sizeof(type))

typedef struct file_node {
    char *name;
    char *contents;
    struct file_node *next;
} file_node;

// Recursive file walker
void walk_dir(char *dir, file_node **list) {
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    char *path;
    FILE *fp;

    dp = opendir(dir);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        path = malloc(strlen(dir) + strlen(entry->d_name) + 2);
        strcpy(path, dir);
        strcat(path, "/");
        strcat(path, entry->d_name);

        if (lstat(path, &statbuf) < 0) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            walk_dir(path, list);
        } else if (S_ISREG(statbuf.st_mode)) {
            fp = fopen(path, "r");
            if (fp == NULL) {
                perror("fopen");
                continue;
            }

            // Read the file into memory
            fseek(fp, 0, SEEK_END);
            long size = ftell(fp);
            rewind(fp);

            char *contents = malloc(size + 1);
            fread(contents, 1, size, fp);
            fclose(fp);
            contents[size] = '\0';

            // Add the file to the list
            file_node *node = ALLOC(file_node);
            node->name = strdup(path);
            node->contents = contents;
            LIST_APPEND(*list, node);
        }

        free(path);
    }

    closedir(dp);
}

// File synchronizer
void sync_files(file_node *local_list, file_node *remote_list) {
    // Compare the two lists and identify the differences
    file_node *local_node, *remote_node;
    for (local_node = local_list; local_node != NULL; local_node = local_node->next) {
        for (remote_node = remote_list; remote_node != NULL; remote_node = remote_node->next) {
            if (strcmp(local_node->name, remote_node->name) == 0) {
                // Files have the same name, compare the contents
                if (strcmp(local_node->contents, remote_node->contents) != 0) {
                    // Files have different contents, update the remote file
                    FILE *fp = fopen(remote_node->name, "w");
                    if (fp == NULL) {
                        perror("fopen");
                        continue;
                    }

                    fwrite(local_node->contents, 1, strlen(local_node->contents), fp);
                    fclose(fp);
                }
            } else {
                // Files have different names, create the remote file
                FILE *fp = fopen(remote_node->name, "w");
                if (fp == NULL) {
                    perror("fopen");
                    continue;
                }

                fwrite(remote_node->contents, 1, strlen(remote_node->contents), fp);
                fclose(fp);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s local_dir remote_dir\n", argv[0]);
        return 1;
    }

    // Walk the local and remote directories
    file_node *local_list = NULL, *remote_list = NULL;
    walk_dir(argv[1], &local_list);
    walk_dir(argv[2], &remote_list);

    // Synchronize the files
    sync_files(local_list, remote_list);

    // Free the memory
    file_node *node;
    FOR_EACH(node, local_list) LIST_REMOVE(local_list, node);
    FOR_EACH(node, remote_list) LIST_REMOVE(remote_list, node);

    return 0;
}