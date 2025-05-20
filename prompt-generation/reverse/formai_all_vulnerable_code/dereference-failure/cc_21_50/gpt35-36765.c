//FormAI DATASET v1.0 Category: Computer Biology ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Struct for representing a DNA sequence
typedef struct {
    char* sequence;
    int length;
} DNA;

// Struct for representing an amino acid sequence
typedef struct {
    char* sequence;
    int length;
} AminoAcids;

// Function to convert a DNA sequence to an amino acid sequence
AminoAcids dna_to_aa(DNA* dna_seq) {
    AminoAcids amino_acids;
    amino_acids.length = dna_seq->length / 3;
    amino_acids.sequence = (char*) malloc((amino_acids.length + 1) * sizeof(char));
    amino_acids.sequence[amino_acids.length] = '\0';
    int i, j;
    for (i = 0, j = 0; i < dna_seq->length; i += 3, j++) {
        char* codon = (char*) malloc(4 * sizeof(char));
        codon[3] = '\0';
        strncpy(codon, dna_seq->sequence + i, 3);
        if (strcmp(codon, "ATG") == 0) {
            amino_acids.sequence[j] = 'M';
        } else if (strcmp(codon, "TAA") == 0 || strcmp(codon, "TAG") == 0 || strcmp(codon, "TGA") == 0) {
            amino_acids.sequence[j] = '\0';
            break;
        } else if (strcmp(codon, "TTT") == 0 || strcmp(codon, "TTC") == 0) {
            amino_acids.sequence[j] = 'F';
        } else if (strcmp(codon, "TTA") == 0 || strcmp(codon, "TTG") == 0 || strcmp(codon, "CTT") == 0 || strcmp(codon, "CTC") == 0 || strcmp(codon, "CTA") == 0 || strcmp(codon, "CTG") == 0) {
            amino_acids.sequence[j] = 'L';
        } else if (strcmp(codon, "ATT") == 0 || strcmp(codon, "ATC") == 0 || strcmp(codon, "ATA") == 0) {
            amino_acids.sequence[j] = 'I';
        } else if (strcmp(codon, "GTT") == 0 || strcmp(codon, "GTC") == 0 || strcmp(codon, "GTA") == 0 || strcmp(codon, "GTG") == 0) {
            amino_acids.sequence[j] = 'V';
        } else if (strcmp(codon, "TCT") == 0 || strcmp(codon, "TCC") == 0 || strcmp(codon, "TCA") == 0 || strcmp(codon, "TCG") == 0 || strcmp(codon, "AGT") == 0 || strcmp(codon, "AGC") == 0) {
            amino_acids.sequence[j] = 'S';
        } else if (strcmp(codon, "CCT") == 0 || strcmp(codon, "CCC") == 0 || strcmp(codon, "CCA") == 0 || strcmp(codon, "CCG") == 0) {
            amino_acids.sequence[j] = 'P';
        } else if (strcmp(codon, "ACT") == 0 || strcmp(codon, "ACC") == 0 || strcmp(codon, "ACA") == 0 || strcmp(codon, "ACG") == 0) {
            amino_acids.sequence[j] = 'T';
        } else if (strcmp(codon, "GCT") == 0 || strcmp(codon, "GCC") == 0 || strcmp(codon, "GCA") == 0 || strcmp(codon, "GCG") == 0) {
            amino_acids.sequence[j] = 'A';
        } else if (strcmp(codon, "TAT") == 0 || strcmp(codon, "TAC") == 0) {
            amino_acids.sequence[j] = 'Y';
        } else if (strcmp(codon, "TGG") == 0) {
            amino_acids.sequence[j] = 'W';
        } else if (strcmp(codon, "CAT") == 0 || strcmp(codon, "CAC") == 0) {
            amino_acids.sequence[j] = 'H';
        } else if (strcmp(codon, "CAA") == 0 || strcmp(codon, "CAG") == 0) {
            amino_acids.sequence[j] = 'Q';
        } else if (strcmp(codon, "AAT") == 0 || strcmp(codon, "AAC") == 0) {
            amino_acids.sequence[j] = 'N';
        } else if (strcmp(codon, "AAA") == 0 || strcmp(codon, "AAG") == 0) {
            amino_acids.sequence[j] = 'K';
        } else if (strcmp(codon, "GAT") == 0 || strcmp(codon, "GAC") == 0) {
            amino_acids.sequence[j] = 'D';
        } else if (strcmp(codon, "GAA") == 0 || strcmp(codon, "GAG") == 0) {
            amino_acids.sequence[j] = 'E';
        } else if (strcmp(codon, "TGT") == 0 || strcmp(codon, "TGC") == 0) {
            amino_acids.sequence[j] = 'C';
        } else if (strcmp(codon, "CGT") == 0 || strcmp(codon, "CGC") == 0 || strcmp(codon, "CGA") == 0 || strcmp(codon, "CGG") == 0 || strcmp(codon, "AGA") == 0 || strcmp(codon, "AGG") == 0) {
            amino_acids.sequence[j] = 'R';
        } else if (strcmp(codon, "GGT") == 0 || strcmp(codon, "GGC") == 0 || strcmp(codon, "GGA") == 0 || strcmp(codon, "GGG") == 0) {
            amino_acids.sequence[j] = 'G';
        } else {
            amino_acids.sequence[j] = 'X';
        }
        free(codon);
    }
    return amino_acids;
}

int main() {
    DNA dna_seq = {
        .sequence = "ATGGCGTAA",
        .length = 9
    };
    AminoAcids aa_seq = dna_to_aa(&dna_seq);
    printf("DNA sequence: %s\n", dna_seq.sequence);
    printf("Amino acid sequence: %s\n", aa_seq.sequence);
    free(aa_seq.sequence);
    return 0;
}