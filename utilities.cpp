#include "utilities.h"
#include <cstdio>
#include <algorithm>

Triple::Triple(int a,int b,int c):s1(a),s2(b),max(c){}

Triple lcs(const int *tab1,const int *tab2){
	int A[N+1][N+1];
    int ind1,ind2,max=-1;
    for(int i=0;i<N+1;i++)
        A[0][i] = A[i][0] = 0;
        for(int i = 1; i<=N; i++)
            for(int j = 1; j<=N;j++){
                if(tab1[i]==tab2[j]){
                    A[i][j] = A[i-1][j-1]+1;
                    if(A[i][j] > max){
                        max = A[i][j];
                        ind1 = i-max+1;
                        ind2 = j-max+1;
                    }
                }
                else
                    A[i][j] = 0;
            }
    return Triple(ind1,ind2,max);
}
