//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,j,k,n,a=0,b=0,count=0,d,e,f,q=0,r=0,s=0,t=0;
    int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
    srand(time(0));
    
    printf("\n\n---------------------------------------\n");
    printf("SIMULATION OF AN ELEVATOR SYSTEM IN C\n");
    printf("---------------------------------------\n\n");
    
    printf("Enter the total number of floors in the building: ");
    scanf("%d",&n);
    
    printf("\nEnter the total number of people waiting on each floor:\n");
    
    //Generating random number of people waiting on each floor
    int waiting[n];
    for(i=0;i<n;i++)
    {
        waiting[i]=(rand()%10)+1;
        printf("Floor %d: %d\n",i+1,waiting[i]);
    }
    printf("\n");
    
    
    //Elevator at floor 1 initially
    printf("Elevator is at floor 1.\n");
    
    //Moving elevator to highest floor where there are people waiting
    for(j=n;j>=1;j--)
    {
        if(waiting[j-1]!=0)
        {
            printf("Elevator moved to floor %d.\n",j);
            break;
        }
    }
    
    //Opening elevator door and letting out people at this floor
    printf("Elevator door opened.\n");
    a=waiting[j-1];
    printf("%d people got out of the elevator at floor %d.\n",a,j);
    
    //Elevator currently at highest floor(j) where there are people waiting and picking them up
    printf("Elevator door closed.\n");
    printf("Elevator started moving down.\n");
    
    for(k=j;k>=1;k--)
    {
        if(waiting[k-1]!=0)
        {
            printf("Elevator reached floor %d.\n",k);
            printf("Elevator door opened.\n");
            b=waiting[k-1];
            printf("%d people got into the elevator at floor %d.\n",b,k);
            printf("Elevator door closed.\n");
            waiting[k-1]=0;
            count++;
            
            //Elevator at full capacity, moving towards ground floor
            if(count==10)
            {
                flag1=1;
                printf("\nElevator is at full capacity and moving towards ground floor.\n");
                break;
            }
        }
    }
    
    //Elevator has reached the ground floor, letting out people
    if(flag1==1)
    {
        printf("\nElevator reached the ground floor.\n");
        printf("Elevator door opened.\n");
        printf("%d people got out of the elevator at ground floor.\n",a+b);
        printf("Elevator door closed.\n");
    }
    
    //Moving elevator to floor with highest number of people waiting
    int max=0,pos=0;
    for(e=0;e<n;e++)
    {
        if(waiting[e]>max)
        {
            max=waiting[e];
            pos=e+1;
        }
    }
    
    if(max!=0)
    {
        printf("\nElevator moved to floor %d where there are %d people waiting.\n",pos,max);
        printf("Elevator door opened.\n");
        
        //Letting only 5 people into the elevator if there are more waiting
        if(max>5)
        {
            f=5;
            printf("%d people got into the elevator at floor %d.\n",f,pos);
            printf("Elevator door closed.\n");
            waiting[pos-1]=waiting[pos-1]-f;
            printf("\nElevator moving down.\n");
            
            //Elevator has reached the ground floor
            printf("Elevator reached the ground floor.\n");
            printf("Elevator door opened.\n");
            printf("%d people got out of the elevator at ground floor.\n",f);
            printf("Elevator door closed.\n\n");
        }
        
        //All people waiting at this floor got in the elevator
        else
        {
            f=max;
            printf("%d people got into the elevator.\n",f);
            printf("Elevator door closed.\n");
            waiting[pos-1]=0;
            printf("\nElevator moving down.\n");
            
            //Elevator has reached the ground floor
            printf("Elevator reached the ground floor.\n");
            printf("Elevator door opened.\n");
            printf("%d people got out of the elevator at ground floor.\n",f);
            printf("Elevator door closed.\n\n");
        }
        
        //Moving elevator to highest floor with people waiting again
        for(q=n;q>=1;q--)
        {
            if(waiting[q-1]!=0)
            {
                printf("Elevator moved to floor %d.\n",q);
                break;
            }
        }
        
        //Opening elevator door and letting out people at this floor
        printf("Elevator door opened.\n");
        s=waiting[q-1];
        printf("%d people got out of the elevator at floor %d.\n",s,q);
        
        //Elevator currently at highest floor(q) where there are people waiting and picking them up
        printf("Elevator door closed.\n");
        printf("Elevator started moving down.\n");
        
        for(r=q;r>=1;r--)
        {
            if(waiting[r-1]!=0)
            {
                printf("Elevator reached floor %d.\n",r);
                printf("Elevator door opened.\n");
                t=waiting[r-1];
                printf("%d people got into the elevator at floor %d.\n",t,r);
                printf("Elevator door closed.\n");
                waiting[r-1]=0;
                count++;
                
                //Elevator at full capacity, moving towards ground floor
                if(count==10)
                {
                    flag2=1;
                    printf("\nElevator is at full capacity and moving towards ground floor.\n");
                    break;
                }
            }
        }
        
        //Elevator has reached the ground floor, letting out people
        if(flag2==1)
        {
            printf("\nElevator reached the ground floor.\n");
            printf("Elevator door opened.\n");
            printf("%d people got out of the elevator at ground floor.\n",s+t);
            printf("Elevator door closed.\n");
        }
        
        //Elevator has no more people waiting to pick up or drop off
        if(max==0 && s==0 && flag2==0)
        {
            printf("\nElevator has no more people to pick up or drop off.\n");
        }
    }
    
    //All floors are empty, elevator is idle
    if(max==0 && s==0 && flag2==0)
    {
        printf("All floors are empty, elevator is idle.\n");
    }
    
    return 0;
}