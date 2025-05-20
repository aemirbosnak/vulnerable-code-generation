//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

struct Vehicle {
    int distance;
    int lane;
};

struct Node {
    struct Vehicle vehicle;
    struct Node* next;
};

struct Node* create_vehicle() {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->vehicle.distance = 0;
    new_node->vehicle.lane = 0;
    new_node->next = NULL;
    return new_node;
}

void simulate_traffic(struct Node* root) {
    int distance = 0;
    int lane = 0;
    struct Node* current = root;
    
    while (current!= NULL) {
        int movement_direction = rand() % 10 + 1;
        
        switch (movement_direction) {
            case 1:
                distance += 1;
                break;
            case 2:
                distance -= 1;
                break;
            case 3:
                lane += 1;
                break;
            case 4:
                lane -= 1;
                break;
            case 5:
                lane = (lane + 1) % 4;
                break;
            case 6:
                printf("Vehicle exits the road.\n");
                current->next = NULL;
                break;
            case 7:
                lane = (lane + 2) % 4;
                break;
            case 8:
                lane = (lane - 2) % 4;
                break;
            case 9:
                lane = (lane + 1) % 4;
                break;
            case 10:
                distance += 1;
                break;
            default:
                break;
        }
        
        current = current->next;
    }
    
    printf("Total distance traveled: %d\n", distance);
    printf("Number of vehicles that exited the road: %d\n", count_exits(root));
}

int count_exits(struct Node* root) {
    int count = 0;
    struct Node* current = root;
    
    while (current!= NULL) {
        if (current->next == NULL) {
            count++;
        }
        current = current->next;
    }
    
    return count;
}

int main() {
    struct Node* root = create_vehicle();
    
    simulate_traffic(root);
    
    return 0;
}