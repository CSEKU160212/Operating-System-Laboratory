#include<bits/stdc++.h>

using namespace std;

//process structure
struct process
{
    string processName;
    //double processArrivalTime;
    double priority;
    double processBurstTime;
    double turnaroundTime;
    double waitingTime;
    double completionTime;
};
void display_gantt_chart(process all_process_array[], int no_of_process); //function prototype for gantt_chart
void FCFS(int no_of_process, process all_process_array[]);

bool acompare(process lft, process rht)
{
    /*if(lft.processArrivalTime<rht.processArrivalTime)
    {
        return lft.processArrivalTime<rht.processArrivalTime;
    }
    else if(lft.processArrivalTime == rht.processArrivalTime)
    {
        return lft.processBurstTime < rht.processBurstTime;
    }
    else if(lft.processBurstTime <= rht.processBurstTime)
    {
        return lft.processArrivalTime < rht.processArrivalTime;
    }
    else
    {*/
        return lft.priority < rht.priority;
   // }
        
}


int main()
{
     cout<<"****Non-Preemtive Priority Scheduling Algorithm****"<<endl;
    cout<<"****Considering arrival time = 0 ****"<<endl<<endl;

    int no_of_process; //total no of process

    cout<<"Enter total no of process: ";
    cin>>no_of_process;

    process all_process_array[no_of_process]; //new process type array
    cout<<endl;
    for(int i=0; i<no_of_process; i++)          //input
    {
        cout<<"Enter the Name of process "<<i+1<<": ";
        cin>>all_process_array[i].processName;
        //cout<<"Enter the Arrival Time of process "<<i+1<<": ";
        //cin>>all_process_array[i].processArrivalTime;
        cout<<"Enter the Burst Time of process "<<i+1<<": ";
        cin>>all_process_array[i].processBurstTime;
        cout<<"Enter the Burst Priority of process "<<i+1<<": ";
        cin>>all_process_array[i].priority;
        
        all_process_array[i].turnaroundTime = all_process_array[i].waitingTime = 0;
        all_process_array[i].completionTime = 0;
        cout<<endl;
    }

    sort(all_process_array, all_process_array+no_of_process, acompare);



    FCFS(no_of_process, all_process_array);
  
    return 0;
}

void display_gantt_chart(process all_process_array[], int no_of_process)
{
    cout<<"\t\"Gantt Chart\""<<endl<<"\t-------------"<<endl<<"-";
    for(int i=0; i<no_of_process; i++)
    {
        int nameLength = all_process_array[i].processName.size();
        for(int j=0; j<(int)all_process_array[i].processBurstTime; j++)
        {
            cout<<"--";
        }
        for(int j=0; j<nameLength; j++)
        {
            cout<<"-";
        }
        cout<<"-";
    }


    cout<<endl<<"|";
    for(int i=0; i<no_of_process; i++)
    {
        for(int j=0; j<(int)all_process_array[i].processBurstTime; j++)
        {
            cout<<" ";
        }
        cout<<all_process_array[i].processName;

        for(int j=0; j<(int)all_process_array[i].processBurstTime; j++)
        {
            cout<<" ";
        }
        cout<<"|";
    }

    cout<<endl<<"+";
    for(int i=0; i<no_of_process; i++)
    {
        int nameLength = all_process_array[i].processName.size();
        for(int j=0; j<(int)all_process_array[i].processBurstTime; j++)
        {
            cout<<"--";
        }
        for(int j=0; j<nameLength; j++)
        {
            cout<<"-";
        }
        cout<<"+";
    }
}

void FCFS(int no_of_process, process all_process_array[]){
   all_process_array[0].turnaroundTime = all_process_array[0].processBurstTime;
    for(int i=1; i<no_of_process; i++)
    {
        all_process_array[i].waitingTime = all_process_array[i-1].waitingTime+ all_process_array[i-1].processBurstTime;
        all_process_array[i].turnaroundTime = all_process_array[i].waitingTime + all_process_array[i].processBurstTime;
    }

    int totalWaitingTime = 0;
    for(int i=0; i<no_of_process; i++)
    {
        totalWaitingTime +=all_process_array[i].waitingTime;
    }
    double avgWaitingTime = totalWaitingTime / (double)no_of_process;

    display_gantt_chart(all_process_array, no_of_process);

    cout<<endl<<0;

    for(int i = 0; i<no_of_process; i++)
    {
        int nameLength = all_process_array[i].processName.size();
        for(int j=0; j<all_process_array[i].processBurstTime; j++)
        {
            cout<<"  ";
        }
        for(int j=0; j<nameLength; j++)
        {
            cout<<" ";
        }
        if(all_process_array[i].turnaroundTime > 9)
            cout<<"\b";
        cout<<all_process_array[i].turnaroundTime;
    }

    cout<<endl<<endl<<"\tTurnaround Time:"<<endl<<"\t----------------"<<endl;
    for(int i=0; i<no_of_process; i++)
    {
        cout<<"Process_Name: "<<all_process_array[i].processName<<"\tTurnaround_Time: "<<all_process_array[i].turnaroundTime<<endl;
    }

    cout<<endl<<endl;

    cout<<"\tWaiting Time:"<<endl<<"\t-------------"<<endl;
    for(int i=0; i<no_of_process; i++)
    {
        cout<<"Process_Name: "<<all_process_array[i].processName<<"\tWaiting_Time: "<<all_process_array[i].waitingTime<<endl;
    }
    cout<<endl<<endl;
    cout<<"Total waiting time: "<<totalWaitingTime<<endl;
    cout<<"Average waiting time: "<<avgWaitingTime<<endl;

}
