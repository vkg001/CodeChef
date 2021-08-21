#include<bits/stdc++.h>

using namespace std;



void Solve(int &tracks, int curr_tracks, queue<int> &possible_ways, int src, int &mid, map<int, list<int>> &arr, map<int, bool> &isVisited)
{
    if(curr_tracks <= tracks){
        if(src == mid){
            possible_ways.push(curr_tracks);
            return;
        }
    }else{
        return;
    }
    
    if(isVisited[src] == true)
        return;
        
        
    isVisited[src] = true;
    for(auto v: arr[src])
    {
        if(!isVisited[v])
        {
            Solve(tracks, curr_tracks+1, possible_ways, v, mid, arr, isVisited);
        }
    }
    isVisited[src] = false;
}



void FindAnswer(int &answer, int src, int &dest, map<int, list<int>> &arr, map<int, bool> &isVisited, int &tracks, int curr_tracks)
{
    if(curr_tracks == tracks  &&  src == dest)
    {
        answer++;
        return;
    }
    if(isVisited[src] == true)
        return;
        
    isVisited[src] = true;
    for(auto v: arr[src])
    {
        if(!isVisited[v])
        {
            FindAnswer(answer, v, dest, arr, isVisited, tracks, curr_tracks+1);
        }
    }
    isVisited[src] = false;
}




int main() {
    
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int n, links, a, b, i, src, dest, mid, tracks, answer = 0;
        map<int, list<int>> arr;
        map<int, bool> isVisited;
        queue<int> possible_ways;
                
        // INPUT
        cin >> n >> links ;
        for(i=0;  i<links;  i++)
        {
            cin >> a >> b;
            arr[a].push_back(b);
        }
        cin >> src >> mid >> dest >> tracks;
        
        // PROCESSING
        Solve(tracks, 0, possible_ways, src, mid, arr, isVisited);
        answer = 0;
        while(!possible_ways.empty())
        {
            int v = possible_ways.front();
            possible_ways.pop();
            FindAnswer(answer, mid, dest, arr, isVisited, tracks, v);
        }
        cout << answer << endl;
    }
	return 0;
}
