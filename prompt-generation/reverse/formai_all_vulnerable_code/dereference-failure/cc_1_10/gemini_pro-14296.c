//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_DISKS 10

typedef struct{
    int num_disks;
    int *disks;
} tower;

tower * create_tower(int num_disks){
    tower *t = (tower*)malloc(sizeof(tower));
    t->num_disks = num_disks;
    t->disks = (int*)malloc(sizeof(int) * num_disks);
    for(int i=0; i<num_disks; i++){
        t->disks[i] = num_disks - i;
    }
    return t;
}

void print_tower(tower *t){
    for(int i=0; i<t->num_disks; i++){
        printf("%d ", t->disks[i]);
    }
    printf("\n");
}

void move_disk(tower *from, tower *to){
    int disk = from->disks[from->num_disks-1];
    from->num_disks--;
    to->disks[to->num_disks++] = disk;
}

void tower_of_hanoi(tower *from, tower *to, tower *aux, int num_disks){
    if(num_disks == 0){
        return;
    }
    tower_of_hanoi(from, aux, to, num_disks-1);
    move_disk(from, to);
    tower_of_hanoi(aux, to, from, num_disks-1);
}

int main(){
    tower *t1 = create_tower(NUM_DISKS);
    tower *t2 = create_tower(0);
    tower *t3 = create_tower(0);

    printf("Initial state:\n");
    print_tower(t1);
    print_tower(t2);
    print_tower(t3);

    tower_of_hanoi(t1, t2, t3, NUM_DISKS);

    printf("Final state:\n");
    print_tower(t1);
    print_tower(t2);
    print_tower(t3);

    return 0;
}