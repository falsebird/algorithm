#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

const int maxn = 100;
int n,V,maxValue= 0,ans=0;//物品件数 背包容量 最大价值 第二种方式最大值记录

//DFS index 为当前处理物品的编号
//index sumW sumW 为当前处理的物品编号 当前总价值 和当前价值
void DFS(int index , int sumW , int sumC, int w[] , int c[]){
    if(sumW > V){//当前重量已经超过背包容量进行剪枝操作
        return;
    }
    //边界条件，已经完成对 n件物品的搜索
    if(index ==n){
        if(sumW <=V && sumC >maxValue){
            maxValue = sumC;
        }
        return;
    }
    DFS(index +1 , sumW , sumC,w,c);
    DFS(index +1 , sumW + w[index] , sumC + c[index], w ,c);

}

void DFS2(int index , int sumW , int sumC, int w[] , int c[]){
    //边界条件，已经完成对 n件物品的搜索
    //printf("%d %d %d\n",index,sumW ,sumC);
    if(index ==n){
        return;
    }
    DFS2(index +1 , sumW , sumC,w,c);
    if(sumW +w[index]<=V ){
        if(sumC +c[index] > ans)
            ans = sumC +c[index];
            //printf("%d\n",ans);
        DFS2(index +1 , sumW + w[index] , sumC + c[index], w ,c);

    }

}


int main(){
    n=5;
    V=8;
    int w[maxn]={3,5,1,2,2};// 每件物品的重量
    int c[maxn]={4,5,2,1,3};//每件物品的价值
    DFS(0,0,0 ,w ,c);
    DFS2(0,0,0 ,w ,c);
    printf("%d\n",maxValue);
    printf("%d\n",ans);

    return 0;
}
