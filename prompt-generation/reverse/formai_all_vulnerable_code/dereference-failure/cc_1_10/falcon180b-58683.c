//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MEGABYTE 1048576

int main() {
    int i;
    double total_ram, used_ram, free_ram;
    char *buffer;
    FILE *fp;

    // Open /proc/meminfo
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        printf("Error: Failed to open /proc/meminfo\n");
        exit(1);
    }

    // Read total RAM from /proc/meminfo
    fseek(fp, 0, SEEK_SET);
    while ((buffer = fgets(buffer, 1024, fp))!= NULL) {
        if (strstr(buffer, "MemTotal")!= NULL) {
            sscanf(buffer, "MemTotal: %lf kB", &total_ram);
            break;
        }
    }
    fclose(fp);

    // Get used and free RAM
    system("free -m | grep -E '^Mem:' > /dev/null");
    fp = popen("free -m | grep -E '^Mem:'", "r");
    if (fp == NULL) {
        printf("Error: Failed to execute free\n");
        exit(1);
    }
    fgets(buffer, 1024, fp); // eat first line
    while ((buffer = fgets(buffer, 1024, fp))!= NULL) {
        sscanf(buffer, "Mem: %lfMB", &used_ram);
        sscanf(buffer, "Swap: %lfMB", &free_ram);
        break;
    }
    pclose(fp);

    // Print RAM usage
    printf("Total RAM: %.2lf MB\n", total_ram / MEGABYTE);
    printf("Used RAM: %.2lf MB\n", used_ram / MEGABYTE);
    printf("Free RAM: %.2lf MB\n", free_ram / MEGABYTE);

    return 0;
}