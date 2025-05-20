//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_COMP 1000

struct component{
    int type;
    int num_pins;
    double val[3];
    struct component *next;
};

struct circuit{
    int num_comps;
    struct component *head;
};

void add_component(struct circuit *ckt, int type, int num_pins, double val1, double val2, double val3){
    struct component *new_comp = (struct component *)malloc(sizeof(struct component));
    new_comp->type = type;
    new_comp->num_pins = num_pins;
    new_comp->val[0] = val1;
    new_comp->val[1] = val2;
    new_comp->val[2] = val3;
    new_comp->next = NULL;

    if(ckt->head == NULL){
        ckt->head = new_comp;
    }
    else{
        struct component *temp = ckt->head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = new_comp;
    }

    ckt->num_comps++;
}

void print_ckt(struct circuit *ckt){
    struct component *temp = ckt->head;
    int i;
    while(temp!= NULL){
        printf("Component %d has %d pins and values %lf, %lf, %lf\n", temp->type, temp->num_pins, temp->val[0], temp->val[1], temp->val[2]);
        temp = temp->next;
    }
}

int main(){
    int i;
    struct circuit ckt;
    ckt.num_comps = 0;

    for(i = 0; i < MAX_COMP; i++){
        add_component(&ckt, i, 2, 1.0, 2.0, 3.0);
    }

    printf("The circuit has %d components:\n", ckt.num_comps);
    print_ckt(&ckt);

    return 0;
}