//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define BUFFER_SIZE 256

void log_event(const char *event) {
    FILE *logfile = fopen(LOG_FILE, "a");
    if (logfile == NULL) {
        perror("Failed to open log file");
        return;
    }
    
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline character
    
    fprintf(logfile, "[%s] %s\n", timestamp, event);
    fclose(logfile);
}

void *monitor_cpu_usage(void *arg) {
    while (1) {
        char cpu_usage[BUFFER_SIZE];
        FILE *fp = popen("top -bn1 | grep 'Cpu(s)'", "r");
        if (fp == NULL) {
            log_event("Failed to get CPU usage");
            continue;
        }
        fgets(cpu_usage, sizeof(cpu_usage), fp);
        pclose(fp);
        
        char log_message[BUFFER_SIZE];
        snprintf(log_message, sizeof(log_message), "CPU usage: %s", cpu_usage);
        log_event(log_message);
        
        sleep(5);
    }
    return NULL;
}

void *monitor_memory_usage(void *arg) {
    while (1) {
        char memory_usage[BUFFER_SIZE];
        FILE *fp = popen("free -m | grep 'Mem'", "r");
        if (fp == NULL) {
            log_event("Failed to get memory usage");
            continue;
        }
        fgets(memory_usage, sizeof(memory_usage), fp);
        pclose(fp);

        char log_message[BUFFER_SIZE];
        snprintf(log_message, sizeof(log_message), "Memory usage: %s", memory_usage);
        log_event(log_message);
        
        sleep(5);
    }
    return NULL;
}

void *monitor_disk_usage(void *arg) {
    while (1) {
        char disk_usage[BUFFER_SIZE];
        FILE *fp = popen("df -h | grep '/dev/sda1'", "r");
        if (fp == NULL) {
            log_event("Failed to get disk usage");
            continue;
        }
        fgets(disk_usage, sizeof(disk_usage), fp);
        pclose(fp);

        char log_message[BUFFER_SIZE];
        snprintf(log_message, sizeof(log_message), "Disk usage: %s", disk_usage);
        log_event(log_message);
        
        sleep(5);
    }
    return NULL;
}

void *monitor_file_system(void *arg) {
    char *watched_file = (char *)arg;
    while (1) {
        if (access(watched_file, F_OK) != -1) {
            log_event("Watched file exists");
        } else {
            log_event("Watched file does not exist");
        }
        
        sleep(10);
    }
    return NULL;
}

int main() {
    pthread_t cpu_thread, memory_thread, disk_thread, file_thread;
    char *watched_file = "important_file.txt";

    // Create log file
    FILE *logfile = fopen(LOG_FILE, "w");
    if (logfile == NULL) {
        perror("Failed to create log file");
        exit(EXIT_FAILURE);
    }
    fclose(logfile);

    // Start monitoring threads
    pthread_create(&cpu_thread, NULL, monitor_cpu_usage, NULL);
    pthread_create(&memory_thread, NULL, monitor_memory_usage, NULL);
    pthread_create(&disk_thread, NULL, monitor_disk_usage, NULL);
    pthread_create(&file_thread, NULL, monitor_file_system, watched_file);

    // Wait for threads to finish (which they never will)
    pthread_join(cpu_thread, NULL);
    pthread_join(memory_thread, NULL);
    pthread_join(disk_thread, NULL);
    pthread_join(file_thread, NULL);

    return 0;
}