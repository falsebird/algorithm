#include<cstring>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
struct student{
    int id;
    char name[100];
    int score;

}stuList[100000];


int cmp1(student s1 , student s2){
    return s1.id>s2.id;
}
int cmp2(student s1 , student s2){
    return strcmp(s1.name ,s2.name);
}
int cmp3(student s1 , student s2){
    return s1.score >s2.score;
}

int main(){
    int N,C;
    while(scanf("%d%d",&N,&C)!=EOF){
        for(int i = 0 ; i < N ; i++){
           scanf("%d%s%d",stuList[i].id,stuList[i].name,stuList[i].score);

        }
        switch(C){
        case 1:
            sort(stuList, stuList+N , cmp1);
            break;
        case 2:
            sort(stuList, stuList+N , cmp2);
            break;
        case 3:
            sort(stuList, stuList+N , cmp3);
            break;
        }
        printf("Case %d:\n",C);
        for(int i = 0 ; i < N ; i++){
            printf("%06d ",stuList[i].id);
            printf("%d " ,stuList[i].name);
            printf("%02d\n",stuList[i].score);

        }


    }

    return 0;
}
