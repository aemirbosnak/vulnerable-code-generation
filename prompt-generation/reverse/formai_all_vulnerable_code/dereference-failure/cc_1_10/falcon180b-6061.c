//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000
#define MAX_WORD_LEN 50
#define MAX_FIELDS 20

typedef struct {
    char *name;
    char *value;
} Field;

int main() {
    FILE *fp;
    char line[MAX_LINE];
    char *token;
    char *saveptr;
    int fields = 0;
    Field *resume;

    resume = (Field *)malloc(MAX_FIELDS * sizeof(Field));
    if (!resume) {
        printf("Memory error\n");
        return 1;
    }

    fp = fopen("resume.txt", "r");
    if (!fp) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        token = strtok_r(line, ":", &saveptr);
        while (token!= NULL) {
            if (fields >= MAX_FIELDS) {
                printf("Too many fields\n");
                return 1;
            }
            resume[fields].name = strdup(token);
            token = strtok_r(NULL, ":", &saveptr);
            if (token == NULL) {
                printf("Invalid field\n");
                return 1;
            }
            if (strlen(token) > MAX_WORD_LEN) {
                printf("Field too long\n");
                return 1;
            }
            resume[fields].value = strdup(token);
            fields++;
            token = strtok_r(NULL, ":", &saveptr);
        }
    }

    fclose(fp);

    printf("Name: %s\n", resume[0].value);
    printf("Address: %s\n", resume[1].value);
    printf("Phone: %s\n", resume[2].value);
    printf("Email: %s\n", resume[3].value);

    for (int i = 4; i < fields; i++) {
        printf("Field %d: %s\n", i, resume[i].value);
    }

    for (int i = 0; i < fields; i++) {
        free(resume[i].name);
        free(resume[i].value);
    }
    free(resume);

    return 0;
}