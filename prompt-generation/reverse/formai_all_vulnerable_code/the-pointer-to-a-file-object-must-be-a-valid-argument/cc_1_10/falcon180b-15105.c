//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 118

//Structure for an element
typedef struct{
    char name[20];
    char symbol[4];
    int atomic_number;
    float atomic_mass;
    char category[20];
}element;

//Function to initialize elements
void init(){
    element periodic_table[SIZE];
    FILE *fp;
    char line[100];
    int i=0;

    //Opening the file
    fp=fopen("periodic_table.txt","r");

    //Reading the file
    while(fgets(line,sizeof(line),fp)!=NULL){
        //Splitting the line into values
        sscanf(line,"%s %s %d %f %s",periodic_table[i].name,periodic_table[i].symbol,&periodic_table[i].atomic_number,&periodic_table[i].atomic_mass,periodic_table[i].category);
        i++;
    }

    //Closing the file
    fclose(fp);
}

//Function to display elements
void display(element periodic_table[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("\n");
        printf("Name: %s\n",periodic_table[i].name);
        printf("Symbol: %s\n",periodic_table[i].symbol);
        printf("Atomic Number: %d\n",periodic_table[i].atomic_number);
        printf("Atomic Mass: %.2f\n",periodic_table[i].atomic_mass);
        printf("Category: %s\n\n",periodic_table[i].category);
    }
}

//Function to ask questions
int ask_question(element periodic_table[],int n){
    int correct=0;
    int user_answer;
    char user_input[20];
    srand(time(NULL));
    int random_index=rand()%n;

    printf("Question: What is the symbol of the element with atomic number %d?\n",periodic_table[random_index].atomic_number);
    scanf("%s",user_input);

    if(strcmp(user_input,periodic_table[random_index].symbol)==0){
        correct=1;
    }

    return correct;
}

//Main function
int main(){
    int n=0;
    element periodic_table[SIZE];
    init(periodic_table);
    n=SIZE;

    int score=0;
    int number_of_questions=5;

    printf("Welcome to the Periodic Table Quiz!\n\n");

    while(number_of_questions--){
        if(ask_question(periodic_table,n)){
            score++;
        }
    }

    printf("\nYour score is %d out of %d.\n",score,number_of_questions);

    return 0;
}