#include<bits/stdc++.h>

using namespace std;

struct process{
    string processName;
    double processBurstTime;
    double waitingTime;
    double turnarroundTime;
    double remainingTime;
};


void display_gantt_chart(process all_process_array[], int size_of_array);


int main()
{
    int quantumTime;
    int no_Of_Process;

    cout<<"***Round-Robin Scheduling Algorithm***"<<endl<<"Considering Arival time = 0"<<endl<<endl;
    cout<<"Enter the Total No of Process: ";
    cin>>no_Of_Process;
    cout<<"Eneter Quantum Time: ";
    cin>>quantumTime;

    double total_Waiting_Time = 0;
    double total_turnaround_time = 0;
    int time=0;
    process all_process_array[no_Of_Process];

    cout<<endl<<endl;
    for(int i=0; i<no_Of_Process; i++)
    {
        cout<<"Enter Process name of Process "<<i+1<<" : ";
        cin>>all_process_array[i].processName;
        cout<<"Enter Burst time of process "<<i+1<<" : ";
        cin>>all_process_array[i].processBurstTime;
        all_process_array[i].waitingTime = all_process_array[i].turnarroundTime = 0;
        all_process_array[i].remainingTime = all_process_array[i].processBurstTime;
        cout<<endl<<endl;
    }
    //waiting time calculation
    while(1)
    {
        int workdone = 1;
        for(int i=0; i<no_Of_Process; i++)
        {
            if(all_process_array[i].remainingTime > 0)
            {
               workdone = 0;
               if(all_process_array[i].remainingTime > quantumTime)
               {
                   time += quantumTime;
                   all_process_array[i].remainingTime -=quantumTime;
               } 
               else
               {
                   time += all_process_array[i].remainingTime;
                   all_process_array[i].waitingTime = time - all_process_array[i].processBurstTime;
                   all_process_array[i].remainingTime = 0;
               }
            }
        }
        if(workdone == 1) break;
    }

    //turnaround time caluclation

    for(int i=0; i<no_Of_Process; i++)
    {
        all_process_array[i].turnarroundTime = all_process_array[i].waitingTime + all_process_array[i].processBurstTime;
    }

    for (int i=0; i<no_Of_Process; i++)
    {
        total_Waiting_Time = total_Waiting_Time + all_process_array[i].waitingTime;
        total_turnaround_time += all_process_array[i].turnarroundTime;
    }
    
    cout<<endl<<endl;

     cout<<endl<<endl<<"\tTurnaround Time:"<<endl<<"\t----------------"<<endl;
    for(int i=0; i<no_Of_Process; i++)
    {
        cout<<"Process_Name: "<<all_process_array[i].processName<<"\tTurnaround_Time: "<<all_process_array[i].turnarroundTime<<endl;
    }

    cout<<endl<<endl;

    cout<<"\tWaiting Time:"<<endl<<"\t-------------"<<endl;
    for(int i=0; i<no_Of_Process; i++)
    {
        cout<<"Process_Name: "<<all_process_array[i].processName<<"\tWaiting_Time: "<<all_process_array[i].waitingTime<<endl;
    }
    cout<<endl<<endl;
    cout<<"Total waiting time: "<<total_Waiting_Time<<endl;
    cout<<"Average waiting time: "<<total_Waiting_Time / (double)no_Of_Process <<endl;

    return 0;
}
