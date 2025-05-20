//FormAI DATASET v1.0 Category: Data mining ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int** createDataset(int numRows, int numCols) {
	// allocating memory for dataset
    int** dataset = (int**)malloc(numRows * sizeof(int *));
    for (int i = 0; i < numRows; i++)
         dataset[i] = (int*)malloc(numCols * sizeof(int));

    // initializing dataset
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            dataset[i][j] = rand() % 100;
        }
    }
    return dataset;
}

double** normalizeDataset(int** dataset, int numRows, int numCols){
    // allocating memory for normalizedDataset
    double** normalizedDataset = (double**)malloc(numRows * sizeof(double *));
    for (int i = 0; i < numRows; i++)
         normalizedDataset[i] = (double*)malloc(numCols * sizeof(double));

    for(int i=0; i<numCols; i++){
        int min = 100, max = 0;
        for(int j=0; j<numRows; j++){
            if(dataset[j][i]<min) min = dataset[j][i];
            if(dataset[j][i]>max) max = dataset[j][i];
        }
        for(int j=0; j<numRows; j++){
            normalizedDataset[j][i] = (double)(dataset[j][i]-min)/(double)(max-min);
        }
    }
    return normalizedDataset;
}

void printDataset(double** dataset, int numRows, int numCols){
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            printf("%.2f ", dataset[i][j]);
        }
        printf("\n");
    }
}

int main(){
	// creating dataset
    int numRows = 10;
    int numCols = 5;
    int** dataset = createDataset(numRows, numCols);
    
    // normalizing dataset
    double** normalizedDataset = normalizeDataset(dataset, numRows, numCols);
    printf("Normalized Dataset:\n");
    printDataset(normalizedDataset, numRows, numCols);

    // freeing memory
    for (int i = 0; i < numRows; i++){
        free(dataset[i]);
        free(normalizedDataset[i]);
    }
    free(dataset);
    free(normalizedDataset);
    return 0;
}