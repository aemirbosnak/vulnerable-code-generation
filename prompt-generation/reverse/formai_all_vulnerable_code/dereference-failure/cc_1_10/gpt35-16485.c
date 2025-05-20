//FormAI DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

struct student {
    char name[64];
    double score;
};

int main(int argc, char *argv[]) {

    char *filename;
    FILE *fp;
    char line[MAX_LINE_LEN];
    char *token;
    int num_students = 0;
    struct student *students;
    double score_sum = 0.0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    filename = argv[1];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {

        // Parse the line and extract the name and score
        token = strtok(line, ",");
        if (token == NULL) continue;
        char *name = token;

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        double score = atof(token);

        // Create a new student entry in the array
        struct student s;
        strcpy(s.name, name);
        s.score = score;

        num_students++;
        students = (struct student *) realloc(students, num_students * sizeof(struct student));
        students[num_students-1] = s;

        score_sum += score;
    }

    // Calculate the average score
    double avg_score = score_sum / num_students;
    printf("Average score: %.2f\n", avg_score);

    // Free the memory allocated for the array of students
    free(students);

    // Close the file
    fclose(fp);

    return 0;
}