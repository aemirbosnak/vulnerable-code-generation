//FormAI DATASET v1.0 Category: File Synchronizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/inotify.h>

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define EVENT_BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )

void sync_dir(const char *source, const char *destination);

void sync_file(const char *source_file, const char *dest_file);

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_directory destination_directory\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Ensure source directory exists
    DIR *source_dir = opendir(argv[1]);
    if (source_dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    closedir(source_dir);

    // Call the directory synchronization function
    sync_dir(argv[1], argv[2]);
    return 0;
}

void sync_dir(const char *source, const char *destination) {
    // Create inotify instance
    int inotify_fd = inotify_init();
    if (inotify_fd < 0) {
        perror("inotify_init");
        exit(EXIT_FAILURE);
    }

    // Add source directory to watch list
    int watch_fd = inotify_add_watch(inotify_fd, source, IN_CREATE | IN_DELETE | IN_MODIFY);
    if (watch_fd < 0) {
        perror("inotify_add_watch");
        exit(EXIT_FAILURE);
    }

    // Sync directory once at start
    DIR *source_dir = opendir(source);
    if (source_dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    struct dirent *entry;
    while ((entry = readdir(source_dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char source_file[PATH_MAX];
            char dest_file[PATH_MAX];
            sprintf(source_file, "%s/%s", source, entry->d_name);
            sprintf(dest_file, "%s/%s", destination, entry->d_name);
            sync_file(source_file, dest_file);
        }
    }
    closedir(source_dir);

    // Start event loop
    char event_buf[EVENT_BUF_LEN];
    for (;;) {
        // Wait for events
        int event_count = read(inotify_fd, event_buf, EVENT_BUF_LEN);
        if (event_count < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Parse events
        int i = 0;
        while (i < event_count) {
            struct inotify_event *event = (struct inotify_event *)&event_buf[i];
            if (event->len > 0) { // Event has name
                char source_file[PATH_MAX];
                char dest_file[PATH_MAX];
                sprintf(source_file, "%s/%s", source, event->name);
                sprintf(dest_file, "%s/%s", destination, event->name);
                switch (event->mask) {
                    case IN_CREATE:
                    case IN_MODIFY:
                        sync_file(source_file, dest_file);
                        break;
                    case IN_DELETE:
                        unlink(dest_file);
                        break;
                }
            }
            i += EVENT_SIZE + event->len;
        }
    }

    // Remove directory from watch list
    inotify_rm_watch(inotify_fd, watch_fd);

    // Close inotify instance
    close(inotify_fd);
}

void sync_file(const char *source_file, const char *dest_file) {
    // Open source file
    int source_fd = open(source_file, O_RDONLY);
    if (source_fd < 0) {
        perror("open");
        return;
    }

    // Get source file size
    struct stat source_stat;
    if (fstat(source_fd, &source_stat) < 0) {
        perror("fstat");
        close(source_fd);
        return;
    }

    // Check if destination file exists and has the same size
    struct stat dest_stat;
    if (stat(dest_file, &dest_stat) < 0 || dest_stat.st_size != source_stat.st_size) {
        // Destination file does not exist or has different size, overwrite
        int dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, source_stat.st_mode);
        if (dest_fd < 0) {
            perror("open");
            close(source_fd);
            return;
        }

        // Copy source file contents to destination file
        char buffer[BUFSIZ];
        ssize_t bytes;
        while ((bytes = read(source_fd, buffer, sizeof(buffer))) > 0) {
            if (write(dest_fd, buffer, bytes) < 0) {
                perror("write");
                close(source_fd);
                close(dest_fd);
                return;
            }
        }

        // Close destination file
        close(dest_fd);
    }

    // Close source file
    close(source_fd);
}