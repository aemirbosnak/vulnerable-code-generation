//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
} Message;

void init_message(Message *msg) {
    msg->data = malloc(MAX_SIZE * sizeof(char));
    msg->size = 0;
}

void append_char(Message *msg, char c) {
    msg->data[msg->size] = c;
    msg->size++;
}

int get_checksum(Message msg) {
    int sum = 0;
    for (int i = 0; i < msg.size; i++) {
        sum += msg.data[i];
    }
    return sum;
}

void print_message(Message msg) {
    printf("Message: %s\n", msg.data);
    printf("Size: %d\n", msg.size);
    printf("Checksum: %d\n", get_checksum(msg));
}

int main() {
    Message msg;
    init_message(&msg);

    char input[MAX_SIZE];
    while (fgets(input, MAX_SIZE, stdin)!= NULL) {
        if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }
        append_char(&msg, input[0]);
    }

    print_message(msg);

    free(msg.data);
    return 0;
}