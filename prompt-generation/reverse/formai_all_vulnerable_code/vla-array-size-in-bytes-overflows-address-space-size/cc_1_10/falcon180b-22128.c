//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_TEMP 100
#define MIN_TEMP -100

typedef struct {
    char name[20];
    float temperature;
} Sensor;

void read_sensors(Sensor sensors[], int num_sensors) {
    for (int i = 0; i < num_sensors; i++) {
        sensors[i].temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        printf("Reading temperature from sensor %d: %.2f\n", i+1, sensors[i].temperature);
    }
}

void display_sensors(Sensor sensors[], int num_sensors) {
    printf("\nCurrent Temperatures:\n");
    for (int i = 0; i < num_sensors; i++) {
        printf("Sensor %d (%s): %.2f\n", i+1, sensors[i].name, sensors[i].temperature);
    }
}

int main() {
    srand(time(NULL));

    int num_sensors;
    printf("Enter the number of sensors: ");
    scanf("%d", &num_sensors);

    Sensor sensors[num_sensors];

    for (int i = 0; i < num_sensors; i++) {
        printf("Enter the name of sensor %d: ", i+1);
        scanf("%s", sensors[i].name);
    }

    while (TRUE) {
        read_sensors(sensors, num_sensors);
        display_sensors(sensors, num_sensors);

        printf("\nDo you want to continue? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    return 0;
}