//GEMINI-pro DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple data structure to represent a student
typedef struct {
  char name[50];
  int age;
  float gpa;
} Student;

// Function to read students from a file
int read_students(const char *filename, Student **students) {
  FILE *fp;
  int num_students;
  int i;

  // Open the file for reading
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return -1;
  }

  // Read the number of students from the file
  fscanf(fp, "%d\n", &num_students);

  // Allocate memory for the students
  *students = malloc(sizeof(Student) * num_students);
  if (*students == NULL) {
    perror("Error allocating memory");
    fclose(fp);
    return -1;
  }

  // Read the students from the file
  for (i = 0; i < num_students; i++) {
    fscanf(fp, "%s %d %f\n", (*students)[i].name, &(*students)[i].age, &(*students)[i].gpa);
  }

  // Close the file
  fclose(fp);

  return num_students;
}

// Function to write students to a file
int write_students(const char *filename, const Student *students, int num_students) {
  FILE *fp;
  int i;

  // Open the file for writing
  fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file");
    return -1;
  }

  // Write the number of students to the file
  fprintf(fp, "%d\n", num_students);

  // Write the students to the file
  for (i = 0; i < num_students; i++) {
    fprintf(fp, "%s %d %f\n", students[i].name, students[i].age, students[i].gpa);
  }

  // Close the file
  fclose(fp);

  return 0;
}

// Main function
int main() {
  Student *students;
  int num_students;

  // Read the students from the file
  num_students = read_students("students.txt", &students);
  if (num_students < 0) {
    return 1;
  }

  // Print the students
  for (int i = 0; i < num_students; i++) {
    printf("%s %d %f\n", students[i].name, students[i].age, students[i].gpa);
  }

  // Write the students to a new file
  if (write_students("students_new.txt", students, num_students) < 0) {
    return 1;
  }

  // Free the memory allocated for the students
  free(students);

  return 0;
}