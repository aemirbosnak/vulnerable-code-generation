//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char symbol[3];
    int atomic_number;
    char name[50];
    char group;
    char period;
} Element;

void read_file(const char *filename, Element elements[], int size);
void print_table(Element elements[], int size);

int main(int argc, char *argv[]) {
    const char *filename = "periodic_table.txt";
    int size = 118; // Number of elements in the periodic table
    Element elements[size];

    if (argc > 1 && strlen(argv[1]) > 0) {
        filename = argv[1];
    }

    read_file(filename, elements, size);
    print_table(elements, size);

    return 0;
}

void read_file(const char *filename, Element elements[], int size) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        exit(1);
    }

    int i = 0;
    char line[1024];

    while (fgets(line, sizeof(line), file) != NULL) {
        if (i >= size) {
            fprintf(stderr, "Error: Size of array is too small\n");
            exit(1);
        }

        sscanf(line, "%2s%d%[^%d%n]%d%s%s%c",
               elements[i].symbol, &elements[i].atomic_number,
               elements[i].name, &elements[i].group, &elements[i].period, NULL);

        i++;
    }

    fclose(file);
}

void print_table(Element elements[], int size) {
    printf(" %-2s | %-10s | %-15s | %-5s | %-5s | %-10s\n", "", "Symbol", "Name", "Group", "Period", "Block");
    printf("-------------------------------------------------------------------------------------------------------");

    for (int i = 0; i < size; i++) {
        printf("\n%2d | %-10s | %-15s | %-5s | %-5s | %-10s",
               i + 1, elements[i].symbol, elements[i].name,
               elements[i].group, elements[i].period,
               (elements[i].group == 'N' || elements[i].period > 6) ? "Noble Gas" : "Non-metal/Metal");
    }
}