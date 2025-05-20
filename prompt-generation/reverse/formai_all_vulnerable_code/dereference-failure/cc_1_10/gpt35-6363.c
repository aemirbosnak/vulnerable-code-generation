//FormAI DATASET v1.0 Category: Database querying ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10000
#define MAX_NAME_LEN 20
#define MAX_ADDRESS_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    int age;
} Person;

int num_records = 0;
Person records[MAX_RECORDS];

void load_database() {
    FILE *fp = fopen("database.txt", "r");
    if (fp != NULL) {
        char line[100];
        while (fgets(line, sizeof(line), fp) != NULL) {
            char *token = strtok(line, ";");
            records[num_records].id = atoi(token);
            token = strtok(NULL, ";");
            strcpy(records[num_records].name, token);
            token = strtok(NULL, ";");
            strcpy(records[num_records].address, token);
            token = strtok(NULL, ";");
            records[num_records].age = atoi(token);
            num_records++;
        }
        fclose(fp);
    }
}

void print_record(Person *p) {
    printf("%d\t%s\t%s\t%d\n", p->id, p->name, p->address, p->age);
}

void print_database() {
    printf("ID\tName\tAddress\tAge\n");
    for (int i = 0; i < num_records; i++) {
        print_record(&records[i]);
    }
}

void query_by_name(char *name) {
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, name) == 0) {
            print_record(&records[i]);
        }
    }
}

void query_by_address(char *address) {
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].address, address) == 0) {
            print_record(&records[i]);
        }
    }
}

void query_by_age(int age) {
    for (int i = 0; i < num_records; i++) {
        if (records[i].age == age) {
            print_record(&records[i]);
        }
    }
}

int main() {
    load_database();
    printf("Loaded %d records from database.\n\n", num_records);
    // print_database();

    printf("Querying database...\n");
    query_by_name("John");
    query_by_address("123 Main St.");
    query_by_age(30);

    return 0;
}