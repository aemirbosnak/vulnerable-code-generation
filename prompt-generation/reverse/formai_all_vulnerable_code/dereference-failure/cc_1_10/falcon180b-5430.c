//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEMP_SENSORS 10
#define TEMP_SENSOR_NAME_LENGTH 20

struct temp_sensor {
    char name[TEMP_SENSOR_NAME_LENGTH];
    int sensor_id;
    double current_temperature;
    double max_temperature;
    double min_temperature;
};

void print_temp_sensor(struct temp_sensor *sensor) {
    printf("Name: %s\n", sensor->name);
    printf("ID: %d\n", sensor->sensor_id);
    printf("Current temperature: %.2f°C\n", sensor->current_temperature);
    printf("Max temperature: %.2f°C\n", sensor->max_temperature);
    printf("Min temperature: %.2f°C\n", sensor->min_temperature);
    printf("\n");
}

void initialize_temp_sensor(struct temp_sensor *sensor, char *name, int sensor_id) {
    strcpy(sensor->name, name);
    sensor->sensor_id = sensor_id;
    sensor->current_temperature = 0.0;
    sensor->max_temperature = 0.0;
    sensor->min_temperature = 0.0;
}

void update_temp_sensor(struct temp_sensor *sensor, double temperature) {
    sensor->current_temperature = temperature;
    if (temperature > sensor->max_temperature) {
        sensor->max_temperature = temperature;
    }
    if (temperature < sensor->min_temperature) {
        sensor->min_temperature = temperature;
    }
}

int main() {
    int num_sensors;
    printf("Enter number of temperature sensors: ");
    scanf("%d", &num_sensors);

    struct temp_sensor *sensors = (struct temp_sensor *) malloc(num_sensors * sizeof(struct temp_sensor));

    for (int i = 0; i < num_sensors; i++) {
        printf("Enter name for sensor %d: ", i+1);
        char name[TEMP_SENSOR_NAME_LENGTH];
        scanf("%s", name);

        printf("Enter ID for sensor %s: ", name);
        int sensor_id;
        scanf("%d", &sensor_id);

        initialize_temp_sensor(&sensors[i], name, sensor_id);
    }

    while (1) {
        for (int i = 0; i < num_sensors; i++) {
            printf("Sensor %s:\n", sensors[i].name);
            print_temp_sensor(&sensors[i]);
        }
        sleep(1);
    }

    return 0;
}