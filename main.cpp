#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int max(int a, int b);

int main() {
    int i,j,n,k,Wm, c[100], w[100], m[100][100][2],items[100];
    FILE *F;

    F=fopen("input.txt", "r");
    fscanf(F, "%d %d",&n, &Wm);

    for (i=1; i<n+1; i++){
        fscanf(F, "%d", &c[i]);
        printf("%2d ", c[i]);
    }
    printf("\n");
    for (i=1; i<n+1; i++){
        fscanf(F, "%d", &w[i]);
        printf("%2d ", w[i]);
    }
    printf("\n");

    for (j=0; j<Wm+1; j++){
        m[0][j][0] = 0;
        m[0][j][1] = 0;
    }

    k=1;
    for (i=1; i<n+1; i++){
        for (j=0; j<Wm+1; j++){
            if (w[i]>j) {
                m[i][j][0] = m[i - 1][j][0];
                m[i][j][1] = m[i - 1][j][1];

            }
                else {
                    if (max(m[i - 1][j][0], (m[i - 1][j - w[i]][0]) + c[i])) {
                        m[i][j][0] = (m[i - 1][j - w[i]][0]) + c[i];
                        m[i][j][1] = m[i - 1][j - w[i]][1]+1;
                        k=m[i][j][1];
                        items[k]=i;

                    }
                else {
                        m[i][j][0]=m[i - 1][j][0];
                        m[i][j][1] = m[i - 1][j][1];
                    }
            }
        }
    }
    printf("%d\n",m[n][Wm][0]);
    for (i=1; i<k+1; i++){
        printf("%d ", items[i]);
    }
    return 0;
}

int max(int a, int b) {
    if (a >= b) return 0;
    else if (b > a) return 1;
    return 0;
}