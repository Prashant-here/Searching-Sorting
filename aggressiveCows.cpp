// Problem of Hard Binary Search 

#include <bits/stdc++.h>         // TC O(n*m) SC O(1)   

using namespace std;
bool isCompatible(vector < int > inp, int dist, int cows) {
  int n = inp.size();
  int k = inp[0];
  cows--;
  for (int i = 1; i < n; i++) {
    if (inp[i] - k >= dist) {
      cows--;
      if (!cows) {
        return true;
      }
      k = inp[i];
    }
  }
  return false;
}
int main() {
  int n = 5, m = 3;
  vector<int> inp {1,2,8,4,9};
  sort(inp.begin(), inp.end());
  int maxD = inp[n - 1] - inp[0];
  int ans = INT_MIN;
  for (int d = 1; d <= maxD; d++) {
    bool possible = isCompatible(inp, d, m);
    if (possible) {
      ans = max(ans, d);
    }
  }
  cout << "The largest minimum distance is " << ans << '\n';
}


// Using Binary Search 
// O(n*logm)       SC O(1)
#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> arr,int mid,int k)
{
     int cntcows=1;
    
     int lastPlacedCows=arr[0];
     for(int i=1;i<arr.size();i++)
     {
        if(arr[i]-lastPlacedCows>=mid)
        {
            cntcows++;
            lastPlacedCows=arr[i];
        }
     }
     if(cntcows>=k) return true;
     else return false;
}
int findAggressiveCows(vector<int> arr,int size,int k)
{
    sort(arr.begin(),arr.end());
    int low=0,high=arr[size-1]-arr[0];
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(canWePlace(arr,mid,k)==true)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}
int main()
{
    vector<int> arr={0,3,4,7,9,10};
    int size=arr.size();
    int k=4;
    cout<<findAggressiveCows(arr,size,k);
    return 0;
}
