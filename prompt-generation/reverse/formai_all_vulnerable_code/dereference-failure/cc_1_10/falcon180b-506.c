//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_SENSORS 10
#define SENSOR_NAME_SIZE 20
#define SENSOR_VALUE_SIZE 20
#define TEMP_THRESHOLD 50
#define ALARM_SOUND "alarm.wav"
#define SLEEP_SECONDS 5

typedef struct {
    char name[SENSOR_NAME_SIZE];
    char value[SENSOR_VALUE_SIZE];
} sensor_t;

sensor_t sensors[MAX_SENSORS];
int num_sensors = 0;

void read_sensors() {
    FILE *fp;
    char line[100];
    int i;

    for (i = 0; i < num_sensors; i++) {
        sprintf(line, "cat /sys/class/thermal/thermal_zone%d/temp", i);
        if ((fp = popen(line, "r"))!= NULL) {
            fgets(sensors[i].value, SENSOR_VALUE_SIZE, fp);
            pclose(fp);
        } else {
            printf("Error: Failed to read sensor %s\n", sensors[i].name);
        }
    }
}

void check_temperature() {
    int i;

    for (i = 0; i < num_sensors; i++) {
        if (atoi(sensors[i].value) >= TEMP_THRESHOLD) {
            printf("ALARM: Sensor %s is at %sC\n", sensors[i].name, sensors[i].value);
            system("afplay " ALARM_SOUND);
        }
    }
}

void add_sensor(char *name) {
    if (num_sensors >= MAX_SENSORS) {
        printf("Error: Maximum number of sensors reached\n");
        return;
    }

    strcpy(sensors[num_sensors].name, name);
    num_sensors++;
}

int main(int argc, char **argv) {
    int i;

    if (argc < 2) {
        printf("Usage: %s sensor_name [sensor_name...]\n", argv[0]);
        return 1;
    }

    for (i = 1; i < argc; i++) {
        add_sensor(argv[i]);
    }

    while (1) {
        read_sensors();
        check_temperature();
        sleep(SLEEP_SECONDS);
    }

    return 0;
}