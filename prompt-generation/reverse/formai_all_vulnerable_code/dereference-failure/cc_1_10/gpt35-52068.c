//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#define SERVER_SPEED 100 // Mbps
#define MAX_BUFFER_SIZE 100000000 // 100 MB
#define MIN_BUFFER_SIZE 10000000 // 10 MB
#define TEST_COUNT 5 // Number of times to test speed
#define MAX_SLEEP_TIME 5 // Maximum amount of time to wait before testing again (in seconds)

// Function to generate a random buffer of a given size
void generate_buffer(char *buffer, int size) {
    for (int i = 0; i < size; i++) {
        buffer[i] = 'a' + (rand() % 26);
    }
}

// Function to calculate the speed in Mbps
double calculate_speed(int buffer_size, double elapsed_time) {
    double speed = (buffer_size / elapsed_time) * 8 / (1024 * 1024);
    return speed;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    printf("Starting speed test...\n");
    
    for (int i = 1; i <= TEST_COUNT; i++) {
        // Generate a random buffer size between MIN_BUFFER_SIZE and MAX_BUFFER_SIZE
        int buffer_size = rand() % (MAX_BUFFER_SIZE - MIN_BUFFER_SIZE + 1) + MIN_BUFFER_SIZE;
        
        // Allocate memory for the buffer
        char *buffer = (char*) malloc(buffer_size);
        
        // Generate the random buffer
        generate_buffer(buffer, buffer_size);
        
        // Record the start time
        clock_t start_time = clock();
        
        // Simulate sending the buffer to a server
        usleep(buffer_size * 8 / SERVER_SPEED * 1000000);
        
        // Record the end time
        clock_t end_time = clock();
        
        // Calculate the elapsed time
        double elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
        
        // Calculate the speed
        double speed = calculate_speed(buffer_size, elapsed_time);
        
        // Display the test results
        printf("Test %d: Speed = %.2f Mbps, Buffer size = %d bytes, Elapsed time = %.2f seconds\n", i, speed, buffer_size, elapsed_time);
        
        // Free the memory allocated for the buffer
        free(buffer);
        
        // Sleep for a random amount of time before testing again
        int sleep_time = rand() % MAX_SLEEP_TIME + 1;
        printf("Sleeping for %d seconds before testing again...\n", sleep_time);
        sleep(sleep_time);
    }
    
    return 0;
}