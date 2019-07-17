#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
/** \brief 有一个神奇的口袋，总的容积是40，用这个口袋可以变出一些物品，
这些物品的总体积必须是40。John现在有n个想要得到的物品，
每个物品的体积分别是a1，a2……an。John可以从这些物品中选择一些，
如果选出的物体的总体积是40，那么利用这个神奇的口袋，John就可以得到这些物品。
现在的问题是，John有多少种不同的选择物品的方式。
 *
输入的第一行是正整数n (1 <= n <= 20)，表示不同的物品的数目。
接下来的n行，每行有一个1到40之间的正整数，分别给出a1，a2……an的值。
输出不同的选择物品的方式的数目。
 * \param
 * \param
 * \return
 *
 */
const int maxn = 20;
const int W = 40;

int n;
int ans;

void DFS(int w[] ,int index, int sumW)
{
    //printf("%d %d\n",index , sumW);
    if(index == n) //遍历到满足条件的方案方案数自曾并且返回
    {
        return;
    }

    DFS(w,index +1, sumW);//选择该节点
    if((sumW +w[index]) ==W ){
        ans++;
        return;
    }else if((sumW + w[index])< W){
        DFS(w,index +1, sumW + w[index]);//不选择该节点
    }


}

int main(){
    int w[maxn];
    //scanf("d")
  /*  scanf("%d",&n);

    memset(w,0,sizeof(w));//jiang shuzu zhi kong
    ans = 0;
    for (int i = 0; i < n ; i++)
    {
        scanf("%d",&w[i]);

    }

    DFS(w ,0,0);
    printf("%d\n",ans);
*/
    while(scanf("%d",&n)!=EOF){
     memset(w,0,sizeof(w));//jiang shuzu zhi kong
     ans = 0;
     for (int i = 0;i < n ; i++){
         scanf("%d",&w[i]);
     }
     DFS(w ,0,0);
     printf("%d\n",ans);

    }

    return 0;
}
