//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
  // Welcome message
  printf("Welcome to the Internet Speed Test App!\n");

  // Get user input for number of tests
  int num_tests;
  printf("How many times would you like to run the test? ");
  scanf("%d", &num_tests);

  // Allocate memory for test results
  double* test_results = (double*) malloc(num_tests * sizeof(double));

  // Run test num_tests times
  for (int i = 0; i < num_tests; i++) {
    
    // Generate random download and upload speeds
    srand(time(0)); // Set seed for random generation
    double download_speed = ((double) rand() / (double) RAND_MAX) * 1000.0; // Random download speed from 0 to 1000 Mbps
    double upload_speed = ((double) rand() / (double) RAND_MAX) * 100.0; // Random upload speed from 0 to 100 Mbps
    
    // Calculate latency
    double latency = ((double) rand() / (double) RAND_MAX) * 100.0; // Random latency from 0 to 100 ms

    // Print test results
    printf("Test %d:\n", i+1);
    printf("\tDownload Speed: %.2f Mbps\n", download_speed);
    printf("\tUpload Speed: %.2f Mbps\n", upload_speed);
    printf("\tLatency: %.2f ms\n", latency);

    // Save test result
    double test_result = download_speed + upload_speed - latency; // Calculate final test result
    test_results[i] = test_result;
  }

  // Calculate average test result
  double sum = 0;
  for (int i = 0; i < num_tests; i++) {
    sum += test_results[i];
  }
  double avg_result = sum / (double) num_tests;

  // Print final average result
  printf("Average Test Result: %.2f\n", avg_result);

  // Free memory
  free(test_results);

  return 0;
}