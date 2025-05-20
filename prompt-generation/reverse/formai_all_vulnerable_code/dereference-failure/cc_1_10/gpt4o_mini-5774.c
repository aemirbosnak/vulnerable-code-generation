//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void query_books(MYSQL *con) {
    if (mysql_query(con, "SELECT title, author, published_year FROM books")) {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    printf("Books in the Database:\n");
    printf("%-30s %-30s %-20s\n", "Title", "Author", "Published Year");
    printf("--------------------------------------------------------------\n");

    while ((row = mysql_fetch_row(result))) {
        printf("%-30s %-30s %-20s\n", row[0], row[1], row[2]);
    }

    mysql_free_result(result);
}

void insert_book(MYSQL *con) {
    char title[100], author[100];
    int year;

    printf("Enter book title: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0;  // Remove newline character

    printf("Enter author name: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = 0;  // Remove newline character

    printf("Enter published year: ");
    scanf("%d", &year);
    while (getchar() != '\n');  // Clear newline char from buffer

    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO books(title, author, published_year) VALUES('%s', '%s', %d)", title, author, year);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }

    printf("Inserted book: '%s' by '%s', published in %d\n", title, author, year);
}

void delete_book(MYSQL *con) {
    int id;
    printf("Enter the ID of the book you want to delete: ");
    scanf("%d", &id);
    while (getchar() != '\n');  // Clear newline char from buffer

    char query[64];
    snprintf(query, sizeof(query), "DELETE FROM books WHERE id=%d", id);

    if (mysql_query(con, query)) {
        finish_with_error(con);
    }

    printf("Deleted book with ID: %d\n", id);
}

void show_menu() {
    printf("\nBook Database Menu:\n");
    printf("1. Query Books\n");
    printf("2. Insert Book\n");
    printf("3. Delete Book\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MYSQL *con = mysql_init(NULL);
    if (con == NULL) {
        finish_with_error(con);
    }

    if (mysql_real_connect(con, "localhost", "root", "password", "bookstore", 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    int choice;
    while (1) {
        show_menu();
        scanf("%d", &choice);
        while (getchar() != '\n');  // Clear newline char from buffer

        switch (choice) {
            case 1:
                query_books(con);
                break;
            case 2:
                insert_book(con);
                break;
            case 3:
                delete_book(con);
                break;
            case 4:
                mysql_close(con);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    mysql_close(con);
    return 0;
}