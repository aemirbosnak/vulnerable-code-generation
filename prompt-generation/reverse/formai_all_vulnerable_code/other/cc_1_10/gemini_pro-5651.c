//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// A simple implementation of a priority queue, using a binary heap.
struct pq_node {
  int priority;
  void *data;
};

struct priority_queue {
  size_t size;
  size_t capacity;
  struct pq_node *nodes;
};

struct priority_queue *pq_create(size_t capacity) {
  struct priority_queue *pq = malloc(sizeof(*pq));
  assert(pq != NULL);

  pq->size = 0;
  pq->capacity = capacity;
  pq->nodes = malloc(sizeof(*pq->nodes) * capacity);
  assert(pq->nodes != NULL);

  return pq;
}

void pq_destroy(struct priority_queue *pq) {
  free(pq->nodes);
  free(pq);
}

void pq_push(struct priority_queue *pq, int priority, void *data) {
  assert(pq->size < pq->capacity);

  // Insert the new node at the end of the heap.
  pq->nodes[pq->size].priority = priority;
  pq->nodes[pq->size].data = data;
  pq->size++;

  // Bubble up the new node until it reaches its correct position.
  size_t i = pq->size - 1;
  while (i > 0) {
    size_t parent = (i - 1) / 2;
    if (pq->nodes[i].priority < pq->nodes[parent].priority) {
      // Swap the new node with its parent.
      struct pq_node tmp = pq->nodes[i];
      pq->nodes[i] = pq->nodes[parent];
      pq->nodes[parent] = tmp;

      i = parent;
    } else {
      break;
    }
  }
}

void *pq_pop(struct priority_queue *pq) {
  assert(pq->size > 0);

  // Swap the first and last nodes.
  struct pq_node tmp = pq->nodes[0];
  pq->nodes[0] = pq->nodes[pq->size - 1];
  pq->nodes[pq->size - 1] = tmp;

  // Remove the last node from the heap.
  pq->size--;

  // Bubble down the first node until it reaches its correct position.
  size_t i = 0;
  while (i < pq->size) {
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    // Find the child with the lowest priority.
    size_t min_child = i;
    if (left < pq->size && pq->nodes[left].priority < pq->nodes[min_child].priority) {
      min_child = left;
    }
    if (right < pq->size && pq->nodes[right].priority < pq->nodes[min_child].priority) {
      min_child = right;
    }

    if (min_child == i) {
      break;
    } else {
      // Swap the node with its child.
      tmp = pq->nodes[i];
      pq->nodes[i] = pq->nodes[min_child];
      pq->nodes[min_child] = tmp;

      i = min_child;
    }
  }

  return tmp.data;
}

int main() {
  // Create a priority queue with a capacity of 100.
  struct priority_queue *pq = pq_create(100);

  // Push some nodes into the priority queue.
  pq_push(pq, 10, "Ten");
  pq_push(pq, 5, "Five");
  pq_push(pq, 15, "Fifteen");
  pq_push(pq, 2, "Two");
  pq_push(pq, 7, "Seven");

  // Pop and print the nodes from the priority queue.
  while (pq->size > 0) {
    printf("%s\n", (char *)pq_pop(pq));
  }

  // Destroy the priority queue.
  pq_destroy(pq);

  return 0;
}