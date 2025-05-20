//FormAI DATASET v1.0 Category: Computer Biology ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUFFER_SIZE 1024

struct Gene {
    char name[50];
    char id[10];
    int length;
    char sequence[MAX_BUFFER_SIZE];
};

struct Genome {
    char name[50];
    char description[500];
    int num_genes;
    struct Gene *genes;
};

void create_genome(struct Genome *genome, char *name, char *description) {
    strcpy(genome->name, name);
    strcpy(genome->description, description);
    genome->num_genes = 0;
    genome->genes = NULL;
}

void add_gene(struct Genome *genome, char *name, char *id, char *sequence) {
    if(genome->num_genes == 0) {
        genome->genes = (struct Gene*) malloc(sizeof(struct Gene));
    } else {
        genome->genes = (struct Gene*) realloc(genome->genes, (genome->num_genes + 1) * sizeof(struct Gene));
    }
    strcpy(genome->genes[genome->num_genes].name, name);
    strcpy(genome->genes[genome->num_genes].id, id);
    genome->genes[genome->num_genes].length = strlen(sequence);
    strcpy(genome->genes[genome->num_genes].sequence, sequence);

    genome->num_genes++;
}

void print_gene(struct Gene gene) {
    printf("Gene name: %s\nID: %s\nLength: %d\nSequence: %s\n\n", gene.name, gene.id, gene.length, gene.sequence);
}

void print_genome(struct Genome genome) {
    printf("Genome name: %s\nDescription: %s\nNumber of genes: %d\n", genome.name, genome.description, genome.num_genes);
    for(int i=0; i<genome.num_genes; i++) {
        printf("\nGene #%d:\n", i+1);
        print_gene(genome.genes[i]);
    }
}

int main() {
    struct Genome human_genome;

    create_genome(&human_genome, "Human Genome", "The complete set of human genes");

    add_gene(&human_genome, "CRLF2", "ENSG00000198626", "gtcagctgctagtctaatactgatgatgtgatgatgatgactgcatctgccctccgggtcattcatgatcaatcgatcgggacttagattctccgactgggtatatactgtcacctcctcaatatggacgtagtgagaaaattgggctgtacaaactctctaaaattaaaagcctcaattctagtgaccggacgcagtagccatggtataggaactcttctcatgttctgtgctgaacaggactgggaatggtggtggtgtcacttgcggagccgcggccgccctgctgccttggagagccatccctcgggctggtagcacccccattgcactttgtctgggacccgcaggcaggctgcctgccccaggccagtgtgtgaaacggtgggcctgcgtcacacattgattatgggccaaaatttagaaggcctcacggctagcccctagaccacttttttttttttttttttttttgctgttggtgatcaatgggtactcccagggttgggagtgtatggactagcacacaggtaaggacagttgggtgggcgtgctgactttgctggggtggggcatctgaatgacggcagcaaagcactataatgctcagcaggtgtctgggagaaacccatgaacaaaatttgtagggtgaagtgattgagg");
    add_gene(&human_genome, "BRCA2", "ENSG00000139618", "gccaggcagtgaaattttgtctgggtttgtgtaagctgggtcagcctcattggcgggggaggcccttggggagagtgggagtggagattgctggaatgccccagcaacagtagccactggagacagtactccagaagtgagtatgcacagaactgggagtgggtctttctttctttcaaactttaggaaaatgaggcctttgaggagagctgatgacctggtgctcctggacctgggctgaaatggcaccgtgacctggatcagaagaaagtctgcattcccctcccagcagtctccatcctcccgaagccccagtgattgtagttgtgatgtgtaggctggcactgcccgtgacaggagccaaggcctccccgactggtggacagaagccaagtctctgctgaccttctacttcacttactgaatgtttggtgttcataactaatacactacttacccagcctggtcctctcatgtctggtctttcagggtgcagtctggattctgagggttcatgactggagaagtttgtgttttcctcttcattttgctgggccgtctgaatagctctgggaccccacaagtacatggctgggccagataaaggcgagcaggtacggtgggaggatcacactcaggcctccagggcctccagttcgggagggggaataggcgacttcaagtgggagggaggccacaccatggagatctggctggaacacaggtggcccagtctag");
    add_gene(&human_genome, "TP53", "ENSG00000141510", "gcccgggcgcggggaggcggggactgggcctcaaagtgacttccagaagatgatgacccagatggctgcggggacagcggctcaagaccccattctctaaaaagggagggttttgcaagctctacctcccagggcctgggcaacaaggtactccccctcaggaatttattcccgcctttccgggccaggctggagctatgcctggtaatctttcccattctcactttgatcctcctcctcggctgctctctctctccaggctgggcactgtgccccccacaagttctcctgcctccccacccccgagtccccactggctaagtctccctgcctccttctcctgtcccaactccacacccagggcctctccccggcccagcatctcccctccccaggtctccccactcccggccccagctcccagcttggacctggagtgcaagggcaaggcccctgcctcccggatttctgcaacaggcccgccccctgcccaggtgcccggacggccagggtggctggggccatcaccctgctccccctcttctggattcttaggctcgggcacctggaaggactcctgcctcccaagactgctatcttctctgtccccccacctcccatcttcccaggaacgacatgacctgtggctttgggaga");
    
    print_genome(human_genome);

    return 0;
}