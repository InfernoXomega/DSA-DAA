#include <stdio.h>
#include <stdbool.h>

#define N 4 // Number of men and women

// Function to check if woman prefers one man over another
bool prefers(int prefer[2*N][N], int w, int m, int m1) {
    for (int i = 0; i < N; i++) {
        // If m1 comes before m in w's list, then w prefers her current match
        // over m
        if (prefer[w][i] == m1)
            return true;
        // If m comes before m1 in w's list, then w prefers m over her current match
        if (prefer[w][i] == m)
            return false;
    }
    return false;
}

// Function to find stable matching for men and women
void stableMarriage(int prefer[2*N][N]) {
    int wPartner[N]; // Stores partner of women
    bool mFree[N];   // Stores availability of men

    // Initialize all men and women as free
    for (int i = 0; i < N; i++) {
        wPartner[i] = -1;
        mFree[i] = true;
    }

    int freeCount = N;

    // While there are free men
    while (freeCount > 0) {
        int m;
        // Pick the first free man
        for (m = 0; m < N; m++)
            if (mFree[m] == true)
                break;

        // Traverse all women according to m's preferences
        for (int i = 0; i < N && mFree[m] == true; i++) {
            int w = prefer[m][i];

            // The woman of preference is free, engage them
            if (wPartner[w - N] == -1) {
                wPartner[w - N] = m;
                mFree[m] = false;
                freeCount--;
            } else {
                // If w is not free
                int m1 = wPartner[w - N];

                // If w prefers m over her current engagement m1,
                // then break the engagement between w and m1 and engage m and w.
                if (prefers(prefer, w, m, m1) == false) {
                    wPartner[w - N] = m;
                    mFree[m] = false;
                    mFree[m1] = true;
                }
            }
        }
    }

    // Print the stable matching
    printf("Woman   Man\n");
    for (int i = 0; i < N; i++)
        printf(" %d \t %d\n", i + N, wPartner[i]);
}

int main() {
    int prefer[2*N][N];
    printf("Enter the preference list for men:\n");
    for(int i = 0; i < N; i++) {
        printf("Preferences for man %d: ", i);
        for(int j = 0; j < N; j++)
            scanf("%d", &prefer[i][j]);
    }
    printf("Enter the preference list for women:\n");
    for(int i = 0; i < N; i++) {
        printf("Preferences for woman %d: ", i + N);
        for(int j = 0; j < N; j++)
            scanf("%d", &prefer[i + N][j]);
    }

    stableMarriage(prefer);
    return 0;
}
