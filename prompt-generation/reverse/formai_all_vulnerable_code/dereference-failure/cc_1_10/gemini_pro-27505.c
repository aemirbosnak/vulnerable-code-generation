//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node
{
  int id;
  char *tag;
  struct node *next;
} node_t;

typedef struct queue
{
  node_t *front;
  node_t *rear;
} queue_t;

typedef struct hashtable
{
  int size;
  node_t **table;
} hashtable_t;

void enqueue(queue_t *q, int id, char *tag)
{
  node_t *new_node = malloc(sizeof(node_t));
  new_node->id = id;
  new_node->tag = tag;
  new_node->next = NULL;

  if (q->rear == NULL)
  {
    q->front = new_node;
    q->rear = new_node;
  }
  else
  {
    q->rear->next = new_node;
    q->rear = new_node;
  }
}

node_t *dequeue(queue_t *q)
{
  if (q->front == NULL)
    return NULL;

  node_t *temp = q->front;
  q->front = q->front->next;

  if (q->front == NULL)
    q->rear = NULL;

  return temp;
}

int hash_function(int id, int size)
{
  return id % size;
}

hashtable_t *create_hashtable(int size)
{
  hashtable_t *ht = malloc(sizeof(hashtable_t));
  ht->size = size;
  ht->table = malloc(sizeof(node_t *) * size);

  for (int i = 0; i < size; i++)
    ht->table[i] = NULL;

  return ht;
}

void insert_into_hashtable(hashtable_t *ht, int id, char *tag)
{
  int index = hash_function(id, ht->size);
  node_t *new_node = malloc(sizeof(node_t));
  new_node->id = id;
  new_node->tag = tag;
  new_node->next = NULL;

  if (ht->table[index] == NULL)
    ht->table[index] = new_node;
  else
  {
    node_t *temp = ht->table[index];
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = new_node;
  }
}

node_t *search_in_hashtable(hashtable_t *ht, int id)
{
  int index = hash_function(id, ht->size);
  node_t *temp = ht->table[index];

  while (temp != NULL)
  {
    if (temp->id == id)
      return temp;
    temp = temp->next;
  }

  return NULL;
}

void delete_from_hashtable(hashtable_t *ht, int id)
{
  int index = hash_function(id, ht->size);
  node_t *temp = ht->table[index];
  node_t *prev = NULL;

  if (temp != NULL && temp->id == id)
  {
    ht->table[index] = temp->next;
    free(temp);
    return;
  }

  while (temp != NULL && temp->id != id)
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
    return;

  prev->next = temp->next;
  free(temp);
}

void print_queue(queue_t *q)
{
  node_t *temp = q->front;
  while (temp != NULL)
  {
    printf("%d\t%s\n", temp->id, temp->tag);
    temp = temp->next;
  }
}

void print_hashtable(hashtable_t *ht)
{
  for (int i = 0; i < ht->size; i++)
  {
    node_t *temp = ht->table[i];
    if (temp != NULL)
    {
      printf("Index: %d\n", i);
      while (temp != NULL)
      {
        printf("\tID: %d\tTag: %s\n", temp->id, temp->tag);
        temp = temp->next;
      }
    }
  }
}

int main()
{
  queue_t baggage_queue;
  baggage_queue.front = NULL;
  baggage_queue.rear = NULL;

  hashtable_t *baggage_hashtable = create_hashtable(100);

  enqueue(&baggage_queue, 1, "AAA123");
  enqueue(&baggage_queue, 2, "BBB234");
  enqueue(&baggage_queue, 3, "CCC345");
  enqueue(&baggage_queue, 4, "DDD456");
  enqueue(&baggage_queue, 5, "EEE567");

  insert_into_hashtable(baggage_hashtable, 1, "AAA123");
  insert_into_hashtable(baggage_hashtable, 2, "BBB234");
  insert_into_hashtable(baggage_hashtable, 3, "CCC345");
  insert_into_hashtable(baggage_hashtable, 4, "DDD456");
  insert_into_hashtable(baggage_hashtable, 5, "EEE567");

  printf("Baggage Queue:\n");
  print_queue(&baggage_queue);

  printf("\nBaggage Hashtable:\n");
  print_hashtable(baggage_hashtable);

  node_t *baggage = dequeue(&baggage_queue);
  while (baggage != NULL)
  {
    delete_from_hashtable(baggage_hashtable, baggage->id);
    baggage = dequeue(&baggage_queue);
  }

  return 0;
}