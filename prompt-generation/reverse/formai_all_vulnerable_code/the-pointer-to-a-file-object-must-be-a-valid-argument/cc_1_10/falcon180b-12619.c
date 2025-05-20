//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 1000000 // 1 MB heap size

int main() {
    char *heap = malloc(HEAP_SIZE);
    if (heap == NULL) {
        printf("Error: Failed to allocate heap memory.\n");
        return 1;
    }

    int total_ram = 0;
    int used_ram = 0;

    while (1) {
        // Get total RAM
        FILE *fp = fopen("/proc/meminfo", "r");
        char line[100];
        while (fgets(line, 100, fp)!= NULL) {
            if (strstr(line, "MemTotal")!= NULL) {
                sscanf(line, "MemTotal: %d kB", &total_ram);
                break;
            }
        }
        fclose(fp);

        // Get used RAM
        fp = fopen("/proc/meminfo", "r");
        while (fgets(line, 100, fp)!= NULL) {
            if (strstr(line, "MemFree")!= NULL) {
                sscanf(line, "MemFree: %d kB", &used_ram);
                break;
            }
        }
        fclose(fp);

        // Calculate percentage of RAM used
        float percent_used = ((float) used_ram / (float) total_ram) * 100;

        // Print RAM usage
        printf("Total RAM: %d MB\n", total_ram);
        printf("Used RAM: %d MB (%d%%)\n", used_ram, (int) percent_used);
        printf("Heap size: %d bytes\n", HEAP_SIZE);
        printf("Heap usage: %d bytes\n", (int) (HEAP_SIZE - malloc_usable_size(heap)));
        printf("\n");

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}