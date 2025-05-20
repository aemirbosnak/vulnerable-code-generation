//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>

void display_memory_usage(long total, long free, long used) {
    system("clear");
    printf("====================================\n");
    printf("          RAM Usage Monitor         \n");
    printf("====================================\n\n");

    printf("Total RAM:       %ld MB\n", total / 1024);
    printf("Free RAM:       %ld MB\n", free / 1024);
    printf("Used RAM:       %ld MB\n", used / 1024);

    long percent_used = (used * 100) / total;

    int bar_length = 50; // Length of the bar
    int used_length = (percent_used * bar_length) / 100; // Calculate used length

    printf("\nMemory Usage Visualization:\n");
    printf("[");
    for (int i = 0; i < used_length; i++) {
        printf("█");
    }
    for (int i = used_length; i < bar_length; i++) {
        printf(" ");
    }
    printf("] %ld%% Used\n", percent_used);
    printf("\nUpdates every 2 seconds. Press Ctrl+C to exit.\n");
    printf("====================================\n");
}

int main(void) {
    struct sysinfo info;

    while (1) {
        if (sysinfo(&info) != 0) {
            perror("sysinfo");
            exit(EXIT_FAILURE);
        }
        
        long total_ram = info.totalram;
        long free_ram = info.freeram;
        long used_ram = total_ram - free_ram;

        display_memory_usage(total_ram, free_ram, used_ram);
        sleep(2); // Sleep for 2 seconds
    }

    return 0;
}