#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=100;
/** \brief
 * 查找最长公共子序列
 * \param  字符串
 * \param 字符串
 * \param 存储最优结果
 * \return void
 *
 */
void longestCommonSequence(char a[] , char b[] , int dp[][N]){
    int lenA = strlen(a + 1);
    int lenB = strlen(b + 1);
    //处理边界
    for (int i = 0; i < lenA ; i++){
        dp[i][0] = 0;
    }
    for (int j = 0; j < lenB ; j++){
        dp[0][j] = 0;
    }
    for (int i = 1;i<=lenA ; i++ ){

        for (int j = 1;j <=lenB ;j++ ){
            //printf("%c %c\n",a[i],b[j]);
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] +1;
              //  printf("%d %d\n",dp[i][j],dp[i-1][j-1]);
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                //printf("%d %d %d\n",dp[i-1][j],dp[i][j-1], dp[i][j]);
            }
        }

    }


}

int main(){
    //char a[N];
    char a[N]="0sadstory";
    //char b[N];
    char b[N]="0adminsorry";
    //fgets(a, N, stdin);
    //fgets(b, N, stdin);

    int lenA = strlen(a + 1);
    int lenB = strlen(b + 1);
    int dp[N][N];
    longestCommonSequence(a , b , dp);

    printf("%d",dp[lenA][lenB]);
    return 0;
}
