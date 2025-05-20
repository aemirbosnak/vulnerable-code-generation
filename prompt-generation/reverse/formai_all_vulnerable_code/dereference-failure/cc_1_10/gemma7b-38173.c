//Gemma-7B DATASET v1.0 Category: Antivirus scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Virus {
    char name[50];
    char description[100];
    int damage;
    int detection;
    struct Virus *next;
} Virus;

Virus *virus_head = NULL;

void scan_virus() {
    virus_head = NULL;

    FILE *fp = fopen("virus.txt", "r");
    if (fp == NULL) {
        return;
    }

    char line[1024];
    while (fgets(line, 1024, fp) != NULL) {
        Virus *new_virus = malloc(sizeof(Virus));
        strcpy(new_virus->name, line);
        new_virus->damage = rand() % 10;
        new_virus->detection = rand() % 3;
        new_virus->next = virus_head;
        virus_head = new_virus;
    }

    fclose(fp);
}

int main() {
    scan_virus();

    Virus *current_virus = virus_head;
    while (current_virus) {
        printf("Name: %s\n", current_virus->name);
        printf("Description: %s\n", current_virus->description);
        printf("Damage: %d\n", current_virus->damage);
        printf("Detection: %d\n", current_virus->detection);
        printf("\n");
        current_virus = current_virus->next;
    }

    return 0;
}