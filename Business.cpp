#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
/** \brief
 *As the manager of your company, you have to carefully consider, for each project,
 the time taken to finish it, the deadline, and the profit you can gain,
 in order to decide if your group should take this project. For example, given 3 projects as the following:

    Project[1] takes 3 days, it must be finished in 3 days in order to gain 6 units of profit.
    Project[2] takes 2 days, it must be finished in 2 days in order to gain 3 units of profit.
    Project[3] takes 1 day only, it must be finished in 3 days in order to gain 4 units of profit.

You may take Project[1] to gain 6 units of profit. But if you take Project[2] first,
then you will have 1 day left to complete Project[3] just in time, and hence gain 7 units of profit in total.
Notice that once you decide to work on a project, you have to do it from beginning to the end without any interruption.
    使用回溯法
 * \param
 * \param
 * \return
 *
 */

using namespace std;
struct project{
    int profit;
    int lasting;
    int deadline;

}Pro;

void travle(int index , vector<project> proList,){

}


int main(){
    vector<project> proList;
    int n ;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++){
        scanf("%d%d%d",&Pro.profit,&Pro.lasting,&Pro.deadline);
        proList.push_back(Pro);
    }



    return 0;
}
