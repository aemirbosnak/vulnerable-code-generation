//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int size;
    unsigned char *data;
} virus_t;

int main(int argc, char **argv) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    virus_t *viruses = NULL;
    int num_viruses = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    while ((read = getline(&line, &len, fp))!= -1) {
        if (read == 0)
            break;

        char *p = line;
        while (*p) {
            if (isalpha(*p)) {
                virus_t *v = malloc(sizeof(virus_t));
                v->name = strdup(line);
                v->size = strlen(line);
                v->data = malloc(v->size);
                memcpy(v->data, line, v->size);
                viruses = realloc(viruses, sizeof(virus_t) * ++num_viruses);
                viruses[num_viruses - 1] = *v;
                free(v);
            }
            p++;
        }
    }

    fclose(fp);

    for (int i = 0; i < num_viruses; i++) {
        printf("Found virus: %s (%d bytes)\n", viruses[i].name, viruses[i].size);
    }

    return 0;
}