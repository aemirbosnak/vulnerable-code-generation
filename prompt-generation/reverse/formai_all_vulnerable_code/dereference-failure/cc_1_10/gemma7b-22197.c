//Gemma-7B DATASET v1.0 Category: Firewall ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct Firewall {
    char buffer[BUFFER_SIZE];
    int head;
    int tail;
    int capacity;
} Firewall;

Firewall* firewall_init(int capacity) {
    Firewall* fw = malloc(sizeof(Firewall));
    fw->capacity = capacity;
    fw->head = 0;
    fw->tail = 0;
    memset(fw->buffer, 0, BUFFER_SIZE);
    return fw;
}

void firewall_add(Firewall* fw, char data) {
    if (fw->head - fw->tail >= fw->capacity) {
        return;
    }
    fw->buffer[fw->tail++] = data;
}

char firewall_get(Firewall* fw) {
    if (fw->head - fw->tail <= 0) {
        return -1;
    }
    return fw->buffer[fw->head++];
}

int main() {
    Firewall* fw = firewall_init(5);
    firewall_add(fw, 'a');
    firewall_add(fw, 'b');
    firewall_add(fw, 'c');
    firewall_add(fw, 'd');
    firewall_add(fw, 'e');

    char data = firewall_get(fw);
    if (data != -1) {
        printf("%c\n", data);
    } else {
        printf("No data\n");
    }

    return 0;
}