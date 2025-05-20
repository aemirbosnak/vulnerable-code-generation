//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: Cryptic
#pragma STDC F90

typedef int *SP;

#define K 127
#define S_N 1024
#define SPAM 1
#define HAM 0
#define UNKNOWN 2

char *Spams[] = {
        "FREE MONEY", "URGENT", "WIN A PRIZE", "ENLARGE YOUR",
        "GUARANTEED", "NO OBLIGATION",
};

char *Hams[] = {
        "Hello", "How are you", "Thank you", "Good morning",
        "See you later", "Have a nice day",
};

int Cmp(char *s1, char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
        if (s1[i] != s2[i]) return 0;
        else i++;
    return s1[i] == s2[i];
}

int Spam(char *s) {
    int i, j, k = 0;
    for (i = 0; i < K; i++)
        for (j = 0; j < S_N; j++) {
            if (s[k] != Spams[i][j] && Spams[i][j] != '\0') break;
            if (Spams[i][j] == '\0') {
                return SPAM;
            }
            k++;
        }
    for (i = 0; i < K; i++)
        for (j = 0; j < S_N; j++) {
            if (s[k] != Hams[i][j] && Hams[i][j] != '\0') break;
            if (Hams[i][j] == '\0') {
                return HAM;
            }
            k++;
        }
    return UNKNOWN;
}

SP Create(int s) {
    SP h = malloc(sizeof(int) * s);
    int i;
    for (i = 0; i < s; i++) h[i] = UNKNOWN;
    return h;
}

SP Train(SP h, char *s, int c) {
    int i, j, k = 0;
    for (i = 0; i < K; i++)
        for (j = 0; j < S_N; j++) {
            if (s[k] != Spams[i][j] && Spams[i][j] != '\0') break;
            if (Spams[i][j] == '\0') {
                h[i] = c;
                return h;
            }
            k++;
        }
    for (i = 0; i < K; i++)
        for (j = 0; j < S_N; j++) {
            if (s[k] != Hams[i][j] && Hams[i][j] != '\0') break;
            if (Hams[i][j] == '\0') {
                h[i + K] = c;
                return h;
            }
            k++;
        }
    return h;
}

int Classify(SP h, char *s) {
    int i, j, k = 0, c = 0;
    for (i = 0; i < K; i++)
        for (j = 0; j < S_N; j++) {
            if (s[k] != Spams[i][j] && Spams[i][j] != '\0') break;
            if (Spams[i][j] == '\0') {
                c |= h[i] == SPAM;
                break;
            }
            k++;
        }
    for (i = 0; i < K; i++)
        for (j = 0; j < S_N; j++) {
            if (s[k] != Hams[i][j] && Hams[i][j] != '\0') break;
            if (Hams[i][j] == '\0') {
                c |= h[i + K] == HAM;
                break;
            }
            k++;
        }
    if (c) return SPAM;
    else return HAM;
}

int main() {
    char s[] = "FREE MONEY";
    SP h = Create(2 * K);
    h = Train(h, Spams[0], SPAM);
    h = Train(h, Hams[0], HAM);
    printf("%s is %s\n", s, Spam(s) == SPAM ? "SPAM" : "HAM");
    printf("%s is %s\n", s, Classify(h, s) == SPAM ? "SPAM" : "HAM");
    return 0;
}