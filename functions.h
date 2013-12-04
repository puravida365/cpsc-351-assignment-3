void AvailabletoWork(){}
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			Work[i][j] = Available[i][j];
		}
	}
}
void printResources(){
	cout << "Resources-" << m << " " << resources[m] << endl;
}


		void Request()
		{
			int P;
			cout<<" Customer number 0-5 " << " " << "Enter the request number: " << endl;
			cin >>P;
			switch (P)
		    {
		        case 1 : {
		        	cout << "You have entered customer number 1" << " " << "Please enter request number" <<endl;
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