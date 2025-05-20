//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int type;
    int size;
    int offset;
} Variable;

Variable *parse_variable(char *line) {
    Variable *var = malloc(sizeof(Variable));
    int len = strlen(line);
    int i = 0;
    while (i < len && isspace(line[i])) {
        i++;
    }
    var->name = malloc(len - i + 1);
    strncpy(var->name, line + i, len - i);
    var->name[len - i] = '\0';
    while (i < len &&!isspace(line[i])) {
        i++;
    }
    while (i < len && isspace(line[i])) {
        i++;
    }
    if (i < len && line[i] == '*') {
        var->type = 1; // pointer
        i++;
    } else {
        var->type = 0; // not pointer
    }
    while (i < len &&!isspace(line[i])) {
        i++;
    }
    while (i < len && isspace(line[i])) {
        i++;
    }
    var->size = atoi(line + i);
    while (i < len && isspace(line[i])) {
        i++;
    }
    var->offset = atoi(line + i);
    return var;
}

void print_variable(Variable *var) {
    printf("Name: %s\n", var->name);
    printf("Type: %s\n", var->type? "pointer" : "not pointer");
    printf("Size: %d\n", var->size);
    printf("Offset: %d\n", var->offset);
}

int main() {
    FILE *fp;
    char line[1024];
    fp = fopen("metadata.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    while (fgets(line, sizeof(line), fp)!= NULL) {
        Variable *var = parse_variable(line);
        print_variable(var);
    }
    fclose(fp);
    return 0;
}