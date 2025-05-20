//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define MAX_SENSORS 10
#define MAX_SAMPLES 1000
#define SENSOR_DATA_SIZE 4

typedef struct {
    char name[20];
    int value;
} sensor_t;

sensor_t sensors[MAX_SENSORS];
int num_sensors;
int sample_count;

void *sensor_thread(void *arg) {
    int i;
    for (i = 0; i < num_sensors; i++) {
        sensors[i].value = rand() % 100;
        sleep(1);
    }
    return NULL;
}

int main() {
    int i;
    char input[20];

    printf("Enter number of sensors: ");
    scanf("%d", &num_sensors);

    for (i = 0; i < num_sensors; i++) {
        printf("Enter name of sensor %d: ", i+1);
        scanf("%s", sensors[i].name);
    }

    pthread_t threads[num_sensors];
    int rc;

    for (i = 0; i < num_sensors; i++) {
        rc = pthread_create(&threads[i], NULL, sensor_thread, (void *)i);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < num_sensors; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Enter number of samples to take: ");
    scanf("%d", &sample_count);

    FILE *fp;
    fp = fopen("sensor_data.txt", "w");

    for (i = 0; i < sample_count; i++) {
        for (int j = 0; j < num_sensors; j++) {
            fprintf(fp, "%s %d\n", sensors[j].name, sensors[j].value);
        }
        sleep(1);
    }

    fclose(fp);
    printf("Data saved to sensor_data.txt\n");

    return 0;
}