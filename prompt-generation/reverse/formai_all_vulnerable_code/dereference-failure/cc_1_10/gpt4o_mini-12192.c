//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_DISK 10

int num_disks;
int rods[3][MAX_DISK]; // 0 = source, 1 = auxiliary, 2 = destination
int top[3] = {-1, -1, -1}; // Top of each rod

pthread_mutex_t mutex[3]; // Mutex for each rod

void print_rods() {
    printf("\nCurrent state of rods:\n");
    for (int i = 0; i < 3; i++) {
        printf("Rod %d: ", i + 1);
        for (int j = 0; j <= top[i]; j++) {
            printf("%d ", rods[i][j]);
        }
        printf("\n");
    }
}

void* move_disk(void* arg) {
    int* params = (int*)arg;
    int n = params[0]; // The number of disks to move
    int from_rod = params[1]; // Source rod
    int to_rod = params[2]; // Destination rod
    int aux_rod = 3 - from_rod - to_rod; // Auxiliary rod

    if (n == 1) {
        pthread_mutex_lock(&mutex[from_rod]);
        pthread_mutex_lock(&mutex[to_rod]);

        printf("Moving disk %d from rod %d to rod %d.\n", rods[from_rod][top[from_rod]], to_rod + 1);
        rods[to_rod][++top[to_rod]] = rods[from_rod][top[from_rod]--];
        print_rods();

        pthread_mutex_unlock(&mutex[to_rod]);
        pthread_mutex_unlock(&mutex[from_rod]);
        return NULL;
    }

    int move_params1[3] = {n - 1, from_rod, aux_rod};
    int move_params2[3] = {1, from_rod, to_rod};
    int move_params3[3] = {n - 1, aux_rod, to_rod};

    move_disk(move_params1);
    move_disk(move_params2);
    move_disk(move_params3);

    return NULL;
}

void tower_of_hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    if (n == 1) {
        printf("Moving disk from rod %d to rod %d.\n", from_rod + 1, to_rod + 1);
    } else {
        tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
        printf("Moving disk from rod %d to rod %d.\n", from_rod + 1, to_rod + 1);
        tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
    }
}

void setup_rods() {
    for (int i = 0; i < 3; i++) {
        top[i] = -1;
        pthread_mutex_init(&mutex[i], NULL);
    }
    
    for (int i = num_disks; i >= 1; i--) {
        rods[0][++top[0]] = i; // Initialize source rod
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_disks>\n", argv[0]);
        return 1;
    }

    num_disks = atoi(argv[1]);
    if (num_disks < 1 || num_disks > MAX_DISK) {
        printf("Please enter a number of disks between 1 and %d.\n", MAX_DISK);
        return 1;
    }

    setup_rods();
    print_rods();
    
    pthread_t threads[3];

    int params[3][3];
    for (int i = 0; i < 3; i++) {
        params[i][0] = num_disks; // Number of disks
        params[i][1] = 0; // From rod
        params[i][2] = 2; // To rod (should be varied)
        pthread_create(&threads[i], NULL, move_disk, (void*)params[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All disks moved successfully!\n");

    for (int i = 0; i < 3; i++) {
        pthread_mutex_destroy(&mutex[i]);
    }

    return 0;
}