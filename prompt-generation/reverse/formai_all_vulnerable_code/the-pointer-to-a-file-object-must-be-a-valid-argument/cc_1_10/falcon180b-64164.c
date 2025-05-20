//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RAM_MONITOR_INTERVAL 10 // seconds

// Function to get the RAM usage in MB
float get_ram_usage() {
    FILE *file = fopen("/proc/meminfo", "r");
    char line[1024];
    float ram_usage = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strstr(line, "MemTotal")!= NULL) {
            char *token = strtok(line, " ");
            ram_usage = atof(token) / (1024 * 1024); // Convert to MB
            break;
        }
    }

    fclose(file);
    return ram_usage;
}

// Function to print the RAM usage
void print_ram_usage(float ram_usage) {
    printf("RAM usage: %.2f MB\n", ram_usage);
}

// Function to play a sound
void play_sound(char *filename) {
    system(filename);
}

int main() {
    float ram_usage;
    int i = 0;

    while (1) {
        ram_usage = get_ram_usage();
        printf("Iteration %d\n", i++);
        print_ram_usage(ram_usage);

        // Play a sound if the RAM usage exceeds 80%
        if (ram_usage > 0.8) {
            play_sound("alert.wav");
        }

        sleep(RAM_MONITOR_INTERVAL);
    }

    return 0;
}