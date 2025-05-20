//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	time_t t;
	struct tm *loc_time;
	int year, month, day;

	//Get current time
	t = time(NULL);

	//Get local time
	loc_time = localtime(&t);

	//Print current date and time
	printf("Current Date and Time: %s", asctime(loc_time));

	//Prompt the user to enter a year, month, and day
	printf("Enter a year: ");
	scanf("%d", &year);

	printf("Enter a month (1-12): ");
	scanf("%d", &month);

	//Verify that the month is valid
	if(month < 1 || month > 12)
	{
		printf("Invalid month.\n");
		exit(1);
	}

	printf("Enter a day (1-31): ");
	scanf("%d", &day);

	//Verify that the day is valid
	if(day < 1 || day > 31)
	{
		printf("Invalid day.\n");
		exit(1);
	}

	//Set the time structure to the user's input
	loc_time->tm_year = year - 1900;
	loc_time->tm_mon = month - 1;
	loc_time->tm_mday = day;

	//Convert the time structure to a time_t
	t = mktime(loc_time);

	//Check for errors in mktime()
	if(t == (time_t)-1)
	{
		printf("Error in mktime().\n");
		exit(1);
	}

	//Convert the time_t back to a time structure
	loc_time = localtime(&t);

	//Print the new date and time
	printf("New Date and Time: %s", asctime(loc_time));

	return 0;
}