//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

#define NUM_FLOORS 10
#define ELEVATOR_CAPACITY 10

struct Passenger{
    int current_floor;
    int destination_floor;
    int id;
};

struct Elevator {
    int current_floor;
    int current_capacity;
    int passengers[ELEVATOR_CAPACITY];
};

struct Queue{
    int front;
    int rear;
    int size;
    struct Passenger *passenger_array;
};

typedef struct Passenger passenger;
typedef struct Elevator elevator;
typedef struct Queue queue;

queue* init_queue(){
    queue *q = (queue*)malloc(sizeof(queue));
    q->front = q->rear = q->size = 0;
    q->passenger_array = (passenger*)malloc(sizeof(passenger)*ELEVATOR_CAPACITY);
    return q;
}

elevator* init_elevator(){
    elevator *e = (elevator*)malloc(sizeof(elevator));
    e->current_capacity = 0;
    e->current_floor = 0;
    return e;
}

void print_queue(queue *q){
    printf("Queue: ");
    if(q->size==0) {
        printf("Empty\n");
        return;
    }
    for(int i=q->front;i<q->rear;i++){
        printf("%d ", q->passenger_array[i].id);
    }
    printf("\n");
}

int is_queue_empty(queue *q){
    return q->size==0;
}

int is_queue_full(queue *q){
    return q->size == ELEVATOR_CAPACITY;
}

void enqueue(queue *q, passenger p){
    if(is_queue_full(q)) {
        printf("Queue is full!");
        return;
    }
    q->passenger_array[q->rear++] = p;
    q->size++;
}

passenger dequeue(queue *q){
    if(is_queue_empty(q)) {
        printf("Queue is empty!");
        passenger p; p.id = -1;
        return p;
    }
    passenger removed = q->passenger_array[q->front++];
    q->size--;
    return removed;
}

int get_direction(int current, int destination){
    if(destination>current) return 1;
    if(destination<current) return -1;
    return 0;
}

void move_elevator(elevator *elevator, int destination_floor){
    int direction = get_direction(elevator->current_floor, destination_floor);
    printf("Elevator moves from %d to %d\n", elevator->current_floor, destination_floor);
    if(direction>0){
        for(int i=elevator->current_floor+1;i<=destination_floor;i++){
            printf("Elevator reached floor %d, stopping\n", i);
            elevator->current_floor = i;
        }
    } else if(direction<0){
        for(int i=elevator->current_floor-1;i>=destination_floor;i--){
            printf("Elevator reached floor %d, stopping\n", i);
            elevator->current_floor = i;
        }
    }
}

void remove_passenger(elevator *elevator, int passenger_idx){
    for(int i=passenger_idx+1;i<elevator->current_capacity;++i){
        elevator->passengers[i-1] = elevator->passengers[i];
    }
    elevator->current_capacity--;
}

void add_passenger(elevator *elevator, int passenger_id){
    elevator->passengers[elevator->current_capacity++] = passenger_id;
}

void elevator_simulate(queue *q){
    int num_passengers = 0;
    int max_passengers_moved = 0;
    elevator *e = init_elevator();
    while (!is_queue_empty(q)){
        while (!is_queue_empty(q) && (e->current_capacity+ELEVATOR_CAPACITY/2<=ELEVATOR_CAPACITY)){
            passenger p = dequeue(q);
            printf("Passenger %d entered elevator at floor %d\n", p.id, p.current_floor);
            add_passenger(e, p.id);
            num_passengers++;
        }
        printf("Elevator moves to floor 0\n");
        e->current_floor = 0;
        int passenger_idx = 0;
        while (passenger_idx<e->current_capacity){
            int passenger_id = e->passengers[passenger_idx];
            if(passenger_id==e->current_floor){
                printf("Passenger %d exited the elevator at floor %d\n", passenger_id, e->current_floor);
                remove_passenger(e, passenger_idx);
                passenger_idx--;
                max_passengers_moved++;
            }
            passenger_idx++;
        }
        if(!is_queue_empty(q)){
            passenger p = q->passenger_array[q->front];
            move_elevator(e, p.current_floor);
        }
    }
    printf("All passengers have reached their destination\n");
    printf("Number of passengers transported: %d\n", num_passengers);
    printf("Maximum number of passengers moved in a trip: %d\n", max_passengers_moved);
}

int main(){
    srand(0);
    queue *q = init_queue();

    for(int i=1;i<=20;++i){
        passenger p = {rand()%NUM_FLOORS+1, rand()%NUM_FLOORS+1, i};
        if(p.current_floor==p.destination_floor) continue;
        enqueue(q, p);
    }

    print_queue(q);
    elevator_simulate(q);
    return 0;
}