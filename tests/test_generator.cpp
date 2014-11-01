#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(int argc,const char* argv[]){
    int n;
    scanf("%d", &n);
    srand(time(NULL));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == j) printf("0 ");
            else{
                printf("%d ",rand() % 50 + 1);
            }
        }
        printf("\n");
    }
    return 0;
}
