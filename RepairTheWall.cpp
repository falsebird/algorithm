#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

//输入
//L N
//需要修补的矩形长度  可以使用的物体的数量

int cmp(int a ,int b){//从大到小排序
    return a > b;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 2 2
12 11
14 3
27 11 4
109 5
38 15 6 21 32
5 3
1 1 1

1
1
5
impossible
 */


int main(){
    int L,N;
    int A[605];
    bool flag ;
    int sum ;
    int num ;
    while(scanf("%d%d",&L,&N)!=EOF){

        for(int i = 0 ; i <N ; i ++){
            scanf("%d",&A[i]);
        }
        flag = false;
        num = 0;
        sum = 0;
        //cout<<"case 1"<<"falg:"<<flag<<"num: "<<num<<"sum: "<<sum<<endl;
        sort(A, A+N , cmp);
        for(int i = 0; i <N ; i ++){
            if((sum + A[i]) >= L){
                num++;
                flag = true;
                //cout<<"case 2"<<"i: "<<i<<"falg:"<<flag<<"num: "<<num<<"sum: "<<sum<<endl;
                break;
            }else{
                num++;
                sum += A[i];
                //cout<<"case 3"<<"i: "<<i<<"falg:"<<flag<<"num: "<<num<<"sum: "<<sum<<endl;
            }

        }
        if(flag){
            printf("%d\n",num);
        }else{
            printf("impossible\n");
        }
    }
    return 0;
}
