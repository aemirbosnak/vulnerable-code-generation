//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(0));
    int playerCount,bugCount;
    char playerName[20];

    printf("Enter the number of players: ");
    scanf("%d",&playerCount);

    printf("Enter the number of bugs: ");
    scanf("%d",&bugCount);

    int playerId[playerCount];

    for(int i=0;i<playerCount;i++){
        printf("Enter the player %d name: ",i+1);
        scanf("%s",playerName);
        playerId[i] = rand()%100;
        printf("Player ID for %s is %d\n",playerName,playerId[i]);
    }

    printf("\nGame started...\n");

    int level = 1;
    int score[playerCount];
    int playerBugs[playerCount][bugCount];

    for(int i=0;i<playerCount;i++){
        for(int j=0;j<bugCount;j++){
            playerBugs[i][j] = rand()%100;
        }
    }

    while(level<=5){

        printf("\nLevel %d started...\n",level);

        for(int i=0;i<playerCount;i++){

            int bugCaught = 0;
            printf("%s's turn...\n",playerName);

            for(int j=0;j<bugCount;j++){

                printf("Did you catch bug %d? (1=Yes/0=No): ",j+1);
                scanf("%d",&playerBugs[i][j]);

                if(playerBugs[i][j] == 1){
                    bugCaught++;
                }

            }

            score[i] = bugCaught*10;
            printf("Score: %d\n",score[i]);

        }

        level++;
    }

    printf("\nGame Over!\n");

    for(int i=0;i<playerCount;i++){

        printf("\nPlayer name: %s\n",playerName);
        printf("Player ID: %d\n",playerId[i]);
        printf("Total score: %d\n",score[i]);

        for(int j=0;j<bugCount;j++){
            if(playerBugs[i][j] == 1){
                printf("Bug %d was caught.\n",j+1);
            }
        }
    }

    return 0;
}