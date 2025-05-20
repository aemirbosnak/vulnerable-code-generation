//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: creative
#include<stdio.h>

int main(){

    int n, m, i, j, sum=0;

    printf("Enter The Number Of Items: ");
    scanf("%d",&n);

    printf("Enter The Maximum Weight Allowed: ");
    scanf("%d",&m);

    int weight[n], value[n], ratio[n];

    printf("Enter The Weight And Value Of Each Item: \n");

    for(i=0;i<n;i++){
        printf("Weight[%d]: ",i);
        scanf("%d",&weight[i]);
        printf("Value[%d]: ",i);
        scanf("%d",&value[i]);
        ratio[i] = value[i]/weight[i]; //calculate the value/weight ratio
    }

    // bubble sorting the items according to their ratios in descending order
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(ratio[j]<ratio[j+1]){
                int temp = ratio[j+1];
                ratio[j+1] = ratio[j];
                ratio[j] = temp;

                temp = weight[j+1];
                weight[j+1] = weight[j];
                weight[j] = temp;

                temp = value[j+1];
                value[j+1] = value[j];
                value[j] = temp;
            }
        }
    }

    //Selecting Items
    printf("Selected Items:\n");
    for(i=0;i<n;i++){
        if(m>=weight[i]){
            m -= weight[i];
            printf("\nItem[%d]: Weight=%d Value=%d",i+1,weight[i],value[i]);
            sum += value[i]; //adding the value of the selected item 
        }
        else{
            float fraction = (float)m/weight[i]; //calculating the fraction of the last item that can be selected
            printf("\nItem[%d]: Weight=%d Value=%f",i+1,m,fraction*value[i]);
            sum += fraction*value[i]; //adding the value of the selected item in proportion to the fraction of the item selected
            break;
        }
    }

    printf("\nTotal Value: %d\n",sum); //Printing The Total Value

    return 0;
}