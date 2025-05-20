//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELD_NUM 10
#define MAX_FIELD_LEN 1024

struct field {
    char name[MAX_FIELD_LEN];
    char value[MAX_FIELD_LEN];
};

struct resume {
    int field_num;
    struct field fields[MAX_FIELD_NUM];
};

void init_resume(struct resume *r) {
    r->field_num = 0;
}

void add_field(struct resume *r, char *name, char *value) {
    if (r->field_num >= MAX_FIELD_NUM) {
        printf("Error: Too many fields in resume.\n");
        exit(1);
    }

    strncpy(r->fields[r->field_num].name, name, MAX_FIELD_LEN);
    strncpy(r->fields[r->field_num].value, value, MAX_FIELD_LEN);

    r->field_num++;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LEN];
    char *name, *value;
    struct resume r;

    init_resume(&r);

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open resume file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        name = strtok(line, ":");
        value = strtok(NULL, ":");

        if (name == NULL || value == NULL) {
            printf("Error: Invalid line in resume file.\n");
            exit(1);
        }

        add_field(&r, name, value);
    }

    fclose(fp);

    // Print the parsed resume
    printf("Name: %s\n", r.fields[0].value);
    printf("Email: %s\n", r.fields[1].value);
    printf("Phone: %s\n", r.fields[2].value);
    printf("Address: %s\n", r.fields[3].value);
    printf("Education: %s\n", r.fields[4].value);
    printf("Experience: %s\n", r.fields[5].value);

    // Save the parsed resume to a new file
    fp = fopen("parsed_resume.txt", "w");
    if (fp == NULL) {
        printf("Error: Cannot create parsed resume file.\n");
        exit(1);
    }

    fprintf(fp, "Name: %s\n", r.fields[0].value);
    fprintf(fp, "Email: %s\n", r.fields[1].value);
    fprintf(fp, "Phone: %s\n", r.fields[2].value);
    fprintf(fp, "Address: %s\n", r.fields[3].value);
    fprintf(fp, "Education: %s\n", r.fields[4].value);
    fprintf(fp, "Experience: %s\n", r.fields[5].value);

    fclose(fp);

    return 0;
}