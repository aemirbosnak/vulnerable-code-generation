//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>

// A structure to represent the queue
typedef struct QueueNode{
	int data;
	struct QueueNode* next;
} QueueNode;

// A structure to represent the queue
typedef struct Queue{
	QueueNode* head;
	QueueNode* tail;
	int size;
} Queue;

// Function to initialize the queue
void Queue_init(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
}

// Function to insert a node at the end of the queue
void Queue_enqueue(Queue* q, int data)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->data = data;
	newNode->next = NULL;

	if(q->size == 0){
		q->head = newNode;
		q->tail = newNode;
	}else{
		q->tail->next = newNode;
		q->tail = newNode;
	}

	q->size++;
}

// Function to remove a node from the front of the queue
int Queue_dequeue(Queue* q)
{
	int data = -1;

	if(q->size == 0){
		printf("Queue is empty\n");
		return data;
	}

	data = q->head->data;
	QueueNode* temp = q->head;
	q->head = q->head->next;

	if(q->head == NULL){
		q->tail = NULL;
	}

	free(temp);
	q->size--;

	return data;
}

// Function to display the elements of the queue
void Queue_display(Queue* q)
{
	if(q->size == 0){
		printf("Queue is empty\n");
		return;
	}

	QueueNode* temp = q->head;
	while(temp!= NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}

	printf("\n");
}

int main()
{
	Queue q;
	Queue_init(&q);

	// Inserting elements into the queue
	Queue_enqueue(&q, 10);
	Queue_enqueue(&q, 20);
	Queue_enqueue(&q, 30);
	Queue_enqueue(&q, 40);
	Queue_enqueue(&q, 50);

	// Displaying the elements of the queue
	Queue_display(&q);

	// Removing an element from the front of the queue
	int data = Queue_dequeue(&q);
	printf("Element removed: %d\n", data);

	// Displaying the updated elements of the queue
	Queue_display(&q);

	return 0;
}