//FormAI DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <ctype.h>
#include <string.h>

void showHeader(){
	printf("|   PID   |    USER   |   NAME   \n");
}

void showProcess(char *pid, char *user, char *name){
	printf("| %7s | %9s | %8s |\n", pid, user, name);
}

void getUsers(char users[100][20]){
	FILE *file;
	char line[100];

	file = fopen("/etc/passwd", "r");
	if (file){
		int i = 0;
		while (fgets(line, sizeof(line), file)){
			char *token;
			token = strtok(line, ":");
			if (token != NULL){
				strcpy(users[i], token);
				i++;
			}
		}
		fclose(file);
	}
	else{
		printf("ERROR: Could not read file.\n");
	}
}

void checkNumber(char s[]){
	int i = 0;
	while(s[i] != '\0'){
		if (!isdigit(s[i])){
			printf("ERROR: Invalid PID.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void getName(char *path, char name[]){
	FILE *file;
	char *token;
	char line[100];
	char *key;
	size_t len = 0;

	file = fopen(path, "r");
	if (file){
		while (getline(&key, &len, file) != -1){
			token = strtok(key, " ");
			if (strcmp(token, "Name:") == 0){
				token = strtok(NULL, " ");
				token[strlen(token) - 1] = '\0'; // Remove newline
				strcpy(name, token);
				break;
			}
		}
		fclose(file);
	}
	else{
		printf("ERROR: Could not read file.\n");
	}
}

void viewProcess(char pid[]){
	DIR *dir;
	struct dirent *d;
	char path[50];
	char name[20];
	char user[20] = "";
	char u[20];
	int flag = 0;

	sprintf(path, "/proc/%s", pid);

	dir = opendir(path);
	if (dir){
		while ((d = readdir(dir)) != NULL){
			if (isdigit(d->d_name[0])){
				sprintf(path, "/proc/%s/status", pid);
				getName(path, name);
				flag = 1;
				break;
			}
		}
		if (!flag) printf("ERROR: Process not found.\n");
	}
	else{
		printf("ERROR: Process not found.\n");
		exit(EXIT_FAILURE);
	}

	sprintf(path, "/proc/%s/status", pid);

	FILE *file = fopen(path, "r");
    if (file) {
    	char line[100];
        while (fgets(line, sizeof(line), file)) {
        	char *token;
            token = strtok(line, ":");
            if (token != NULL){
            	if (strcmp(token, "Uid") == 0){
            		token = strtok(NULL, ":");
            		strcpy(u, token);

            		// Get username from uid
            		char users[100][20];
            		getUsers(users);
            		for (int i = 0; i < 100; i++){
            			char *end;
            			long int id = strtol(users[i + 1], &end, 10);
            			if (id == atoi(u)){
            				strcpy(user, users[i]);
            				break;
            			}
            		}
            	}
            }
        }
        fclose(file);
    }

    showProcess(pid, user, name);
}

void viewProcesses(){
	DIR *dir;
	struct dirent *d;
	char path[50];
	char pid[20];

	showHeader();

	dir = opendir("/proc");
	if (dir){
		while ((d = readdir(dir)) != NULL){
			if (isdigit(d->d_name[0])){
				strcpy(pid, d->d_name);
				viewProcess(pid);
			}
		}
	}
	else{
		printf("ERROR: Could not open directory.\n");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char const *argv[]){
	viewProcesses();

	return 0;
}