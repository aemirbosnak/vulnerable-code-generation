//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the total RAM usage
double getTotalRAMUsage() {
    FILE *fp = fopen("/proc/meminfo", "r");
    char line[100];
    double totalRAM = 0.0;
    while (fgets(line, 100, fp)!= NULL) {
        if (strstr(line, "MemTotal:")!= NULL) {
            sscanf(line, "MemTotal: %lf kB", &totalRAM);
            break;
        }
    }
    fclose(fp);
    return totalRAM;
}

// Function to calculate the free RAM usage
double getFreeRAMUsage() {
    FILE *fp = fopen("/proc/meminfo", "r");
    char line[100];
    double freeRAM = 0.0;
    while (fgets(line, 100, fp)!= NULL) {
        if (strstr(line, "MemFree:")!= NULL) {
            sscanf(line, "MemFree: %lf kB", &freeRAM);
            break;
        }
    }
    fclose(fp);
    return freeRAM;
}

// Function to calculate the used RAM usage
double getUsedRAMUsage(double totalRAM, double freeRAM) {
    return totalRAM - freeRAM;
}

// Function to display the RAM usage information
void displayRAMUsage(double totalRAM, double freeRAM, double usedRAM) {
    printf("Total RAM usage: %.2lf MB\n", totalRAM / (1024.0));
    printf("Free RAM usage: %.2lf MB\n", freeRAM / (1024.0));
    printf("Used RAM usage: %.2lf MB\n", usedRAM / (1024.0));
}

int main() {
    double totalRAM = getTotalRAMUsage();
    double freeRAM = getFreeRAMUsage();
    double usedRAM = getUsedRAMUsage(totalRAM, freeRAM);

    displayRAMUsage(totalRAM, freeRAM, usedRAM);

    return 0;
}