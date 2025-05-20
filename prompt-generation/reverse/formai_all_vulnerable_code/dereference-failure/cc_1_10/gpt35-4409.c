//FormAI DATASET v1.0 Category: Data recovery tool ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
    float marks;
} Student;

void recover(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int size, num;
    fread(&size, sizeof(int), 1, fp);
    Student* students = (Student*) malloc(size * sizeof(Student));
    fread(students, sizeof(Student), size, fp);
    fclose(fp);

    fp = fopen("recovered.txt", "w");
    printf("Recovered data:\n");
    printf("----------------\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        fprintf(fp, "%d %s %.2f\n", students[i].id, students[i].name, students[i].marks);
    }
    fclose(fp);

    free(students);
}

void createSampleFile() {
    Student s1 = {1, "John Doe", 85.5};
    Student s2 = {2, "Jane Smith", 93.0};
    Student s3 = {3, "Bob Johnson", 72.5};
    Student s4 = {4, "Alice Williams", 88.0};

    FILE* fp = fopen("sample.bin", "wb");
    int size = 4;
    fwrite(&size, sizeof(int), 1, fp);
    fwrite(&s1, sizeof(Student), 1, fp);
    fwrite(&s2, sizeof(Student), 1, fp);
    fwrite(&s3, sizeof(Student), 1, fp);
    fwrite(&s4, sizeof(Student), 1, fp);
    fclose(fp);
}

int main() {
    createSampleFile();
    recover("sample.bin");
    return 0;
}