//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n,i,j,k,flag=0,maxcount=0;
    float e,sigma,distance,epsilon;

    printf("Enter the number of elements : ");
    scanf("%d",&n);

    float X[n][2];
    int cluster_assignment[n];
    int NOISE[n];

    printf("Enter the elements : ");
    for(i=0;i<n;i++)
    {
        cluster_assignment[i]=0;
        NOISE[i]=0;
        scanf("%f %f",&X[i][0],&X[i][1]);
    }

    printf("Enter the value of 'Eps' : ");
    scanf("%f",&e);

    printf("Enter the value of 'MinPts' : ");
    scanf("%d",&k);

    sigma=e*e;
    for(i=0;i<n;i++)
    {
        int count=0;
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                distance=(pow((X[i][0]-X[j][0]),2) + pow((X[i][1]-X[j][1]),2));
                if(distance<=sigma)
                    count++;
            }
        }
        if(count>=k)
        {
            cluster_assignment[i]=++flag;
            if(count>maxcount)
                maxcount=count;
        }
    }

    for(i=0;i<n;i++)
    {
        if(cluster_assignment[i]==0)
        {
            int count=0;
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    distance=(pow((X[i][0]-X[j][0]),2) + pow((X[i][1]-X[j][1]),2));
                    if(distance<=sigma && cluster_assignment[j]!=0)
                    {
                        int present=0;
                        for(int a=0;a<count;a++)
                        {
                            if(NOISE[a]==cluster_assignment[j])
                            {
                                present=1;
                                break;
                            }
                        }
                        if(present==0)
                        {
                            NOISE[count++]=cluster_assignment[j];
                            if(count>maxcount)
                                break;
                        }
                    }
                }
            }
            if(count>0)
            {
                cluster_assignment[i]=-1;
                if(count>maxcount)
                    maxcount=count;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(cluster_assignment[i]==0)
        {
            int neighbor[k],count=0;
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    distance=(pow((X[i][0]-X[j][0]),2) + pow((X[i][1]-X[j][1]),2));
                    if(distance<=sigma)
                        neighbor[count++]=j;
                }
            }
            if(count>0)
            {
                cluster_assignment[i]=++flag;
                if(count>maxcount)
                    maxcount=count;
                for(j=0;j<count;j++)
                {
                    if(cluster_assignment[neighbor[j]]==-1)
                    {
                        cluster_assignment[neighbor[j]]=flag;
                        for(int a=0;a<n;a++)
                        {
                            if(cluster_assignment[a]==-1)
                            {
                                int present=0;
                                for(int b=0;b<count;b++)
                                {
                                    if((neighbor[b])==a)
                                    {
                                        present=1;
                                        break;
                                    }
                                }
                                if(present==1)
                                    cluster_assignment[a]=flag;
                            }
                        }
                    }
                    else if(cluster_assignment[neighbor[j]]==0)
                    {
                        cluster_assignment[neighbor[j]]=flag;
                    }
                }
            }
        }
    }

    printf("\nNumber of clusters : %d\n\n",flag);

    for(i=1;i<=flag;i++)
    {
        printf("Cluster %d : ",i);
        for(j=0;j<n;j++)
            if(cluster_assignment[j]==i)
                printf("%d ",j+1);
        printf("\n");
    }

    printf("\nOutliers : ");
    for(i=0;i<n;i++)
    {
        if(cluster_assignment[i]==-1)
            printf("%d ",i+1);
    }

    printf("\n\nMaximum points clustered together : %d\n",maxcount);

    return 0;
}