//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_CHARS_PER_SEQUENCE 1000

void print_sequence(char* sequence) {
    for (int i = 0; i < strlen(sequence); i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

int main() {
    char* sequence = (char*)malloc(MAX_CHARS_PER_SEQUENCE * sizeof(char));
    char* template = (char*)malloc(MAX_CHARS_PER_SEQUENCE * sizeof(char));

    printf("Enter the template sequence: ");
    scanf("%s", template);

    printf("Enter the input sequence: ");
    scanf("%s", sequence);

    print_sequence(sequence);

    char* buffer = (char*)malloc(MAX_CHARS_PER_SEQUENCE * sizeof(char));
    int match_count = 0;
    int mismatch_count = 0;
    int insert_count = 0;
    int delete_count = 0;

    for (int i = 0; i < strlen(sequence); i++) {
        if (sequence[i] == template[i]) {
            match_count++;
        } else if (sequence[i] == '-') {
            insert_count++;
        } else if (template[i] == '-') {
            delete_count++;
        } else {
            mismatch_count++;
        }
    }

    printf("Matching bases: %d\n", match_count);
    printf("Mismatching bases: %d\n", mismatch_count);
    printf("Insertions: %d\n", insert_count);
    printf("Deletions: %d\n", delete_count);

    free(sequence);
    free(template);
    free(buffer);

    return 0;
}