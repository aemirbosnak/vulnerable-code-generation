//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
 
//Defining structure for medical store details
 
struct medicalStore
{
    char medName[MAX];
    float medPrice;
    int medQuantity;
};
 
//Sorting function that sorts the medical stores on the basis of stock 
 
void sortByStock(struct medicalStore *med, int n)
{
    int i, j;
    struct medicalStore temp;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(med[i].medQuantity<med[j].medQuantity)
            {
                temp=med[i];
                med[i]=med[j];
                med[j]=temp;
            }
        }
    }
}
 
//Main function
 
int main()
{
    int n,i;
    float totalCost=0.0f;
    struct medicalStore *med;
    char ch[MAX];
    printf("\nEnter the number of medical stores: ");
    scanf("%d",&n);
    med=(struct medicalStore*)malloc(n*sizeof(struct medicalStore));
    for(i=0;i<n;i++)
    {
        printf("\nEnter details of medical store %d: ",i+1);
        printf("\nName: ");
        scanf("%s",med[i].medName);
        printf("\nPrice: ");
        scanf("%f",&med[i].medPrice);
        printf("\nQuantity: ");
        scanf("%d",&med[i].medQuantity);
    }
    //Sorting the medical stores on the basis of stock
    sortByStock(med,n);
    //Printing the sorted medical stores
    printf("\n****************************Medical Stores******************************\n");
    for(i=0;i<n;i++)
    {
        printf("%d.\nName: %s \nPrice: %.2f \nQuantity: %d \n",i+1,med[i].medName,med[i].medPrice,med[i].medQuantity);
        totalCost+=med[i].medPrice*med[i].medQuantity;
    }
    printf("\nTotal cost of all the medical stores: Rs.%.2f",totalCost);
    printf("\nEnter the name of the medical store you want to search: ");
    scanf("%s",ch);
    for(i=0;i<n;i++)
    {
        if(strcmp(med[i].medName,ch)==0)
        {
            printf("\nMedical store available in the list.");
            printf("\nName: %s \nPrice: Rs.%.2f \nQuantity: %d \n",med[i].medName,med[i].medPrice,med[i].medQuantity);
            break;
        }
    }
    if(i==n)
    {
        printf("\nSorry, the medical store you are searching is not available.");
    }
    return 0;
}