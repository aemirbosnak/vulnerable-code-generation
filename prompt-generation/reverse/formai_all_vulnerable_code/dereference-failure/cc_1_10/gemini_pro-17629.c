//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char* name;
    int num_inputs;
    int num_outputs;
    int** truth_table;
}gate;

gate* create_gate(char* name,int num_inputs,int num_outputs){
    gate* new_gate=(gate*)malloc(sizeof(gate));
    new_gate->name=strdup(name);
    new_gate->num_inputs=num_inputs;
    new_gate->num_outputs=num_outputs;
    new_gate->truth_table=(int**)malloc(sizeof(int*)*(1<<num_inputs));
    for(int i=0;i<(1<<num_inputs);i++){
        new_gate->truth_table[i]=(int*)malloc(sizeof(int)*num_outputs);
    }
    return new_gate;
}

void destroy_gate(gate* gate){
    free(gate->name);
    for(int i=0;i<(1<<gate->num_inputs);i++){
        free(gate->truth_table[i]);
    }
    free(gate->truth_table);
    free(gate);
}

void print_gate(gate* gate){
    printf("Gate: %s\n",gate->name);
    printf("Number of inputs: %d\n",gate->num_inputs);
    printf("Number of outputs: %d\n",gate->num_outputs);
    printf("Truth table:\n");
    for(int i=0;i<(1<<gate->num_inputs);i++){
        for(int j=0;j<gate->num_outputs;j++){
            printf("%d ",gate->truth_table[i][j]);
        }
        printf("\n");
    }
}

int main(){
    gate* and_gate=create_gate("AND",2,1);
    and_gate->truth_table[0][0]=0;
    and_gate->truth_table[1][0]=0;
    and_gate->truth_table[2][0]=0;
    and_gate->truth_table[3][0]=1;
    print_gate(and_gate);
    destroy_gate(and_gate);
    return 0;
}