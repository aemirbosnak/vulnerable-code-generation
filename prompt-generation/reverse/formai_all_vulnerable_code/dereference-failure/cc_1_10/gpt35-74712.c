//FormAI DATASET v1.0 Category: Digital Auction System ; Style: shape shifting
#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
    int bidder_id; 
    int bid_amount; 
    struct node *next; 
};

typedef struct node *NODEPTR;

NODEPTR getnode() 
{ 
    NODEPTR p; 
    p = (NODEPTR) malloc(sizeof(struct node)); 
    return p; 
} 

void freenode(NODEPTR p) 
{ 
    free(p); 
} 

NODEPTR insert(NODEPTR head,int id,int amt) 
{ 
    NODEPTR p,q; 
    q = getnode(); 
    q->bidder_id = id; 
    q->bid_amount= amt;
    p=head;
    
    if(head == NULL || amt >= head->bid_amount) 
    { 
        q->next = head; 
        head = q; 
    } 
    else 
    { 
        while(p->next != NULL && p->next->bid_amount > amt) 
            p=p->next; 
            
        q->next = p->next; 
        p->next = q; 
    } 
    return head; 
} 

void display(NODEPTR head) 
{ 
    NODEPTR p; 
    if(head == NULL) 
    { 
        printf("Auction is closed!\n"); 
        return; 
    } 
    printf("\nBid History\n"); 
    printf("Bidder  Bid Amount\n");
    for(p=head;p!=NULL;p=p->next) 
    { 
        printf(" %d\t  %d\n",p->bidder_id,p->bid_amount); 
    } 
    printf("\n"); 
} 

int main() 
{ 
    NODEPTR head; 
    head = NULL; 
    int choice, bid, bidder_id; 
    
    do 
    { 
        printf("Welcome to the Digital Auction System!\n"); 
        printf("1. Place a bid.\n"); 
        printf("2. Display bid history.\n"); 
        printf("3. Close the auction.\n"); 
        printf("Enter your choice: "); 
        scanf("%d",&choice); 
        
        switch(choice) 
        { 
            case 1: 
                printf("\nEnter Your Bidder ID:"); 
                scanf("%d", &bidder_id); 

                printf("Enter Your Bid Amount:"); 
                scanf("%d", &bid); 
                head=insert(head,bidder_id,bid); 
                printf("\nBid Placed successfully!\n"); 
                break; 

            case 2: 
                display(head); 
                break; 

            case 3: 
                display(head); 
                printf("\n\nAuction Closed!\nHighest Bid Amount = %d\n",head->bid_amount); 
                break; 

            default: 
                printf("Invalid choice!\n"); 
        } 
    }while (choice!=3); 
    return 0; 
}