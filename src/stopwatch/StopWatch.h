#ifndef STOPWATCH_H
#define STOPWATCH_H

// returns the amount of time in seconds that has passed since the process (i.e. your program) started executing 
class StopWatch{
	public:
	    StopWatch();
	    double starTime();
	    double timElapsed();
	    void reseTime();
	    double getProcessTime();
	private:
	    double timeClock;
};

#endif
