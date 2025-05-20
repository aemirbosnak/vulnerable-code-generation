//Falcon-180B DATASET v1.0 Category: Database querying ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

typedef struct {
    char name[50];
    int age;
    char gender[10];
    int score;
} player;

void create_table(MYSQL *conn) {
    char query[100];
    sprintf(query, "CREATE TABLE IF NOT EXISTS players (name VARCHAR(50), age INT, gender VARCHAR(10), score INT)");
    mysql_query(conn, query);
}

void insert_player(MYSQL *conn, player p) {
    char query[100];
    sprintf(query, "INSERT INTO players VALUES ('%s', %d, '%s', %d)", p.name, p.age, p.gender, p.score);
    mysql_query(conn, query);
}

void update_player(MYSQL *conn, player p) {
    char query[100];
    sprintf(query, "UPDATE players SET age=%d, gender='%s', score=%d WHERE name='%s'", p.age, p.gender, p.score, p.name);
    mysql_query(conn, query);
}

void delete_player(MYSQL *conn, char name[50]) {
    char query[100];
    sprintf(query, "DELETE FROM players WHERE name='%s'", name);
    mysql_query(conn, query);
}

void display_players(MYSQL *conn) {
    char query[100];
    sprintf(query, "SELECT * FROM players");
    if (mysql_query(conn, query)) {
        printf("Error: %s\n", mysql_error(conn));
        return;
    }
    MYSQL_RES *res = mysql_store_result(conn);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))!= NULL) {
        player p;
        strcpy(p.name, row[0]);
        p.age = atoi(row[1]);
        strcpy(p.gender, row[2]);
        p.score = atoi(row[3]);
        printf("%s %d %s %d\n", p.name, p.age, p.gender, p.score);
    }
    mysql_free_result(res);
}

int main() {
    MYSQL *conn;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        printf("Error: %s\n", mysql_error(conn));
        return 1;
    }
    create_table(conn);
    player p1 = {"John", 25, "Male", 100};
    insert_player(conn, p1);
    player p2 = {"Jane", 30, "Female", 200};
    insert_player(conn, p2);
    display_players(conn);
    update_player(conn, p1);
    update_player(conn, p2);
    display_players(conn);
    delete_player(conn, "John");
    delete_player(conn, "Jane");
    display_players(conn);
    mysql_close(conn);
    return 0;
}