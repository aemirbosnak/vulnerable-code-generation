//FormAI DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    int id;
    char name[50];
    int age;
};

typedef struct student Student;

typedef struct {
    int index;
    int offset;
} index_t;

void create_index(Student **students, index_t **index, int size) {
    *index = calloc(size, sizeof(index_t));
    for (int i=0; i<size; i++) {
        (*index)[i].index = students[i]->id;
        (*index)[i].offset = i*sizeof(Student);
    }
}

int binary_search(index_t *index, int size, int value) {
    int left = 0;
    int right = size-1;
    while (left <= right) {
        int mid = (left+right)/2;
        if (index[mid].index == value)
            return mid;
        if (index[mid].index < value)
            left = mid+1;
        else
            right = mid-1;
    }
    return -1;
}

Student *find_student_by_id(FILE *data_file, index_t *index, int index_size, int id_to_find) {
    int index_location = binary_search(index, index_size, id_to_find);
    if (index_location == -1)
        return NULL;
    fseek(data_file, index[index_location].offset, SEEK_SET);
    Student *student = malloc(sizeof(Student));
    fread(student, sizeof(Student), 1, data_file);
    return student;
}

void save_student_to_file(FILE *data_file, index_t **index, int *index_size, Student *student) {
    int id = student->id;
    int student_size = sizeof(Student);
    fseek(data_file, 0, SEEK_END);
    fwrite(student, student_size, 1, data_file);
    (*index_size)++;
    *index = realloc(*index, *index_size*sizeof(index_t));
    (*index)[*index_size-1].index = id;
    (*index)[*index_size-1].offset = ftell(data_file)-student_size;
}

void print_student(Student *student) {
    printf("ID: %d\n", student->id);
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
}

int main() {
    FILE *data_file = fopen("students.dat", "w+b");
    if (data_file == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    Student *alice = malloc(sizeof(Student));
    alice->id = 1001;
    strcpy(alice->name, "Alice");
    alice->age = 18;

    Student *bob = malloc(sizeof(Student));
    bob->id = 1002;
    strcpy(bob->name, "Bob");
    bob->age = 20;

    Student *charlie = malloc(sizeof(Student));
    charlie->id = 1003;
    strcpy(charlie->name, "Charlie");
    charlie->age = 22;

    index_t *index;
    int index_size = 0;

    save_student_to_file(data_file, &index, &index_size, alice);
    save_student_to_file(data_file, &index, &index_size, bob);
    save_student_to_file(data_file, &index, &index_size, charlie);

    create_index(&alice, &index, index_size);

    Student *found_student = find_student_by_id(data_file, index, index_size, 1002);
    if (found_student != NULL) {
        printf("Found student by id:\n");
        print_student(found_student);
        free(found_student);
    }

    free(alice);
    free(bob);
    free(charlie);
    free(index);
    fclose(data_file);
    return 0;
}