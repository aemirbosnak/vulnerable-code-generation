//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Custom data structure to represent a task
typedef struct task {
    int id;
    int arrivalTime;
    int executionTime;
    int completionTime;
    int waitingTime;
} Task;

// Custom data structure to represent a queue
typedef struct queue {
    Task* tasks;
    int front;
    int rear;
    int size;
} Queue;

// Function to initialize a queue with a given size
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->tasks = (Task*)malloc(sizeof(Task) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

// Function to check if a queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to check if a queue is full
bool isFull(Queue* queue) {
    return queue->rear == queue->size - 1;
}

// Function to add a task to the rear of the queue
void enqueue(Queue* queue, Task task) {
    if (!isFull(queue)) {
        if (queue->rear == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->tasks[queue->rear] = task;
    }
}

// Function to remove a task from the front of the queue
Task dequeue(Queue* queue) {
    Task task;
    if (!isEmpty(queue)) {
        task = queue->tasks[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }
    }
    return task;
}

// Function to sort an array of tasks in ascending order of their arrival times
void sortTasksByArrivalTime(Task* tasks, int numTasks) {
    for (int i = 0; i < numTasks - 1; i++) {
        for (int j = i + 1; j < numTasks; j++) {
            if (tasks[i].arrivalTime > tasks[j].arrivalTime) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

// Function to calculate the completion time, waiting time, and turnaround time for each task
void calculateTaskMetrics(Task* tasks, int numTasks) {
    int currentTime = 0;
    for (int i = 0; i < numTasks; i++) {
        if (currentTime < tasks[i].arrivalTime) {
            currentTime = tasks[i].arrivalTime;
        }
        tasks[i].completionTime = currentTime + tasks[i].executionTime;
        tasks[i].waitingTime = tasks[i].completionTime - tasks[i].arrivalTime - tasks[i].executionTime;
    }
}

// Function to calculate the average waiting time and turnaround time for a set of tasks
void calculateAverageMetrics(Task* tasks, int numTasks) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    for (int i = 0; i < numTasks; i++) {
        totalWaitingTime += tasks[i].waitingTime;
        totalTurnaroundTime += tasks[i].completionTime - tasks[i].arrivalTime;
    }
    printf("Average waiting time: %.2f\n", (float)totalWaitingTime / numTasks);
    printf("Average turnaround time: %.2f\n", (float)totalTurnaroundTime / numTasks);
}

// Main function
int main() {
    // Initialize a queue to represent the ready queue
    Queue* readyQueue = createQueue(10);

    // Declare an array of tasks
    Task tasks[5] = {
        {1, 0, 3},
        {2, 2, 6},
        {3, 4, 4},
        {4, 6, 5},
        {5, 8, 2}
    };

    // Sort the tasks by their arrival times
    sortTasksByArrivalTime(tasks, 5);

    // Add the tasks to the ready queue in order of their arrival times
    for (int i = 0; i < 5; i++) {
        enqueue(readyQueue, tasks[i]);
    }

    // Process the tasks in the ready queue
    while (!isEmpty(readyQueue)) {
        // Dequeue the task from the front of the ready queue
        Task task = dequeue(readyQueue);

        // Execute the task
        printf("Executing task %d\n", task.id);

        // Update the task metrics
        calculateTaskMetrics(&task, 1);
    }

    // Calculate the average waiting time and turnaround time for the tasks
    calculateAverageMetrics(tasks, 5);

    return 0;
}