//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000
#define MAX_LINE_SIZE 80

typedef struct {
    char name[MAX_SIZE];
    int age;
    char address[MAX_SIZE];
} Person;

void read_data_from_file(Person *people, FILE *file) {
    char line[MAX_LINE_SIZE];
    int count = 0;

    while(fgets(line, MAX_LINE_SIZE, file)) {
        if(count >= MAX_SIZE) {
            printf("Error: Maximum number of records reached.\n");
            exit(1);
        }

        strcpy(people[count].name, line);
        people[count].age = atoi(strtok(line, " "));
        strcpy(people[count].address, strtok(NULL, " "));

        count++;
    }
}

void write_data_to_file(Person *people, FILE *file) {
    int count = 0;

    while(count < MAX_SIZE && people[count].name[0]!= '\0') {
        fprintf(file, "%s %d %s\n", people[count].name, people[count].age, people[count].address);
        count++;
    }
}

void search_data(Person *people, char *query) {
    int count = 0;

    while(count < MAX_SIZE && people[count].name[0]!= '\0') {
        if(strstr(people[count].name, query)!= NULL) {
            printf("%s %d %s\n", people[count].name, people[count].age, people[count].address);
        }
        count++;
    }
}

int main() {
    FILE *file;
    Person people[MAX_SIZE];
    char query[MAX_LINE_SIZE];

    file = fopen("database.txt", "r+");

    if(file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    read_data_from_file(people, file);

    printf("Enter search query: ");
    scanf("%s", query);

    search_data(people, query);

    fclose(file);

    return 0;
}