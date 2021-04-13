#include <stdio.h>
#define N 4
#define M 5

int main(){
    int f,c;
    double *pmt;
    double mt[N][M];
    pmt = &mt[0][0];

    for(f = 0; f < N; f++){
        for(c = 0; c < M; c++){
            printf("%f ", *(pmt + (f*M + c)));
        }
        printf("\n");
    }
    return 0;
}