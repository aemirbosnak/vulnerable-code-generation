//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

struct record {
    char name[MAX_STR_LEN];
    int age;
    char gender;
};

struct record *read_records(FILE *fp, int *num_records) {
    struct record *records = malloc(sizeof(struct record) * *num_records);
    char line[MAX_STR_LEN];
    int i = 0;
    while (fgets(line, MAX_STR_LEN, fp) != NULL && i < *num_records) {
        sscanf(line, "%s %d %c", records[i].name, &records[i].age, &records[i].gender);
        i++;
    }
    *num_records = i;
    return records;
}

void print_records(struct record *records, int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("%s %d %c\n", records[i].name, records[i].age, records[i].gender);
    }
}

void sort_records(struct record *records, int num_records) {
    for (int i = 0; i < num_records; i++) {
        for (int j = i + 1; j < num_records; j++) {
            if (records[i].age > records[j].age) {
                struct record temp = records[i];
                records[i] = records[j];
                records[j] = temp;
            }
        }
    }
}

int main() {
    FILE *fp = fopen("data.txt", "r");
    int num_records = 0;
    struct record *records = read_records(fp, &num_records);
    fclose(fp);
    print_records(records, num_records);
    sort_records(records, num_records);
    print_records(records, num_records);
    return 0;
}