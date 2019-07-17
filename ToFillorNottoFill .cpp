#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

const int maxn = 510;
struct gasStation{
    double price;
    double distace;
    int next;
    friend bool operator < (gasStation g1 , gasStation g2){
        if(g1.distace!=g2.distace)
        return g1.distace < g2.distace; //按照距离从小到大进性排序
    else
        return g1.price <g2.price; //当距离相等是按照价格从小到大排序
    }
}GAS ,gass[maxn];//存储加油站
int N;//当前车辆最多装汽油 与目的城市的距离 每单位油走的距离 加油站的数量
double Cmax,D,Davg;
vector<int> avliable[maxn];//存储每个加油站可以辐射到后边加油站的编号 使用存储vection<int>的一维数组
double currntGasVolum;//当前油量
int rids ;
//找到所有加油站中 最便宜的加油站，看在该站加满油能不能到目的地能就加足够的油不能就加满在下一站接着加油
//寻找油费最少的加油站，将问题分割为两部分，在在这连个部分中寻找油费最少的加油站
//判断在加油最少的地方加到可以到达问题的终点需要多少，如果加满也到不了，判断中间是否有加油站补充
/*测试数据
59 525 19 2
3.00 314
3.00 0
*/

int cmp(gasStation g1 , gasStation g2){//比较规则将加油站进排序
    if(g1.distace!=g2.distace)
        return g1.distace < g2.distace; //按照距离从小到大进性排序
    else
        return g1.price <g2.price; //当距离相等是按照价格从小到大排序
}



//获取每个加油站能够、辐射到的加油站的编号
void getavilable(int rids){//每个加油站能够向后辐射的距离
    for (int i = 0 ;i < N ;i++ ){
        for (int j = i+1; j < N ; j++){
            if(gass[i].distace+  rids > gass[j].distace){
                //cout<<"getavilable "<<i<<" "<<j<<endl;
                avliable[i].push_back(j);
            }else{
                break;
            }
        }
        if(avliable[i].empty()){//当前加油站没有能够辐射到的加油站无发继续进行
            break;
        }

    }
}



//写一个函数判断该当前加是否有下一个加油站可用，并且返回其中最便宜的加油站的编号 如果没有返回-1
//获取所有能到达加油站能辐射到加油站中最便宜的
void getNext(int index ){//获得每一个加油站下一个能到达加油站中最便宜的
    int nextt = 0;
    int minn;
    //cout<<"getNext index:"<<index<<endl;
    if(index ==N -1){//当加油站为最后一个返回-1
        return ;
    }
    if(index ==0 && gass[index].distace != 0){
        return ;
    }
    if(avliable[index].empty()){
        gass[index].next =-1;
        return ;
    } else {
        minn = gass[ avliable[index][0] ].price;//获取第一个可以辐射到的加油站的价格
        nextt = avliable[index][0];
        for(int i = 1 ; i < avliable[index].size();i++){//得到能够辐射到的加油站中最便宜的
            if(gass[avliable[index][i]].price < minn){
                minn =gass[avliable[index][i]].price;
                //cout<<"getNext minin:"<<minn<<endl;
                nextt = i;
            }
        }
//cout<<"getNext nextt:"<<nextt<<endl;
        gass[index].next= nextt;
        getNext(nextt);
    }
    return;
}
bool judge( int &index ){//判断能否到大目的地底
    //cout<<"judge "<<index<<endl;
    while(index--){//寻找最后一个到达的加油站
        if(gass[index].next != -1){
            index = gass[index].next;
            //cout<<"judge "<<index<<endl;
            break;
        }

    }
    if((gass[index].distace +rids) > D)
    {

        //cout<<"judge "<<"true "<<gass[index].distace +rids<<endl;
        return true;
    }else{
       // cout<<"judge "<<"false"<<endl;
        return false;
    }

}
void travl(int f , int e ,double &free ){//能到大目的地是计算花的钱
    while (f<e){//从第一个加油站开始到最后一个加油站停止
            //cout<<"travl  f:"<<f<<" e:"<<e<<"free:"<<free<<endl;
        if(gass[f].price <= gass[gass[f].next].price){//当前油站比下一个油站便宜加满油
            if(gass[f].distace + rids <N){//当前加油站无法辐射到目的地
                free += (Cmax- currntGasVolum ) * gass[f].price;
                //cout<<"travl 2 free"<<free<<endl;
                currntGasVolum = Cmax - (double)(gass[gass[f].next].distace -gass[f].distace  ) / Davg;//到下一个加油站剩下的油为满油 减去跑完倒下一个加油站 的距离消耗的油
                f = gass[f].next;
            }else{
                free += ((double)(D- gass[f].distace)/Davg)*gass[f].price;
                //cout<<"travl 1 free:"<<free<<endl;
                f = gass[f].next;
                return;
            }

        }else{

            free +=((gass[gass[f].next].distace -gass[f].distace)/Davg -currntGasVolum )*gass[f].price;//加油加到能到达下一个加油站即可
            //cout<<"travl 3 free"<<free<<endl;
            currntGasVolum =0;//跑到下一个加油站油量为0
            f = gass[f].next;
        }

    }
    //cout<<"travl 4 free"<<free<<endl;
    free += (D - gass[e].distace - currntGasVolum*Davg)*gass[e].price; //计算最后一个加油站加油需要的花费

}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300

