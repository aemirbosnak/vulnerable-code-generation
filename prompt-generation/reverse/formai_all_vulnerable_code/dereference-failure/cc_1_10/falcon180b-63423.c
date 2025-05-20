//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_FIELDS 100

typedef struct {
    char* name;
    char* value;
} field_t;

typedef struct {
    int num_fields;
    field_t* fields;
} record_t;

record_t* create_record() {
    record_t* r = (record_t*)malloc(sizeof(record_t));
    r->num_fields = 0;
    r->fields = NULL;
    return r;
}

void add_field(record_t* r, char* name, char* value) {
    field_t* f = (field_t*)malloc(sizeof(field_t));
    f->name = strdup(name);
    f->value = strdup(value);
    r->fields = (field_t*)realloc(r->fields, sizeof(field_t)*(r->num_fields+1));
    r->fields[r->num_fields] = *f;
    r->num_fields++;
}

void free_record(record_t* r) {
    for (int i = 0; i < r->num_fields; i++) {
        free(r->fields[i].name);
        free(r->fields[i].value);
    }
    free(r->fields);
    free(r);
}

record_t* parse_line(char* line) {
    record_t* r = create_record();
    char* token = strtok(line, ",");
    while (token!= NULL) {
        char* name = strtok(token, ":");
        char* value = strtok(NULL, ":");
        if (name!= NULL && value!= NULL) {
            add_field(r, name, value);
        }
        token = strtok(NULL, ",");
    }
    return r;
}

void print_record(record_t* r) {
    for (int i = 0; i < r->num_fields; i++) {
        printf("%s: %s\n", r->fields[i].name, r->fields[i].value);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    record_t* r = NULL;

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (r!= NULL) {
            free_record(r);
        }
        r = parse_line(line);
        print_record(r);
    }

    if (r!= NULL) {
        free_record(r);
    }

    return 0;
}