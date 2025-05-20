//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/inotify.h>
#include <errno.h>

#define EVENT_SIZE (sizeof(struct inotify_event))
#define EVENT_BUF_LEN (1024 * (EVENT_SIZE + 16))

#define MONITOR_PATH "/tmpMonitor"

void handle_event(struct inotify_event *event) {
    if (event->len) {
        if (event->mask & IN_CREATE) {
            printf("New file created: %s\n", event->name);
        }
        if (event->mask & IN_MODIFY) {
            printf("File modified: %s\n", event->name);
        }
        if (event->mask & IN_DELETE) {
            printf("File deleted: %s\n", event->name);
        }
        if (event->mask & IN_ACCESS) {
            printf("File accessed: %s\n", event->name);
        }
    }
}

void start_monitoring(const char *path) {
    int fd, wd;
    char buffer[EVENT_BUF_LEN];

    /* Initialize inotify */
    fd = inotify_init();
    if (fd < 0) {
        perror("inotify_init");
        exit(EXIT_FAILURE);
    }

    /* Add the monitoring path */
    wd = inotify_add_watch(fd, path, IN_CREATE | IN_MODIFY | IN_DELETE | IN_ACCESS);
    if (wd == -1) {
        perror("inotify_add_watch");
        exit(EXIT_FAILURE);
    }

    printf("Monitoring directory: %s\n", path);
    while (1) {
        int num_read = read(fd, buffer, EVENT_BUF_LEN);
        if (num_read < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Process all the events 
        for (int i = 0; i < num_read; ) {
            struct inotify_event *event = (struct inotify_event *)&buffer[i];
            handle_event(event);
            i += EVENT_SIZE + event->len;
        }
    }

    // Cleanup (won't reach here in normal operation)
    inotify_rm_watch(fd, wd);
    close(fd);
}

int main() {
    // Create monitor directory if it doesn't exist
    if (mkdir(MONITOR_PATH, 0755) == -1 && errno != EEXIST) {
        perror("mkdir");
        return EXIT_FAILURE;
    }

    // Start monitoring
    start_monitoring(MONITOR_PATH);

    return EXIT_SUCCESS;
}