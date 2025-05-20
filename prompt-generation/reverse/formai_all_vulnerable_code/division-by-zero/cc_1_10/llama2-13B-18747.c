//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN_VALUE 0
#define MAX_VALUE 100

// Global variables
int avg_score = 0;
int sum_score = 0;
int num_files = 0;

// Function to read data from a file
void read_data(char *file_name) {
  FILE *file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Error: Could not open file %s\n", file_name);
    return;
  }
  char line[100];
  while (fgets(line, 100, file) != NULL) {
    // Ignore comment lines
    if (line[0] == '#') continue;
    // Parse the score
    int score = atoi(line);
    if (score < MIN_VALUE || score > MAX_VALUE) {
      printf("Error: Invalid score %d in file %s\n", score, file_name);
      continue;
    }
    // Add the score to the sum
    sum_score += score;
    // Increment the number of files
    num_files++;
  }
  fclose(file);
}

// Function to calculate the average score
void calculate_average() {
  avg_score = sum_score / num_files;
  printf("Average score: %d\n", avg_score);
}

int main() {
  // Read data from three files
  read_data("file1.txt");
  read_data("file2.txt");
  read_data("file3.txt");
  
  // Calculate the average score
  calculate_average();
  
  return 0;
}