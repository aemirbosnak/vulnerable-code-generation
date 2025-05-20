//MISTRAL-7B DATASET v1.0 Category: Mortgage Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

typedef struct Dream {
    char name[50];
    float value;
} Dream;

Dream dreams[10];
float principal, interest_rate, years, monthly_payment;
int dream_counter = 0;

void read_dreams() {
    FILE *fp;
    fp = fopen("dreams.txt", "r");
    char line[100];

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%s %f", dreams[dream_counter].name, &dreams[dream_counter].value);
        dream_counter++;
    }

    fclose(fp);
}

void calculate_mortgage() {
    monthly_payment = principal * (interest_rate / 1200) * pow((1 + interest_rate / 1200), years * 12);
}

void print_results() {
    printf("Monthly Payment: $%.2f\n", monthly_payment);
    printf("Your dreams:\n");

    for (int i = 0; i < dream_counter; i++) {
        printf("%s: $%.2f\n", dreams[i].name, dreams[i].value);
    }
}

int main() {
    srand(time(NULL));
    read_dreams();

    printf("Enter principal: $");
    scanf("%f", &principal);
    printf("Enter interest rate (as a decimal): ");
    scanf("%f", &interest_rate);
    printf("Enter years: ");
    scanf("%f", &years);

    calculate_mortgage();
    print_results();

    int random_dream = rand() % dream_counter;
    printf("Your subconscious mind chose: %s\n", dreams[random_dream].name);

    return 0;
}