//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Struct for each expense
typedef struct
{
	char name[30];
	float amount;
	int count;
	float total;
} expense;

// Function to add an expense
void addExpense(expense* expenseList, char* name, float amount)
{
	expense* newExpense = (expense*)malloc(sizeof(expense));
	strcpy(newExpense->name, name);
	newExpense->amount = amount;
	newExpense->count = 1;
	newExpense->total = amount;
	expenseList = realloc(expenseList, (sizeof(expense)*(expenseList->count+1)));
	expenseList[expenseList->count] = *newExpense;
}

// Function to display all expenses
void displayExpenses(expense* expenseList, int count)
{
	printf("Total expenses: %d\n", count);
	for(int i = 0; i < count; i++)
	{
		printf("Name: %s\tAmount: %.2f\tCount: %d\tTotal: %.2f\n", expenseList[i].name, expenseList[i].amount, expenseList[i].count, expenseList[i].total);
	}
}

// Function to update expense count
void updateExpenseCount(expense* expenseList, int index, int count)
{
	expenseList[index].count = count;
	expenseList[index].total = expenseList[index].amount * count;
}

// Function to update total
void updateTotal(expense* expenseList, int index, float total)
{
	expenseList[index].total = total;
}

// Function to remove an expense
void removeExpense(expense* expenseList, int index)
{
	expenseList[index].count = 0;
	expenseList[index].total = 0;
}

// Function to calculate the average expense
float calculateAverage(expense* expenseList, int count)
{
	float sum = 0;
	for(int i = 0; i < count; i++)
	{
		sum += expenseList[i].total;
	}
	return sum/count;
}

int main()
{
	expense* expenseList = (expense*)malloc(sizeof(expense));
	strcpy(expenseList->name, "Rent");
	expenseList->amount = 1000;
	expenseList->count = 1;
	expenseList->total = 1000;

	addExpense(expenseList, "Groceries", 200);
	addExpense(expenseList, "Electricity", 50);

	displayExpenses(expenseList, 3);

	printf("Average expense: %.2f\n", calculateAverage(expenseList, 3));

	updateExpenseCount(expenseList, 0, 2);
	updateTotal(expenseList, 0, 2000);

	removeExpense(expenseList, 1);

	displayExpenses(expenseList, 2);

	free(expenseList);
	return 0;
}