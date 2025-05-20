//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    int age;
    char *city;
} Person;

void read_csv_file(FILE *file, Person **data, int *count) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }
        Person *person = malloc(sizeof(Person));
        person->name = strdup(token);
        token = strtok(NULL, ",");
        person->age = atoi(token);
        token = strtok(NULL, ",");
        person->city = strdup(token);
        *data = realloc(*data, sizeof(Person) * (*count + 1));
        (*data)[*count] = *person;
        (*count)++;
    }
}

void print_data(Person *data, int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s\nAge: %d\nCity: %s\n", data[i].name, data[i].age, data[i].city);
    }
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    Person *data = NULL;
    int count = 0;
    read_csv_file(file, &data, &count);
    printf("Data:\n");
    print_data(data, count);
    free(data);
    fclose(file);
    return 0;
}