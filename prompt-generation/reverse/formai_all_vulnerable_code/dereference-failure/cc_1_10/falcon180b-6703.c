//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: mathematical
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000
#define PI 3.14159265358979323846

typedef struct node{
    double value;
    struct node *next;
}node;

typedef struct circuit{
    double R,C;
    node *head;
}circuit;

node *create_node(double value){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->value = value;
    newnode->next = NULL;
    return newnode;
}

void add_node(node **head, double value){
    node *newnode = create_node(value);
    newnode->next = *head;
    *head = newnode;
}

void print_circuit(circuit *ckt){
    printf("Circuit Parameters:\n");
    printf("R = %lf ohms\n",ckt->R);
    printf("C = %lf farads\n",ckt->C);
    printf("Initial Conditions:\n");
    printf("Vc = %lf volts\n",ckt->head->value);
    printf("Ic = %lf amperes\n",ckt->head->value/ckt->R);
}

void evaluate_circuit(circuit *ckt){
    node *temp = ckt->head;
    while(temp!= NULL){
        temp->value += temp->value/ckt->C;
        temp = temp->next;
    }
}

void simulate_circuit(circuit *ckt, double t){
    int n = 0;
    double dt = t/MAX;
    printf("Time\tVc\tIc\n");
    for(n=0;n<=MAX;n++){
        evaluate_circuit(ckt);
        printf("%lf\t%lf\t%lf\n",n*dt,ckt->head->value,ckt->head->value/ckt->R);
    }
}

int main(){
    circuit ckt;
    ckt.R = 1000;
    ckt.C = 0.001;
    ckt.head = (node*)malloc(sizeof(node));
    ckt.head->value = 10;
    add_node(&(ckt.head),0);
    simulate_circuit(&ckt,0.1);
    return 0;
}