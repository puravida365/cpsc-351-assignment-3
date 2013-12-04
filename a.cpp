/*
	CPSC 351 - Fall 2012
	Assignment #3
	Chapter 7: Banker's Algorithm
	Description: Multithreaded program. 
				 The banker will grant a request only if it leaves the system in a safe state. 
				 A request that leaves the system in an unsafe state will be denied. 
	Group Members: Harry Mora, Robert Rivas
	Date: 12/03/13
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

// Class Banker
class Banker{
	private:
		// declarations
		//vector <int> seq;
		int processes[];
		int resources[];
		int request[];
		int customer_num;
		int n; // number of processes
		int r; // number of resources

		/* the available amount of each resource */
		int Available [5][3];

		/* the maximum demand of each customer */
		int Max [5][3];

		/* the amount currently allocated to each customer */
		int Allocation [5][3];

		/* the remaining need of each customer */
		int Need [5][3];

		int Work [5][3];
		int Finish[5];
		
		bool successful = false;

		int i, x, j, k, a;
	public:
		Banker(char **argv, int argc){
			for(int m = 0; m < argc; m++)
			{
				resources[m] = atoi(argv[m]);
			}

		}
		void GetVector()
		{
		    cout << "Enter Allocation matrix:" << endl;
		    for (i = 0; i < 5; i++)
		    {
		    	for (j = 0; j < 3; j++)
		        {
		            cin >> x;
		            Allocation[i][j] = x;
		        }
		    }
		 
		    cout << "Enter Max matrix:" << endl;
		    for (i = 0; i < 5; i++)
		    {
		        for (j = 0; j < 3; j++)
		        {
		            cin >> x;
		            Max[i][j] = x;
		            Need[i][j] = Max[i][j] - Allocation[i][j];
		        }
		    }
		    cout << "Need matrix:" << endl;
		    for (i = 0; i < 5; i++)
		    {
		        for (j = 0; j < 3; j++)
		        {
		            cout << Need[i][j] << " ";
		        }
		        cout << endl;
		    }
		    
		    /*
		    cout << "Enter first entry of availability matrix." << endl;
		    for (j = 0; j < 2; j++)
		    {
		        cin >> x;
		        Available[0][j] = x;
		    }	
		    */
		}
		void Request()
		{
			int P;
			cout<<" Customer number 0-5 " << " " << "Enter the request number: " << endl;
			cin >>P;
			switch (P)
		    {
		        case 1 : {
		        	cout << "You have entered customer number 1" << " " << "Please enter request number" << endl;
		        		int x,i;
		        		int req[3];
		        		cin >> x;
		        		for (int j = 0; j < 2; j++){
			                cin >> x;
			                Available[0][j] = x;
			        	}
		        		if((req[3]<=Need[5][3])&&(req[3]<=Available[5][3]))
		        			for (i = 0; i < 5; i++){
			                	for (int j = 0; j < 3; j++){
			                    	Available[i][j] = Available[i][j] - req[i];
			        				Need[i][j]=Need[i][j]-req[i];
			        				Allocation[i][j]=Allocation[i][j]+req[i];
			        			}
			            	}
		        		else
		        			cout << "error" << endl;
		        		};
		        break;
		        case 2 : cout << "Bravo";
		        break;
		        case 3 : cout << "Charlie";
		        break;
		        case 4 : cout << "Delta";
		        break;
		        case 5 : cout << "Echo";
		        break;
		    }
		}
		bool request_resources(){
			if(true){// if successful return 0; request has been granted
				return false;
			}
			else{
				// if unsuccessful return -1
				return -1;
			}
		}
		bool release_resources(){
			if(true){// if successful return 0; request has been granted
				return false;
			}
			else{
				// if unsuccessful return -1
				return -1;
			}
		}
		void mutexLock(){
			// mechanism to avoid race conditions 
		}
};
/*
	Main function. 
	Accepts arguements from command line.
	Number of resources for each type should be passed
	Example: 10 instances of 1st type, 5 of second type, 7 of third type
	Example program run from command line: ./a.out 10 5 7
*/
int main( int argc, char* argv[] )
{
	// create Banker Object
	Banker A(argv, argc);
	// class methods calls
	A.GetVector();
	//A.Request();
	//A.FindPath();
	return(0);
}

/*
	I/O:


*/
