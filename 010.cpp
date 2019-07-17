#include<cstdio>
#include<algorithm>
using namespace std;

const int maxm = 100;

struct inteval{
    int x , y ;
}in[maxm] ;

int cmp (inteval a , inteval b){
    if(a.x != b.x)
    return a.x > a.y;//先按左端点从大到小
    else return a.y< b.y;// 在按右端点从小到大排序
}

int main(){

}
