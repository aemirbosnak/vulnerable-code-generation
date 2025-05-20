//Gemma-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCES 100
#define MAX_SEQUENCE_LENGTH 1000

typedef struct SequencingData {
    char sequence[MAX_SEQUENCE_LENGTH];
    int quality[MAX_SEQUENCE_LENGTH];
    struct SequencingData* next;
} SequencingData;

SequencingData* createSequencingData() {
    SequencingData* data = malloc(sizeof(SequencingData));
    data->sequence[0] = '\0';
    data->quality[0] = '\0';
    data->next = NULL;
    return data;
}

void insertSequencingData(SequencingData* head, char* sequence, int quality) {
    SequencingData* new_data = createSequencingData();
    strcpy(new_data->sequence, sequence);
    new_data->quality[0] = quality;

    if (head == NULL) {
        head = new_data;
    } else {
        head->next = new_data;
    }
    head = new_data;
}

void simulateSequencing(int num_sequences) {
    time_t t = time(NULL);
    srand(t);

    SequencingData* head = NULL;
    for (int i = 0; i < num_sequences; i++) {
        char sequence[MAX_SEQUENCE_LENGTH];
        int length = rand() % MAX_SEQUENCE_LENGTH + 1;
        for (int j = 0; j < length; j++) {
            sequence[j] = 'A' + rand() % 4;
        }
        sequence[length] = '\0';

        int quality = rand() % 10 + 1;
        insertSequencingData(head, sequence, quality);
    }

    printf("Simulated sequencing data:\n");
    for (SequencingData* data = head; data; data = data->next) {
        printf("Sequence: %s\n", data->sequence);
        printf("Quality: %d\n", data->quality[0]);
        printf("\n");
    }
}

int main() {
    simulateSequencing(MAX_SEQUENCES);
    return 0;
}