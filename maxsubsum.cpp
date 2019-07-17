#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

//动态规划
void maxsubsum(int a[] , int dp[] , int n){
    //状态转移方程
    //dp[i] =max( a[i] +dp[i-1] ,a[i] )
    //边界
    dp[0] = a[0];
    for(int i = 1 ; i < n ; i++){
        dp[i] =max( a[i] +dp[i-1] ,a[i] );
    }
}



int main(){
    int a[10]={ -2 ,11,-4 ,13 ,-5 ,-2};
    int n = 6;
    int dp[10] ;
    memset(dp , 0 , sizeof(dp));//初始化dp数组
    maxsubsum(a ,dp ,n);
    int maxsum = dp[0];
    for (int i = 1;i <n ;i++ ){
        if(dp[i]>maxsum)
            maxsum = dp[i];
    }
    printf("%d",maxsum);
    return 0;
}
