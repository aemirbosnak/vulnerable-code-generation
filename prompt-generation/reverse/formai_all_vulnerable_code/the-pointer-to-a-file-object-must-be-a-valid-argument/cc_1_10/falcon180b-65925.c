//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define global variables
long int total_ram = 0;
long int free_ram = 0;
long int used_ram = 0;
float ram_usage_percentage = 0;

// Function to get total, used and free RAM in bytes
void get_ram_info(void) {
    FILE *file = fopen("/proc/meminfo", "r");
    char line[100];
    while (fgets(line, 100, file)!= NULL) {
        if (strstr(line, "MemTotal")!= NULL) {
            sscanf(line, "MemTotal: %ld kB", &total_ram);
        } else if (strstr(line, "MemFree")!= NULL) {
            sscanf(line, "MemFree: %ld kB", &free_ram);
        } else if (strstr(line, "MemAvailable")!= NULL) {
            sscanf(line, "MemAvailable: %ld kB", &free_ram);
        }
    }
    fclose(file);
    used_ram = total_ram - free_ram;
    ram_usage_percentage = ((float)used_ram / (float)total_ram) * 100;
}

// Function to print RAM usage information
void print_ram_info(void) {
    printf("Total RAM: %ld KB\n", total_ram);
    printf("Used RAM: %ld KB\n", used_ram);
    printf("Free RAM: %ld KB\n", free_ram);
    printf("RAM Usage Percentage: %.2f%%\n", ram_usage_percentage);
}

// Main function
int main(void) {
    while (true) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        printf("\n");
        printf("=============================================================\n");
        printf("=                                                            =\n");
        printf("=           RAM USAGE MONITOR - %s                           =\n", t->tm_mon + 1 < 10? "0" : "");
        printf("=                                                            =\n");
        printf("=============================================================\n");
        get_ram_info();
        print_ram_info();
        sleep(5);
    }
    return 0;
}