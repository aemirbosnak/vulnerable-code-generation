//FormAI DATASET v1.0 Category: Linked list operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a student structure that holds student information
struct student {
  char* name;
  int id;
  float grade;
  struct student* next;
};

// Function to create a new student record and add it to the linked list
struct student* add_student(struct student* head, char* name, int id, float grade) {
  struct student* new_student = (struct student*)malloc(sizeof(struct student));
  new_student->name = name;
  new_student->id = id;
  new_student->grade = grade;
  new_student->next = NULL;

  if (head == NULL) {
    head = new_student;
  } else {
    struct student* current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_student;
  }

  return head;
}

// Function to delete a student record from the linked list
struct student* delete_student(struct student* head, int id) {
  struct student* current = head;
  struct student* previous = NULL;

  while (current != NULL && current->id != id) {
    previous = current;
    current = current->next;
  }

  if (current == NULL) {
    printf("Student with ID %d not found.\n", id);
    return head;
  } else {
    if (previous == NULL) {
      head = current->next;
    } else {
      previous->next = current->next;
    }
    free(current);
    printf("Student with ID %d deleted.\n", id);
    return head;
  }
}

// Function to search for a student record in the linked list
void search_student(struct student* head, int id) {
  struct student* current = head;

  while (current != NULL && current->id != id) {
    current = current->next;
  }

  if (current == NULL) {
    printf("Student with ID %d not found.\n", id);
  } else {
    printf("Student with ID %d found!\n", id);
    printf("Name: %s\n", current->name);
    printf("Grade: %.2f\n", current->grade);
  }
}

// Function to display all student records in the linked list
void display_students(struct student* head) {
  if (head == NULL) {
    printf("No student records found.\n");
    return;
  }

  struct student* current = head;

  while (current != NULL) {
    printf("\nName: %s\n", current->name);
    printf("ID: %d\n", current->id);
    printf("Grade: %.2f\n", current->grade);
    current = current->next;
  }
}

// Main function to test the linked list operations
int main() {
  struct student* head = NULL;

  // Add some student records to the linked list
  head = add_student(head, "John Doe", 1234, 3.45);
  head = add_student(head, "Jane Smith", 5678, 4.00);
  head = add_student(head, "Bob Wilson", 9012, 2.75);

  // Display all student records
  printf("DISPLAYING ALL STUDENT RECORDS:\n");
  display_students(head);

  // Search for a specific student record
  printf("\nSEARCHING FOR STUDENT WITH ID 5678:\n");
  search_student(head, 5678);

  // Delete a student record
  printf("\nDELETING STUDENT WITH ID 1234:\n");
  head = delete_student(head, 1234);

  // Display all student records again
  printf("\nDISPLAYING ALL STUDENT RECORDS AFTER DELETION:\n");
  display_students(head);

  return 0;
}