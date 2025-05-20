//FormAI DATASET v1.0 Category: Database simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  int id;
  char* name;
  char* major;
  float gpa;
};

void add(struct Student**, int*, int, char*, char*, float);
void print(struct Student*, int);
void search(struct Student*, int, char*);
void update(struct Student*, int, int, char*, char*, float);
void delete(struct Student**, int*, int);

int main() {
  int size = 0;
  struct Student* students = NULL;

  add(&students, &size, 1001, "John Doe", "Computer Science", 3.5);
  add(&students, &size, 1002, "Jane Smith", "Biology", 3.8);
  add(&students, &size, 1003, "Bob Johnson", "History", 3.2);

  printf("Displaying all students:\n");
  print(students, size);

  printf("\nSearching for student with ID 1002:\n");
  search(students, size, "1002");

  printf("\nUpdating student with ID 1003:\n");
  update(students, size, 1003, "Samantha Lee", "Psychology", 3.7);
  print(students, size);

  printf("\nDeleting student with ID 1001:\n");
  delete(&students, &size, 1001);
  print(students, size);

  return 0;
}

void add(struct Student** studentsPtr, int* sizePtr, int id, char* name, char* major, float gpa) {
  *sizePtr += 1;
  *studentsPtr = realloc(*studentsPtr, sizeof(struct Student) * (*sizePtr));
  struct Student newStudent = {id, name, major, gpa};
  (*studentsPtr)[*sizePtr-1] = newStudent;
}

void print(struct Student* students, int size) {
  for (int i = 0; i < size; i++) {
    printf("ID: %d\nName: %s\nMajor: %s\nGPA: %.2f\n\n", students[i].id, students[i].name, students[i].major, students[i].gpa);
  }
}

void search(struct Student* students, int size, char* target) {
  for (int i = 0; i < size; i++) {
    if (students[i].id == atoi(target)) {
      printf("ID: %d\nName: %s\nMajor: %s\nGPA: %.2f\n\n", students[i].id, students[i].name, students[i].major, students[i].gpa);
      return;
    }
  }
  printf("Student not found.\n");
}

void update(struct Student* students, int size, int id, char* name, char* major, float gpa) {
  for (int i = 0; i < size; i++) {
    if (students[i].id == id) {
      students[i].name = name;
      students[i].major = major;
      students[i].gpa = gpa;
      return;
    }
  }
  printf("Student not found.\n");
}

void delete(struct Student** studentsPtr, int* sizePtr, int id) {
  for (int i = 0; i < *sizePtr; i++) {
    if ((*studentsPtr)[i].id == id) {
      // shift all elements after the deleted one
      for (int j = i; j < *sizePtr-1; j++) {
        (*studentsPtr)[j] = (*studentsPtr)[j+1];
      }
      *sizePtr -= 1;
      *studentsPtr = realloc(*studentsPtr, sizeof(struct Student) * (*sizePtr));
      return;
    }
  }
  printf("Student not found.\n");
}