//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define EVENT_SIZE ( sizeof (struct inotify_event) )
#define BUF_LEN ( 1024 * ( EVENT_SIZE + 16 ) )
#define MAX_PATH_LENGTH 1024

void sync_file(const char *src, const char *dest) {
    char command[MAX_PATH_LENGTH * 2 + 50];
    snprintf(command, sizeof(command), "cp -u '%s' '%s' 2>/dev/null", src, dest);
    system(command);
}

void delete_file(const char *path) {
    char command[MAX_PATH_LENGTH + 50];
    snprintf(command, sizeof(command), "rm '%s' 2>/dev/null", path);
    system(command);
}

void sync_directories(const char *src_dir, const char *dest_dir) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(src_dir)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char src_path[MAX_PATH_LENGTH];
                char dest_path[MAX_PATH_LENGTH];
                snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
                snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

                struct stat src_stat;
                if (stat(src_path, &src_stat) == 0) {
                    if (S_ISDIR(src_stat.st_mode)) {
                        sync_directories(src_path, dest_path);
                    } else {
                        sync_file(src_path, dest_path);
                    }
                }
            }
        }
        closedir(dir);
    }
}

void handle_event(struct inotify_event *event, const char *src_dir, const char *dest_dir) {
    char full_path[MAX_PATH_LENGTH];
    snprintf(full_path, sizeof(full_path), "%s/%s", src_dir, event->name);

    if (event->mask & IN_CREATE) {
        sync_file(full_path, dest_dir);
        printf("File created: %s\n", full_path);
    } else if (event->mask & IN_MODIFY) {
        sync_file(full_path, dest_dir);
        printf("File modified: %s\n", full_path);
    } else if (event->mask & IN_DELETE) {
        delete_file(dest_dir);
        printf("File deleted: %s\n", full_path);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *src_dir = argv[1];
    const char *dest_dir = argv[2];

    int fd = inotify_init();
    if (fd < 0) {
        perror("inotify_init");
        exit(EXIT_FAILURE);
    }

    int wd = inotify_add_watch(fd, src_dir, IN_CREATE | IN_MODIFY | IN_DELETE);
    if (wd == -1) {
        perror("inotify_add_watch");
        close(fd);
        exit(EXIT_FAILURE);
    }

    sync_directories(src_dir, dest_dir);

    char buffer[BUF_LEN];
    while (1) {
        int length = read(fd, buffer, BUF_LEN);
        if (length < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < length; i += EVENT_SIZE + buffer[i + EVENT_SIZE]) {
            struct inotify_event *event = (struct inotify_event *) &buffer[i];
            handle_event(event, src_dir, dest_dir);
        }
    }

    inotify_rm_watch(fd, wd);
    close(fd);
    return 0;
}