//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STR_LEN 1024

typedef struct {
  char *name;
  int age;
  float salary;
} person_t;

int main() {
  // Read in the data from a file.
  FILE *fp = fopen("data.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Create an array to store the data.
  person_t *data = malloc(sizeof(person_t) * 100);
  if (data == NULL) {
    perror("Error allocating memory");
    return EXIT_FAILURE;
  }

  // Read in the data from the file.
  int i = 0;
  char line[MAX_STR_LEN];
  while (fgets(line, MAX_STR_LEN, fp) != NULL) {
    // Parse the line.
    char *name = strtok(line, ",");
    int age = atoi(strtok(NULL, ","));
    float salary = atof(strtok(NULL, ","));

    // Store the data in the array.
    data[i].name = malloc(strlen(name) + 1);
    strcpy(data[i].name, name);
    data[i].age = age;
    data[i].salary = salary;

    i++;
  }

  // Close the file.
  fclose(fp);

  // Compute the mean and standard deviation of the age and salary.
  float mean_age = 0.0;
  float mean_salary = 0.0;
  for (i = 0; i < 100; i++) {
    mean_age += data[i].age;
    mean_salary += data[i].salary;
  }
  mean_age /= 100.0;
  mean_salary /= 100.0;

  float stddev_age = 0.0;
  float stddev_salary = 0.0;
  for (i = 0; i < 100; i++) {
    stddev_age += pow(data[i].age - mean_age, 2);
    stddev_salary += pow(data[i].salary - mean_salary, 2);
  }
  stddev_age = sqrt(stddev_age / 100.0);
  stddev_salary = sqrt(stddev_salary / 100.0);

  // Print the mean and standard deviation of the age and salary.
  printf("Mean age: %.2f\n", mean_age);
  printf("Standard deviation of age: %.2f\n", stddev_age);
  printf("Mean salary: %.2f\n", mean_salary);
  printf("Standard deviation of salary: %.2f\n", stddev_salary);

  // Free the memory allocated for the data.
  for (i = 0; i < 100; i++) {
    free(data[i].name);
  }
  free(data);

  return EXIT_SUCCESS;
}