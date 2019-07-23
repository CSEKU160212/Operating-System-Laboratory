#include<bits/stdc++.h>

using namespace std;
int main()
{
    int LogicalMemorySize, PhysicalMemorySize, PagingUnitSize, LogicalMAddress, p, d;
    cout<<"Logical Memory Size (K): ";
    cin>>LogicalMemorySize;

    cout<<"Physical Memory Size (K): ";
    cin>>PhysicalMemorySize;


    cout<<"Paging Unit Size (K): ";
    cin>>PagingUnitSize;

    int LogicalMemoryBlock = int(LogicalMemorySize / PagingUnitSize);
    int PhysicalMemoryBlock = int(PhysicalMemorySize / PagingUnitSize);

    int PageTable[PhysicalMemoryBlock+1];

    for(int i=0; i<PhysicalMemoryBlock; i++)
    {
        cout<<"Frame no "<<i<<": ";
        cin>>PageTable[i];
    }

    cout<<"Enter Logical Address: ";
    cin>>LogicalMAddress;

    p = LogicalMAddress / (PagingUnitSize*1024);
    d = LogicalMAddress % (PagingUnitSize*1024);

    int PhysicalMAddress = PageTable[p] * 1024 * PagingUnitSize + d;

    cout<<endl<<"\tLogical Memory\n\t--------------"<<endl;
    cout<<"---------------------"<<endl;
    for(int i=0; i<LogicalMemoryBlock; i++)
        {
            cout<<"|";
            cout<<i*PagingUnitSize<<"K-"<<i*PagingUnitSize+PagingUnitSize<<"K";
            cout<<"|";
            cout<<" Frame "<<i;
            if(i<10) cout<<" ";
            cout<<"|"<<endl;
            cout<<"---------------------"<<endl;
        }
    cout<<endl<<endl;
    cout<<endl<<"\tPage table\n\t-----------"<<endl;
    cout<<"---------"<<endl;
    for(int i=0; i<PhysicalMemoryBlock; i++)
    {
        cout<<"| ";
        cout<<i<<" | "<<PageTable[i]<<" |"<<endl;
        cout<<"---------"<<endl;
    }
    cout<<endl<<endl;
    cout<<endl<<"\tPhysical Memory\n\t-----------"<<endl;
    cout<<"-------------------"<<endl;
    for(int i=0; i<PhysicalMemoryBlock; i++)
    {
            cout<<"|";
            cout<<i*PagingUnitSize<<"K-"<<i*PagingUnitSize+PagingUnitSize<<"K";
            cout<<"|";
            cout<<" Frame "<<i;
            if(i<10) cout<<" ";
            cout<<"|";
            if(i == PageTable[p]) cout<<" <-----";
            cout<<endl;
            cout<<"-------------------"<<endl;
    }

    return 0;
}