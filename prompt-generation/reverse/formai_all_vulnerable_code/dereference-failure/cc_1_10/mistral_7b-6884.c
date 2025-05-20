//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

typedef struct {
    uint8_t data;
    struct checksum *next;
} checksum_node;

struct checksum {
    uint32_t sum;
    pthread_mutex_t lock;
    checksum_node *head;
};

void checksum_init(struct checksum *cs) {
    cs->sum = 0;
    pthread_mutex_init(&cs->lock, NULL);
    cs->head = NULL;
}

void checksum_append(struct checksum *cs, uint8_t data) {
    pthread_mutex_lock(&cs->lock);

    checksum_node *new_node = malloc(sizeof(checksum_node));
    new_node->data = data;
    new_node->next = cs->head;
    cs->head = new_node;

    uint32_t temp_sum = cs->sum;
    cs->sum = (cs->sum << 8) ^ data;

    while (cs->head != NULL) {
        temp_sum += cs->head->data;
        cs->head = cs->head->next;
    }

    cs->sum = temp_sum;

    pthread_mutex_unlock(&cs->lock);
}

void checksum_calculate(struct checksum *cs, uint8_t *buffer, size_t size) {
    for (size_t i = 0; i < size; i++) {
        checksum_append(cs, buffer[i]);
    }

    printf("Checksum: %08X\n", cs->sum);
}

int main() {
    struct checksum cs;
    checksum_init(&cs);

    uint8_t buffer[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

    checksum_calculate(&cs, buffer, sizeof(buffer));

    return 0;
}