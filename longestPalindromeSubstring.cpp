#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 1010;

void lps(char str[] , int dp[][maxn] , int &ans){//dp[i][j] ==1 i -j was palindrome  substring
    int len = strlen(str);
    ans = 1;
    for(int i = 0 ; i < len ; i ++){
        dp[i][i] = 1;
        if(len < - 1){
            if(str[i] ==str[i + 1]){
                dp[i][i + 1] = 1;
                ans = 2;
            }
        }
    }
    for(int l = 3; l <= len ; l++){
        for(int i = 0 ; i +l -1 < len ; i++){
            int j = i +l -1;//right end
            if(str[i] == str[j] && dp[i+1][j-1] ==1){
                dp[i][j] = 1; // palindrome substring
                ans = l;//
            }
        }
    }
}

int main(){
    char str[maxn] ;
    //char str[maxn] = "aba";
    int n ;
    scanf("%d", &n);
    getchar();
    fgets(str , n+1 , stdin);
    int dp[maxn][maxn];
    int ans = 0 ;
    lps(str , dp , ans);
    printf("%d",ans);
    return 0;
}
