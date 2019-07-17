#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
struct tv{
    int si;//开始时间
    int ei;//结束时间

    bool selected;
}TV;

int cmp(tv t1, tv t2){//按照结束时间非递减排序 ,当结束时间相等时按照开始时间非递增排序
    if(t1.ei!=t2.ei)
        return t1.ei<t2.ei;
    else
        return t1.si > t2.si;
}

int main(){
    int n ;
    vector<tv> tvlist;
    int endtime;//记录当前正在看的节目的结尾时间
    int num ;//记录当前已经看的揭开节目数
    while(scanf("%d",&n)!=EOF){
        endtime =0 ;//初始化数据，清空vector
        num =0;
        tvlist.clear();//
        for (int i = 0; i < n ;i++ ){
            scanf("%d%d",&TV.si,&TV.ei);
            TV.selected =false;
            tvlist.push_back(TV);
        }
        scanf("%d",&endtime);
        sort(tvlist.begin(),tvlist.end(),cmp);//按照电视节目结束的时间非递减排序
        vector<tv>::iterator it = tvlist.begin();
        while(it !=tvlist.end()){
            if(it->si >=endtime){
                it->selected = true;
                num++;
                endtime = it->ei;
            }
            it++;
        }
        printf("%d",num);
    }

    return 0;
}
