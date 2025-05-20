//Gemma-7B DATASET v1.0 Category: Firewall ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct Firewall
{
    char **buffer;
    int size;
    int head;
    int tail;
    int drop_counter;
} Firewall;

Firewall *firewall_init(int size)
{
    Firewall *fw = malloc(sizeof(Firewall));
    fw->buffer = malloc(size * BUFFER_SIZE);
    fw->size = size;
    fw->head = 0;
    fw->tail = 0;
    fw->drop_counter = 0;
    return fw;
}

void firewall_push(Firewall *fw, char *data)
{
    int len = strlen(data) + 1;
    if (fw->tail - fw->head >= fw->size)
    {
        fw->drop_counter++;
        return;
    }

    memcpy(fw->buffer[fw->tail], data, len);
    fw->tail = (fw->tail + 1) % fw->size;
}

void firewall_flush(Firewall *fw)
{
    fw->head = 0;
    fw->tail = 0;
    fw->drop_counter = 0;
}

int main()
{
    Firewall *fw = firewall_init(10);
    firewall_push(fw, "HELLO, WORLD!");
    firewall_push(fw, "THIS IS A MESSAGE");
    firewall_push(fw, "BUT IT WILL BE DROPED");
    firewall_push(fw, "HELLO AGAIN");

    firewall_flush(fw);

    firewall_push(fw, "NEW MESSAGE");
    firewall_push(fw, "THIS ONE WILL NOT BE DROPED");

    printf("Messages received: %d\n", fw->drop_counter);
    printf("Messages dropped: %d\n", fw->drop_counter);

    return 0;
}