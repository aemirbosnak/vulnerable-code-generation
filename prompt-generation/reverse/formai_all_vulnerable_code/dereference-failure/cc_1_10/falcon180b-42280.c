//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char *name;
    int score;
} Student;

Student *students = NULL;
int num_students = 0;

void read_csv(FILE *file) {
    char line[10000];
    int i = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strlen(line) > 0 && line[0]!= '#') {
            char *token = strtok(line, ",");
            if (token!= NULL) {
                students = (Student *)realloc(students, sizeof(Student) * ++num_students);
                students[num_students - 1].name = strdup(token);
            }
            else {
                printf("Error: Invalid line format.\n");
            }
        }
    }
}

int compare_students(const void *a, const void *b) {
    Student *student1 = (Student *)a;
    Student *student2 = (Student *)b;
    return strcmp(student1->name, student2->name);
}

void search_students(char *query) {
    qsort(students, num_students, sizeof(Student), compare_students);
    int low = 0;
    int high = num_students - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (strcmp(students[mid].name, query) == 0) {
            printf("Found student: %s\n", students[mid].name);
            printf("Score: %d\n", students[mid].score);
            return;
        }
        else if (strcmp(students[mid].name, query) < 0) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    printf("Student not found.\n");
}

int main() {
    FILE *file = fopen("students.csv", "r");
    if (file == NULL) {
        printf("Error: Failed to open file.\n");
        return 1;
    }
    read_csv(file);
    fclose(file);

    char query[100];
    printf("Enter student name to search: ");
    fgets(query, sizeof(query), stdin);

    search_students(query);

    for (int i = 0; i < num_students; i++) {
        free(students[i].name);
    }
    free(students);
    return 0;
}