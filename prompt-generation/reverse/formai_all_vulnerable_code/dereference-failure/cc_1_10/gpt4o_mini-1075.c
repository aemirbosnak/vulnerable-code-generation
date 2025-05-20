//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "ERROR: %s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void list_products(MYSQL *con) {
    if (mysql_query(con, "SELECT id, name, price FROM products")) {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    printf("Products List:\n");
    printf("+-----+-------------------+--------+\n");
    printf("| ID  | Name              | Price  |\n");
    printf("+-----+-------------------+--------+\n");

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("| %-3s | %-17s | %-6s |\n", row[0], row[1] ? row[1] : "NULL", row[2] ? row[2] : "NULL");
        }
        printf("+-----+-------------------+--------+\n");
    }

    mysql_free_result(result);
}

void insert_product(MYSQL *con, const char *name, double price) {
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO products(name, price) VALUES('%s', %f)", name, price);
    if (mysql_query(con, query)) {
        finish_with_error(con);
    }
    printf("Product added: %s with price %.2f\n", name, price);
}

void delete_product(MYSQL *con, int id) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM products WHERE id=%d", id);
    if (mysql_query(con, query)) {
        finish_with_error(con);
    }
    printf("Product with ID %d deleted.\n", id);
}

int main(int argc, char **argv) {
    MYSQL *con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "user", "password", "testdb", 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    list_products(con);

    char product_name[50];
    double product_price;

    printf("Enter product name to add: ");
    scanf("%49s", product_name);
    printf("Enter product price: ");
    scanf("%lf", &product_price);
    insert_product(con, product_name, product_price);

    printf("Updated Products List:\n");
    list_products(con);

    int delete_id;
    printf("Enter product ID to delete: ");
    scanf("%d", &delete_id);
    delete_product(con, delete_id);

    printf("Final Products List:\n");
    list_products(con);

    mysql_close(con);
    return 0;
}