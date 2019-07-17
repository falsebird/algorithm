#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

void downAdjust(int heap[] , int low , int high){
    int i = low, j = i*2;
    while (j < high){
        if(j +1 <=high &&heap[j+1] > heap[j]){
            j = j+1;
        }
        if(heap[i] <heap[j]){//while root element smaller than child exchange and make child to root continue to loop
            swap(heap[i] , heap[j]);
            i = j ;
            j = i *2;
        }else{//while root element bigger than child stop loop;
            break;
        }
    }
}

void createHeap(int heap[] , int low , int high){
    for(int i = high/2 ; i>=low ; i --){// adjust element from bottom
        downAdjust(heap , i ,high);
    }
}

void heapsort(int heap[] , int low ,int high){
    createHeap(heap,low,high);
    for(int i = high ; i >=low ; i --){
        swap(heap[low] , heap[i]);
        downAdjust(heap , low , i-1);//adjust element from top
    }
}

int main(){
    int heap[11]={0,22,123,4,545,2,44,67,34,23,55};
    for(int i = 1 ; i < 11 ; i ++){
        printf("%d ",heap[i]);
    }
    printf("\n");
    heapsort(heap, 1,10);
    for(int i = 1 ; i < 11 ; i ++){
        printf("%d ",heap[i]);
    }
    printf("\n");
    return 0;
}
