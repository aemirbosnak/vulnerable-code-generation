//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_NUM_STRINGS 10

struct string_node {
    char str[MAX_STR_LEN];
    struct string_node *next;
};

struct string_list {
    struct string_node *head;
    int num_strings;
};

void init_string_list(struct string_list *list) {
    list->head = NULL;
    list->num_strings = 0;
}

void add_string(struct string_list *list, char *str) {
    struct string_node *node = malloc(sizeof(struct string_node));
    strcpy(node->str, str);
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        struct string_node *curr_node = list->head;
        while (curr_node->next!= NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = node;
    }

    list->num_strings++;
}

void print_string_list(struct string_list *list) {
    struct string_node *node = list->head;
    while (node!= NULL) {
        printf("%s\n", node->str);
        node = node->next;
    }
}

void free_string_list(struct string_list *list) {
    struct string_node *node = list->head;
    while (node!= NULL) {
        list->head = node->next;
        free(node);
        node = list->head;
    }
    list->num_strings = 0;
}

int main() {
    struct string_list strings;
    init_string_list(&strings);

    add_string(&strings, "The game is afoot!");
    add_string(&strings, "Elementary, my dear Watson.");
    add_string(&strings, "I am not a psychopath, I am a high functioning sociopath.");

    print_string_list(&strings);

    free_string_list(&strings);

    return 0;
}