#include<bits/stdc++.h>

using namespace std;

int main(){
int noOfPage, noOfFrames;
char pageSeq[10000];

cout<<"\t **************************************************"<<endl;
cout<<"\t **********LRU Page Replacement Algorithm**********"<<endl;
cout<<"\t **************************************************"<<endl<<endl;

cout<<"Enter total no of page: ";
cin>>noOfPage;
cout<<endl<<"Enter reference string: "<<endl;
for(int i=0; i<noOfPage; i++){
    cin>>pageSeq[i];
}

cout<<endl<<"Enter total no of frames: ";
cin>>noOfFrames;

char frames[noOfFrames] = {-1};
int PF=0;
int frameNo = 0;
for(int i=0; i<noOfPage; i++)
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
   if(found == 0){
        PF++;
        if(frameNo < noOfFrames){
            frames[frameNo] = pageSeq[i];
            frameNo++;
        }
        else
        {
            int level[noOfFrames]={0};
            for(int j=i; j>=0; j--)
            {
                for(int k=i; k>=0; k--)
                {
                    if(frames[j] == pageSeq[k])
                    {
                        level[j] = i-k;
                        break;
                    }
                }
            }
            /*
            for(int k=0; k<noOfFrames; k++)
                cout<<endl<<"Level  "<<level[k]<<endl;
              */  
                int max = 0;
                for(int k=0; k<noOfFrames; k++)
                {
                    if(level[k]>=max)
                        max = level[k];
                }
                int flag = 0;
                for(int k=0; k<frameNo; k++)
                {
                    if(level[k]==0)
                    {
                        frames[k] = pageSeq[i];
                        flag = 1;
                        break;
                    }    
                }
                if(flag==0)
                {
                    for(int k=0; k<frameNo; k++)
                    {
                        if(level[k]==max)
                        {
                           frames[k] = pageSeq[i];
                            flag = 1;
                           break;
                       }
                        
                    }   
                 }
        }
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

cout<<endl<<"Total Page Fault = "<<PF<<endl;

    return 0;
}