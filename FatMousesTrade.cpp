#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 1000;

struct Room{
    double J,F;//J[i] pounds of JavaBeans and requires F[i] pounds of cat food
    double avg;//average cat food can get avg javaBean
    Room(){}
    Room(double _J ,double _F){
        J = _J;
        F = _F;
        avg = _J/_F;
    }
};

int cmp(Room r1 , Room r2){// sort as avg decrease;
    if(r1.avg != r2.avg)
        return r1.avg > r2.avg;
    else
        return r1.F > r2.F;
}


/** \brief
 *  he may get J[i]* a% pounds of JavaBeans if he pays F[i]* a% pounds of cat food

 For each test case, print in a single line a real number accurate up to 3 decimal places,
  which is the maximum amount of JavaBeans that FatMouse can obtain.
 * \param M pounds of cat food
 * \param N warehouse has N Rooms
 * \param i-th Room contains J[i] pounds of JavaBeans and requires F[i] pounds of cat food
 * \param
 * \param
 * \return
 *
 */
void tread(int index , int N , int M, double &maximum ,vector<Room> viRooms){

    if(index >=N){//travles to last room
        return ;
    }
    if(M > viRooms[index].F){
            maximum +=viRooms[index].J;
        tread(index +1 , N , M - viRooms[index].F ,maximum ,viRooms);
    }else{
        maximum += M * viRooms[index].avg;
        index = index -1;
        M = 0 ;
        return;
    }
}

int main(){

    int M,N;
    scanf("%d%d",&M,&N);
    vector<Room> viRooms;
    double maximum = 0;
    double jj ,ff;
    while(M !=-1 ||N != -1 ){
        for(int i = 0 ; i < N; i ++){
            scanf("%lf%lf",&jj,&ff);
            viRooms.push_back(Room(jj,ff));
        }
        sort(viRooms.begin() , viRooms.end() , cmp);
        /*
        for(int i = 0 ; i < N; i ++){
            printf("%0.3f %0.3f %0.3f\n", viRooms[i].J, viRooms[i].F , viRooms[i].avg);
        }
        */
        tread(0,N,M,maximum , viRooms);
        printf("%0.3f\n",maximum);
        scanf("%d%d",&M,&N);//while input was two -1 stop the loop
    }
    return 0;
}

