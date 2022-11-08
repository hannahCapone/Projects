// Hannah Capone
// First Come First Served

#include <iostream>
#include <queue> // for use of queue as data structure
#include <utility> // for use of pair
#include <signal.h>
#include <unistd.h>
#include <math.h>


using namespace std;

int main()
{

	queue<pair<string, int> > processes;

	int waitingTimes = 0;
	int turnaroundTimes = 0;
	int count = 0;
    

    string name;
  	int time;
  	int totalruntime = 0;

  	// Read the list until end of transmission
    while (cin >> name >> time)
    {
    	pair<string,int> pair;
    	pair.first = name;
    	pair.second = time;

    	processes.push(pair);
    	count++;
    }
    cout << endl;
    
    queue<double> forThroughput;

    double i = 0.0;
   
    // FCFS Simulation
    while (!processes.empty())
    {
    	i++;
    	pair<string, int> temp;
	    temp = processes.front();

	   	processes.pop();
	   	
	    sleep(temp.second);

	   	cout << temp.first << " Finished" << endl;	
	   	waitingTimes += totalruntime;
	   	totalruntime += temp.second; 
	   	turnaroundTimes += totalruntime;
	   	forThroughput.push(i/totalruntime);
	   	//cout << "### Adding to queue: " << i << "/" << totalruntime << endl;
	   	cout << "Total Time running: " << totalruntime << endl;   		
	   	
	   	
    }
    cout << "no processes left" << endl;

    cout << endl;

    cout << "Average Waiting time: " << waitingTimes/count << endl;
    cout << "Average Turnaround time: " << turnaroundTimes/count << endl;

    // Average Throughput

    double avThrough = 0.0;
    while(!forThroughput.empty())
    {
    	avThrough = avThrough + forThroughput.front();
    	forThroughput.pop();
    }
    avThrough = avThrough/count;
    cout.precision(3);
    cout << "Average Throughput: " << avThrough<< endl;
}
