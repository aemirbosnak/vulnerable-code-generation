//Gemma-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000

typedef struct SequencingData
{
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
    struct SequencingData* next;
} SequencingData;

SequencingData* createSequencingData(int length)
{
    SequencingData* data = malloc(sizeof(SequencingData));
    data->length = length;
    data->sequence[0] = '\0';
    data->next = NULL;
    return data;
}

void addSequenceToData(SequencingData* data, char sequence)
{
    data->sequence[data->length++] = sequence;
    data->sequence[data->length] = '\0';
}

void printSequencingData(SequencingData* data)
{
    for (int i = 0; i < data->length; i++)
    {
        printf("%c ", data->sequence[i]);
    }
    printf("\n");
}

int main()
{
    SequencingData* head = createSequencingData(20);

    addSequenceToData(head, 'A');
    addSequenceToData(head, 'C');
    addSequenceToData(head, 'G');
    addSequenceToData(head, 'T');

    printSequencingData(head);

    return 0;
}