749.17

50 1300 12 2
7.10 0
7.00 600

The maximum travel distance = 1200.00
 */

int main(){
    /*
    scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N);//当前车辆最多装汽油 与目的城市的距离 每单位油走的距离 加油站的数量
    for (int i = 0; i <N; i++){
        scanf("%f%f",&gass[i].price,&gass[i].distace);//将加油站加入数组
       gass[i].next = -1;
    }
     */
    Cmax = 50;
    D = 1300;
    Davg = 12;
    N =8;
    for (int i = 0; i <N; i++){
        //scanf("%f%d",&gass[i].price,&gass[i].distace);//将加油站加入数组
        gass[i].next = -1;
    }
    gass[1].price = 6.0;
    gass[1].distace = 1250;
    gass[0].price = 7.0;
    gass[0].distace = 600;
    gass[2].price = 7.0;
    gass[2].distace = 150;
    gass[3].price = 7.10;
    gass[3].distace = 0;
    gass[4].price = 7.20;
    gass[4].distace = 200;
    gass[5].price = 7.5;
    gass[5].distace = 400;
    gass[6].price = 7.3;
    gass[6].distace = 1000;
    gass[7].price = 6.85;
    gass[7].distace = 300;


    sort(gass , gass + N ,cmp);//排序

    rids = Cmax * Davg;//每个加油站能够辐射的距离
    double free =0;//当前花费
    int index = N-1;//能到达的最后一个加油站位置
    currntGasVolum =0;
    getavilable( rids);//获取每个加油站能够辐射到加油站编号
    //for(int i = 0 ; i< N ; i++){
     //   cout<<gass[i].next;
   // }
   /*
   for (int i = 0 ; i< N ;i++ ){
       for(int j = 0 ; j< avliable[i].size();j++){
            cout<<avliable[i][j]<<" ";
        }
        cout<<endl;
   }
   */
    getNext(0);//获取所有能到达加油站能辐射到加油站中最便宜的
    //for(int i = 0 ; i< N ; i++){//avliaable 运行正常 get next 运行正常
    //    cout<<gass[i].next<<endl;
    //}
    //for (int i = 0 ; i< N ;i++ ){
       // printf("%04d %0.2f %02d\n",gass[i].distace,gass[i].price,gass[i].next);
       // cout<<gass[i].distace<<" "<<gass[i].price<<" "<<gass[i].next<<endl;
    //}

    bool flag = judge( index);//获取最后一个可以到达的加油站并且判断能能否到达目的地
    //cout<<index<<endl;
    //cout<<rids<<endl;
    if(!flag){//不能到达终点
        double dis = gass[index].distace+rids;
        printf("The maximum travel distance = %0.2f",dis);
       // cout<<(rids+gass[index].distace)<<endl;
    }else{
        travl(0,index, free);
        printf("%.2f",free);
    }
    return 0;
}
