//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 100 // number of students
#define M 5 // number of questions
#define SCALE 10 // scale of scores (0-10)

// define a structure to hold student data
typedef struct {
    int id; // student ID
    int scores[M]; // scores for each question
} Student;

// function to read student data from a file
Student *read_students(const char *file_name) {
    // open file in read mode
    FILE *file = fopen(file_name, "r");

    // check if file is empty
    if (file == NULL) {
        printf("Error: unable to open file %s\n", file_name);
        return NULL;
    }

    // allocate memory for student data
    Student *students = (Student *)calloc(N, sizeof(Student));

    // read student data from file
    for (int i = 0; i < N; i++) {
        fscanf(file, "%d%*c", &students[i].id);
        for (int j = 0; j < M; j++) {
            fscanf(file, "%d", &students[i].scores[j]);
        }
    }

    // close file
    fclose(file);

    return students;
}

// function to calculate mean and standard deviation for each question
void calculate_means_stddevs(Student *students) {
    for (int i = 0; i < M; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += students[j].scores[i];
        }
        double mean = (double)sum / N;
        double stddev = 0;
        for (int j = 0; j < N; j++) {
            double diff = students[j].scores[i] - mean;
            stddev += diff * diff;
        }
        stddev = sqrt(stddev / N);
        printf("Question %d mean: %f stddev: %f\n", i + 1, mean, stddev);
    }
}

// main function
int main() {
    // read student data from file
    Student *students = read_students("students.txt");

    // calculate mean and standard deviation for each question
    calculate_means_stddevs(students);

    // free memory for student data
    free(students);

    return 0;
}