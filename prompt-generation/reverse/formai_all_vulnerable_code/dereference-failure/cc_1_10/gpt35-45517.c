//FormAI DATASET v1.0 Category: Data recovery tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    float height;
} Person;

void write_to_file(Person arr[], int size) {
    FILE *fp = fopen("data.bin", "wb");
    if(fp == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    fwrite(arr, sizeof(Person), size, fp);
    fclose(fp);
}

Person* read_from_file(int *size) {
    FILE *fp = fopen("data.bin", "rb");
    if(fp == NULL) {
        printf("Failed to open file.\n");
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    rewind(fp);
    Person *arr = malloc(fsize);
    fread(arr, sizeof(Person), fsize/sizeof(Person), fp);
    fclose(fp);
    *size = fsize/sizeof(Person);
    return arr;
}

void print_person(Person p) {
    printf("Name: %s\nAge: %d\nHeight: %f\n", p.name, p.age, p.height);
}

int main() {
    Person people[3] = {
        {"Alice", 20, 1.6},
        {"Bob", 30, 1.8},
        {"Charlie", 40, 1.9}
    };
    write_to_file(people, 3);
    int size;
    Person *loaded_people = read_from_file(&size);
    for(int i = 0; i < size; i++) {
        print_person(loaded_people[i]);
    }
    free(loaded_people);
    return 0;
}