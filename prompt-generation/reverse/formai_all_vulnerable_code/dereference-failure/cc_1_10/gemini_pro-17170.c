//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct customer {
  char name[32];
  int age;
  char gender;
  char address[64];
  char occupation[32];
  char income[16];
  char credit_score[16];
};

struct customer_data {
  struct customer *customers;
  int num_customers;
};

void read_customer_data(struct customer_data *data) {
  FILE *file = fopen("customers.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  char line[256];
  while (fgets(line, sizeof(line), file)) {
    struct customer *customer = malloc(sizeof(struct customer));
    if (customer == NULL) {
      perror("Error allocating memory");
      exit(1);
    }

    sscanf(line, "%s %d %c %s %s %s %s", customer->name, &customer->age, &customer->gender, customer->address, customer->occupation, customer->income, customer->credit_score);

    data->customers = realloc(data->customers, sizeof(struct customer) * (data->num_customers + 1));
    data->customers[data->num_customers++] = *customer;
  }

  fclose(file);
}

void print_customer_data(struct customer_data *data) {
  for (int i = 0; i < data->num_customers; i++) {
    struct customer *customer = &data->customers[i];
    printf("%s %d %c %s %s %s %s\n", customer->name, customer->age, customer->gender, customer->address, customer->occupation, customer->income, customer->credit_score);
  }
}

int main(void) {
  struct customer_data data;
  data.customers = NULL;
  data.num_customers = 0;

  read_customer_data(&data);
  print_customer_data(&data);

  for (int i = 0; i < data.num_customers; i++) {
    free(&data.customers[i]);
  }
  free(data.customers);

  return 0;
}