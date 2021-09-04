#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, evpos, odpos, evnum, odnum, ans = 0;
        evnum = odnum = 0;
        cin >> n;
        int arr[n];
        for(i=0;  i<n;  i++)
        {
            cin >> arr[i];
            if(arr[i]&1){
                odnum++;
            }else{
                evnum++;
            }
        }
        
        
        if(n&1){
            odpos = (n/2)+1;
            evpos = n-odpos;
        }else{
            odpos = evpos = (n/2);
        }
        
        
        ans += min(odpos, evnum);
        ans += min(evpos, odnum);
        
        cout << ans << endl;
    }
	return 0;
}
