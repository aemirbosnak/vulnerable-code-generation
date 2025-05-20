//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_TEMPERATURES 100
#define MAX_TEMPERATURE_NAME_LENGTH 20

typedef struct {
    char name[MAX_TEMPERATURE_NAME_LENGTH];
    float temperature;
    time_t timestamp;
} Temperature;

void print_usage() {
    printf("Usage: \n");
    printf("    temperature_monitor -a <temperature_name> <temperature_value>\n");
    printf("    temperature_monitor -d <temperature_name>\n");
    printf("    temperature_monitor -l\n");
}

void add_temperature(Temperature *temperatures, int num_temperatures, char *name, float value) {
    if (num_temperatures >= MAX_TEMPERATURES) {
        printf("Maximum number of temperatures reached.\n");
        return;
    }

    int i;
    for (i = 0; i < num_temperatures; i++) {
        if (strcmp(temperatures[i].name, name) == 0) {
            printf("Temperature '%s' already exists.\n", name);
            return;
        }
    }

    strcpy(temperatures[num_temperatures].name, name);
    temperatures[num_temperatures].temperature = value;
    temperatures[num_temperatures].timestamp = time(NULL);
    num_temperatures++;
}

void delete_temperature(Temperature *temperatures, int num_temperatures, char *name) {
    int i;
    for (i = 0; i < num_temperatures; i++) {
        if (strcmp(temperatures[i].name, name) == 0) {
            memmove(&temperatures[i], &temperatures[i+1], sizeof(Temperature) * (num_temperatures - i - 1));
            num_temperatures--;
            return;
        }
    }

    printf("Temperature '%s' not found.\n", name);
}

void list_temperatures(Temperature *temperatures, int num_temperatures) {
    printf("Name\t\tTemperature\tTimestamp\n");
    printf("------------------------------------------------------------\n");

    int i;
    for (i = 0; i < num_temperatures; i++) {
        printf("%-20s\t%.2f\t\t%s\n", temperatures[i].name, temperatures[i].temperature, ctime(&temperatures[i].timestamp));
    }
}

int main(int argc, char *argv[]) {
    Temperature temperatures[MAX_TEMPERATURES];
    int num_temperatures = 0;

    if (argc < 3) {
        print_usage();
        return 1;
    }

    if (strcmp(argv[1], "-a") == 0) {
        if (argc!= 4) {
            print_usage();
            return 1;
        }

        add_temperature(temperatures, num_temperatures, argv[2], atof(argv[3]));
    } else if (strcmp(argv[1], "-d") == 0) {
        if (argc!= 3) {
            print_usage();
            return 1;
        }

        delete_temperature(temperatures, num_temperatures, argv[2]);
    } else if (strcmp(argv[1], "-l") == 0) {
        list_temperatures(temperatures, num_temperatures);
    } else {
        print_usage();
        return 1;
    }

    return 0;
}