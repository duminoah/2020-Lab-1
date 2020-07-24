#include <iostream>
#include "StopWatch.h"
using namespace std;

int main(void){
    StopWatch stopWtchObj;

    stopWtchObj.starTime();
//*******CLIENT'S CODE_1********

    int num=10;
    for (int x=0; x<50000000 ;x++){num=num*x;}

//-----------------------------
    auto elpsT=stopWtchObj.timElapsed();
    cout<<"The Runtime for Client's code 1 is: "<<elpsT<<" seconds"<<endl;

    stopWtchObj.reseTime();
//*******CLIENT'S CODE_2********

    num=10;
    for (int x=0; x<50000 ;x++){num=num*x;}

//-----------------------------

    elpsT=stopWtchObj.timElapsed();
    cout<<"The Runtime for client's code 2 is: "<<elpsT<<" seconds"<<endl;

return 0;
}
