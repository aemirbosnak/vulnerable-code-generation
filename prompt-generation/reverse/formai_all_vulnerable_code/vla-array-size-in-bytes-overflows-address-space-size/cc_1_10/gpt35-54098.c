//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

//Defining a structure to hold Voter Information
struct voter{
    char name[50];
    int age;
    char sex;
    char address[100];
    char constituency[50];
    int voted;
};

//function to clear input buffer
void clear_input_buffer(){
    char c;
    while((c=getchar()) != '\n' && c!= EOF);
}

//function to check if voter is eligible to vote
int check_eligibility(int age){
    if(age>=18){
        return 1;
    }
    return 0;
}

//function to display voting options
void display_options(){
    printf("Please select your preferred party from the list below:\n");
    printf("1. Party A\n");
    printf("2. Party B\n");
    printf("3. Party C\n");
}

//function to update vote count
void update_vote_count(int party, int *vote_count){
    if(party == 1){
        *vote_count = *vote_count + 1;
    }
    else if(party == 2){
        *(vote_count+1) = *(vote_count+1) + 1;
    }
    else if(party == 3){
        *(vote_count+2) = *(vote_count+2) + 1;
    }
    else{
        printf("Invalid party selected!\n");
    }
}

int main(){

    int num_voters;
    printf("Enter the number of voters:\n");
    scanf("%d",&num_voters);

    //Creating an array of structures to hold voter information
    struct voter voters[num_voters];

    for(int i=0; i<num_voters; i++){
        printf("\n\nEnter details for voter %d:\n",i+1);

        //Clearing input buffer to avoid issues with scanf
        clear_input_buffer();

        printf("Name: ");
        fgets(voters[i].name,50,stdin);

        printf("Age: ");
        scanf("%d",&voters[i].age);

        printf("Sex(M/F): ");
        scanf(" %c",&voters[i].sex);

        printf("Address: ");
        clear_input_buffer();
        fgets(voters[i].address,100,stdin);

        printf("Constituency: ");
        fgets(voters[i].constituency,50,stdin);

        //Checking if voter is eligible to vote
        if(check_eligibility(voters[i].age)){
            voters[i].voted = 0;
        }
        else{
            voters[i].voted = 1;
            printf("Sorry, you are not eligible to vote!\n\n");
        }
    }

    //Initializing vote count
    int vote_count[3] = {0,0,0};

    //Loop to allow voting
    int flag = 1;
    while(flag){
        printf("\n\nEnter Voter ID to vote (Enter -1 to end voting):\n");
        int voter_id;
        scanf("%d",&voter_id);

        //Checking if voter ID is valid
        if(voter_id>=1 && voter_id<=num_voters){

            //Checking if voter has already voted
            if(voters[voter_id-1].voted == 1){
                printf("Sorry, you have already voted!\n\n");
            }

            else{
                //Displaying voting options
                display_options();

                int party;
                printf("\n\nSelect Party: ");
                scanf("%d",&party);

                //Updating vote count
                update_vote_count(party,vote_count);

                //Marking voter as voted
                voters[voter_id-1].voted = 1;

                printf("\n\nThank you for voting!\n\n");
            }
        }

        else if(voter_id == -1){
            flag = 0;
        }

        else{
            printf("Invalid Voter ID!\n");
        }
    }

    //Displaying final vote count
    printf("\n\nFinal Vote Count:\n");
    printf("Party A: %d votes\n",vote_count[0]);
    printf("Party B: %d votes\n",vote_count[1]);
    printf("Party C: %d votes\n",vote_count[2]);

    return 0;
}