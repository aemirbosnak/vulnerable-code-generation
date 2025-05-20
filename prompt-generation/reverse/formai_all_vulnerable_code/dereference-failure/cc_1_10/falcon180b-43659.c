//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
} person_t;

int main() {
    person_t people[MAX_SIZE];
    int num_people = 0;

    // Read in data from a file
    FILE *fp = fopen("people.txt", "r");
    if (fp == NULL) {
        printf("Error reading file\n");
        exit(1);
    }

    char line[MAX_SIZE];
    while (fgets(line, MAX_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        strcpy(people[num_people].name, token);
        token = strtok(NULL, ",");
        people[num_people].age = atoi(token);
        num_people++;
    }

    // Sort the data by age
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[i].age > people[j].age) {
                person_t temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // Search for a person by name
    char search_name[MAX_SIZE];
    printf("Enter a name to search for: ");
    scanf("%s", search_name);

    int result = binary_search(people, num_people, search_name);

    if (result == -1) {
        printf("Name not found\n");
    } else {
        printf("Found %s, age %d\n", people[result].name, people[result].age);
    }

    return 0;
}

int binary_search(person_t arr[], int n, char search_name[]) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (strcmp(arr[mid].name, search_name) == 0) {
            return mid;
        } else if (strcmp(arr[mid].name, search_name) > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}