//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: beginner-friendly
#include<stdio.h>
int main()
{
    int n,i,x,j,quantum,sum=0,count=0,temp;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int bt[n],wt[n],tat[n],at[n],rt[n],p[n],ct[n];
    printf("Enter burst time and arrival time for each process:\n");
    for(i=0;i<n;i++)
    {
        printf("Process %d: ",i+1);
        printf("Burst time: ");
        scanf("%d",&bt[i]);
        printf("Arrival time: ");
        scanf("%d",&at[i]);
        p[i]=i+1;
        rt[i]=bt[i];
        ct[i]=0;
        wt[i]=0;
    }
    printf("Enter quantum time: ");
    scanf("%d",&quantum);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(at[i]>at[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    }
    x=0;
    printf("Gantt Chart:\n");
    while(1)
    {
        int flag=1;
        for(i=0;i<n;i++)
        {
            if(rt[i]>0 && at[i]<=x)
            {
                flag=0;
                if(rt[i]>quantum)
                {
                    x+=quantum;
                    rt[i]-=quantum;
                    printf("P%d -> ",p[i]);
                }
                else
                {
                    x+=rt[i];
                    ct[i]=x;
                    tat[i]=ct[i]-at[i];
                    wt[i]=tat[i]-bt[i];
                    rt[i]=0;
                    printf("P%d -> ",p[i]);
                    sum+=wt[i];
                    count++;
                }
            }
        }
        if(flag)
        {
            int min=9999,index=0;
            for(i=0;i<n;i++)
            {
                if(at[i]<min && rt[i]>0)
                {
                    min=at[i];
                    index=i;
                }
            }
            x=at[index];
        }
        if(count==n)
            break;
    }
    printf("\n\nProcess     Burst Time    Arrival Time     Waiting Time    Turnaround Time    Completion Time\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p[i],bt[i],at[i],wt[i],tat[i],ct[i]);
    }
    printf("\nAverage Waiting Time: %0.2f",(float)sum/n);
    return 0;
}