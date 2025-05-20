//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MB (1024 * 1024)

void printHeader() {
    printf("\n\n");
    printf("-------------------------\n");
    printf("| RAM Usage Monitor V1.0 |\n");
    printf("-------------------------\n\n");
}

void printMemoryStats() {
    static long pageSize = 0;
    if (pageSize == 0) {
        pageSize = sysconf(_SC_PAGESIZE) / MB;
    }

    FILE *file = fopen("/proc/meminfo", "r");
    char line[256];
    int memTotal = 0, memFree = 0, buffers = 0, cached = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            sscanf(line + 9, "%d", &memTotal);
        } else if (strncmp(line, "MemFree:", 8) == 0) {
            sscanf(line + 8, "%d", &memFree);
        } else if (strncmp(line, "Buffers:", 8) == 0) {
            sscanf(line + 8, "%d", &buffers);
        } else if (strncmp(line, "Cached:", 7) == 0) {
            sscanf(line + 7, "%d", &cached);
        }
    }

    fclose(file);

    int usedRAM = memTotal - memFree - buffers - cached;
    printf("Total Memory:\t%d MB\n", memTotal);
    printf("Used Memory:\t%d MB\n", usedRAM);
    printf("Free Memory:\t%d MB\n", memFree);
    printf("Cached RAM:\t%d MB\n", cached);
    printf("Buffers:\t%d MB\n", buffers);
    printf("Page Size:\t%ld MB\n\n", pageSize);
}

int main() {
    printHeader();

    while (1) {
        printMemoryStats();
        sleep(1);
    }

    return 0;
}