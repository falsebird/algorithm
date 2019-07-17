#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

//动态规划
void lengthIncreaseSequence(int a[] , int dp[] , int n , int &ans){//an要使用引用否则无法传值
    //状态转移方程
    //dp[i] =max( 1 ,dp[j] +1 )
    //(j=1,2,...i-1&&a[j]<a[i])
    //边界
    dp[0] = 1;
    ans = -1;
    for(int i = 1 ; i <= n ; i++){
        dp[i]=1;
        for(int j = 1; j <i ;j ++){
            if(a[i]>=a[j] && (dp[j] +1>dp[i]) ){
                dp[i] = dp[j] +1;
            }
        }

        ans = max(ans , dp[i]);//选出最大不下降子段
    }
}



int main(){
    int a[100]={ 0 , 1 , 2 , 3 ,-9 ,3 ,9 ,0 ,11};
    int n = 8;
    int dp[100] ;
    //memset(dp , 0 , sizeof(dp));//初始化dp数组
    int ans;
    lengthIncreaseSequence(a ,dp ,n , ans);
    printf("%d",ans);
    return 0;
}
