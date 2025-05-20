//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 2048
#define PLUGIN_NAME "MathPlugin"

// Function to compute the factorial of a number
long long factorial(int n) {
    if (n < 0)
        return -1; // Error for negative inputs
    if (n == 0 || n == 1)
        return 1;
    
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to perform addition
int add(int a, int b) {
    return a + b;
}

// Function to handle HTTP requests
void handle_request(char* request) {
    char *method, *path, *query;

    method = strtok(request, " ");
    path = strtok(NULL, " ");
    query = strtok(NULL, "\0");

    if (strcmp(method, "GET") == 0) {
        // Displaying function based on the requested path
        if (strcmp(path, "/factorial") == 0) {
            int num = atoi(query);
            long long result = factorial(num);
            printf("Content-type: text/html\n\n");
            printf("<html><body>");
            printf("<h1>Factorial of %d is %lld</h1>", num, result);
            printf("</body></html>");
        } 
        else if (strcmp(path, "/add") == 0) {
            // Parse the query string for numbers to add
            int num1, num2;
            sscanf(query, "a=%d&b=%d", &num1, &num2);
            int result = add(num1, num2);
            printf("Content-type: text/html\n\n");
            printf("<html><body>");
            printf("<h1>Result of %d + %d is %d</h1>", num1, num2, result);
            printf("</body></html>");
        } 
        else {
            printf("Content-type: text/html\n\n");
            printf("<html><body>");
            printf("<h1>Invalid request!</h1>");
            printf("</body></html>");
        }
    } else {
        printf("Content-type: text/html\n\n");
        printf("<html><body>");
        printf("<h1>Only GET requests are supported!</h1>");
        printf("</body></html>");
    }
}

int main() {
    char request[BUFFER_SIZE];

    // Simulating an incoming request for demonstration
    // In a real browser plugin, you would get this from the web server
    snprintf(request, sizeof(request), "GET /factorial 5");

    // Call the handler to process the request
    handle_request(request);

    return 0;
}