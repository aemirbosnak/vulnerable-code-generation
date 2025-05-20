//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

struct node {
    char *name;
    char *type;
    int size;
    struct node *next;
};

struct symbol_table {
    struct node *head;
    int count;
};

void insert_symbol(struct symbol_table *st, char *name, char *type, int size) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->name = strdup(name);
    new_node->type = strdup(type);
    new_node->size = size;
    new_node->next = NULL;

    if (st->head == NULL) {
        st->head = new_node;
    } else {
        struct node *current = st->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    st->count++;
}

struct node *lookup_symbol(struct symbol_table *st, char *name) {
    struct node *current = st->head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    struct symbol_table st = { NULL, 0 };

    insert_symbol(&st, "x", "int", 4);
    insert_symbol(&st, "y", "float", 8);
    insert_symbol(&st, "z", "char", 1);

    struct node *x = lookup_symbol(&st, "x");
    printf("%s is a %s of size %d\n", x->name, x->type, x->size);

    struct node *y = lookup_symbol(&st, "y");
    printf("%s is a %s of size %d\n", y->name, y->type, y->size);

    struct node *z = lookup_symbol(&st, "z");
    printf("%s is a %s of size %d\n", z->name, z->type, z->size);

    return 0;
}