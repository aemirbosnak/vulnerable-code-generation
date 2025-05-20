//FormAI DATASET v1.0 Category: Password management ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 25
#define MAX_WEBSITE_LENGTH 100

typedef struct {
    char website[MAX_WEBSITE_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

PasswordEntry *load_passwords(char *filename, int *num_entries) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    int max_entries = 10;
    PasswordEntry *passwords = malloc(max_entries * sizeof(PasswordEntry));
    *num_entries = 0;

    char line[MAX_WEBSITE_LENGTH + MAX_PASSWORD_LENGTH + 2];
    while (fgets(line, MAX_WEBSITE_LENGTH + MAX_PASSWORD_LENGTH + 2, file) != NULL) {
        char *newline = strchr(line, '\n');
        if (newline != NULL) {
            *newline = '\0';
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        char *delimiter = strchr(line, ':');
        if (delimiter == NULL) {
            printf("Error: invalid file format in %s\n", filename);
            exit(1);
        }

        char *website = line;
        *delimiter = '\0';
        char *password = delimiter + 1;

        PasswordEntry entry;
        strncpy(entry.website, website, MAX_WEBSITE_LENGTH + 1);
        strncpy(entry.password, password, MAX_PASSWORD_LENGTH + 1);

        if (*num_entries == max_entries) {
            max_entries *= 2;
            passwords = realloc(passwords, max_entries * sizeof(PasswordEntry));
        }

        passwords[(*num_entries)++] = entry;
    }

    fclose(file);
    return passwords;
}

void save_passwords(char *filename, PasswordEntry *passwords, int num_entries) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file %s for writing\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%s:%s\n", passwords[i].website, passwords[i].password);
    }

    fclose(file);
}

void print_menu() {
    printf("Password Manager v1.0\n");
    printf("1. List passwords\n");
    printf("2. Add password\n");
    printf("3. Remove password\n");
    printf("4. Change password\n");
    printf("5. Save and exit\n");
    printf("Enter your choice (1-5): ");
}

int get_choice() {
    int choice;
    scanf("%d", &choice);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return choice;
}

void list_passwords(PasswordEntry *passwords, int num_entries) {
    printf("Website                     Password\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%-25s %s\n", passwords[i].website, passwords[i].password);
    }
}

void add_password(PasswordEntry *passwords, int *num_entries) {
    printf("Enter website name (max %d characters): ", MAX_WEBSITE_LENGTH);
    char website[MAX_WEBSITE_LENGTH + 1];
    fgets(website, MAX_WEBSITE_LENGTH + 1, stdin);
    char *newline = strchr(website, '\n');
    if (newline != NULL) {
        *newline = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("Enter password (max %d characters): ", MAX_PASSWORD_LENGTH);
    char password[MAX_PASSWORD_LENGTH + 1];
    fgets(password, MAX_PASSWORD_LENGTH + 1, stdin);
    newline = strchr(password, '\n');
    if (newline != NULL) {
        *newline = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    PasswordEntry entry;
    strncpy(entry.website, website, MAX_WEBSITE_LENGTH + 1);
    strncpy(entry.password, password, MAX_PASSWORD_LENGTH + 1);

    if (*num_entries == 10) {
        printf("Error: password database is full\n");
        return;
    }

    passwords[(*num_entries)++] = entry;
    printf("Password added.\n");
}

void remove_password(PasswordEntry *passwords, int *num_entries) {
    if (*num_entries == 0) {
        printf("Error: password database is empty\n");
        return;
    }

    printf("Enter website name to remove: ");
    char website[MAX_WEBSITE_LENGTH + 1];
    fgets(website, MAX_WEBSITE_LENGTH + 1, stdin);
    char *newline = strchr(website, '\n');
    if (newline != NULL) {
        *newline = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    int removed = 0;
    for (int i = 0; i < *num_entries; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            removed = 1;
            for (int j = i + 1; j < *num_entries; j++) {
                passwords[j - 1] = passwords[j];
            }
            (*num_entries)--;
            break;
        }
    }

    if (removed) {
        printf("Password for %s removed.\n", website);
    } else {
        printf("Error: website not found\n");
    }
}

void change_password(PasswordEntry *passwords, int num_entries) {
    if (num_entries == 0) {
        printf("Error: password database is empty\n");
        return;
    }

    printf("Enter website name to change password: ");
    char website[MAX_WEBSITE_LENGTH + 1];
    fgets(website, MAX_WEBSITE_LENGTH + 1, stdin);
    char *newline = strchr(website, '\n');
    if (newline != NULL) {
        *newline = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        PasswordEntry *entry = &passwords[i];
        if (strcmp(entry->website, website) == 0) {
            found = 1;

            printf("Enter new password (max %d characters): ", MAX_PASSWORD_LENGTH);
            char password[MAX_PASSWORD_LENGTH + 1];
            fgets(password, MAX_PASSWORD_LENGTH + 1, stdin);
            newline = strchr(password, '\n');
            if (newline != NULL) {
                *newline = '\0';
            } else {
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }

            strncpy(entry->password, password, MAX_PASSWORD_LENGTH + 1);

            printf("Password for %s updated.\n", website);
            break;
        }
    }

    if (!found) {
        printf("Error: website not found\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <password file>\n", argv[0]);
        exit(1);
    }

    int num_entries;
    PasswordEntry *passwords = load_passwords(argv[1], &num_entries);

    while (1) {
        print_menu();
        int choice = get_choice();

        switch (choice) {
            case 1:
                list_passwords(passwords, num_entries);
                break;
            case 2:
                add_password(passwords, &num_entries);
                break;
            case 3:
                remove_password(passwords, &num_entries);
                break;
            case 4:
                change_password(passwords, num_entries);
                break;
            case 5:
                save_passwords(argv[1], passwords, num_entries);
                printf("Password database saved, exiting.\n");
                exit(0);
            default:
                printf("Error: invalid choice\n");
        }
    }

    return 0;
}