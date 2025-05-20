//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Function to sort items in increasing order of their ratios
void sort(double w[], double p[], double ratio[], int n) {
    double temp;
    int i, j;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(ratio[i] < ratio[j]){
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
                temp = w[j];
                w[j] = w[i];
                w[i] = temp;
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
}

// Function to find maximum profit using greedy approach
double maxProfit(double w[], double p[], double capacity, int n) {
    double totalProfit = 0, x[n], ratio[n];
    int i;
    for(i=0; i<n; i++){
        ratio[i] = (double)p[i] / (double)w[i];
        x[i] = 0.0;
    }
    sort(w, p, ratio, n);
    for(i=0; i<n; i++){
        if(w[i] <= capacity){
            x[i] = 1.0;
            capacity -= w[i];
            totalProfit += p[i];
        }
        else{
            x[i] = capacity / w[i];
            totalProfit += x[i] * p[i];
            break;
        }
    }
    return totalProfit;
}

int main() {
    int n, i;
    double capacity, *w, *p, max_profit;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    w = (double*)malloc(n * sizeof(double));
    p = (double*)malloc(n * sizeof(double));
    printf("Enter the weights of the items: \n");
    for(i=0;i<n;i++){
        scanf("%lf",&w[i]);
    }
    printf("Enter the profits of the items: \n");
    for(i=0;i<n;i++){
        scanf("%lf",&p[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%lf",&capacity);
    max_profit = maxProfit(w, p, capacity, n);
    printf("Maximum Profit: %.2lf\n", max_profit);
    return 0;
}