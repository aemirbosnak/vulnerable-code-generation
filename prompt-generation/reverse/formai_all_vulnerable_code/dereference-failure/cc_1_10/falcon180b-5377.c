//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_NUM_FIELDS 10
#define MAX_ERROR_LEN 256

typedef struct {
    char *name;
    int value;
} field_t;

typedef struct {
    field_t *fields;
    int num_fields;
} form_t;

void read_form(form_t *form)
{
    char line[MAX_LINE_LEN];
    char *token;
    char *value;
    int i = 0;

    while (fgets(line, MAX_LINE_LEN, stdin)!= NULL) {
        if (i >= MAX_NUM_FIELDS) {
            fprintf(stderr, "Error: Too many fields in form.\n");
            exit(1);
        }
        token = strtok(line, ":");
        if (token == NULL) {
            fprintf(stderr, "Error: Invalid field format.\n");
            exit(1);
        }
        value = strtok(NULL, ":");
        if (value == NULL) {
            fprintf(stderr, "Error: Invalid field format.\n");
            exit(1);
        }
        form->fields[i].name = strdup(token);
        form->fields[i].value = atoi(value);
        i++;
    }
    form->num_fields = i;
}

int main()
{
    form_t form;
    char error_msg[MAX_ERROR_LEN];
    int result;

    form.fields = malloc(MAX_NUM_FIELDS * sizeof(field_t));
    if (form.fields == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        exit(1);
    }
    form.num_fields = 0;

    read_form(&form);

    if (form.num_fields < 3) {
        fprintf(stderr, "Error: Invalid form.\n");
        exit(1);
    }

    if (form.fields[0].value <= 0 || form.fields[1].value <= 0) {
        fprintf(stderr, "Error: Invalid input values.\n");
        exit(1);
    }

    result = form.fields[0].value * form.fields[1].value;
    sprintf(error_msg, "Result: %d", result);

    printf("%s\n", error_msg);

    return 0;
}