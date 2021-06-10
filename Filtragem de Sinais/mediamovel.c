#include <stdio.h>

#define N 5

int main(int argc, char *argv[]) {
    int i = 0;
    float values[N] = {0};
    
    while(1) {
        float sum = 0;
        printf("--- Iteração %d ---\n", i);
        scanf("%f", &values[i % N]);

        for(int j = 0; j < N; j++) {
            printf("%f ", values[j]);
            sum += values[j];
        }

        sum /= N;
        printf("\nMedia Movel: %f\n\n", sum);
        i++;
    }
}


