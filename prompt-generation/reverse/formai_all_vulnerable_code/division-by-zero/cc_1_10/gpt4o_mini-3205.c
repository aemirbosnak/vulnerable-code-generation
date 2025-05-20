//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef __linux__
#include <sys/types.h>
#include <sys/sysinfo.h>
#endif

void display_memory_usage(long total_mem, long free_mem) {
    long used_mem = total_mem - free_mem;
    int percentage_used = (100 * used_mem) / total_mem;

    // Clear the terminal
    printf("\033[H\033[J"); // ANSI escape code to clear the screen

    // Print the shape-shifting visual representation
    printf("RAM Usage Monitor\n");
    printf("Total RAM: %ld MB\n", total_mem / (1024 * 1024));
    printf("Used RAM: %ld MB\n", used_mem / (1024 * 1024));
    printf("Free RAM: %ld MB\n", free_mem / (1024 * 1024));
    printf("Percentage Used: %d%%\n", percentage_used);

    // Shape shifting: Different shapes depending on percentage
    printf("Memory Visualization: ");
    if (percentage_used <= 50) {
        printf("[");
        for (int i = 0; i < percentage_used / 5; i++) {
            printf("=");
        }
        for (int i = percentage_used / 5; i < 20; i++) {
            printf(" ");
        }
        printf("] - Healthy\n");
    } else if (percentage_used <= 75) {
        printf("[");
        for (int i = 0; i < percentage_used / 5; i++) {
            printf("=");
        }
        for (int i = percentage_used / 5; i < 20; i++) {
            printf("~");
        }
        printf("] - Caution\n");
    } else {
        printf("[");
        for (int i = 0; i < 20; i++) {
            printf("=");
        }
        printf("] - Danger!\n");
    }
}

int main() {
    struct sysinfo memInfo;
    
    while (1) {
        if (sysinfo(&memInfo) != 0) {
            perror("sysinfo");
            return 1;
        }
        
        long total_mem = memInfo.totalram;
        long free_mem = memInfo.freeram;

        display_memory_usage(total_mem, free_mem);

        // Delay for a few seconds before updating
        sleep(2);
    }
    
    return 0;
}