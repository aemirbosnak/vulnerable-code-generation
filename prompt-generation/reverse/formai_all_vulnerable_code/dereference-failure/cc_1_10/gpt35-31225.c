//FormAI DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PATH_MAX 4096

char path[PATH_MAX];
char buf[64];

void print_header() {
    printf("Process Name\t\tPID\t\tPPID\t\tUID\n");
}

void print_process(char *name, int pid, int ppid, int uid) {
    printf("%s\t\t%d\t\t%d\t\t%d\n", name, pid, ppid, uid);
}

void read_directory(char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Failed to open directory %s\n", path);
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            snprintf(buf, sizeof(buf), "%s/%s/status", path, entry->d_name);
            int fd = open(buf, O_RDONLY);
            if (fd < 0) {
                continue;
            }

            char buf[512];
            char *name = NULL;
            int pid = -1, ppid = -1, uid = -1;

            while (read(fd, buf, sizeof(buf)) > 0) {
                if (strncmp(buf, "Name:", 5) == 0) {
                    name = strdup(buf + 6);
                    name[strlen(name) - 1] = '\0';
                } else if (strncmp(buf, "Pid:", 4) == 0) {
                    pid = atoi(buf + 5);
                } else if (strncmp(buf, "PPid:", 5) == 0) {
                    ppid = atoi(buf + 6);
                } else if (strncmp(buf, "Uid:", 4) == 0) {
                    uid = atoi(buf + 5);
                }
            }

            close(fd);

            if (name != NULL && pid >= 0 && ppid >= 0 && uid >= 0) {
                print_process(name, pid, ppid, uid);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    printf("          Welcome to the Dream Process Viewer!\n");
    printf("                        .-''''''-.\n");
    printf("                      .'          '.\n");
    printf("                     /              \\\n");
    printf("                    ;                ;\n");
    printf("                    |               ;\n");
    printf("                    |               |\n");
    printf("      .--''''''--.. |               |\n");
    printf("    /'             \\\\_)              ;\n");
    printf("   /               \\\\3              /\n");
    printf("  /   Dream        ;|                |\n");
    printf(" ;                ;|             _  |\n");
    printf(" |               / ;            / `=\n");
    printf(" |         ___--'  /             \\\n");
    printf("  \\\__.---'~      /               \\\n");
    printf("                  ;                ;\n");
    printf("                  .'              /\n");
    printf("                  \\          __.'\n");
    printf("                   ':-....--''\n");

    realpath(argv[1], path);

    print_header();
    read_directory(path);

    printf("Sweet Dreams!\n");

    return 0;
}