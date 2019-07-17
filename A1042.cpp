#include<cstdio>

void out(int a[]){
    char mp[6] = {'S' ,'H','C' , 'D','J'};
    for(int i = 1 ; i <=54 ; i++){
        printf("%c%d",mp[a[i]/13] ,a[i]%13 + 1 );
        //cout<<mp[i/13]<<a[i]%13 + 1;
        if(i <= 53)
            printf(" ");
    }
}
void swap(int a[] , int i , int j ){//exchange location of i and j on array
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main(){
    int a[55];//扑克初始序列

    int b[55];//given order;
    int n , temp ; //repeat times
    for (int i = 1 ; i <= 54 ; i ++ ){
        a[i] = i;
    }
    (void)scanf("%d",&n);
    for (int i = 1 ; i <= 54 ; i ++ ){
        (void)scanf("%d",&b[i]);
        //cin>>b[i];
    }
    for(int j = 0 ; j < n ; j ++){
        for (int i = 1 ; i <= 54 ;i++ ){
            temp = a[i];
            a[i] = a[b[i]];
            a[b[i]] = temp;
        }
    }
    out(a);
    return 0;
}
