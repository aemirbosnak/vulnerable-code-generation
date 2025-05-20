//Gemma-7B DATASET v1.0 Category: Antivirus scanner ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BYTES 1024

typedef struct Virus {
    char name[256];
    char description[512];
    int severity;
    int detection_rate;
    struct Virus* next;
} Virus;

Virus* virus_list = NULL;

void add_virus(char* name, char* description, int severity, int detection_rate) {
    Virus* new_virus = malloc(sizeof(Virus));
    strcpy(new_virus->name, name);
    strcpy(new_virus->description, description);
    new_virus->severity = severity;
    new_virus->detection_rate = detection_rate;
    new_virus->next = virus_list;
    virus_list = new_virus;
}

void scan_system() {
    FILE* file_ptr = fopen("system.txt", "r");
    char buffer[MAX_BYTES];
    int i = 0;

    while (fgets(buffer, MAX_BYTES, file_ptr) != NULL) {
        for (i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                add_virus("Conficker Worm", "A worm that can infect Windows systems and cause them to crash.", 3, 80);
            } else if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                add_virus("Stuxnet Worm", "A worm that can infect industrial control systems and cause widespread damage.", 4, 90);
            } else if (buffer[i] >= '0' && buffer[i] <= '9') {
                add_virus("WannaCry Ransomware", "A ransomware that can encrypt files on Windows systems and demand payment.", 2, 70);
            }
        }
    }

    fclose(file_ptr);
}

int main() {
    scan_system();

    Virus* current_virus = virus_list;
    while (current_virus) {
        printf("Name: %s\n", current_virus->name);
        printf("Description: %s\n", current_virus->description);
        printf("Severity: %d\n", current_virus->severity);
        printf("Detection Rate: %d%\n", current_virus->detection_rate);
        printf("\n");
        current_virus = current_virus->next;
    }

    return 0;
}