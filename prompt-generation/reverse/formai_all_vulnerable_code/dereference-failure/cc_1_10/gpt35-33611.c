//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct baggage {
    char passenger_name[100];
    int weight;
};

struct node {
    struct baggage* data;
    struct node* next;
};

// Function to create a new baggage
struct baggage* create_baggage(char* passenger_name, int weight) {
    struct baggage* new_baggage = (struct baggage*) malloc(sizeof(struct baggage));
    strcpy(new_baggage->passenger_name, passenger_name);
    new_baggage->weight = weight;
    return new_baggage;
}

// Function to add a baggage to the queue
void enqueue(struct node** front, struct node** rear, struct baggage* new_baggage) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_baggage;
    new_node->next = NULL;

    if (*rear == NULL) {
        *front = *rear = new_node;
    } else {
        (*rear)->next = new_node;
        *rear = new_node;
    }

    printf("\nAdded baggage of %s with weight %d\n", new_baggage->passenger_name, new_baggage->weight);
}

// Function to remove a baggage from the queue
struct baggage* dequeue(struct node** front, struct node** rear) {
    if (*front == NULL) {
        return NULL;
    }

    struct baggage* removed_baggage = (*front)->data;
    struct node* temp = *front;
    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL;
    }

    free(temp);
    printf("\nRemoved baggage of %s with weight %d\n", removed_baggage->passenger_name, removed_baggage->weight);

    return removed_baggage;
}

int main() {
    srand(time(NULL));
    int total_iterations = 5, max_interval = 10; // Total number of iterations and maximum interval between each iteration in seconds
    int max_weight = 50; // Maximum weight of a baggage
    struct node* front = NULL;
    struct node* rear = NULL;

    for (int i = 1; i <= total_iterations; i++) {
        int interval = rand() % max_interval + 1; // Generate random interval between 1 and max_interval
        printf("\nIteration %d - %d second interval", i, interval);
        sleep(interval);

        int num_of_new_baggage = rand() % 5 + 1; // Generate random number of new baggage between 1 and 5
        printf("\n%d new baggage(s) arrived:\n", num_of_new_baggage);

        for (int j = 1; j <= num_of_new_baggage; j++) {
            char passenger_name[100];
            int weight = rand() % max_weight + 1; // Generate random weight between 1 and max_weight

            sprintf(passenger_name, "Passenger %d", rand() % 1000 + 1);
            struct baggage* new_baggage = create_baggage(passenger_name, weight);
            enqueue(&front, &rear, new_baggage);
        }

        int num_of_completed_baggage = rand() % 5 + 1; // Generate random number of completed baggage between 1 and 5
        printf("\n%d baggage(s) completed:\n", num_of_completed_baggage);

        for (int j = 1; j <= num_of_completed_baggage; j++) {
            struct baggage* removed_baggage = dequeue(&front, &rear);
            if (removed_baggage != NULL) {
                free(removed_baggage);
            }
        }
    }

    return 0;
}