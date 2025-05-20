//FormAI DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Load data from file
    FILE *fp;
    fp = fopen("student_data.csv", "r");

    char buffer[1024];
    char *record, *line;

    int num_students = 0;
    int num_courses = 0;
    int i, j, k;

    float student_data[100][100];
    while((line = fgets(buffer, sizeof(buffer), fp)) != NULL) {
        record = strtok(line, ",");
        j = 0;
        while(record != NULL) {
            student_data[num_students][j++] = atof(record);
            record = strtok(NULL, ",");
        }
        num_students++;
    }
    fclose(fp);

    num_courses = j - 1;

    // Analyze data
    float average_scores[num_courses];
    int total_above_avg = 0;

    for(i = 0; i < num_courses; i++) {
        float course_sum = 0.0;
        for(j = 0; j < num_students; j++) {
            course_sum += student_data[j][i+1];
        }
        average_scores[i] = course_sum / num_students;
    }

    for(j = 0; j < num_students; j++) {
        int above_avg = 0;
        for(i = 0; i < num_courses; i++) {
            if(student_data[j][i+1] > average_scores[i]) {
                above_avg++;
            }
        }
        if(above_avg == num_courses) {
            total_above_avg++;
        }
    }

    // Display results
    printf("Course Averages:\n");
    for(i = 0; i < num_courses; i++) {
        printf("Course %d: %.2f\n", i+1, average_scores[i]);
    }

    printf("\nNumber of Students above Average in All Courses: %d\n", total_above_avg);

    return 0;
}