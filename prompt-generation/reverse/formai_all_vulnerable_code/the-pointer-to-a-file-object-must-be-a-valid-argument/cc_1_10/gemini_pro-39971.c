//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct {
    char *name;
    double amount;
    char *category;
    char *date;
} expense_t;

typedef struct {
    int fd;
    bool is_open;
} file_t;

file_t open_file(const char *path) {
    int fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    return (file_t) {fd, true};
}

void close_file(file_t file) {
    if (file.is_open) {
        close(file.fd);
        file.is_open = false;
    }
}

void write_expense(file_t file, expense_t expense) {
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "%s,%f,%s,%s\n", expense.name, expense.amount, expense.category, expense.date);
    write(file.fd, buffer, strlen(buffer));
}

void read_expenses(file_t file, void (*callback)(expense_t)) {
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file.fd)) {
        char *name = strtok(buffer, ",");
        double amount = atof(strtok(NULL, ","));
        char *category = strtok(NULL, ",");
        char *date = strtok(NULL, "\n");
        callback((expense_t) {name, amount, category, date});
    }
}

void print_expense(expense_t expense) {
    printf("%s, %f, %s, %s\n", expense.name, expense.amount, expense.category, expense.date);
}

int main() {
    file_t file = open_file("expenses.csv");
    write_expense(file, (expense_t) {"Coffee", 3.50, "Food", "2023-03-08"});
    read_expenses(file, print_expense);
    close_file(file);
    return 0;
}