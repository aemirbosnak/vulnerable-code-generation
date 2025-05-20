//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Statistical parameters
#define MEAN 50
#define STD_DEV 10

// Anomaly detection threshold
#define THRESHOLD 3

// Data point struct
typedef struct {
    double value;
    double timestamp;
} data_point;

// Anomaly detection function
int is_anomaly(data_point *point) {
    // Calculate z-score
    double z_score = (point->value - MEAN) / STD_DEV;

    // Check if z-score is greater than threshold
    return (fabs(z_score) > THRESHOLD);
}

// Main function
int main() {
    // Generate random data points
    int num_points = 100;
    data_point *points = malloc(num_points * sizeof(data_point));

    for (int i = 0; i < num_points; i++) {
        points[i].value = MEAN + STD_DEV * (rand() / (double)RAND_MAX - 0.5);
        points[i].timestamp = i;
    }

    // Detect anomalies
    int num_anomalies = 0;
    for (int i = 0; i < num_points; i++) {
        if (is_anomaly(&points[i])) {
            num_anomalies++;
            printf("Anomaly detected at timestamp %d with value %f\n", points[i].timestamp, points[i].value);
        }
    }

    // Print results
    printf("Total number of data points: %d\n", num_points);
    printf("Total number of anomalies: %d\n", num_anomalies);

    // Free memory
    free(points);

    return 0;
}