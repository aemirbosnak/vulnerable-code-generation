//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>

void printHeader() {
    printf("==========================================\n");
    printf("  Cyberpunk RAM Monitor v1.0\n");
    printf("  Neon Dreams & Digital Nightmares\n");
    printf("==========================================\n");
}

void printUsage(struct sysinfo info) {
    long totalRam = info.totalram / (1024 * 1024); // Convert to MB
    long freeRam = info.freeram / (1024 * 1024);
    long usedRam = totalRam - freeRam;
    float percentUsed = (usedRam / (float)totalRam) * 100.0;

    printf("Total RAM:       %ld MB\n", totalRam);
    printf("Used RAM:        %ld MB (%.2f%%)\n", usedRam, percentUsed);
    printf("Free RAM:        %ld MB\n", freeRam);
    printf("------------------------------------------\n");
}

void printVisualRepresentation(struct sysinfo info) {
    long totalRam = info.totalram / (1024 * 1024);
    long usedRam = (info.totalram - info.freeram) / (1024 * 1024);
    int percentage = (usedRam * 100) / totalRam;
    
    printf("[");

    // Print used memory block
    for (int i = 0; i < percentage / 2; i++) {
        printf("█");
    }

    // Print free memory block
    for (int i = percentage / 2; i < 50; i++) {
        printf(" ");
    }

    printf("] %d%% used\n", percentage);
}

void printFooter() {
    printf("==========================================\n");
    printf("     A blade in the dark, you are\n");
    printf("==========================================\n");
}

int main() {
    struct sysinfo info;
    
    while (1) {
        if (sysinfo(&info) == 0) {
            printHeader();
            printUsage(info);
            printVisualRepresentation(info);
            printFooter();
        } else {
            perror("sysinfo");
            exit(EXIT_FAILURE);
        }
        
        sleep(2); // Update every 2 seconds
        printf("\033[H\033[J"); // Clear the console (works on most terminals)
    }

    return 0;
}