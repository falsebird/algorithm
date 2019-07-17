#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn =100;
struct node{
    int x,y;
}Node;
int n,m;//  数组的大小为n*m
int matrix[maxn][maxn];//01矩阵
bool inq[maxn][maxn] = {false};//记录位置(x,y)是已经入过队
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};

bool judge(int x, int y){//  (x,y)
    //越界返回false
    if(x >= n|| x < 0||y >= m || y < 0)return false;
    //当前位置为0或者已经访问过返回false
    if(matrix[x][y] ==0 || inq[x][y] ==true) return false;
    //以上都不满足返回false
    return true;
}

void BFS(int x, int y){
    queue<node> Q;
    Node.x = x, Node.y = y;
    Q.push(Node);//将该节点入队
    inq[x][y]=true;//已经访问该节点
    while(!Q.empty()){//当队列非空时进行循环
        node top = Q.front();
        Q.pop();//队首出队
        for(int i = 0 ; i <4 ; i++){//访问相邻位置
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(judge(newX , newY)){//如果可以访问将其入并且将已访问标志值为true
                Node.x = newX;
                Node.y = newY;
                Q.push(Node);
                inq[newX][newY] = true;
            }
        }

    }
}
int main(){
    n = 7;
    m = 6;
    memset(matrix , 0 , sizeof(matrix));
     for(int x = 0 ; x < n ; x++){
        for (int y = 0;y < m ;y++ ){
            scanf("%d",&matrix[x][y]);
        }
     }
     /*
    matrix[0][1] =1;
    matrix[0][2] =1;
    matrix[0][3] =1;
    matrix[0][6] =1;
    matrix[1][2] = 1;
    matrix[2][5] = 1;
    matrix[3][3] =1;
    matrix[3][4] =1;
    matrix[3][5] =1;
    matrix[4][1] = 1;
    matrix[4][0] = 1;
    matrix[4][2] = 1;
    matrix[4][4] = 1;
    matrix[5][0] = 1;
    matrix[5][1] = 1;
    matrix[5][2] = 1;
    matrix[5][3] = 1;
    */
    int ans = 0;
    for(int x = 0 ; x < n ; x++){
        for (int y = 0;y < m ;y++ ){
            if(matrix[x][y] ==1 &&inq[x][y] ==false){
                ans++;
                BFS(x ,y);//访问该快将该块的所有inqdou 标记为true
            }
        }

    }
    printf("%d\n",ans);
    return 0;
}
