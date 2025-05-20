//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_SIZE);
    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        printf("Error reading line\n");
        exit(1);
    }
    return line;
}

char *trim_whitespace(char *str) {
    char *end;
    while (isspace(*str)) {
        str++;
    }
    if (*str == 0) {
        return "";
    }
    end = str + strlen(str) - 1;
    while (isspace(*end)) {
        end--;
    }
    *(end + 1) = 0;
    return str;
}

Person *parse_person(char *line) {
    Person *person = malloc(sizeof(Person));
    char *name = trim_whitespace(line);
    person->name = strdup(name);
    line = strchr(line, ',') + 1;
    line = trim_whitespace(line);
    person->age = atoi(line);
    line = strchr(line, ',') + 1;
    line = trim_whitespace(line);
    person->email = strdup(line);
    return person;
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Email: %s\n", person->email);
}

void free_person(Person *person) {
    free(person->name);
    free(person->email);
    free(person);
}

void read_csv_file(FILE *file, void (*callback)(Person *)) {
    char *line;
    while ((line = read_line(file))!= NULL) {
        Person *person = parse_person(line);
        callback(person);
        free_person(person);
    }
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    read_csv_file(file, print_person);
    fclose(file);
    return 0;
}