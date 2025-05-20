//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 100
#define NUM_LINES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

int main() {
    FILE *file;
    Person people[NUM_LINES];
    int num_people = 0;
    char line[MAX_LINE_LENGTH];
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];

    file = fopen("data.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, " ");
        if (token != NULL) {
            strcpy(name1, token);
            token = strtok(NULL, " ");
            sscanf(token, "%d", &people[num_people].age);
            token = strtok(NULL, " ");
            strcpy(name2, token);
            num_people++;
        }
    }

    fclose(file);

    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            int love_at_first_sight = strcmp(name1, name2) > 0 ? j : i;
            if (people[i].age < 18 || people[j].age < 18) continue;
            if (people[i].age + people[j].age > 80) continue;

            printf("A new pair found!\n");
            printf("Romeo: %s, %d years old\n", name1, people[i].age);
            printf("Juliet: %s, %d years old\n", name2, people[j].age);
            break;
        }
    }

    return 0;
}