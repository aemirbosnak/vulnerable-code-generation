//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SENSORS 10
#define SENSOR_NAME_LENGTH 20

struct sensor {
    char name[SENSOR_NAME_LENGTH];
    double temperature;
};

void read_sensors(struct sensor sensors[]) {
    FILE *fp;
    char line[100];
    char *token;
    int i = 0;

    fp = fopen("sensors.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        strcpy(sensors[i].name, token);

        token = strtok(NULL, ",");
        sensors[i].temperature = atof(token);

        i++;
    }

    fclose(fp);
}

void print_sensors(struct sensor sensors[], int num_sensors) {
    int i;

    for (i = 0; i < num_sensors; i++) {
        printf("%s: %.2f°C\n", sensors[i].name, sensors[i].temperature);
    }
}

int main() {
    struct sensor sensors[MAX_SENSORS];
    int num_sensors;

    read_sensors(sensors);
    num_sensors = sizeof(sensors) / sizeof(sensors[0]);

    print_sensors(sensors, num_sensors);

    return 0;
}