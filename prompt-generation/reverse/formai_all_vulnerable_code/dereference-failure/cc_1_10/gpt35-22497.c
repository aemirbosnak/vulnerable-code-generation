//FormAI DATASET v1.0 Category: Database querying ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_GRADES 5

typedef struct {
    char name[MAX_NAME_LEN];
    int grades[MAX_GRADES];
} Student;

int main() {
    FILE *file;
    Student students[100];
    int num_students = 0;

    char filename[] = "students.txt";
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char* name = strtok(line, ",");
        strcpy(students[num_students].name, name);

        int i = 0;
        while (i < MAX_GRADES) {
            char* grade_str = strtok(NULL, ",");
            if (grade_str == NULL) {
                break;
            }
            int grade = atoi(grade_str);
            students[num_students].grades[i] = grade;
            i++;
        }

        num_students++;
    }

    fclose(file);

    // Calculate the average grade for each student
    for (int i = 0; i < num_students; i++) {
        float avg_grade = 0;
        for (int j = 0; j < MAX_GRADES; j++) {
            avg_grade += students[i].grades[j];
        }
        avg_grade /= MAX_GRADES;
        printf("%s: %f\n", students[i].name, avg_grade);
    }

    return 0;
}