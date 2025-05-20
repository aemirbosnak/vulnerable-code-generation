//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Romeo and Juliet's love letters
char *romeo_letters[] = {
    "My sweetest love, my dearest friend.",
    "I love thee more than words can say.",
    "With every breath I take, I long for you.",
    "My heart is thine, and thine alone.",
    "Forever and always, I am yours."
};

// Juliet's love letters
char *juliet_letters[] = {
    "My dearest Romeo, my love so true.",
    "I adore thee, my precious one.",
    "With every heartbeat, I think of you.",
    "My soul is bound to yours, forevermore.",
    "I am thine, and thou art mine."
};

// The queue to hold the love letters
struct Queue {
    char **letters;
    int front, rear, size;
};

// Create a new queue
struct Queue *create_queue(int size) {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->letters = (char **)malloc(sizeof(char *) * size);
    queue->front = queue->rear = -1;
    queue->size = size;
    return queue;
}

// Check if the queue is full
int is_full(struct Queue *queue) {
    return queue->rear == queue->size - 1;
}

// Check if the queue is empty
int is_empty(struct Queue *queue) {
    return queue->front == -1;
}

// Enqueue a love letter
void enqueue(struct Queue *queue, char *letter) {
    if (is_full(queue)) {
        printf("The queue is full! Romeo and Juliet must wait to send their love letters.\n");
        return;
    }

    // If the queue is empty, set the front to 0
    if (is_empty(queue)) {
        queue->front = 0;
    }

    // Increment the rear and add the letter to the queue
    queue->rear++;
    queue->letters[queue->rear] = letter;
}

// Dequeue a love letter
char *dequeue(struct Queue *queue) {
    if (is_empty(queue)) {
        printf("The queue is empty! Romeo and Juliet have no love letters to read.\n");
        return NULL;
    }

    // Store the front letter and increment the front
    char *letter = queue->letters[queue->front];
    queue->front++;

    // If the queue is now empty, set the front and rear to -1
    if (is_empty(queue)) {
        queue->front = queue->rear = -1;
    }

    return letter;
}

// Print the love letters in the queue
void print_queue(struct Queue *queue) {
    if (is_empty(queue)) {
        printf("The queue is empty! Romeo and Juliet's love letters are hidden.\n");
        return;
    }

    // Iterate through the queue and print the letters
    printf("Romeo and Juliet's love letters:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%s\n", queue->letters[i]);
    }
}

int main() {
    // Create a queue to hold 10 love letters
    struct Queue *queue = create_queue(10);

    // Enqueue Romeo's love letters
    for (int i = 0; i < 5; i++) {
        enqueue(queue, romeo_letters[i]);
    }

    // Enqueue Juliet's love letters
    for (int i = 0; i < 5; i++) {
        enqueue(queue, juliet_letters[i]);
    }

    // Print the love letters in the queue
    print_queue(queue);

    // Dequeue and read the love letters
    while (!is_empty(queue)) {
        char *letter = dequeue(queue);
        printf("\nRomeo and Juliet read: %s\n", letter);
    }

    return 0;
}