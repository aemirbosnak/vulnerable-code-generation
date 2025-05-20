//FormAI DATASET v1.0 Category: Data recovery tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
} Person;

char* retrieve_data(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    
    char* data = malloc(100);
    fread(data, sizeof(char), 100, fp);
    
    fclose(fp);
    return data;
}

void recover_data(char* filename, Person* p) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    
    fread(p, sizeof(Person), 1, fp);
    
    fclose(fp);
}

int main() {
    char* data = retrieve_data("data.bin");
    
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == '\0') {
            data[i] = ' ';
        }
    }
    
    Person* p = malloc(sizeof(Person));
    recover_data("person.bin", p);
    
    printf("Recovered data from data.bin: %s\n", data);
    printf("Recovered person from person.bin: Name - %s, Age - %d\n", p->name, p->age);
    
    return 0;
}