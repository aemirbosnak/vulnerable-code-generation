//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int value;
} KeyValue;

KeyValue *parse_keyvalue(char *line) {
    KeyValue *kv = malloc(sizeof(KeyValue));
    char *name_start = line;
    int name_len = 0;

    while (*line != ':' && *line != '\0') {
        if (*line == ' ') {
            name_len = line - name_start;
            name_start[name_len] = '\0';
            break;
        }
        line++;
    }

    if (*line == ':') {
        line++;
        kv->value = atoi(line);
        return kv;
    }

    free(kv);
    return NULL;
}

void parse_resume(FILE *fp) {
    char line[1024];
    KeyValue *kv;
    int name_len;

    while (fgets(line, sizeof(line), fp) != NULL) {
        kv = parse_keyvalue(line);
        if (kv) {
            printf("%s: %d\n", kv->name, kv->value);
            free(kv->name);
            free(kv);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    parse_resume(fp);
    fclose(fp);
    return 0;
}