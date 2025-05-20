//Gemma-7B DATASET v1.0 Category: Antivirus scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

typedef struct Virus {
    char name[256];
    char description[256];
    int severity;
    struct Virus *next;
} Virus;

Virus *scan_virus(FILE *file) {
    Virus *head = NULL;
    char buffer[MAX_BUFFER];
    char *line;

    while (fgets(buffer, MAX_BUFFER, file) != NULL) {
        line = strtok(buffer, ",");
        while (line) {
            Virus *virus = malloc(sizeof(Virus));
            strcpy(virus->name, line);
            line = strtok(NULL, ",");
            strcpy(virus->description, line);
            line = strtok(NULL, ",");
            virus->severity = atoi(line);
            virus->next = head;
            head = virus;
        }
    }

    return head;
}

int main() {
    FILE *file = fopen("virus.txt", "r");
    Virus *viruses = scan_virus(file);

    for (Virus *virus = viruses; virus; virus = virus->next) {
        printf("Name: %s\n", virus->name);
        printf("Description: %s\n", virus->description);
        printf("Severity: %d\n", virus->severity);
        printf("\n");
    }

    fclose(file);

    return 0;
}