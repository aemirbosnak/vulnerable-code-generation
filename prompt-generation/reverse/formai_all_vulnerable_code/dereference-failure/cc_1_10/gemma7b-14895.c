//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct IntrusionDetectionSystem {
    char *buffer;
    int size;
    int index;
} IDS;

IDS *createIDS(int size) {
    IDS *ids = malloc(sizeof(IDS));
    ids->buffer = malloc(size * MAX_SIZE);
    ids->size = size;
    ids->index = 0;
    return ids;
}

void addIDS(IDS *ids, char *data) {
    if (ids->index >= ids->size) {
        printf("IDS full\n");
        return;
    }
    strcpy(ids->buffer + ids->index, data);
    ids->index++;
}

int checkIDS(IDS *ids, char *pattern) {
    for (int i = 0; i < ids->index; i++) {
        if (strstr(ids->buffer + i, pattern) != NULL) {
            return 1;
        }
    }
    return 0;
}

int main() {
    IDS *ids = createIDS(10);
    addIDS(ids, "This is a test data");
    addIDS(ids, "Another test data");
    addIDS(ids, "Secret data");

    if (checkIDS(ids, "test") == 1) {
        printf("Alert: suspicious data found\n");
    }

    if (checkIDS(ids, "Secret") == 1) {
        printf("Alert: secret data found\n");
    }

    return 0;
}