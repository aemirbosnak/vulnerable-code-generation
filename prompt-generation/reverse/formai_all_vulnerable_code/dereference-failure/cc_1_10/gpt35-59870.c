//FormAI DATASET v1.0 Category: Browser Plugin ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint32_t id;
    uint32_t length;
    uint8_t* data;
} Message;

typedef struct {
    uint32_t num_messages;
    Message** messages;
} Inbox;

Inbox* inbox_init() {
    Inbox* inbox = malloc(sizeof(Inbox));
    inbox->num_messages = 0;
    inbox->messages = malloc(sizeof(Message*));
    return inbox;
}

void inbox_add_message(Inbox* inbox, Message* message) {
    inbox->num_messages += 1;
    inbox->messages = realloc(inbox->messages, inbox->num_messages * sizeof(Message*));
    inbox->messages[inbox->num_messages - 1] = message;
}

void inbox_free(Inbox* inbox) {
    for (int i = 0; i < inbox->num_messages; i++) {
        free(inbox->messages[i]->data);
        free(inbox->messages[i]);
    }
    free(inbox->messages);
    free(inbox);
}

void on_message_receive(uint32_t id, uint32_t length, uint8_t* data, void* user_data) {
    Inbox* inbox = (Inbox*) user_data;
    Message* message = malloc(sizeof(Message));
    message->id = id;
    message->length = length;
    message->data = malloc(length);
    memcpy(message->data, data, length);
    inbox_add_message(inbox, message);
}

uint8_t* plugin_process_messages(Inbox* inbox) {
    uint32_t num_messages = inbox->num_messages;
    uint32_t offset = 0;
    for (int i = 0; i < num_messages; i++) {
        offset += inbox->messages[i]->length;
    }

    uint8_t* output = malloc(offset);
    offset = 0;
    for (int i = 0; i < num_messages; i++) {
        memcpy(output + offset, inbox->messages[i]->data, inbox->messages[i]->length);
        offset += inbox->messages[i]->length;
    }

    return output;
}

int main() {
    Inbox* inbox = inbox_init();
    uint8_t data1[] = {0x01, 0x02, 0x03};
    Message* message1 = malloc(sizeof(Message));
    message1->id = 1;
    message1->length = sizeof(data1);
    message1->data = data1;
    inbox_add_message(inbox, message1);

    uint8_t data2[] = {0x04, 0x05};
    Message* message2 = malloc(sizeof(Message));
    message2->id = 2;
    message2->length = sizeof(data2);
    message2->data = data2;
    inbox_add_message(inbox, message2);

    uint8_t* output = plugin_process_messages(inbox);
    printf("Output:\n");
    for (int i = 0; i < inbox->num_messages; i++) {
        for (int j = 0; j < inbox->messages[i]->length; j++) {
            printf("%02x ", output[j]);
        }
        printf("\n");
    }

    inbox_free(inbox);
    free(output);

    return 0;
}