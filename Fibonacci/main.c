    #include <stdio.h>
    #include <stdlib.h>
    #define MAX 50
    
    // Vector that will keep the series
    int fibonacci[MAX];

    // Calculate the fibonacci series
    int Fibonacci_series(int final_N){
        int a = 0,b = 1,c = 0;
        
        for(int i = 0; i < final_N;i++){
            c = a + b;
            b = a;
            a = c;
        }
        return a;
    }
    
    void Assignment(){
        int n;
        printf("Enter the length of the fibonacci series: ");
        scanf("%d", n);
        Fibonacci_series(n);
    }


    int main(){
        Assignment();
        return 0;
    }


    