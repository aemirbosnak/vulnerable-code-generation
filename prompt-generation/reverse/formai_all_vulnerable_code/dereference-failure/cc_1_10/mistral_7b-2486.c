//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Rockstar's CSV Reader v1.0
// Unleash the power of CSV files like never before!

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 512
#define MAX_RECORDS 65536

typedef struct {
    char name[MAX_LINE_LEN];
    int age;
    float salary;
} Record;

void die(const char *msg) {
    fprintf(stderr, "[%s]\n", msg);
    exit(1);
}

void parse_line(char *line, Record *record) {
    char *token = strtok(line, ",");

    strcpy(record->name, token);
    token = strtok(NULL, ",");
    record->age = atoi(token);
    token = strtok(NULL, ",");
    record->salary = atof(token);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    Record records[MAX_RECORDS];
    int i = 0;

    if (argc != 2) {
        die("Usage: csv_reader <file.csv>");
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        die("Could not open file");
    }

    printf("-------------------------\n");
    printf("| Rockstar's CSV Reader |\n");
    printf("-------------------------\n");

    while (fgets(line, MAX_LINE_LEN, fp)) {
        if (i >= MAX_RECORDS) {
            die("Too many records in file");
        }

        parse_line(line, &records[i]);
        printf("| %s | %d | %.2f |\n", records[i].name, records[i].age, records[i].salary);
        i++;
    }

    fclose(fp);
    return 0;
}