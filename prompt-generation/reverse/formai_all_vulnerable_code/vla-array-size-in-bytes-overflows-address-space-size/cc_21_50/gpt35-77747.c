//FormAI DATASET v1.0 Category: Data mining ; Style: safe
#include<stdio.h>

int main() {
    // Initializing variables
    int size, support;
    printf("Enter the number of transactions: ");
    scanf("%d",&size);
    printf("Enter the minimum support count: ");
    scanf("%d",&support);
    int transactions[size][5];
    printf("Enter the transactions (1 for present, 0 for absent):\n");
    for(int i=0;i<size;i++){
        printf("Transaction %d: ",i+1);
        for(int j=0;j<5;j++){
            scanf("%d",&transactions[i][j]);
        }
    }

    // Creating frequency table of size 2-items
    int freq_table[5][5] = {0};
    for(int i=0;i<size;i++){
        for(int j=0;j<5;j++){
            if(transactions[i][j] == 1){
                for(int k=j+1;k<5;k++){
                    if(transactions[i][k] == 1){
                        freq_table[j][k] += 1;
                    }
                }
            }
        }
    }

    // Retrieving frequent itemsets of size 2
    printf("Frequent itemsets of size 2 with minimum support count of %d:\n",support);
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(freq_table[i][j] >= support){
                printf("{%d, %d} : %d\n",i+1,j+1,freq_table[i][j]);
            }
        }
    }

    // Creating frequency table of size 3-items
    int freq_table_3[5][5][5] = {0};
    for(int i=0;i<size;i++){
        for(int j=0;j<5;j++){
            if(transactions[i][j] == 1){
                for(int k=j+1;k<5;k++){
                    if(transactions[i][k] == 1){
                        for(int l=k+1;l<5;l++){
                            if(transactions[i][l] == 1){
                                freq_table_3[j][k][l] += 1;
                            }
                        }
                    }
                }
            }
        }
    }

    // Retrieving frequent itemsets of size 3
    printf("Frequent itemsets of size 3 with minimum support count of %d:\n",support);
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            for(int k=j+1;k<5;k++){
                if(freq_table_3[i][j][k] >= support){
                    printf("{%d, %d, %d} : %d\n",i+1,j+1,k+1,freq_table_3[i][j][k]);
                }
            }
        }
    }

    return 0;
}