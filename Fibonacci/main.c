    #include <stdio.h>
    #include <stdlib.h>
    #define MAX 50

    // Vector that will keep the series.
    int fibonacci[MAX];

    // Calculate the fibonacci series.
    void Fibonacci_series(int final_N){
        int a = 0,b = 1,c = 0;
        fibonacci[0] = 0;
        for(int i = 1; i < final_N;i++){
            c = a + b;
            b = a;
            a = c;
            fibonacci[i] = a;
        }
    }

    // Print out the series for debug purposes.
    void Output(int final_N){
        for(int i = 0; i < final_N;i++){
            printf("[%d] \n",fibonacci[i]);
        }
    }

    // Use binary search for a specify number in the fibonacci series.
    void Fibonacci_Search(int final_N,int key){
        int left = 0;
        int right = final_N - 1;

        while(left <= right){
            int mid_Index = (left + right) / 2;
        
            if (fibonacci[mid_Index] == key){
                printf("The value u want is in the: [%d] index", mid_Index);
                return;
            }
            else if (key < fibonacci[mid_Index]){
                right = mid_Index - 1;
            }
            
            else{
                left = mid_Index + 1;
            }
        }
        printf("\n[-1]");

    }

    // Assignment the length of the series, defined for user && The value the user want to find.
    void Assignment(){
        // Variable creation
        int n, key;
        // The user apply the value of the length and the number.
        printf("Enter the length of the fibonacci series: ");
        scanf("%d", &n);
        printf("Enter what number do you wanna find: ");
        scanf("%d",&key);
        
        // Call of the functions
        Fibonacci_series(n);
        Output(n);
        Fibonacci_Search(n,key);
    }

    int main(){
        Assignment();
        return 0;
    }


    