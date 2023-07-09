// Before solving this problem we have to see Activity Selection Problem and Activity selection problem also contains two cases 
// Case 1:first one is in which the finish[] is already sorted 
// Case 2: and second one wher the finish[] is not sorted we have to made an stucture or combine both the start and finish array using vector of pair<int,int> 
// ans store the both arrays in one vector only and then sort that vector on the basis of finish array and then we have tp follow same steps like case one 

// Case 1 Code 

#include<bits/stdc++.h>
using namespace std;
void maximumActivitiesPerformed(int start[],int finish[],int size)
{
 int i,j;
   cout<<"Following Properties are selected"<<endl;

    i=0;
   cout<<i<<" ";

   for( j=1;j<size;j++)
   {
    if(start[j]>=finish[i])
    {
        cout<<j<<" ";
        i=j;
    }
   }
}
int main()
{
    int start[]={10,12,20};
    int finish[]={20,25,30};
    int size=3;

    maximumActivitiesPerformed(start,finish,size);
    return 0;
}

// Case 2 when the finish array is not sorted

