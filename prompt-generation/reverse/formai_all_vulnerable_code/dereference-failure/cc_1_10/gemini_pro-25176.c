//GEMINI-pro DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// What the heck is this sorcery?
typedef struct {
    char *site;
    char *user;
    char *pass;
} pass_t;

// Oh my gawd, it's a linked list!
typedef struct {
    pass_t *pass;
    struct node *next;
} node_t;

// Holy smokes, a hash table!
typedef struct {
    node_t **table;
    size_t size;
} hash_table_t;

// SHA-256, because I'm feeling fancy
#define SHA256_DIGEST_LENGTH 32
unsigned char sha256_digest[SHA256_DIGEST_LENGTH];

// Insert a password into the hash table
void insert(hash_table_t *table, pass_t *pass) {
    // Calculate the hash value of the site name
    unsigned int hash = 0;
    for (int i = 0; i < strlen(pass->site); i++) {
        hash += pass->site[i];
    }

    // Insert the password into the hash table
    node_t *node = malloc(sizeof(node_t));
    node->pass = pass;
    node->next = table->table[hash % table->size];
    table->table[hash % table->size] = node;
}

// Search for a password in the hash table
pass_t *search(hash_table_t *table, char *site) {
    // Calculate the hash value of the site name
    unsigned int hash = 0;
    for (int i = 0; i < strlen(site); i++) {
        hash += site[i];
    }

    // Search for the password in the hash table
    node_t *node = table->table[hash % table->size];
    while (node != NULL) {
        if (strcmp(node->pass->site, site) == 0) {
            return node->pass;
        }
        node = node->next;
    }

    return NULL;
}

// Initialize the hash table
void init(hash_table_t *table, size_t size) {
    table->table = malloc(sizeof(node_t *) * size);
    for (int i = 0; i < size; i++) {
        table->table[i] = NULL;
    }
    table->size = size;
}

// Free the hash table
void free_table(hash_table_t *table) {
    for (int i = 0; i < table->size; i++) {
        node_t *node = table->table[i];
        while (node != NULL) {
            node_t *next = node->next;
            free(node->pass->site);
            free(node->pass->user);
            free(node->pass->pass);
            free(node->pass);
            free(node);
            node = next;
        }
    }
    free(table->table);
}

// Get a password from the user
pass_t *get_password(void) {
    // Get the site name
    char site[256];
    printf("Enter the site name: ");
    scanf("%s", site);

    // Get the username
    char user[256];
    printf("Enter the username: ");
    scanf("%s", user);

    // Get the password
    char pass[256];
    printf("Enter the password: ");
    scanf("%s", pass);

    // Create a new password struct
    pass_t *p = malloc(sizeof(pass_t));
    p->site = strdup(site);
    p->user = strdup(user);
    p->pass = strdup(pass);

    return p;
}

// Print a password
void print_password(pass_t *pass) {
    printf("Site: %s\n", pass->site);
    printf("User: %s\n", pass->user);
    printf("Pass: %s\n", pass->pass);
}

// Main function
int main(void) {
    // Initialize the hash table
    hash_table_t table;
    init(&table, 100);

    // Get a password from the user
    pass_t *pass = get_password();

    // Insert the password into the hash table
    insert(&table, pass);

    // Search for the password in the hash table
    pass_t *found = search(&table, pass->site);

    // Print the password
    print_password(found);

    // Free the hash table
    free_table(&table);

    return 0;
}