//FormAI DATASET v1.0 Category: Database Indexing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

typedef struct {
    Person* data;
    int len;
} Database;

typedef struct {
    char* index;
    int* offsets;
    int len;
} Index;

void create_index(Database* db, Index* index) {
    index->len = db->len;
    index->index = malloc(db->len * sizeof(char));
    index->offsets = malloc(db->len * sizeof(int));
    for (int i = 0; i < db->len; i++) {
        index->offsets[i] = i * sizeof(Person);
        if (strstr(db->data[i].name, "funny") != NULL) {
            index->index[i] = 'F';
        } else {
            index->index[i] = 'N';
        }
    }
}

void search_index(Database* db, Index* index, char* query) {
    for (int i = 0; i < index->len; i++) {
        if (index->index[i] == 'F') {
            if (strstr(db->data[i].name, query) != NULL) {
                printf("%s is %d years old and funny\n", db->data[i].name, db->data[i].age);
            }
        } else if (index->index[i] == 'N') {
            if (strstr(db->data[i].name, query) != NULL) {
                printf("%s is %d years old but not funny :(\n", db->data[i].name, db->data[i].age);
            }
        }
    }
}

int main() {
    Database db;
    db.data = malloc(3 * sizeof(Person));
    db.len = 3;
    
    strcpy(db.data[0].name, "John Funny");
    db.data[0].age = 30;
    
    strcpy(db.data[1].name, "Jane NotFunny");
    db.data[1].age = 25;
    
    strcpy(db.data[2].name, "Bob Funny");
    db.data[2].age = 50;
    
    Index index;
    create_index(&db, &index);
    
    printf("Welcome to the Funny Database!\n");
    printf("Please enter a name to search for: ");
    
    char query[50];
    scanf("%s", query);
    
    search_index(&db, &index, query);
    
    free(db.data);
    free(index.index);
    free(index.offsets);
    
    printf("Thank you for using the Funny Database!\n");
    
    return 0;
}