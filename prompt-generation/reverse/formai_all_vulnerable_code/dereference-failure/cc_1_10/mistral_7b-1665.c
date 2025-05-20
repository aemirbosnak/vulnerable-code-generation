//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the struct for the stock data
typedef struct {
    char symbol[5];
    float current_price;
    float previous_closing_price;
    float change_percentage;
} Stock;

// Function to get the current time as a string
char* get_time_string() {
    time_t now = time(NULL);
    char time_string[20];
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return strdup(time_string);
}

// Function to calculate the change percentage
float calculate_change_percentage(float current, float previous) {
    if (previous == 0) {
        return 0.0;
    }
    return ((current - previous) / previous) * 100.0;
}

// Function to print the stock data in a creative style
void print_stock_data(Stock stock) {
    char* time_string = get_time_string();
    printf("\n%s\n", time_string);
    printf("------------------------------------------\n");
    printf("| %-5s | %-12.2f | %-12.2f | %-8.2f%% |\n", stock.symbol, stock.current_price, stock.previous_closing_price, stock.change_percentage);
    free(time_string);
}

int main() {
    Stock apple = {"AAPL", 135.25, 132.5, 3.12};
    Stock google = {"GOOGL", 1234.56, 1212.34, 3.78};

    apple.current_price += 5.0;
    apple.previous_closing_price = apple.current_price - 3.0;

    google.current_price -= 12.34;
    google.previous_closing_price = google.current_price + 5.0;

    print_stock_data(apple);
    print_stock_data(google);

    return 0;
}