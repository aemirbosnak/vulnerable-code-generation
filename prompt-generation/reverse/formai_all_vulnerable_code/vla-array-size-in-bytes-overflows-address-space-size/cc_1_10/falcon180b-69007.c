//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_LENGTH 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char virus_name[MAX_VIRUS_LENGTH];
    int virus_length;
} Virus;

void load_viruses(Virus viruses[], int num_viruses) {
    int i;
    for (i = 0; i < num_viruses; i++) {
        printf("Enter virus name: ");
        scanf("%s", viruses[i].virus_name);
        printf("Enter virus length: ");
        scanf("%d", &viruses[i].virus_length);
    }
}

int scan_file(FILE *file, Virus viruses[], int num_viruses) {
    char buffer[MAX_FILE_SIZE];
    int buffer_length = fread(buffer, 1, MAX_FILE_SIZE, file);
    int i;
    for (i = 0; i < num_viruses; i++) {
        int virus_length = viruses[i].virus_length;
        int j;
        for (j = 0; j < buffer_length - virus_length + 1; j++) {
            int match = 1;
            int k;
            for (k = 0; k < virus_length; k++) {
                if (buffer[j+k]!= viruses[i].virus_name[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("Virus found: %s\n", viruses[i].virus_name);
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int num_viruses;
    printf("Enter number of viruses: ");
    scanf("%d", &num_viruses);
    Virus viruses[num_viruses];
    load_viruses(viruses, num_viruses);
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    int result = scan_file(file, viruses, num_viruses);
    fclose(file);
    return result;
}