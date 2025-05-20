//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MIN_SPEED 1.0 /* Minimum speed in Mbps. */
#define MAX_SPEED 200.0 /* Maximum speed in Mbps. */
#define RUN_TIME 10.0 /* Duration of the test in seconds. */

double get_random_speed() {
  /* Generates a random speed between minimum and maximum speeds. */
  return (rand() / (double)RAND_MAX) * (MAX_SPEED - MIN_SPEED) + MIN_SPEED;
}

double calculate_average_speed(double* speeds, int num_speeds) {
  /* Calculates the average speed. */
  double sum = 0.0;
  for(int i = 0; i < num_speeds; i++) {
    sum += speeds[i];
  }
  return sum / num_speeds;
}

int main() {
  /* Initialize random number generator. */
  srand(time(NULL));

  printf("Welcome to the Internet Speed Test Application!\n\n");

  int num_tests;  
  printf("How many tests do you want to run? ");
  scanf("%d", &num_tests);

  /* Allocate memory for array of speeds. */
  double* speeds = malloc(num_tests * sizeof(double));

  /* Run the tests. */
  for(int i = 0; i < num_tests; i++) {
    /* Generate a random speed. */
    double speed = get_random_speed();
    printf("Running test %d...", i+1);

    /* Sleep for a random amount of time between 1 and 5 seconds. */
    int sleep_time = rand() % 5 + 1;
    printf("Sleeping for %d seconds...", sleep_time);
    sleep(sleep_time);
    printf("Done.\n");

    /* Record the speed. */
    speeds[i] = speed;
  }

  /* Calculate and display the average speed. */
  double avg_speed = calculate_average_speed(speeds, num_tests);
  printf("\nAverage speed: %.2f Mbps\n", avg_speed);

  /* Free memory. */
  free(speeds);

  return 0;
}