//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_LEN 50
#define MAX_RECORDS 1000

typedef struct {
    int id;
    char name[MAX_FIELD_LEN];
    int age;
    float salary;
} Record;

Record records[MAX_RECORDS];

int num_records = 0;

void read_csv(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    
    char buffer[MAX_FIELD_LEN * 4];
    fgets(buffer, MAX_FIELD_LEN * 4, fp); // skip header row
    
    while (fgets(buffer, MAX_FIELD_LEN * 4, fp)) {
        char* tok = strtok(buffer, ",");
        int id = atoi(tok);
        
        tok = strtok(NULL, ",");
        char name[MAX_FIELD_LEN];
        strcpy(name, tok);
        
        tok = strtok(NULL, ",");
        int age = atoi(tok);
        
        tok = strtok(NULL, ",");
        float salary = atof(tok);
        
        Record r = { id, name, age, salary };
        records[num_records++] = r;
    }
    
    fclose(fp);
}

void print_records() {
    printf("ID\tName\tAge\tSalary\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%d\t%.2f\n", 
            records[i].id, records[i].name, 
            records[i].age, records[i].salary);
    }
}

int main() {
    read_csv("employees.csv");
    print_records();
    return 0;
}