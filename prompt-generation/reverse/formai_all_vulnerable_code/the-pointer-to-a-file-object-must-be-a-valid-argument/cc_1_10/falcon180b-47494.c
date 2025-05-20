//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RAM 100
#define MIN_RAM 10
#define STEP 0.1
#define SLEEP_TIME 1

// Function to calculate the current RAM usage
float get_ram_usage() {
    FILE *file = fopen("/proc/meminfo", "r");
    char line[100];
    float ram_usage = 0.0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strstr(line, "MemTotal")) {
            fgets(line, sizeof(line), file);
            ram_usage = atof(line) / (1024.0 * 1024.0);
            break;
        }
    }
    fclose(file);
    return ram_usage;
}

// Function to set the RAM usage limit
void set_ram_limit(float limit) {
    char command[50];
    sprintf(command, "echo %d > /proc/sys/vm/overcommit_ratio", (int) (limit * 100));
    system(command);
}

int main() {
    float ram_usage = get_ram_usage();
    float ram_limit = MIN_RAM;

    while (1) {
        if (ram_usage >= ram_limit) {
            set_ram_limit(ram_limit);
            printf("RAM limit set to %.2f%%\n", ram_limit * 100);
        } else if (ram_usage <= (ram_limit - STEP)) {
            ram_limit += STEP;
            set_ram_limit(ram_limit);
            printf("RAM limit increased to %.2f%%\n", ram_limit * 100);
        }

        ram_usage = get_ram_usage();
        printf("Current RAM usage: %.2f%%\n", ram_usage * 100);

        sleep(SLEEP_TIME);
    }

    return 0;
}