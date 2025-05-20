//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: Cryptic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BID_LENGTH 50
#define BID_NUMBER 10

typedef struct {
    char name[BID_LENGTH];
    int bid;
    struct node* next;
} node;

node* head = NULL;
int highest_bid = 0;

void display_message(const char* message) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        putchar(message[i] ^ 0x31);
    }
    putchar('\n');
}

void bid() {
    node* new_node = (node*)calloc(1, sizeof(node));
    if (!new_node) {
        display_message("Memory error\n");
        return;
    }

    fputs("Enter your name: ", stdout);
    fgets(new_node->name, sizeof(new_node->name), stdin);
    new_node->name[strlen(new_node->name) - 1] = '\0';

    fputs("Enter your bid: ", stdout);
    scanf("%d", &new_node->bid);

    node* current = head;
    if (!head) {
        head = new_node;
        highest_bid = new_node->bid;
    } else {
        while (current->next) {
            current = current->next;
            if (new_node->bid > current->bid) {
                new_node->next = current->next;
                current->next = new_node;
                if (new_node->bid > highest_bid) {
                    highest_bid = new_node->bid;
                }
                break;
            } else {
                current = current->next;
            }
        }
        if (!current->next) {
            current->next = new_node;
            if (new_node->bid > highest_bid) {
                highest_bid = new_node->bid;
            }
        }
    }

    printf("Your bid has been registered.\n");
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < BID_NUMBER; i++) {
        bid();
    }

    display_message("Current highest bid: ");
    printf("%d\n", highest_bid);

    node* current = head;
    while (current) {
        printf("%s: %d\n", current->name, current->bid);
        current = current->next;
    }

    free(head);
    head = NULL;

    return 0;
}