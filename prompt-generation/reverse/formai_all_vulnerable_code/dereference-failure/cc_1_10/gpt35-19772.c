//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// struct to hold the state of each tower
typedef struct {
    int num_disks;
    int *disks;
    pthread_mutex_t lock;
} Tower;

// function to create a new tower with `num_disks`
Tower new_tower(int num_disks) {
    Tower tower;
    tower.num_disks = num_disks;
    tower.disks = malloc(num_disks * sizeof(int));
    for (int i = 0; i < num_disks; i++) {
        tower.disks[i] = num_disks - i;
    }
    pthread_mutex_init(&tower.lock, NULL);
    return tower;
}

// function to print out the current state of the towers
void print_towers(Tower *towers, int num_towers) {
    for (int i = 0; i < num_towers; i++) {
        Tower tower = towers[i];
        printf("Tower %d: ", i);
        for (int j = 0; j < tower.num_disks; j++) {
            printf("%d ", tower.disks[j]);
        }
        printf("\n");
    }
}

// function to move a disk from one tower to another
void move_disk(Tower *source_tower, Tower *dest_tower) {
    int disk = source_tower->disks[source_tower->num_disks - 1];
    source_tower->num_disks--;
    dest_tower->disks[dest_tower->num_disks] = disk;
    dest_tower->num_disks++;
}

// recursive function to move `num_disks` from `source` to `dest` using `temp` as temporary tower
void move_tower(int num_disks, Tower *source, Tower *dest, Tower *temp) {
    if (num_disks == 1) {
        pthread_mutex_lock(&source->lock);
        pthread_mutex_lock(&dest->lock);
        move_disk(source, dest);
        pthread_mutex_unlock(&source->lock);
        pthread_mutex_unlock(&dest->lock);
        return;
    }
    move_tower(num_disks - 1, source, temp, dest);
    pthread_mutex_lock(&source->lock);
    pthread_mutex_lock(&dest->lock);
    move_disk(source, dest);
    pthread_mutex_unlock(&source->lock);
    pthread_mutex_unlock(&dest->lock);
    move_tower(num_disks - 1, temp, dest, source);
}

// thread function to move a tower
void *move_tower_async(void *args) {
    int *int_args = (int *) args;
    int num_disks = int_args[0];
    Tower *source = (Tower *) int_args[1];
    Tower *dest = (Tower *) int_args[2];
    Tower *temp = (Tower *) int_args[3];
    move_tower(num_disks, source, dest, temp);
    return NULL;
}

int main() {
    int num_disks = 5;
    int num_towers = 3;
    Tower towers[3];
    for (int i = 0; i < num_towers; i++) {
        towers[i] = new_tower(num_disks);
    }
    printf("Initial Towers:\n");
    print_towers(towers, num_towers);

    // initialize arguments array for threads
    int args[4][4] = {
        {num_disks, &towers[0], &towers[1], &towers[2]},
        {num_disks, &towers[0], &towers[2], &towers[1]},
        {num_disks, &towers[1], &towers[2], &towers[0]},
        {num_disks, &towers[1], &towers[0], &towers[2]}
    };

    pthread_t threads[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, move_tower_async, (void *) args[i]);
    }
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final Towers:\n");
    print_towers(towers, num_towers);

    for (int i = 0; i < num_towers; i++) {
        pthread_mutex_destroy(&towers[i].lock);
        free(towers[i].disks);
    }

    return 0;
}