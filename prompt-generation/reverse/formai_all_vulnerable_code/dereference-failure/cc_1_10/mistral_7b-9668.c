//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FIELDS 10
#define MAX_LINE_LEN 256
#define MAX_FIELD_LEN 50

typedef struct {
    char name[MAX_FIELD_LEN];
    int age;
    float height;
} Person;

void skip_line(FILE *fp) {
    char line[MAX_LINE_LEN];
    fgets(line, MAX_LINE_LEN, fp);
    while (fgetc(fp) != '\n') {}
}

int parse_csv_line(FILE *fp, Person *person) {
    char line[MAX_LINE_LEN];
    char *token[MAX_FIELDS];
    int num_fields;

    fgets(line, MAX_LINE_LEN, fp);

    num_fields = 0;
    token[num_fields++] = strtok(line, ",");

    strcpy(person->name, token[0]);

    token[num_fields++] = strtok(NULL, ",");
    person->age = atoi(token[num_fields - 1]);

    token[num_fields++] = strtok(NULL, ",");
    person->height = atof(token[num_fields - 1]);

    if (num_fields < 3) return 0;

    return 1;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    Person people[MAX_FIELDS];
    int i = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    while (parse_csv_line(fp, &people[i++])) {}

    for (int j = 0; j < i; j++) {
        printf("%s (%d years old, %.2f meters tall)\n", people[j].name, people[j].age, people[j].height);
    }

    fclose(fp);
    return 0;
}