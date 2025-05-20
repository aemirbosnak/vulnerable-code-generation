//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the GPS data structure
typedef struct {
    double latitude;
    double longitude;
    double altitude;
    double speed;
    double heading;
    time_t timestamp;
} gps_data_t;

// Define the GPS simulation configuration
typedef struct {
    double min_latitude;
    double max_latitude;
    double min_longitude;
    double max_longitude;
    double min_altitude;
    double max_altitude;
    double min_speed;
    double max_speed;
    double min_heading;
    double max_heading;
    double update_interval;
} gps_sim_config_t;

// Create a new GPS data structure
gps_data_t *gps_data_new() {
    gps_data_t *data = malloc(sizeof(gps_data_t));
    if (data == NULL) {
        return NULL;
    }
    data->latitude = 0.0;
    data->longitude = 0.0;
    data->altitude = 0.0;
    data->speed = 0.0;
    data->heading = 0.0;
    data->timestamp = time(NULL);
    return data;
}

// Free the GPS data structure
void gps_data_free(gps_data_t *data) {
    free(data);
}

// Create a new GPS simulation configuration
gps_sim_config_t *gps_sim_config_new() {
    gps_sim_config_t *config = malloc(sizeof(gps_sim_config_t));
    if (config == NULL) {
        return NULL;
    }
    config->min_latitude = -90.0;
    config->max_latitude = 90.0;
    config->min_longitude = -180.0;
    config->max_longitude = 180.0;
    config->min_altitude = 0.0;
    config->max_altitude = 10000.0;
    config->min_speed = 0.0;
    config->max_speed = 100.0;
    config->min_heading = 0.0;
    config->max_heading = 360.0;
    config->update_interval = 1.0;
    return config;
}

// Free the GPS simulation configuration
void gps_sim_config_free(gps_sim_config_t *config) {
    free(config);
}

// Initialize the GPS simulation
void gps_sim_init(gps_data_t *data, gps_sim_config_t *config) {
    // Set the initial GPS data
    data->latitude = (config->max_latitude - config->min_latitude) * ((double)rand() / (double)RAND_MAX) + config->min_latitude;
    data->longitude = (config->max_longitude - config->min_longitude) * ((double)rand() / (double)RAND_MAX) + config->min_longitude;
    data->altitude = (config->max_altitude - config->min_altitude) * ((double)rand() / (double)RAND_MAX) + config->min_altitude;
    data->speed = (config->max_speed - config->min_speed) * ((double)rand() / (double)RAND_MAX) + config->min_speed;
    data->heading = (config->max_heading - config->min_heading) * ((double)rand() / (double)RAND_MAX) + config->min_heading;
    data->timestamp = time(NULL);
}

// Update the GPS simulation
void gps_sim_update(gps_data_t *data, gps_sim_config_t *config) {
    // Update the GPS data
    data->latitude += (config->max_latitude - config->min_latitude) * ((double)rand() / (double)RAND_MAX) * config->update_interval;
    data->longitude += (config->max_longitude - config->min_longitude) * ((double)rand() / (double)RAND_MAX) * config->update_interval;
    data->altitude += (config->max_altitude - config->min_altitude) * ((double)rand() / (double)RAND_MAX) * config->update_interval;
    data->speed += (config->max_speed - config->min_speed) * ((double)rand() / (double)RAND_MAX) * config->update_interval;
    data->heading += (config->max_heading - config->min_heading) * ((double)rand() / (double)RAND_MAX) * config->update_interval;
    data->timestamp = time(NULL);
}

// Print the GPS data
void gps_data_print(gps_data_t *data) {
    printf("Latitude: %f\n", data->latitude);
    printf("Longitude: %f\n", data->longitude);
    printf("Altitude: %f\n", data->altitude);
    printf("Speed: %f\n", data->speed);
    printf("Heading: %f\n", data->heading);
    printf("Timestamp: %s\n", ctime(&data->timestamp));
}

// Main function
int main() {
    // Create a new GPS data structure
    gps_data_t *data = gps_data_new();
    if (data == NULL) {
        return 1;
    }

    // Create a new GPS simulation configuration
    gps_sim_config_t *config = gps_sim_config_new();
    if (config == NULL) {
        return 1;
    }

    // Initialize the GPS simulation
    gps_sim_init(data, config);

    // Update the GPS simulation
    while (1) {
        gps_sim_update(data, config);

        // Print the GPS data
        gps_data_print(data);

        // Sleep for the update interval
        sleep(config->update_interval);
    }

    // Free the GPS data structure
    gps_data_free(data);

    // Free the GPS simulation configuration
    gps_sim_config_free(config);

    return 0;
}