//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 1000

int cluster[MAX];

void kmeans(int data[], int n, int k)
{
    int i,j,c;
    int count=0;
    int min_dist=INT_MAX;
    int min_index=-1;
    for(i=0;i<k;i++)
    {
        cluster[i]=data[rand()%n];
    }
    for(i=0;i<n;i++)
    {
        cluster[i%k]=data[i];
    }
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            if(i!=j)
            {
                count=0;
                for(c=0;c<n;c++)
                {
                    if(cluster[i]==data[c]) count++;
                    if(cluster[j]==data[c]) count++;
                }
                if(count>0)
                {
                    if(min_dist>abs(i-j))
                    {
                        min_dist=abs(i-j);
                        min_index=i;
                    }
                }
            }
        }
    }
    int temp;
    for(i=0;i<k;i++)
    {
        if(i==min_index) continue;
        temp=cluster[i];
        cluster[i]=cluster[min_index];
        cluster[min_index]=temp;
    }
}

void kmeans_sort(int data[], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(data[i]>data[j])
            {
                int temp=data[i];
                data[i]=data[j];
                data[j]=temp;
            }
        }
    }
}

int main()
{
    int i,n,k;
    int data[MAX];
    printf("Enter the number of data points: ");
    scanf("%d",&n);
    printf("Enter the data points:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&data[i]);
    }
    printf("Enter the number of clusters: ");
    scanf("%d",&k);
    kmeans_sort(data,n);
    kmeans(data,n,k);
    printf("The clusters are:\n");
    for(i=0;i<k;i++)
    {
        printf("%d ",cluster[i]);
    }
    return 0;
}