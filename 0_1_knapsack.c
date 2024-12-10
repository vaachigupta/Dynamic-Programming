#include <stdio.h>
#define M 5

int knapsack(int arr[][2],int size){
    int B[size+1][M+1];
    int i,w;
    for(i=0;i<=size;i++){
        B[i][0]=0;
    }
    for(w=0;w<=M;w++){
        B[0][w]=0;
    }
    for(i=1;i<=size;i++){
        for(w=1;w<=M;w++){
            if(arr[i-1][0]<=w){
                if((arr[i][1]+B[i-1][w-arr[i-1][0]])>B[i-1][w]){
                    B[i][w]=arr[i-1][1]+B[i-1][w-arr[i-1][0]];
                }
                else{
                    B[i][w]=B[i-1][w];
                }
            }
            else{
                B[i][w]=B[i-1][w];
            }
        }
    }
    return B[size][M];
}

int main(){
    int arr[][2]={{2,3},{3,4},{4,5},{5,6}};
    int size_arr=sizeof(arr)/sizeof(arr[0]);
    int profit;
    profit=knapsack(arr,size_arr);
    printf("Maximum Profit: %d\n",profit);

    return 0;
}