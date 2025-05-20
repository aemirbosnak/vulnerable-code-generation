//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_SENSORS 10
#define SENSOR_NAME_LEN 32
#define SENSOR_VALUE_LEN 64

struct sensor {
    char name[SENSOR_NAME_LEN];
    int fd;
};

int main(int argc, char **argv) {
    int i, num_sensors = 0;
    struct sensor sensors[MAX_SENSORS];
    char filename[64];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <sensor1> [<sensor2>...]\n", argv[0]);
        return 1;
    }

    for (i = 1; i < argc; i++) {
        strncpy(sensors[num_sensors].name, argv[i], SENSOR_NAME_LEN - 1);
        sensors[num_sensors].name[SENSOR_NAME_LEN - 1] = '\0';
        sensors[num_sensors].fd = -1;
        num_sensors++;

        if (num_sensors >= MAX_SENSORS) {
            fprintf(stderr, "Maximum number of sensors reached.\n");
            return 1;
        }
    }

    for (i = 0; i < num_sensors; i++) {
        sprintf(filename, "/sys/class/thermal/thermal_zone%d/temp", i);
        sensors[i].fd = open(filename, O_RDONLY);

        if (sensors[i].fd == -1) {
            fprintf(stderr, "Failed to open sensor '%s': %s\n", sensors[i].name, strerror(errno));
            return 1;
        }
    }

    while (1) {
        for (i = 0; i < num_sensors; i++) {
            char value[SENSOR_VALUE_LEN];
            int len;

            len = read(sensors[i].fd, value, SENSOR_VALUE_LEN - 1);

            if (len <= 0) {
                fprintf(stderr, "Failed to read sensor '%s': %s\n", sensors[i].name, strerror(errno));
                close(sensors[i].fd);
                sensors[i].fd = -1;
                continue;
            }

            value[len] = '\0';
            printf("%s: %s\n", sensors[i].name, value);
        }

        sleep(5);
    }

    return 0;
}