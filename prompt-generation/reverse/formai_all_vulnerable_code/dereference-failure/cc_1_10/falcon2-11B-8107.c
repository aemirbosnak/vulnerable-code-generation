//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

struct node {
    int key;
    struct node *next;
};

int main() {
    // Create a new database file
    int dbFile = open("database.db", O_CREAT | O_RDWR, 0666);
    if (dbFile == -1) {
        perror("Error opening database file");
        exit(EXIT_FAILURE);
    }
    
    // Create the root node
    struct node *root = (struct node*)mmap(NULL, sizeof(struct node), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (root == MAP_FAILED) {
        perror("Error mapping root node");
        exit(EXIT_FAILURE);
    }
    root->next = NULL;
    
    // Add elements to the database
    struct node *element1 = (struct node*)mmap(NULL, sizeof(struct node), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (element1 == MAP_FAILED) {
        perror("Error mapping element1");
        exit(EXIT_FAILURE);
    }
    element1->key = 1;
    element1->next = root;
    root = element1;
    
    struct node *element2 = (struct node*)mmap(NULL, sizeof(struct node), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (element2 == MAP_FAILED) {
        perror("Error mapping element2");
        exit(EXIT_FAILURE);
    }
    element2->key = 2;
    element2->next = root;
    root = element2;
    
    struct node *element3 = (struct node*)mmap(NULL, sizeof(struct node), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (element3 == MAP_FAILED) {
        perror("Error mapping element3");
        exit(EXIT_FAILURE);
    }
    element3->key = 3;
    element3->next = root;
    root = element3;
    
    // Print the elements of the database
    struct node *current = root;
    while (current!= NULL) {
        printf("%d ", current->key);
        current = current->next;
    }
    printf("\n");
    
    // Free the memory used by the database
    munmap((void*)root, sizeof(struct node));
    close(dbFile);
    
    return 0;
}