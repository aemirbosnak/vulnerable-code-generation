//FormAI DATASET v1.0 Category: Computer Biology ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// function to check if a given DNA sequence is valid
int check_DNA_sequence(char * seq) {
    int i = 0;

    while(seq[i] != '\0') {
        // check if current character is A, C, G or T
        if(seq[i] != 'A' && seq[i] != 'C' && seq[i] != 'G' && seq[i] != 'T') {
            // if not, sequence is invalid
            return 0;
        }
        // increment index
        i++;
    }

    // if all characters are valid, sequence is valid
    return 1;
}

// function to convert a given DNA sequence to its RNA complement
char * DNA_to_RNA_complement(char * seq) {
    int i = 0, j = 0;
    char * compl_seq = (char *)malloc(sizeof(char) * (strlen(seq) + 1));

    // loop through sequence
    while(seq[i] != '\0') {
        // complement each character with its RNA base pair
        if(seq[i] == 'A') {
            compl_seq[j] = 'U';
        } else if(seq[i] == 'C') {
            compl_seq[j] = 'G';
        } else if(seq[i] == 'G') {
            compl_seq[j] = 'C';
        } else if(seq[i] == 'T') {
            compl_seq[j] = 'A';
        }
        // increment indices
        i++;
        j++;
    }

    // add null terminator to complement sequence
    compl_seq[j] = '\0';

    // return RNA complement sequence
    return compl_seq;
}

int main() {
    char * DNA_seq = "ACGTAGCTTAGA";
    char * RNA_seq;

    // check if DNA sequence is valid
    if(check_DNA_sequence(DNA_seq)) {
        // print DNA sequence
        printf("Given DNA sequence: %s\n", DNA_seq);

        // convert DNA sequence to RNA complement
        RNA_seq = DNA_to_RNA_complement(DNA_seq);

        // print RNA complement sequence
        printf("RNA complement sequence: %s\n", RNA_seq);
    } else {
        // print error message if DNA sequence is invalid
        printf("Invalid DNA sequence!\n");
    }

    return 0;
}