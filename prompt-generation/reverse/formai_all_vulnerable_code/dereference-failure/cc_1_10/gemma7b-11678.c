//Gemma-7B DATASET v1.0 Category: Firewall ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct Firewall {
    char buffer[BUFFER_SIZE];
    int head;
    int tail;
    int size;
} Firewall;

Firewall *createFirewall() {
    Firewall *firewall = malloc(sizeof(Firewall));
    firewall->head = 0;
    firewall->tail = 0;
    firewall->size = BUFFER_SIZE;
    return firewall;
}

void addToFirewall(Firewall *firewall, char data) {
    if (firewall->head - firewall->tail >= firewall->size) {
        printf("Firewall full!\n");
        return;
    }
    firewall->buffer[firewall->head++] = data;
}

char peekFromFirewall(Firewall *firewall) {
    if (firewall->tail == firewall->head) {
        return '\0';
    }
    return firewall->buffer[firewall->tail++];
}

int main() {
    Firewall *firewall = createFirewall();

    // Add data to the firewall
    addToFirewall(firewall, 'a');
    addToFirewall(firewall, 'b');
    addToFirewall(firewall, 'c');
    addToFirewall(firewall, 'd');

    // Peek data from the firewall
    char data = peekFromFirewall(firewall);
    if (data != '\0') {
        printf("Data retrieved: %c\n", data);
    } else {
        printf("Firewall is empty\n");
    }

    return 0;
}