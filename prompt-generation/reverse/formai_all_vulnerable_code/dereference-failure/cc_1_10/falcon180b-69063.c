//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1024
#define MAX_RESUME_LEN 10000

typedef struct {
    char name[MAX_WORD_LEN];
    char value[MAX_WORD_LEN];
} resume_field;

typedef struct {
    int num_fields;
    resume_field fields[MAX_RESUME_LEN];
} resume;

resume* new_resume() {
    resume* r = malloc(sizeof(resume));
    r->num_fields = 0;
    return r;
}

void add_field(resume* r, char* name, char* value) {
    resume_field* f = malloc(sizeof(resume_field));
    strcpy(f->name, name);
    strcpy(f->value, value);
    r->fields[r->num_fields++] = *f;
}

int main() {
    char line[MAX_LINE_LEN];
    char* token;
    char* name;
    char* value;
    resume* r = new_resume();

    while (fgets(line, MAX_LINE_LEN, stdin)!= NULL) {
        token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }
        name = strtok(NULL, ":");
        if (name == NULL) {
            continue;
        }
        value = strtok(NULL, ":");
        if (value == NULL) {
            continue;
        }
        add_field(r, name, value);
    }

    for (int i = 0; i < r->num_fields; i++) {
        printf("%s: %s\n", r->fields[i].name, r->fields[i].value);
    }

    return 0;
}