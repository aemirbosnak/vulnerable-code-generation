//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

struct GPS_Data {
    double latitude;
    double longitude;
    double altitude;
    double speed;
    double heading;
};

struct GPS_Simulator {
    struct GPS_Data current_data;
    double latitude_step;
    double longitude_step;
    double altitude_step;
    double speed_step;
    double heading_step;
};

struct GPS_Simulator *gps_simulator_init(double latitude, double longitude, double altitude, double speed, double heading) {
    struct GPS_Simulator *simulator = malloc(sizeof(struct GPS_Simulator));
    simulator->current_data.latitude = latitude;
    simulator->current_data.longitude = longitude;
    simulator->current_data.altitude = altitude;
    simulator->current_data.speed = speed;
    simulator->current_data.heading = heading;
    simulator->latitude_step = 0.00001;
    simulator->longitude_step = 0.00001;
    simulator->altitude_step = 0.01;
    simulator->speed_step = 0.1;
    simulator->heading_step = 1.0;
    return simulator;
}

void gps_simulator_update(struct GPS_Simulator *simulator) {
    simulator->current_data.latitude += simulator->latitude_step;
    simulator->current_data.longitude += simulator->longitude_step;
    simulator->current_data.altitude += simulator->altitude_step;
    simulator->current_data.speed += simulator->speed_step;
    simulator->current_data.heading += simulator->heading_step;
}

void gps_simulator_print(struct GPS_Simulator *simulator) {
    printf("Latitude: %f\n", simulator->current_data.latitude);
    printf("Longitude: %f\n", simulator->current_data.longitude);
    printf("Altitude: %f\n", simulator->current_data.altitude);
    printf("Speed: %f\n", simulator->current_data.speed);
    printf("Heading: %f\n", simulator->current_data.heading);
}

void gps_simulator_destroy(struct GPS_Simulator *simulator) {
    free(simulator);
}

int main() {
    struct GPS_Simulator *simulator = gps_simulator_init(0.0, 0.0, 0.0, 0.0, 0.0);
    for (int i = 0; i < 100; i++) {
        gps_simulator_update(simulator);
        gps_simulator_print(simulator);
    }
    gps_simulator_destroy(simulator);
    return 0;
}