//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define BUF_SIZE 256

// Function to parse data from /proc/meminfo file
void parse_meminfo(unsigned long* mem_total, unsigned long* mem_free) {
    FILE* fp = fopen("/proc/meminfo", "r");
    char buffer[BUF_SIZE];

    while (fgets(buffer, BUF_SIZE, fp)) {
        if (strstr(buffer, "MemTotal")) sscanf(buffer, "MemTotal: %lu", mem_total);
        else if (strstr(buffer, "MemFree")) sscanf(buffer, "MemFree: %lu", mem_free);
    }

    fclose(fp);
}

// Function to format memory size into human-readable format
void format_memsize(unsigned long size, char* buf) {
    const char* suffixes[] = {"B", "KB", "MB", "GB", "TB"};
    double formatted_size = (double)size;
    int i = 0;
    while (formatted_size >= 1024 && i < 4) {
        formatted_size /= 1024;
        i++;
    }
    sprintf(buf, "%.1f %s", formatted_size, suffixes[i]);
}

// Main function
int main(void) {
    unsigned long mem_total, mem_free;
    char mem_total_str[BUF_SIZE], mem_free_str[BUF_SIZE];
    char time_str[BUF_SIZE];

    // Get initial memory usage
    parse_meminfo(&mem_total, &mem_free);

    // Display initial header
    printf("    Timestamp    | Total Memory | Free Memory | Used Memory |\n");

    while (1) {
        time_t now = time(NULL);

        // Parse memory usage
        parse_meminfo(&mem_total, &mem_free);
        unsigned long mem_used = mem_total - mem_free;

        // Format memory usage into human-readable format
        format_memsize(mem_total, mem_total_str);
        format_memsize(mem_free, mem_free_str);

        // Format timestamp into readable format
        struct tm* tm_info = localtime(&now);
        strftime(time_str, BUF_SIZE, "%Y-%m-%d %H:%M:%S", tm_info);

        // Print memory usage stats
        printf("%s | %12s | %11s | %11lu |\n", time_str, mem_total_str, mem_free_str, mem_used);

        // Sleep for one second
        sleep(1);
    }

    return 0;
}