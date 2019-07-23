#include<bits/stdc++.h>

using namespace std;

int main(){
int noOfPage, noOfFrames;
char pageSeq[10000];

cout<<"\t **************************************************"<<endl;
cout<<"\t **********FIFO Page Replacement Algorithm*********"<<endl;
cout<<"\t **************************************************"<<endl<<endl;

cout<<"Enter total no of page: ";
cin>>noOfPage;
cout<<endl<<"Enter reference string: "<<endl;
for(int i=0; i<noOfPage; i++)
{
    cin>>pageSeq[i];
}

cout<<endl<<"Enter total no of frames: ";
cin>>noOfFrames;

char frames[noOfFrames+1] = {-1};
int PF = 0;
int done = 0;
for(int i=0; i<noOfFrames; i++)
{
    PF++;
    frames[i] = pageSeq[i];
    
    cout<<endl<<pageSeq[i]<<"\t";
    for(int j=0; j<noOfFrames; j++)
    {
        cout<<"+---------------";
    }
    cout<<"+"<<endl<<"\t|";
    
    for(int j=0; j<noOfFrames; j++){
        if(frames[j]==-1)
            cout<<"\t\t";
        else
            cout<<"\t"<<frames[j];
        cout<<"\t"<<"|";
    }
    cout<<endl;
cout<<"\t";
    for(int j=0; j<noOfFrames; j++)
    {
        cout<<"+---------------";
    }
    cout<<"+"<<endl<<endl;
    if(i>=noOfPage-1)
    {
        done = 1;
        break;
    }
        
}
    for(int i=noOfFrames; i<noOfPage; i++)
    {
        int found = 0;
        for(int j=0; j<noOfFrames; j++)
        {
         if(pageSeq[i]==frames[j])
        {
            found = 1;
            break;
         }
    }
    if(found == 0)
    {
        PF++;
        int j=0;
        for(j=0; j<noOfFrames-1; j++)
        {
            frames[j] = frames[j+1];
        }
        frames[j] = pageSeq[i];
    }
    
    cout<<endl<<pageSeq[i]<<"\t";
    for(int j=0; j<noOfFrames; j++)
    {
        cout<<"+---------------";
    }
    cout<<"+"<<endl<<"\t|";
    
    for(int j=0; j<noOfFrames; j++){
        if(frames[j]==-1)
            cout<<"\t";
        else
            cout<<"\t"<<frames[j];
        cout<<"\t"<<"|";
    }
    cout<<endl;
cout<<"\t";
    for(int j=0; j<noOfFrames; j++)
    {
        cout<<"+---------------";
    }
    cout<<"+"<<endl<<endl;
} 
cout<<endl<<"Total Page Fault: "<<PF<<endl;


return 0;
}