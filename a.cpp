/*
	CPSC 351 - Fall 2012
	Assignment #3
	Chapter 7: Banker's Algorithm
	Description: Multithreaded program. 
				 The banker will grant a request only if it leaves the system in a safe state. 
				 A request that leaves the system in an unsafe state will be denied. 
	Group Members: Harry Mora, Robert Rivas, Jennifer Peterson
	Date: 12/03/13
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

// Class Banker definition
class Banker{
	private:
		vector <int> seq;
		/* the available amount of each resource */
		int Available [5][3];
		/* the maximum demand of each customer */
		int Max [5][3];
		/* the amount currently allocated to each customer */
		int Allocation [5][3];
		/* the remaining need of each customer */
		int Need [5][3];
		// declarations
		int customer_num;
		int request[];
		bool successful;

		int np, nr, i, x, j, k, a;
	public:
		void request_resources(){
			if{// if successful return 0; request has been granted
				return false;
			}
			else{
				// if unsuccessful return -1
				return -1;
			}
		}
		void release_resources(){
			if{// if successful return 0; request has been granted
				return false;
			}
			else{
				// if unsuccessful return -1
				return -1;
			}
		}
		void GetVector()
		{
		    cout << "Enter the allocation matrix." << endl;
		    for (i = 0; i < 5; i++)
		    {
		    	for (j = 0; j < 3; j++)
		        {
		            cin >> x;
		            Allocation[i][j] = x;
		        }
		    }
		 
		    cout << "Enter the max matrix." << endl;
		    for (i = 0; i < 5; i++)
		    {
		        for (j = 0; j < 3; j++)
		        {
		            cin >> x;
		            Max[i][j] = x;
		            Need[i][j] = Max[i][j] - Allocation[i][j];
		        }
		    }
		    cout << "Need matrix." << endl;
		    for (i = 0; i < 5; i++)
		    {
		        for (j = 0; j < 3; j++)
		        {
		            cout << Need[i][j] << " ";
		        }
		        cout << endl;
		    }
		    cout << "Enter first entry of availability matrix." << endl;
		    for (j = 0; j < 2; j++)
		    {
		        cin >> x;
		        Available[0][j] = x;
		    }	
		}
		void Request()
		{
			int P;
			cout<<"Customer number 0-5"<<" "<<"Enter the request number "<<endl;
			cin >>P;
			switch (P)
		    {
		        case 1 : {
		        	cout<<"You have entered customer number 1"<<
		        			 " "<<"Please enter request number"<<endl;
		        		int x,i;
		        		int req[3];
		        		cin>>x;
		        		for (int j = 0; j < 2; j++)
		            {
		                cin >> x;
		                Available[0][j] = x;
		        		
		        		}
		        		if((req[3]<=Need[5][3])&&(req[3]<=Available[5][3]))
		        			 for (i = 0; i < 5; i++)
		            {
		                for (int j = 0; j < 3; j++)
		                {
		                    
		                    Available[i][j] = Available[i][j] - req[i];
		        			Need[i][j]=Need[i][j]-req[i];
		        			Allocation[i][j]=Allocation[i][j]+req[i];
		                }
		            }
		        		else
		        			cout<<"error"<<endl;
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
		void FindPath()
		{
			bool flag[5];
		    bool test = true;
		    for (i = 0; i < 5; i++)
		        flag[i] = false;
		    int cnt = 0;
		    while (cnt == 0)
		    {
		    for (i = 0; i < 5; i++)
		    {
		          if (flag[i] == false)
		          {
		              for (j = 0; j < 3; j++)
		              {
		                  if ((Need[i][j] > Available[i][j]))
		                     test = false;
		                  if ((Need[i][j] <= Available[i][j]))
		                     test = true;
		              }
		              if (test == true) 
		              {
		                     seq.push_back(i);
		                     for (k = 0; k < 3; k++)
		                     {
		                         Available[i][k] = Available[i][k] + Allocation[i][k];
		                     }
		                      flag[i] = true;
		              } 
		               
		              } 
		    } 
		    for (a = 0; a < 5; a++)
		    {
		        if (flag[a] == false)
		        {
		           cnt = 0;
		           break;
		        }
		        else
		            cnt++;
		    } 
		   
		    } 
		   
		    cout << "A possible sequence:" << endl;
		    for (i = 0; i < 5; i++)
		        cout << "P" << seq[i] << " -> ";
		    cout << endl;
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
	

	// create Banker Object
	Banker A;
	// class methods calls
	//A.GetVector();
	//A.Request();
	//A.FindPath();
	return(0);
}

/*
	I/O:


*/
