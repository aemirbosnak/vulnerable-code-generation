//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

struct node {
    char *data;
    struct node *next;
};

struct node *compress(char *str) {
    struct node *head = NULL, *cur = NULL, *prev = NULL;
    char *ptr = str;

    while (*ptr != '\0') {
        if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u') {
            cur = (struct node *) malloc(sizeof(struct node));
            cur->data = ptr++;
            if (cur->data[0] == 'a') {
                cur->data[0] = '4';
            } else if (cur->data[0] == 'e') {
                cur->data[0] = '3';
            } else if (cur->data[0] == 'i') {
                cur->data[0] = '2';
            } else if (cur->data[0] == 'o') {
                cur->data[0] = '0';
            } else if (cur->data[0] == 'u') {
                cur->data[0] = '7';
            }
            cur->next = head;
            head = cur;
        } else {
            prev = cur;
            cur = (struct node *) malloc(sizeof(struct node));
            cur->data = ptr++;
            cur->next = head;
            head = cur;
        }
    }

    return head;
}

int main() {
    char str[] = "The quick brown fox jumps over the lazy dog";
    struct node *compressed = compress(str);
    char *ptr = compressed->data;

    while (ptr != NULL) {
        printf("%c", *ptr);
        ptr = compressed->next->data;
    }

    return 0;
}