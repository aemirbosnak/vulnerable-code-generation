//Falcon-180B DATASET v1.0 Category: System administration ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_LINE 1024

void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        execlp(command, command, NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
    }
}

void list_directory(char *path) {
    DIR *dir;
    struct dirent *entry;
    char full_path[MAX_LINE];

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir))!= NULL) {
        snprintf(full_path, MAX_LINE, "%s/%s", path, entry->d_name);
        if (entry->d_type == DT_DIR) {
            printf("Directory: %s\n", entry->d_name);
        } else {
            printf("File: %s\n", entry->d_name);
        }
    }

    closedir(dir);
}

void create_file(char *path) {
    int fd;
    char data[] = "Hello, world!";

    fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (write(fd, data, strlen(data)) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    close(fd);
}

void delete_file(char *path) {
    int result;

    result = remove(path);
    if (result == -1) {
        perror("remove");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    int i;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0) {
            list_directory(argv[i + 1]);
        } else if (strcmp(argv[i], "-c") == 0) {
            create_file(argv[i + 1]);
        } else if (strcmp(argv[i], "-d") == 0) {
            delete_file(argv[i + 1]);
        } else {
            execute_command(argv[i]);
        }
    }

    return 0;
}