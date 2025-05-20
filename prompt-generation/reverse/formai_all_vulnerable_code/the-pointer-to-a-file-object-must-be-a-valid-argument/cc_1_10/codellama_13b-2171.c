//Code Llama-13B DATASET v1.0 Category: Educational ; Style: futuristic
// Futuristic C Program
#include <stdio.h>

// Structure for storing student information
struct student {
    char name[50];
    int age;
    char address[100];
    float marks;
};

// Function to print the student information
void print_student(struct student st) {
    printf("Name: %s\n", st.name);
    printf("Age: %d\n", st.age);
    printf("Address: %s\n", st.address);
    printf("Marks: %f\n", st.marks);
}

// Function to add a new student
void add_student(struct student st) {
    FILE *file = fopen("students.txt", "a");
    fprintf(file, "%s\n%d\n%s\n%f\n", st.name, st.age, st.address, st.marks);
    fclose(file);
}

// Function to remove a student
void remove_student(char *name) {
    FILE *file = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char line[100];
    while (fgets(line, 100, file)) {
        char *line_name = strtok(line, ",");
        if (strcmp(line_name, name) != 0) {
            fprintf(temp, "%s\n", line);
        }
    }
    fclose(file);
    fclose(temp);
    remove("students.txt");
    rename("temp.txt", "students.txt");
}

// Function to display all students
void display_students() {
    FILE *file = fopen("students.txt", "r");
    char line[100];
    while (fgets(line, 100, file)) {
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        char *address = strtok(NULL, ",");
        float marks = atof(strtok(NULL, ","));
        printf("Name: %s\n", name);
        printf("Age: %d\n", age);
        printf("Address: %s\n", address);
        printf("Marks: %f\n", marks);
    }
    fclose(file);
}

// Main function
int main() {
    // Add students
    struct student student1 = {"John Doe", 25, "New York", 85.5};
    add_student(student1);
    struct student student2 = {"Jane Doe", 27, "Los Angeles", 90.5};
    add_student(student2);
    struct student student3 = {"Bob Smith", 30, "Chicago", 75.5};
    add_student(student3);

    // Remove a student
    remove_student("Bob Smith");

    // Display all students
    display_students();

    return 0;
}