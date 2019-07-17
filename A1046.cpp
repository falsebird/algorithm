#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100005;
int dis[MAXN],next[MAXN];
int main(){
    int dis[MAXN],next[MAXN];
    //存储距离
    int start;
    int dest;
    int n1,query,sum = 0 ;
    (void)scanf("%d",&n1);
    for (int i = 1 ;i <= n1 ; i++){
        int temp;
        (void)scanf("%d", &temp);
        next[i]= temp;
        sum +=next[i];
        dis[i] = sum;
    }
    scanf("%d",&query);
    for (int i = 0 ;i < query ; i++){
        (void)scanf("%d%d",&start , &dest);
        if(start > dest)//保证目的地比出发地大
            swap(start , dest);
        int temp = dis[dest -1 ] - dis[start -1];
        printf("%d\n",min(temp , sum -temp));

    }

    return 0 ;
}
