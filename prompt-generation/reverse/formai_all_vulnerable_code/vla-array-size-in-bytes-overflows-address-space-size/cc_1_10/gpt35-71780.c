//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

void fcfs(int n, int at[], int bt[], int ct[], int tat[], int wt[])
{
    int i;
    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];
    for(i=1;i<n;i++)
    {
        ct[i] = ct[i-1] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
}

void sjf(int n, int at[], int bt[], int ct[], int tat[], int wt[])
{
    int i,j,min,pos,temp;
    int bt_copy[n];
    memcpy(bt_copy, bt, n * sizeof(int));
    memset(pos, -1, n);
    for(i=0;i<n;i++)
    {
        min = 9999;
        for(j=0;j<n;j++)
        {
            if(at[j]<=i && bt_copy[j]<min && bt_copy[j]!=0)
            {
                min = bt_copy[j];
                pos = j;
            }
        }
        i+=bt_copy[pos]-1;
        ct[pos] = i+1;
        tat[pos] = ct[pos]-at[pos];
        wt[pos] = tat[pos]-bt[pos];
        bt_copy[pos] = 0;
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
}

void rr(int n, int at[], int bt[], int ct[], int tat[], int wt[], int quantum)
{
    int i,time=0,rem_bt[n],done=0;
    memset(rem_bt, 0, n);
    memcpy(rem_bt, bt, n * sizeof(int));
    while(done!=1)
    {
        done = 1;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time)
            {
                if(rem_bt[i]>0)
                {
                    done = 0;
                    if(rem_bt[i]>quantum)
                    {
                        time+=quantum;
                        rem_bt[i]-=quantum;
                    }
                    else
                    {
                        time+=(rem_bt[i]);
                        ct[i]=time;
                        tat[i]=ct[i]-at[i];
                        wt[i]=tat[i]-bt[i];
                        rem_bt[i]=0;
                    }
                }
            }
            else
            {
                time = at[i];
                i--;
            }
        }
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
}

int main()
{
    int i,n,at[50],bt[50],ct[50],tat[50],wt[50],quantum;
    int choice;
    printf("\nEnter the number of processes: ");
    scanf("%d",&n);
    printf("\nEnter the arrival time and burst time respectively:\n");
    for(i=0;i<n;i++)
    {
        printf("\nProcess P%d:\n",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }
    printf("\nChoose a Scheduling Algorithm:");
    printf("\n1. First-Come, First-Serve");
    printf("\n2. Shortest Job First");
    printf("\n3. Round Robin");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: fcfs(n, at, bt, ct, tat, wt);
                break;
        case 2: sjf(n, at, bt, ct, tat, wt);
                break;
        case 3: printf("\nEnter time quantum for Round Robin Algorithm: ");
                scanf("%d",&quantum);
                rr(n, at, bt, ct, tat, wt, quantum);
                break;
        default: printf("\nInvalid choice.");
    }
    return 0;
}