//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Here's our simulation of the GPS navigation system!

int main() {
    srand(time(NULL));
    
    // Let's start with some fake GPS coordinates.
    double latitude = 40.7128;
    double longitude = -74.0059;
    // And a random destination.
    double dest_lat = 40.6908;
    double dest_lon = -73.9896;
    
    // Now let's simulate the journey!
    int distance = rand() % 10; // Let's say it's between 0 and 9 miles.
    int time = distance * 10; // Assume 10 minutes per mile.
    printf("Starting navigation to destination approximately %d miles away.\n", distance);
    printf("Estimated travel time: %d minutes.\n", time);
    
    // Let's update our location incrementally to simulate movement.
    for (int i = 0; i <= distance; i++) {
        // Calculate the remaining distance and time.
        int remaining_distance = distance - i;
        int remaining_time = remaining_distance * 10;
        
        // Update our coordinates based on the destination and the remaining distance.
        latitude += (dest_lat - latitude) * (i / distance);
        longitude += (dest_lon - longitude) * (i / distance);
        
        // Print the updated coordinates and the remaining distance and time.
        printf("Current location: (%f, %f)\n", latitude, longitude);
        printf("Remaining distance: %d miles\n", remaining_distance);
        printf("Remaining time: %d minutes\n", remaining_time);
        
        // Let's add some occasional detours or delays to spice things up!
        if (rand() % 10 == 0) {
            printf("Unexpected detour encountered!\n");
            distance++; // Increase the distance by 1 mile.
            time += 10; // Increase the time by 10 minutes.
        }
        if (rand() % 15 == 0) {
            printf("Unexpected traffic delay!\n");
            time += 5; // Increase the time by 5 minutes.
        }
        
        // Sleep for a second to simulate the passage of time.
        sleep(1);
    }
    
    // Finally, we have reached the destination!
    printf("Destination reached!\n");
    
    return 0;
}