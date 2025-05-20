//GEMINI-pro DATASET v1.0 Category: System administration ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

// Define the number of samples to collect
#define NUM_SAMPLES 100

// Define the maximum length of each sample
#define MAX_SAMPLE_LENGTH 1024

// Define the path to the file where the samples will be stored
#define SAMPLE_FILE "samples.txt"

// Declare the function that will collect the samples
int collect_samples(char *samples[], int num_samples);

// Declare the function that will write the samples to a file
int write_samples(char *samples[], int num_samples);

// Declare the function that will analyze the samples
int analyze_samples(char *samples[], int num_samples);

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has specified the number of samples to collect
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <num_samples>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Convert the number of samples to an integer
  int num_samples = atoi(argv[1]);

  // Check if the number of samples is valid
  if (num_samples <= 0 || num_samples > NUM_SAMPLES) {
    fprintf(stderr, "Invalid number of samples: %d\n", num_samples);
    exit(EXIT_FAILURE);
  }

  // Allocate memory for the samples
  char *samples[num_samples];
  for (int i = 0; i < num_samples; i++) {
    samples[i] = malloc(MAX_SAMPLE_LENGTH);
  }

  // Collect the samples
  int status = collect_samples(samples, num_samples);
  if (status != 0) {
    fprintf(stderr, "Error collecting samples: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Write the samples to a file
  status = write_samples(samples, num_samples);
  if (status != 0) {
    fprintf(stderr, "Error writing samples to file: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Analyze the samples
  status = analyze_samples(samples, num_samples);
  if (status != 0) {
    fprintf(stderr, "Error analyzing samples: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Free the memory allocated for the samples
  for (int i = 0; i < num_samples; i++) {
    free(samples[i]);
  }

  return EXIT_SUCCESS;
}

// Function to collect the samples
int collect_samples(char *samples[], int num_samples) {
  for (int i = 0; i < num_samples; i++) {
    // Get the current time
    time_t now = time(NULL);
    if (now == (time_t)-1) {
      return -1;
    }

    // Convert the time to a string
    char *time_str = ctime(&now);
    if (time_str == NULL) {
      return -1;
    }

    // Remove the newline character from the time string
    time_str[strlen(time_str) - 1] = '\0';

    // Copy the time string to the sample
    strcpy(samples[i], time_str);
  }

  return 0;
}

// Function to write the samples to a file
int write_samples(char *samples[], int num_samples) {
  // Open the file for writing
  int fd = open(SAMPLE_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd == -1) {
    return -1;
  }

  // Write the samples to the file
  for (int i = 0; i < num_samples; i++) {
    if (write(fd, samples[i], strlen(samples[i])) == -1) {
      close(fd);
      return -1;
    }
  }

  // Close the file
  close(fd);

  return 0;
}

// Function to analyze the samples
int analyze_samples(char *samples[], int num_samples) {
  // Calculate the mean of the samples
  double mean = 0.0;
  for (int i = 0; i < num_samples; i++) {
    mean += atof(samples[i]);
  }
  mean /= num_samples;

  // Calculate the standard deviation of the samples
  double stddev = 0.0;
  for (int i = 0; i < num_samples; i++) {
    stddev += pow(atof(samples[i]) - mean, 2);
  }
  stddev /= num_samples;
  stddev = sqrt(stddev);

  // Print the results to the console
  printf("Mean: %.2f\n", mean);
  printf("Standard deviation: %.2f\n", stddev);

  return 0;
}