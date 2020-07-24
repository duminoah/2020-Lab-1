#include "StopWatch.h"
#include <ctime>
using namespace std;

// returns the amount of time in seconds that has passed since the process (i.e. your program) started executing 
double StopWatch::getProcessTime()
{
	clock_t time = clock();
	return static_cast<double>(time)/CLOCKS_PER_SEC;
}
StopWatch::StopWatch()
    {
        timeClock=0;
    }
double StopWatch::starTime()
    {
        return (timeClock=getProcessTime());
    }
double StopWatch::timElapsed()
    {
        return(getProcessTime()-timeClock);
    }
void StopWatch::reseTime()
    {
       starTime();
    }