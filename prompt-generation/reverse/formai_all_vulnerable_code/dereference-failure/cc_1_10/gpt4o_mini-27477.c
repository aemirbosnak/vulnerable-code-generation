//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>

void display_memory_usage() {
    struct sysinfo sys_info;
    
    if (sysinfo(&sys_info) != 0) {
        perror("sysinfo");
        return;
    }
    
    long total_memory = sys_info.totalram;
    long free_memory = sys_info.freeram;
    long used_memory = total_memory - free_memory;

    float total_memory_mb = total_memory / (1024.0 * 1024.0);
    float free_memory_mb = free_memory / (1024.0 * 1024.0);
    float used_memory_mb = used_memory / (1024.0 * 1024.0);
    
    printf("Total Memory: %.2f MB\n", total_memory_mb);
    printf("Free Memory: %.2f MB\n", free_memory_mb);
    printf("Used Memory: %.2f MB\n", used_memory_mb);
}

void log_to_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Unable to open log file");
        return;
    }
    
    fprintf(file, "%s\n", data);
    fclose(file);
}

void get_time(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tm_info);
}

void monitor_memory_usage(int duration, const char *log_file) {
    char time_buffer[20];
    for (int i = 0; i < duration; i++) {
        // Capture memory usage
        long total_memory, used_memory, free_memory;
        struct sysinfo sys_info;
        sysinfo(&sys_info);
        
        total_memory = sys_info.totalram;
        free_memory = sys_info.freeram;
        used_memory = total_memory - free_memory;
        
        // Log date/time and usage
        get_time(time_buffer, sizeof(time_buffer));
        
        char log_entry[256];
        snprintf(log_entry, sizeof(log_entry), "%s | Total: %.2f MB | Free: %.2f MB | Used: %.2f MB",
                 time_buffer, total_memory / (1024.0 * 1024.0),
                 free_memory / (1024.0 * 1024.0), used_memory / (1024.0 * 1024.0));
        
        log_to_file(log_file, log_entry);
        display_memory_usage();
        
        // Sleep for 1 second
        sleep(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <duration_in_seconds> <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    int duration = atoi(argv[1]);
    const char *log_file = argv[2];

    if (duration <= 0) {
        fprintf(stderr, "Duration must be a positive integer.\n");
        return EXIT_FAILURE;
    }

    printf("Monitoring RAM usage for %d seconds...\n", duration);
    monitor_memory_usage(duration, log_file);
    
    printf("Memory logging completed. Check %s for logs.\n", log_file);
    return EXIT_SUCCESS;
}