// Hannah Capone
// Round-robin Simulation

#include <iostream>
#include <queue> // for use of queue as data structure
#include <utility> // for use of pair
#include <signal.h>
#include <unistd.h>


using namespace std;

const int TIMESLICE = 3;
bool alarmFired = false; // flag

// define alarm handler
void sigalarm_handler(int signum)
{
	alarmFired = true;
}

int main()
{
	signal(SIGALRM, sigalarm_handler);
	alarm(TIMESLICE);

	queue<pair<string, int> > processes;

    string name;
  	int time;

  	// Read the list until end of transmission
    while (cin >> name >> time)
    {
    	pair<string,int> pair;
    	pair.first = name;
    	pair.second = time;

    	processes.push(pair);
    }
    cout << endl;
    
    // RR Simulation
    while (!processes.empty())
    {
    	pair<string, int> temp;
	    temp = processes.front();

	   	processes.pop();
	   	
	   	// alarm to schedule timer 
	   	alarm(TIMESLICE);
	   	if (alarmFired)
	   	{
	   		sleep(temp.second);
	   	}

	   	// update time left
	   	temp.second -= TIMESLICE;

	   	if (temp.second <= 0)
	   	{
    		cout << temp.first << " Finished" << endl;	    		
	   	}
	    else
		{
			cout << temp.first << " " << temp.second << endl;
			processes.push(temp);
		}
	   	
    }
    cout << "no processes left" << endl;
}