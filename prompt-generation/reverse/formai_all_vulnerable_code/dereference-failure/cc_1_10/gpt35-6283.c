//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

// JSON Node structure
typedef struct json_node {
  char name[100];
  char value[100];
  int child_count;
  struct json_node* children[100];
} json_node;

sem_t sem_parse; // Semaphore for parsing
sem_t sem_write; // Semaphore for writing

json_node* root = NULL; // Global root node of JSON

void* parse_json(char* json_str) {
  sem_wait(&sem_parse); // Acquiring parsing semaphore to avoid clashes
  char* token = strtok(json_str, "{},"); // Splitting JSON string into tokens
  
  while(token != NULL) {
    // Creating JSON node for each token
    json_node* node = malloc(sizeof(json_node));
    node->child_count = 0;
    strcpy(node->value, "");
    strcpy(node->name, token);

    char* value = strtok(NULL, "{}:,"); // Getting value of the node
    if(value != NULL) strcpy(node->value, value);

    if(root == NULL) root = node; // Setting root to the first node

    if(strcmp(node->name, root->name) != 0) {
      // Adding child to parent node
      root->children[root->child_count++] = node;
    }
   
    token = strtok(NULL, "{},"); // Getting next token
  }
  
  sem_post(&sem_write); // Releasing write semaphore
  pthread_exit(NULL);
}

void* write_json() {
  sem_wait(&sem_write); // Acquiring write semaphore
  printf("Parsed JSON:\n");
  printf("{\n%s: %s\n", root->name, root->value);
  
  for(int i=0; i<root->child_count; i++) {
    json_node* child = root->children[i];
    printf("  %s: %s", child->name, child->value);
    
    for(int j=0; j<child->child_count; j++) {
      json_node* subchild = child->children[j];
      printf("    %s: %s\n", subchild->name, subchild->value);
    }
  }
  
  printf("}\n");
  sem_post(&sem_parse); // Releasing parsing semaphore
  pthread_exit(NULL);
}

int main() {
  sem_init(&sem_parse, 0, 1); // Initializing semaphores
  sem_init(&sem_write, 0, 0);
  
  // Creating two threads, one for parsing and one for writing
  pthread_t parse_thread, write_thread;
  char json_str[] = "{name: John, age: 25, address: {city: New York, state: NY}}";
  
  pthread_create(&parse_thread, NULL, parse_json, json_str);
  pthread_create(&write_thread, NULL, write_json, NULL);
  
  pthread_join(parse_thread, NULL);
  pthread_join(write_thread, NULL);
  
  sem_destroy(&sem_parse); // Destroying semaphores
  sem_destroy(&sem_write);
  return 0;
}