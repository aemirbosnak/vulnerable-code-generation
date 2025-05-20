//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

struct data_t {
    char* name;
    int age;
    float salary;
    struct data_t* next;
};

struct data_t* data = NULL;

void append_data(struct data_t* new_data) {
    new_data->next = data;
    data = new_data;
}

void display_data(struct data_t* data) {
    printf("Name: %s\n", data->name);
    printf("Age: %d\n", data->age);
    printf("Salary: %f\n", data->salary);
}

int main() {
    char* filename = "data.csv";
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ",");
        while (token!= NULL) {
            struct data_t* new_data = (struct data_t*)malloc(sizeof(struct data_t));
            new_data->name = strdup(token);
            token = strtok(NULL, ",");
            new_data->age = atoi(token);
            token = strtok(NULL, ",");
            new_data->salary = strtof(token, NULL);
            append_data(new_data);
        }
    }

    fclose(file);
    display_data(data);

    return 0;
}