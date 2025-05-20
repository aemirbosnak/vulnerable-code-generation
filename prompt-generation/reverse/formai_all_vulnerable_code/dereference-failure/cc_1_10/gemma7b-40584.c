//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NUMBER_OF_ Sensors 10

struct Sensor {
    int sensor_id;
    char sensor_name[20];
    int sensor_status;
    struct Sensor *next_sensor;
};

struct Sensor *sensors = NULL;

void add_sensor(int sensor_id, char *sensor_name, int sensor_status)
{
    struct Sensor *new_sensor = malloc(sizeof(struct Sensor));
    new_sensor->sensor_id = sensor_id;
    strcpy(new_sensor->sensor_name, sensor_name);
    new_sensor->sensor_status = sensor_status;
    new_sensor->next_sensor = NULL;

    if (sensors == NULL)
    {
        sensors = new_sensor;
    }
    else
    {
        sensors->next_sensor = new_sensor;
        sensors = new_sensor;
    }
}

int main()
{
    add_sensor(1, "Kitchen Door Sensor", 0);
    add_sensor(2, "Living Room Door Sensor", 0);
    add_sensor(3, "Master Bedroom Door Sensor", 0);

    // Simulate sensor activation
    sensors->sensor_status = 1;

    // Check sensor status
    struct Sensor *current_sensor = sensors;
    while (current_sensor)
    {
        if (current_sensor->sensor_status)
        {
            printf("Sensor %d: %s is OPEN!\n", current_sensor->sensor_id, current_sensor->sensor_name);
        }
        current_sensor = current_sensor->next_sensor;
    }

    return 0;
}