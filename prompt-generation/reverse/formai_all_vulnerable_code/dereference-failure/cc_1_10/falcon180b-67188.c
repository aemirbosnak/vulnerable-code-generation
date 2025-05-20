//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char *name;
    int age;
} person_t;

int compare(const void *a, const void *b) {
    person_t *p1 = (person_t *)a;
    person_t *p2 = (person_t *)b;

    return strcmp(p1->name, p2->name);
}

int main() {
    FILE *fp;
    person_t *people = NULL;
    int num_people = 0;
    char line[256];

    fp = fopen("people.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        person_t *p = malloc(sizeof(person_t));

        p->name = strdup(line);
        sscanf(line, "%s %d", p->name, &p->age);

        people = realloc(people, sizeof(person_t) * ++num_people);
        people[num_people - 1] = *p;
        free(p);
    }

    fclose(fp);

    qsort(people, num_people, sizeof(person_t), compare);

    for (int i = 0; i < num_people; i++) {
        printf("%s %d\n", people[i].name, people[i].age);
    }

    free(people);

    return 0;
}