//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct item{
    char name[50];
    int bid;
    int bidder;
};

void display(struct item items[], int n){
    int i;
    printf("\nItem Name\tBid Amount\tBidder\n");
    for(i=0;i<n;i++){
        printf("%s\t%d\t%d\n",items[i].name,items[i].bid,items[i].bidder);
    }
}

void bid(struct item items[], int n, int id){
    char name[50];
    int bid,i;
    printf("\nEnter the item name to place a bid: ");
    scanf("%s",name);
    for(i=0;i<n;i++){
        if(strcmp(name,items[i].name)==0){
            printf("\nEnter your bid amount: ");
            scanf("%d",&bid);
            if(bid>items[i].bid){
                items[i].bid=bid;
                items[i].bidder=id;
            }
        }
    }
}

int main(){
    int n,i;
    printf("\nEnter the number of items for auction: ");
    scanf("%d",&n);
    struct item items[n];
    printf("\nEnter the item name and initial bid amount:\n");
    for(i=0;i<n;i++){
        scanf("%s %d",items[i].name,&items[i].bid);
    }
    int choice,id;
    while(1){
        printf("\n\nDigital Auction System\n");
        printf("\n1.Display Items\n2.Place Bid\n3.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                display(items,n);
                break;
            case 2:
                printf("\nEnter your ID: ");
                scanf("%d",&id);
                bid(items,n,id);
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}