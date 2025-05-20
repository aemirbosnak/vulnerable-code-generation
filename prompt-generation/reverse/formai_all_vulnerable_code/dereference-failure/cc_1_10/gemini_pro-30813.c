//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    PW_VERY_WEAK,
    PW_WEAK,
    PW_MEDIUM,
    PW_STRONG,
    PW_VERY_STRONG
} pw_strength_t;

static const char *pw_strength_strs[] = {
    "Very Weak",
    "Weak",
    "Medium",
    "Strong",
    "Very Strong"
};

static int pw_len_score(size_t len)
{
    if (len < 8)
        return 0;
    else if (len < 16)
        return 1;
    else if (len < 32)
        return 2;
    else
        return 3;
}

static int pw_type_score(const char *pw)
{
    int score = 0;
    int types = 0;

    if (strchr(pw, 'a') || strchr(pw, 'z'))
        types++;
    if (strchr(pw, 'A') || strchr(pw, 'Z'))
        types++;
    if (strchr(pw, '0') || strchr(pw, '9'))
        types++;
    if (strchr(pw, '!'))
        types++;
    if (strchr(pw, '@'))
        types++;
    if (strchr(pw, '#'))
        types++;
    if (strchr(pw, '$'))
        types++;
    if (strchr(pw, '%'))
        types++;

    if (types == 1)
        score = 0;
    else if (types == 2)
        score = 1;
    else if (types == 3)
        score = 2;
    else if (types == 4)
        score = 3;
    else
        score = 4;

    return score;
}

static int pw_seq_score(const char *pw)
{
    int score = 0;
    size_t i;

    for (i = 0; i < strlen(pw) - 2; i++) {
        if (pw[i] == pw[i + 1] && pw[i] == pw[i + 2])
            score--;
    }

    return score;
}

static int pw_common_score(const char *pw)
{
    int score = 0;
    FILE *fp;
    char line[256];

    fp = fopen("common_passwords.txt", "r");
    if (fp == NULL)
        return 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strlen(line) - 1] = '\0';
        if (strcmp(pw, line) == 0) {
            score--;
            break;
        }
    }

    fclose(fp);

    return score;
}

pw_strength_t pw_strength(const char *pw)
{
    int score = 0;

    score += pw_len_score(strlen(pw));
    score += pw_type_score(pw);
    score += pw_seq_score(pw);
    score += pw_common_score(pw);

    if (score < 0)
        score = 0;
    else if (score > 4)
        score = 4;

    return score;
}

int main(int argc, char *argv[])
{
    char pw[256];
    pw_strength_t strength;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    strcpy(pw, argv[1]);

    strength = pw_strength(pw);

    printf("Password: %s\n", pw);
    printf("Strength: %s\n", pw_strength_strs[strength]);

    return EXIT_SUCCESS;
}