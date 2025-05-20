//FormAI DATASET v1.0 Category: Spell checking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 500

typedef struct Node {
    char word[20];
    int count;
    struct Node* next;
}Node;

Node* hash_table[HASH_TABLE_SIZE] = { NULL };

int hash(char* str) {
    int hash_val = 0;
    while (*str)
        hash_val += *str++;
    return hash_val % HASH_TABLE_SIZE;
}

void add_word(char* word) {
    int index = hash(word);
    Node* p = hash_table[index];
    while (p) {
        if (strcmp(p->word, word) == 0) {
            p->count++;
            return;
        }
        p = p->next;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

int check_word(char* word) {
    int index = hash(word);
    Node* p = hash_table[index];
    while (p) {
        if (strcmp(p->word, word) == 0) {
            return p->count;
        }
        p = p->next;
    }
    return 0;
}

int main() {
    FILE* fp = fopen("text_file.txt", "r");
    char buf[1024];
    char* ptr;
    int i;

    while (fgets(buf, 1024, fp)) {
        ptr = strtok(buf, ".,;:!?'\"\n\t ");
        while (ptr) {
            for (i = 0; i < strlen(ptr); i++) {
                if (!isalpha(ptr[i])) {
                    ptr[i] = '\0';
                    break;
                }
                ptr[i] = tolower(ptr[i]);
            }
            if (strlen(ptr) > 0) {
                if (!check_word(ptr)) {
                    add_word(ptr);
                }
            }
            ptr = strtok(NULL, ".,;:!?'\"\n\t ");
        }
    }

    fclose(fp);

    printf("%25s | %10s\n", "WORD", "COUNT");
    printf("%25s-+-%10s\n", "-------------------------", "----------");
    for (i = 0; i < HASH_TABLE_SIZE; i++) {
        Node* p = hash_table[i];
        while (p) {
            printf("%25s | %10d\n", p->word, p->count);
            p = p->next;
        }
    }

    return 0;
}