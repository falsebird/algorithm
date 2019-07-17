#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

int dis(int a[] ,int left , int right){
    int temp = a[left];
    while(left< right){
        while(left<right&&temp < a[right]) right--;
        a[left] = a[right];
        while(left < right && a[left] <= temp) left ++;
        a[right] = a[left];
    }
    a[left] = temp;
    return left;
}

void quickSort(int a[] , int left , int right){
    if(left<right){// while segment bigger than 1
        int pos = dis(a , left , right);
        quickSort(a , left , pos -1);
        quickSort(a , pos +1 , right);
    }

}


int main(){
    int heap[11]={0,22,123,4,545,2,44,67,34,23,55};
    for(int i = 1 ; i < 11 ; i ++){
        printf("%d ",heap[i]);
    }
    printf("\n");
    quickSort(heap, 0,10);
    for(int i = 1 ; i < 11 ; i ++){
        printf("%d ",heap[i]);
    }
    printf("\n");
    return 0;
}
