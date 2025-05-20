//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Structure for storing user data
struct user
{
    char name[50];         //Name of the user
    int age;               //Age of the user
    float height;          //Height of the user
    float weight;          //Weight of the user
    float target_weight;   //Target weight of the user
    int steps;             //Number of steps the user has walked
};

//Function to add a new user
void add_user(struct user *users, int *count)
{
    printf("Enter name: ");
    scanf("%s", users[*count].name);
    printf("Enter age: ");
    scanf("%d", &users[*count].age);
    printf("Enter height (in meters): ");
    scanf("%f", &users[*count].height);
    printf("Enter weight (in kilograms): ");
    scanf("%f", &users[*count].weight);
    printf("Enter target weight (in kilograms): ");
    scanf("%f", &users[*count].target_weight);
    printf("User added successfully!\n");

    //Setting initial step count as 0 for new user
    users[*count].steps = 0;
    (*count)++;  //Increasing user count
}

//Function to get user details
void get_user_details(struct user *users, int count)
{
    int i;
    char name[50];
    printf("Enter name of user: ");
    scanf("%s", name);
    for(i=0; i<count; i++)
    {
        //Checking if the entered name matches any user
        if(strcmp(name, users[i].name) == 0)
        {
            printf("\nName: %s",users[i].name);
            printf("\nAge: %d",users[i].age);
            printf("\nHeight: %.2f meters",users[i].height);
            printf("\nWeight: %.2f kilograms",users[i].weight);
            printf("\nTarget weight: %.2f kilograms",users[i].target_weight);
            printf("\nSteps walked: %d\n",users[i].steps);
            return;
        }
    }
    printf("No user found with the given name.\n");
}

//Function to count number of steps
void count_steps(struct user *users, int count)
{
    int i;
    char name[50];
    int steps;
    printf("Enter name of user: ");
    scanf("%s", name);
    for(i=0; i<count; i++)
    {
        //Checking if the entered name matches any user
        if(strcmp(name, users[i].name) == 0)
        {
            printf("Enter number of steps walked: ");
            scanf("%d", &steps);
            users[i].steps += steps;    //Adding the new steps to the existing step count
            printf("Steps added successfully!\n");
            return;
        }
    }
    printf("No user found with the given name.\n");
}

//Function to calculate body mass index of a user
float calc_BMI(float height, float weight)
{
    return weight / (height * height);
}

//Function to display user report
void show_report(struct user *users, int count)
{
    int i;
    float BMI;
    printf("Enter name of user: ");
    char name[50];
    scanf("%s", name);
    for(i=0; i<count; i++)
    {
        //Checking if the entered name matches any user
        if(strcmp(name, users[i].name) == 0)
        {
            //Calculating BMI for the user
            BMI = calc_BMI(users[i].height, users[i].weight);
            printf("\nName: %s",users[i].name);
            printf("\nAge: %d",users[i].age);
            printf("\nHeight: %.2f meters",users[i].height);
            printf("\nWeight: %.2f kilograms",users[i].weight);
            printf("\nTarget weight: %.2f kilograms",users[i].target_weight);
            printf("\nSteps walked: %d",users[i].steps);
            printf("\nBMI: %.2f", BMI);
            //Checking if the user needs to lose or gain weight
            if(users[i].weight > users[i].target_weight)
            {
                printf("\nNeed to lose %.2f kilograms.\n", users[i].weight - users[i].target_weight);
            }
            else if(users[i].weight < users[i].target_weight)
            {
                printf("\nNeed to gain %.2f kilograms.\n", users[i].target_weight - users[i].weight);
            }
            else
            {
                printf("\nWeight is on target.\n");
            }
            return;
        }
    }
    printf("No user found with the given name.\n");
}

void main()
{
    int option, count=0;
    struct user *users;
    users = (struct user*) malloc(50*sizeof(struct user));   //Creating space in memory for storing 50 users

    do
    {
        printf("\nChoose an option:");
        printf("\n1. Add user");
        printf("\n2. Get user details");
        printf("\n3. Count steps");
        printf("\n4. Show report");
        printf("\n0. Exit\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                add_user(users, &count);
                break;
            case 2:
                get_user_details(users, count);
                break;
            case 3:
                count_steps(users, count);
                break;
            case 4:
                show_report(users, count);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }while(option != 0);
}