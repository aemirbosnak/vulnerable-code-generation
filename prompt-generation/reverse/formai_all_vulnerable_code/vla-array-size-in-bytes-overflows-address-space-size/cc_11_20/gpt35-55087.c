//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include<stdio.h>
#include<string.h>

// defining structure to store player's expense data
struct player{
    char name[20];
    int expense;
};

int main(){
    // declaring variables
    int n, i, j, total_expense = 0;
    char c;
    printf("\nWelcome to the Multiplayer Expense Tracker\n");
    printf("==================================================\n");
    printf("Enter the number of players: ");
    scanf("%d",&n);
    struct player player_list[n];

    // taking input
    for(i=0;i<n;i++){
        printf("Enter the name of player %d: ",i+1);
        scanf("%s",player_list[i].name);
        player_list[i].expense = 0;
    }

    do{
        // displaying player list
        printf("\nExpense List\n");
        printf("==================================================\n");
        for(i=0;i<n;i++){
            printf("%d. %s (Expense: %d)\n",i+1,player_list[i].name,player_list[i].expense);
            total_expense += player_list[i].expense;
        }
        printf("==================================================\n");
        printf("Total Expense - %d\n",total_expense);
        // updating player's expenses
        printf("\nEnter the player number: ");
        scanf("%d",&i);
        if(i<=n){
            printf("Enter the expense amount: ");
            scanf("%d",&j);
            player_list[i-1].expense += j;
        }
        else{
            printf("Invalid player number!!!\n");
        }
        total_expense = 0;
        // asking for input to continue or exit
        printf("\nDo you want to update more expenses? (Y/N): ");
        scanf(" %c",&c);
        while(c!='Y' && c!='y' && c!='N' && c!='n'){
            printf("Invalid input!!!\n");
            printf("\nDo you want to update more expenses? (Y/N): ");
            scanf(" %c",&c);
        }
    }while(c=='Y' || c=='y');
    // displaying final expense list
    printf("\nFinal Expense List\n");
    printf("==================================================\n");
    for(i=0;i<n;i++){
        printf("%d. %s (Total Expense: %d)\n",i+1,player_list[i].name,player_list[i].expense);
    }
    printf("==================================================\n");
    printf("Total Expense - %d\n",total_expense);
    printf("\nThank you for using Multiplayer Expense Tracker!!!\n");
    return 0;
}