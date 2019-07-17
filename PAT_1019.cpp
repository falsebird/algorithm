#include<cstdio>
#include<cstring>
#include<algorithm>

int cmp(int a , int b ){ //  递减排序
    return a > b;
}

void to_array(int n , int num[]){
    int len = sizeof(array)/4;
    for(int i = 0 ; i < len ; i++ ){
        num[i] = n%10;
        n/10;
    }
}

int to_num( int num[]){
    int len = sizeof(array)/4;
    int sum = 0;
    for(int i = 0 ; i < len ; i++ ){
        sum = sum*10+num[i];
    }
    return sum;

}
int main(){
    int n , maxn minn;
    scanf("%d" , &n);
    int num[4];



    return 0;
}
