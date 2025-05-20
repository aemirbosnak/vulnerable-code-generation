//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <sys/ioctl.h>
#include <dirent.h>

#define LOG_FILE "event_log.txt"
#define DEVICE_DIR "/dev/input/"
#define MAX_EVENTS 64

// Function to get the current timestamp
void get_timestamp(char *timestamp, size_t size) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(timestamp, size, "%Y-%m-%d %H:%M:%S", tm_info);
}

// Function to log an event to the log file
void log_event(const char *event_desc) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }
    
    char timestamp[20];
    get_timestamp(timestamp, sizeof(timestamp));
    fprintf(file, "[%s] %s\n", timestamp, event_desc);
    
    fclose(file);
}

// Function to find input devices in the /dev/input/ directory
void find_input_devices(char devices[MAX_EVENTS][100], int *count) {
    struct dirent *entry;
    DIR *dp = opendir(DEVICE_DIR);
    *count = 0;

    if (dp == NULL) {
        perror("Failed to open device directory");
        return;
    }
    
    while ((entry = readdir(dp)) != NULL) {
        if (strstr(entry->d_name, "event") != NULL) {
            snprintf(devices[*count], 100, "%s%s", DEVICE_DIR, entry->d_name);
            (*count)++;
            if (*count >= MAX_EVENTS) break; // Avoid overflow
        }
    }
    
    closedir(dp);
}

// Function to monitor input events
void monitor_events() {
    char devices[MAX_EVENTS][100];
    int device_count = 0;
    find_input_devices(devices, &device_count);

    struct input_event ev;
    for (int i = 0; i < device_count; i++) {
        int fd = open(devices[i], O_RDONLY | O_NONBLOCK);
        if (fd < 0) {
            perror("Failed to open event device");
            continue;
        }

        while (1) {
            ssize_t bytes = read(fd, &ev, sizeof(ev));
            if (bytes > 0) {
                if (ev.type == EV_KEY) {
                    char log_msg[100];
                    snprintf(log_msg, sizeof(log_msg), "Key %s: %s (key_code=%d)",
                             ev.value ? "Pressed" : "Released", 
                             ev.value ? "pressed" : "released", 
                             ev.code);
                    log_event(log_msg);
                }
                else if (ev.type == EV_REL) {
                    char log_msg[100];
                    snprintf(log_msg, sizeof(log_msg), "Mouse moved (value=%d) on device: %s",
                             ev.value, devices[i]);
                    log_event(log_msg);
                }
            }
            usleep(1000); // Sleep for a while to prevent CPU overload
        }
        
        close(fd);
    }
}

int main() {
    printf("Starting event logger...\n");
    log_event("Event logger started.");
    monitor_events();
    log_event("Event logger stopped.");
    return 0;
}