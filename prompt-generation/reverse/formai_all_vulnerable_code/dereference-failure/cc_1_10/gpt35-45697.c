//FormAI DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the structure of a course
typedef struct {
    char name[50];
    int credits;
    char instructor[50];
} Course;

// Defining the structure of a node in the linked list
typedef struct node {
    Course course;
    struct node *next;
} Node;

// Defining the structure of the linked list
typedef struct {
    Node *head;
    int size;
} LinkedList;

// Function prototype declarations
void addCourse(LinkedList *list, Course course);
void deleteCourse(LinkedList *list, char name[]);
void displayCourses(LinkedList list);

// Main function
int main() {
    LinkedList courseList = {NULL, 0};  // Creating an empty linked list
    
    // Adding courses to the list
    addCourse(&courseList, (Course){"C Programming", 4, "John Smith"});
    addCourse(&courseList, (Course){"Data Structures", 3, "Jane Doe"});
    addCourse(&courseList, (Course){"Database Management", 3, "Bob Johnson"});
    addCourse(&courseList, (Course){"Operating Systems", 4, "Sara Lee"});
    
    // Displaying courses in the list
    printf("Courses in the list:\n");
    displayCourses(courseList);
    
    // Deleting a course from the list
    deleteCourse(&courseList, "Data Structures");
    printf("\nCourses in the list after deleting Data Structures:\n");
    displayCourses(courseList);
    
    return 0;
}

// Function to add a course to the linked list
void addCourse(LinkedList *list, Course course) {
    // Creating a new node with the given course
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->course = course;
    newNode->next = NULL;
    
    // Adding the new node at the end of the list
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *curr = list->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    
    // Updating the size of the list
    list->size++;
}

// Function to delete a course from the linked list
void deleteCourse(LinkedList *list, char name[]) {
    Node *prev = NULL;
    Node *curr = list->head;
    
    // Finding the node with the given course name
    while (curr != NULL && strcmp(curr->course.name, name) != 0) {
        prev = curr;
        curr = curr->next;
    }
    
    // Deleting the node if found
    if (curr != NULL) {
        if (prev == NULL) {
            list->head = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
        list->size--;
    }
}

// Function to display all the courses in the linked list
void displayCourses(LinkedList list) {
    Node *curr = list.head;
    while (curr != NULL) {
        printf("%s (%d credits) taught by %s\n", curr->course.name, curr->course.credits, curr->course.instructor);
        curr = curr->next;
    }
}