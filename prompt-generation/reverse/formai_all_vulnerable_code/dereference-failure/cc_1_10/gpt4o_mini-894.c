//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTICLES 100
#define HASH_TABLE_SIZE 20

typedef struct Article {
    int id;
    char title[100];
    char author[50];
    char journal[50];
    int year;
    struct Article* next;
} Article;

typedef struct HashTable {
    Article* table[HASH_TABLE_SIZE];
} HashTable;

// Function Prototypes
unsigned int hash(int id);
HashTable* create_hash_table();
void insert_article(HashTable* ht, int id, const char* title, const char* author, const char* journal, int year);
Article* search_article(HashTable* ht, int id);
void display_articles(HashTable* ht);
void free_hash_table(HashTable* ht);

// Main Function
int main() {
    HashTable* ht = create_hash_table();
    insert_article(ht, 1, "Understanding Quantum Mechanics", "Alice Smith", "Journal of Physics", 2022);
    insert_article(ht, 2, "Advancements in Genomics", "John Doe", "Genetics Today", 2023);
    insert_article(ht, 3, "Artificial Intelligence in Healthcare", "Emily Johnson", "AI & Health", 2021);

    printf("Displaying all articles:\n");
    display_articles(ht);

    int search_id;
    printf("Enter article ID to search: ");
    scanf("%d", &search_id);
    Article* found_article = search_article(ht, search_id);
    if (found_article) {
        printf("Article Found: ID=%d, Title=%s, Author=%s, Journal=%s, Year=%d\n", 
            found_article->id, found_article->title, found_article->author, found_article->journal, found_article->year);
    } else {
        printf("Article with ID=%d not found.\n", search_id);
    }

    free_hash_table(ht);
    return 0;
}

// Hash Function
unsigned int hash(int id) {
    return id % HASH_TABLE_SIZE;
}

// Create Hash Table
HashTable* create_hash_table() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
        ht->table[i] = NULL;
    return ht;
}

// Insert Article
void insert_article(HashTable* ht, int id, const char* title, const char* author, const char* journal, int year) {
    unsigned int index = hash(id);
    Article* new_article = (Article*)malloc(sizeof(Article));
    new_article->id = id;
    strcpy(new_article->title, title);
    strcpy(new_article->author, author);
    strcpy(new_article->journal, journal);
    new_article->year = year;
    new_article->next = ht->table[index];
    ht->table[index] = new_article;
}

// Search Article
Article* search_article(HashTable* ht, int id) {
    unsigned int index = hash(id);
    Article* current = ht->table[index];
    while (current) {
        if (current->id == id)
            return current;
        current = current->next;
    }
    return NULL;
}

// Display Articles
void display_articles(HashTable* ht) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Article* current = ht->table[i];
        while (current) {
            printf("ID=%d, Title=%s, Author=%s, Journal=%s, Year=%d\n", 
                current->id, current->title, current->author, current->journal, current->year);
            current = current->next;
        }
    }
}

// Free Memory
void free_hash_table(HashTable* ht) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Article* current = ht->table[i];
        while (current) {
            Article* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht);
}