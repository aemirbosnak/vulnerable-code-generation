//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: genious
/* This is a classical circuit simulator 
   that takes in a circuit netlist and simulates
   the behavior of the components in the circuit */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXCOMP 100
#define MAXNODE 50

/* Circuit Component Structures */
typedef struct {
    int node[2];
    char type[5];
    double value;
} Component;

/* Main Simulation Function */
void simulate(char *netlist_file){

    /* Open the Netlist file and read it into memory */
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(netlist_file, "r");
    if (fp == NULL){
        printf("\nError Opening Netlist File!");
        exit(EXIT_FAILURE);
    }

    Component c[MAXCOMP];
    int comp_count = 0, node_count = 0;

    while ((read = getline(&line, &len, fp)) != -1) {

        /* Tokenize each line of the netlist file */
        char *token = strtok(line, " ");
        
        if (strcmp(token, "R")==0 || strcmp(token, "C")==0 || strcmp(token, "L")==0){
            /* Component is Resistor, Capacitor or Inductor */
            c[comp_count].node[0] = atoi(strtok(NULL, " "));
            c[comp_count].node[1] = atoi(strtok(NULL, " "));
            strcpy(c[comp_count].type, token);
            c[comp_count].value = atof(strtok(NULL, " "));
            comp_count++;
        }
        else if (strcmp(token, ".dc")==0){
            /* DC Sweep Simulation */
            double start = atof(strtok(NULL, " "));
            double end = atof(strtok(NULL, " "));
            double increment = atof(strtok(NULL, " "));
            
            for (double i = start; i<=end; i+=increment){
                printf("V1 %d %d %f\n", MAXNODE-1, 0, i);
                for (int j=0; j<comp_count; j++){
                    printf("%s %d %d %f\n", c[j].type, c[j].node[0], 
                                            c[j].node[1], c[j].value);
                }
                node_count++;
                printf(".end\n");
            }
        }
        else if (strcmp(token, ".ac")==0){
            /* AC Sweep Simulation */
            double start = atof(strtok(NULL, " "));
            double end = atof(strtok(NULL, " "));
            double increment = atof(strtok(NULL, " "));
            double freq = atof(strtok(NULL, " "));
            
            for (double i = start; i<=end; i+=increment){
                printf("V1 %d %d SINE(0 %f %f)\n", MAXNODE-1, 0, i, freq);
                for (int j=0; j<comp_count; j++){
                    printf("%s %d %d %f\n", c[j].type, c[j].node[0], 
                                            c[j].node[1], c[j].value);
                }
                node_count++;
                printf(".end\n");       
            }
        }
    }

    /* Close the Netlist file and free memory */
    fclose(fp);
    if (line)
        free(line);
}

int main(){

    /* Call the Simulation Function */
    simulate("netlist.txt");
    
    return 0;
}