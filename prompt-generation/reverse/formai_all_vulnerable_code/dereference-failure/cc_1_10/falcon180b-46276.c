//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 1024

char **split(char *str, char delimiter) {
    char **tokens = malloc(sizeof(char *));
    int count = 0;
    char *token = strtok(str, delimiter);
    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, delimiter);
    }
    tokens[count] = NULL;
    return tokens;
}

void print_processes(char *folder) {
    DIR *dir;
    struct dirent *ent;
    char path[MAX];
    if ((dir = opendir(folder))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                sprintf(path, "%s/%s", folder, ent->d_name);
                print_processes(path);
            } else {
                char **process_info = split(ent->d_name, '.');
                if (strcmp(process_info[1], "exe") == 0) {
                    printf("%s\n", ent->d_name);
                }
                free(process_info);
            }
        }
        closedir(dir);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <folder>\n", argv[0]);
        exit(1);
    }
    char *folder = argv[1];
    print_processes(folder);
    return 0;
}