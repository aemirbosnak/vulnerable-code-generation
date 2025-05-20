//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: systematic
#include<stdio.h>

//function to sort the jobs based on their profit
void sortByProfit(int profits[], int deadlines[], int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(profits[j]>profits[i]){
                //sort profits
                temp = profits[i];
                profits[i] = profits[j];
                profits[j] = temp;
                
                //sort deadlines
                temp = deadlines[i];
                deadlines[i] = deadlines[j];
                deadlines[j] = temp;
            }
        }
    }
}

//function to get the maximum deadline from all jobs
int getMaxDeadline(int deadlines[], int n){
    int max=deadlines[0];
    int i;
    for(i=1;i<n;i++){
        if(deadlines[i]>max){
            max = deadlines[i];
        }
    }
    return max;
}

//function to perform job sequencing
void jobSequencing(int profits[], int deadlines[], int n){
    int maxDeadline = getMaxDeadline(deadlines, n);
    int i,j;
    int slots[maxDeadline];
    
    //initialize all slots to 0
    for(i=0;i<maxDeadline;i++){
        slots[i] = 0;
    }
    
    //sort the jobs by their profit in descending order
    sortByProfit(profits, deadlines, n);
    
    //fill the slots with jobs
    for(i=0;i<n;i++){
        for(j=deadlines[i]-1;j>=0;j--){
            if(slots[j]==0){
                slots[j] = i+1;
                break;
            }
        }
    }
    
    //display the job sequence
    printf("Job Sequence: ");
    for(i=0;i<maxDeadline;i++){
        if(slots[i]!=0){
            printf("J%d ",slots[i]);
        }
    }
}

//main function
int main(){
    int n;
    
    printf("Enter the number of jobs: ");
    scanf("%d",&n);
    
    int profits[n], deadlines[n];
    
    int i;
    //input the job details - profit and deadline
    for(i=0;i<n;i++){
        printf("Enter the profit and deadline for job %d: ",i+1);
        scanf("%d %d",&profits[i],&deadlines[i]);
    }
    
    //perform job sequencing
    jobSequencing(profits, deadlines, n);
    
    return 0;
}