//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CHAR 50

// function to calculate distance between two points using pythagorean theorem
float calculate_distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int num_points;
    printf("Enter the number of access points: ");
    scanf("%d", &num_points);
    
    // allocate memory array for access points
    float *ap_x_coords = (float*) malloc(num_points * sizeof(float));
    float *ap_y_coords = (float*) malloc(num_points * sizeof(float));
    int *signal_strengths = (int*) malloc(num_points * sizeof(int));
    
    // get access point information from user
    for (int i = 0; i < num_points; i++) {
        printf("\nEnter the x coordinate for access point %d: ", i+1);
        scanf("%f", &ap_x_coords[i]);
        
        printf("\nEnter the y coordinate for access point %d: ", i+1);
        scanf("%f", &ap_y_coords[i]);
        
        printf("\nEnter the signal strength (in dB) for access point %d: ", i+1);
        scanf("%d", &signal_strengths[i]);
    }
    
    // get user's current location
    float user_x, user_y;
    printf("\nEnter your current x coordinate: ");
    scanf("%f", &user_x);
    
    printf("\nEnter your current y coordinate: ");
    scanf("%f", &user_y);
    
    // calculate distances and strengths for all access points
    float distances[num_points];
    float strengths[num_points];
    for (int i = 0; i < num_points; i++) {
        distances[i] = calculate_distance(user_x, user_y, ap_x_coords[i], ap_y_coords[i]);
        strengths[i] = signal_strengths[i] - (20 * log10(distances[i]));
    }
    
    // determine strongest and weakest signals
    float max_strength = strengths[0];
    float min_strength = strengths[0];
    int max_index = 0;
    int min_index = 0;
    for (int i = 1; i < num_points; i++) {
        if (strengths[i] > max_strength) {
            max_strength = strengths[i];
            max_index = i;
        }
        if (strengths[i] < min_strength) {
            min_strength = strengths[i];
            min_index = i;
        }
    }
    
    // print strongest and weakest signals
    printf("\nStrongest signal: Access Point %d with signal strength %.2f dB\n", max_index+1, max_strength);
    printf("Weakest signal: Access Point %d with signal strength %.2f dB\n", min_index+1, min_strength);
    
    // free allocated memory
    free(ap_x_coords);
    free(ap_y_coords);
    free(signal_strengths);
    
    return 0;
}