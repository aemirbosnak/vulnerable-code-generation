//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 13
#define START_TIME 6
#define END_TIME 22

typedef struct Appointment {
    int start, end;
    struct Appointment *next;
} Appointment;

typedef struct HashNode {
    Appointment *data;
    struct HashNode *next;
} HashNode;

void init_hash_table(HashNode **hash_table) {
    int i;
    *hash_table = calloc(TABLE_SIZE, sizeof(HashNode));
    for (i = 0; i < TABLE_SIZE; i++) {
        (*hash_table)[i].next = NULL;
    }
}

int hash_func(int key) {
    return key % TABLE_SIZE;
}

Appointment *create_appointment(int start, int end) {
    Appointment *appt = malloc(sizeof(Appointment));
    appt->start = start;
    appt->end = end;
    appt->next = NULL;
    return appt;
}

void insert_appointment(HashNode **hash_table, Appointment *appt) {
    int key = hash_func(appt->start);
    HashNode *hash_node = *hash_table + key;
    if (hash_node->data == NULL) {
        hash_node->data = appt;
    } else {
        Appointment *current = hash_node->data;
        while (current->next != NULL && current->next->start < appt->start) {
            current = current->next;
        }
        appt->next = current->next;
        current->next = appt;
    }
}

void print_hash_table(HashNode *hash_table) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("Slot %d: ", i);
        if (hash_table[i].data != NULL) {
            Appointment *appt = hash_table[i].data;
            printf("%d-%d ", appt->start, appt->end);
            while (appt->next != NULL) {
                appt = appt->next;
                printf("%d-%d ", appt->start, appt->end);
            }
        }
        printf("\n");
    }
}

int main() {
    HashNode *hash_table;
    init_hash_table(&hash_table);

    Appointment *appt1 = create_appointment(11, 13);
    insert_appointment(hash_table, appt1);

    Appointment *appt2 = create_appointment(14, 15);
    insert_appointment(hash_table, appt2);

    Appointment *appt3 = create_appointment(17, 18);
    insert_appointment(hash_table, appt3);

    Appointment *appt4 = create_appointment(19, 20);
    insert_appointment(hash_table, appt4);

    print_hash_table(hash_table);

    return 0;
}