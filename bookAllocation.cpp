#include<bits/stdc++.h>
using namespace std;

int countStudents(vector<int> arr,int mid)
{   int size=arr.size();
    int students=1;
    long long PagesStudent=0;
    for(int i=0;i<size;i++)
    {
        if(PagesStudent+arr[i]<=mid)
        {
            PagesStudent+=arr[i];
        
        }
        else{
            students+=1;
            PagesStudent=arr[i];
        }
    }
    return students;
}
int findPages(vector<int> arr,int size,int student)
{
    if(student>size) return -1;

    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);

    while(low<high)
    {
        int mid=(low+high)/2;
        int m=countStudents(arr,mid);
        if(m>student)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
int main()
{
    vector<int> arr={10,20,30,40};
    int size=arr.size();
    int student=2;
    cout<<findPages(arr,size,student);
}
