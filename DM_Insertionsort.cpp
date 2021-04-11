#include<stdio.h>
 
#define MAX_LEN 5
 
 
void InsertionSort(int * arr){
    int i, j;
    int key;
 
    for(i=1; i< MAX_LEN; i++){
        key = arr[i];
        
        for(j=i-1; j>=0; j--){
        
            if(arr[j] > key){       //key의 앞자리를 하나씩 보면서 비교
                arr[j+1] = arr[j];  //앞자리 값이 key값보다 크다면 하나씩 이동
            }else{                  //key보다 작은 값이 나오면 break;
                break;
            }
        
        }
        
        arr[j+1] = key;             //그 자리에 key값을 넣는다.
    }
}
 
int main(void){
    int arr[MAX_LEN] = {9, 5, 3, 7, 1};
    int i;
    
    for(i=0; i<MAX_LEN; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
 
 
    InsertionSort(arr);
 
    for(i=0; i<MAX_LEN; i++){
        printf("%d ", arr[i]);
    }
 
    return 0;
}
