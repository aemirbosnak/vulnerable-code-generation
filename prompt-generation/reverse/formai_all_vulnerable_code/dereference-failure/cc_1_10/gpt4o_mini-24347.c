//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_GENOMES 10
#define BASES "ACGT"

typedef struct {
    char name[50];
    char sequence[MAX_SEQUENCE_LENGTH];
} Genome;

Genome genomes[MAX_GENOMES];
int genome_count = 0;

void generate_random_sequence(char* sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = BASES[rand() % 4];
    }
    sequence[length] = '\0';
}

void add_genome() {
    if (genome_count >= MAX_GENOMES) {
        printf("Maximum genome limit reached.\n");
        return;
    }
    
    printf("Enter genome name: ");
    scanf("%s", genomes[genome_count].name);
    
    int length;
    printf("Enter genome sequence length (max %d): ", MAX_SEQUENCE_LENGTH);
    scanf("%d", &length);
    
    if (length > MAX_SEQUENCE_LENGTH) {
        printf("Length exceeds maximum allowed. Setting to maximum length.\n");
        length = MAX_SEQUENCE_LENGTH;
    }
    
    generate_random_sequence(genomes[genome_count].sequence, length);
    genome_count++;
    printf("Genome %s added with sequence: %s\n", genomes[genome_count - 1].name, genomes[genome_count - 1].sequence);
}

void display_genomes() {
    if (genome_count == 0) {
        printf("No genomes to display.\n");
        return;
    }
    
    printf("\nList of Genomes:\n");
    for (int i = 0; i < genome_count; i++) {
        printf("Genome %d: %s, Sequence: %s\n", i + 1, genomes[i].name, genomes[i].sequence);
    }
}

void save_genomes_to_file(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < genome_count; i++) {
        fprintf(file, ">%s\n%s\n", genomes[i].name, genomes[i].sequence);
    }
    
    fclose(file);
    printf("Genomes saved to %s.\n", filename);
}

void load_genomes_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    
    while (genome_count < MAX_GENOMES && !feof(file)) {
        fscanf(file, ">%[^\n]\n", genomes[genome_count].name);
        fscanf(file, "%[^\n]\n", genomes[genome_count].sequence);
        genome_count++;
    }
    
    fclose(file);
    printf("Loaded %d genomes from %s.\n", genome_count, filename);
}

void clear_genomes() {
    genome_count = 0;
    printf("All genomes cleared.\n");
}

void display_menu() {
    printf("\n=== Genome Sequencing Simulator ===\n");
    printf("1. Add Genome\n");
    printf("2. Display Genomes\n");
    printf("3. Save Genomes to File\n");
    printf("4. Load Genomes from File\n");
    printf("5. Clear All Genomes\n");
    printf("6. Exit\n");
}

int main() {
    srand(time(NULL));
    int choice;
    char filename[100];

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_genome();
                break;
            case 2:
                display_genomes();
                break;
            case 3:
                printf("Enter filename to save to: ");
                scanf("%s", filename);
                save_genomes_to_file(filename);
                break;
            case 4:
                printf("Enter filename to load from: ");
                scanf("%s", filename);
                load_genomes_from_file(filename);
                break;
            case 5:
                clear_genomes();
                break;
            case 6:
                printf("Exiting the simulator. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}