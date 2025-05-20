//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/resource.h>

#define TEMP_FILE "/sys/class/thermal/thermal_zone0/temp"
#define CPU_LOAD_FILE "/proc/stat"
#define CPU_LOAD_LINE "cpu "

int get_cpu_load(double *load) {
    FILE *file = fopen(CPU_LOAD_FILE, "r");
    if (file == NULL) {
        printf("Error: Failed to open %s\n", CPU_LOAD_FILE);
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strncmp(line, CPU_LOAD_LINE, strlen(CPU_LOAD_LINE)) == 0) {
            char *token = strtok(line, " ");
            while (token!= NULL) {
                if (isdigit(token[0])) {
                    *load = atof(token);
                    break;
                }
                token = strtok(NULL, " ");
            }
            break;
        }
    }

    fclose(file);
    return 0;
}

int get_temperature(double *temp) {
    FILE *file = fopen(TEMP_FILE, "r");
    if (file == NULL) {
        printf("Error: Failed to open %s\n", TEMP_FILE);
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strncmp(line, "temp", strlen("temp")) == 0) {
            *temp = atof(line) / 1000.0;
            break;
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <interval in seconds>\n", argv[0]);
        exit(1);
    }

    int interval = atoi(argv[1]);
    double cpu_load, temp;

    while (1) {
        get_cpu_load(&cpu_load);
        get_temperature(&temp);

        printf("CPU Load: %.2f%%\n", cpu_load);
        printf("Temperature: %.2f°C\n\n", temp);

        sleep(interval);
    }

    return 0;
}