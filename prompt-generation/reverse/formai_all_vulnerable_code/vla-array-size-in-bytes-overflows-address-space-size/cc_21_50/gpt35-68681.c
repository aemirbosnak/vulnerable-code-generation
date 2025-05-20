//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: expert-level
#include<stdio.h>
int main()
{
  int floors,i,j,time,max_people,elevator_size,current_floor=1;
  int elevator_direction=1,elevator_space;
  int current_time=0;
  printf("Enter the number of floors in the building: ");
  scanf("%d",&floors);
  printf("Enter the time it takes to travel between floors: ");
  scanf("%d",&time);
  printf("Enter the maximum number of people allowed on the elevator: ");
  scanf("%d",&max_people);
  printf("Enter the number of floors the elevator can travel: ");
  scanf("%d",&elevator_size);
  elevator_space=max_people;
  int people_on_elevator=0;
  int people_waiting[floors];
  for(i=0;i<floors;i++)    
    {
      printf("Enter the number of people waiting on floor %d : ",i+1 );
      scanf("%d",&people_waiting[i]);
    }
  //Simulation starts
  printf("Simulation starts!\n");
  while(1)
    {
      if(elevator_direction==1)//The elevator goes up
	{
	  for(i=current_floor;i<=floors;i++)//Scanning above floors
	    {
	      if(people_waiting[i-1]!=0 && people_on_elevator!=elevator_space)//People waiting and there is space on the elevator
		{
		  int getting_on=people_waiting[i-1];
		  people_waiting[i-1]=0;
		  if(getting_on>elevator_space)//People hopping > the space on the elevator
		    {
		      getting_on=elevator_space;
		      people_waiting[i-1]-=elevator_space;
		    }
		  else
		    {
		      people_waiting[i-1]=0;
		    }
		  printf("\n People getting into the elevator at floor %d\t",i);
		  for(j=1;j<=getting_on;j++)
		    printf("P ");
		  printf("\n");
		  people_on_elevator+=getting_on;
		}
	    }
	  printf("\n Elevator moving up from floor %d",current_floor);
	  if(people_on_elevator!=0)//Some people are on the elevator. Their destination is found.
	    {
	      for(i=current_floor+1;i<=current_floor+elevator_size;i++)//Scanning the floors according to the elevators range
		{
		  if(i<=floors)//Checking if the range goes beyond the floors
		    {
		      if(people_waiting[i-1]==0)//No people waiting at the floor
			{
			  continue;
			}
		      else
			{
			  int getting_off=0;
			  for(j=0;j<people_on_elevator;j++)//Finding the people with the same as the current floor.
			    {
			      if(elevator_direction==1 && current_floor<=i && current_floor+elevator_size>=i)//If the people's destination is in the elevators range
				{
				  getting_off++;
				}
			    }
			  printf("\n People getting off the elevator at floor %d\t",i);
			  for(j=1;j<=getting_off;j++)
			    printf("P ");
			  printf("\n");
			  people_on_elevator-=getting_off;
			}
		    }
		}
	    }
	  printf("\n Elevator stops at floor %d.. Doors opening",current_floor+elevator_size);
	  current_time+=time;
	  printf("\n Time elapsed: %d\n",current_time);
	  elevator_direction=-1;
	  if(current_floor+elevator_size==floors)
	    {
	      printf("\n Elevator now heading down\n");
	      elevator_direction=-1;
	      break;//If the top floor is reached, the elevator starts going to the bottom floor
	    }
	  else
	    {
	      current_floor=current_floor+elevator_size;
	    }
	}
      else//Elevator goes down
	{
	  for(i=current_floor-2;i>=0;i--)
	    {
	      if(people_waiting[i]!=0 && people_on_elevator!=elevator_space)
		{
		  int getting_on=people_waiting[i];
		  people_waiting[i]=0;
		  if(getting_on>elevator_space)
		    {
		      getting_on=elevator_space;
		      people_waiting[i]-=elevator_space;
		    }
		  else
		    {
		      people_waiting[i]=0;
		    }
		  printf("\n People getting into the elevator at floor %d\t",i+1);
		  for(j=1;j<=getting_on;j++)
		    printf("P ");
		  printf("\n");
		  people_on_elevator+=getting_on;
		}
	    }
	  printf("\n Elevator moving down from floor %d",current_floor);
	  if(people_on_elevator!=0)
	    {
	      for(i=current_floor-1;i>=current_floor-elevator_size;i--)
		{
		  if(i>0)
		    {
		      if(people_waiting[i-1]==0)
			{
			  continue;
			}
		      else
			{
			  int getting_off=0;
			  for(j=0;j<people_on_elevator;j++)
			    {
			      if(elevator_direction==-1 && current_floor>=i && current_floor-elevator_size<=i)
				{
				  getting_off++;
				}
			    }
			  printf("\n People getting off the elevator at floor %d\t",i);
			  for(j=1;j<=getting_off;j++)
			    printf("P ");
			  printf("\n");
			  people_on_elevator-=getting_off;
			}
		    }
		}
	    }
	  printf("\n Elevator stops at floor %d.. Doors opening",current_floor-elevator_size);
	  current_time+=time;
	  printf("\n Time elapsed: %d\n",current_time);
	  if(current_floor-elevator_size==1)
	    {
	      printf("\n Elevator now heading up\n");
	      elevator_direction=1;
	      break;//If the elevator reaches the lowest floor, it starts moving up
	    }
	  else
	    {
	      current_floor-=elevator_size;
	    }
	}
    }
  //Simulation ends
  printf("\n Simulation ends!\n");
  printf("\n People left on the waiting systems:\n");
  for(i=0;i<floors;i++)
    {
      printf("\n People on floor %d: %d",i+1,people_waiting[i]);
    }
  printf("\n Time taken by the simulation program: %d",current_time);
  //End of program
  return 0;
}