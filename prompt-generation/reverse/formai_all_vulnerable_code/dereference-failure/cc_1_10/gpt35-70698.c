//FormAI DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    int id;
    char name[100];
    float amount;
    char category[50];
    char date[11];
};

const char* filename = "expenses.txt";
int last_id = 0;

void save_expense(struct Expense expense) {
    FILE *fp;
    fp = fopen(filename, "a");
    fprintf(fp, "%d;%s;%.2f;%s;%s\n", expense.id, expense.name, expense.amount, expense.category, expense.date);
    fclose(fp);
}

int get_last_id() {
    FILE *fp;
    fp = fopen(filename, "r");
    char line[256];
    while(fgets(line, sizeof(line), fp) != NULL) {
        char* id_str = strtok(line, ";");
        int id = atoi(id_str);

        if(id > last_id) {
            last_id = id;
        }
    }
    fclose(fp);
    return last_id;
}

void view_expenses() {
    FILE *fp;
    fp = fopen(filename, "r");
    char line[256];
    printf("ID\tName\tAmount\tCategory\tDate\n");
    while(fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
}

void add_expense() {
    struct Expense expense;
    expense.id = ++last_id;

    printf("Enter expense name: ");
    scanf("%s", expense.name);

    printf("Enter amount: ");
    scanf("%f", &expense.amount);

    printf("Enter category: ");
    scanf("%s", expense.category);

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", expense.date);

    save_expense(expense);
    printf("Expense added successfully!\n");
}

void delete_expense() {
    int id;
    printf("Enter expense id to delete: ");
    scanf("%d", &id);

    FILE *fp1, *fp2;
    char line[256];
    char temp_filename[] = "temp.txt";

    fp1 = fopen(filename, "r");
    fp2 = fopen(temp_filename, "w");

    while(fgets(line, sizeof(line), fp1) != NULL) {
        char* id_str = strtok(line, ";");
        int current_id = atoi(id_str);

        if(current_id != id) {
            fprintf(fp2, "%s", line);
        }
    }
    fclose(fp1);
    fclose(fp2);

    remove(filename);
    rename(temp_filename, filename);
    printf("Expense deleted successfully!\n");
}

void calculate_total_expenses() {
    FILE *fp;
    fp = fopen(filename, "r");

    char line[256];
    float total = 0;

    while(fgets(line, sizeof(line), fp) != NULL) {
        char* amount_str = strtok(line, ";");
        float amount = atof(amount_str);

        total += amount;
    }
    fclose(fp);
    printf("Total expenses: %.2f\n", total);
}

void display_menu() {
    printf("Expenses Tracker\n");
    printf("1. View all expenses\n");
    printf("2. Add expense\n");
    printf("3. Delete expense\n");
    printf("4. Calculate total expenses\n");
    printf("5. Exit\n");
}

int main() {
    last_id = get_last_id();

    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                view_expenses();
                break;
            case 2:
                add_expense();
                break;
            case 3:
                delete_expense();
                break;
            case 4:
                calculate_total_expenses();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}