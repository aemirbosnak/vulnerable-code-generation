//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME 256
#define MAX_LINE_LENGTH 1024
#define MAX_VIRUS_NAMES 100
#define MAX_VIRUS_LENGTH 100

typedef struct {
    char name[MAX_VIRUS_LENGTH];
    int length;
} virus;

virus viruses[MAX_VIRUS_NAMES];
int num_viruses;

void load_viruses() {
    FILE *f = fopen("viruses.txt", "r");
    char line[MAX_LINE_LENGTH];
    char *token;

    while (fgets(line, MAX_LINE_LENGTH, f)!= NULL) {
        num_viruses++;
        viruses[num_viruses - 1].length = strlen(line);
        strcpy(viruses[num_viruses - 1].name, line);
    }

    fclose(f);
}

int is_virus(char *filename) {
    int i;
    FILE *f = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    char *token;

    while (fgets(line, MAX_LINE_LENGTH, f)!= NULL) {
        for (i = 0; i < num_viruses; i++) {
            if (strstr(line, viruses[i].name)!= NULL) {
                fclose(f);
                return 1;
            }
        }
    }

    fclose(f);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    load_viruses();

    if (is_virus(argv[1])) {
        printf("%s is infected with a virus.\n", argv[1]);
    } else {
        printf("%s is clean.\n", argv[1]);
    }

    return 0;
}