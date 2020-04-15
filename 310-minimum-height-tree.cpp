class Solution {
public:
    
        int bfs(int start, map<int, vector<int>> graph, int n){
        int ans = 0;
        vector<bool> visited(n,0);
        queue<int> q;
        q.push(start);
        visited[start]=1;
        q.push(-1);
        
        while(!q.empty() && !(q.size()==1)){
            int x = q.front();
            q.pop();
            if(x==-1){                
                q.push(-1);
                ans++;
            }else{
                for(int i=0;i<graph[x].size();i++){
                    if(!visited[graph[x][i]]){
                        visited[graph[x][i]]=1;
                        q.push(graph[x][i]);
                    }                        
                }
            }
        }
        
        return ans;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        map<int, vector<int>> graph;
        vector<int> inDegree(n,0);
        vector<bool> visited(n,0);
        vector<int> ans;
        for(int i=0;i<edges.size();i++){
            inDegree[edges[i][0]]++;
            inDegree[edges[i][1]]++;
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(inDegree[i]==1 || inDegree[i]==0)
                q.push(i), visited[i]=1;
        }
        q.push(-1);
        
        
        while(!q.empty() && q.size()!=1){
            int x = q.front();        
            q.pop(); 
            if(x==-1){
                if(q.size()==0)
                    break;
                else{
                    ans.clear(); 
                    q.push(-1);
                }
                    
            }else{
                ans.push_back(x);
                for(int i=0;i<graph[x].size();i++){
                    inDegree[graph[x][i]]--;
                    if(inDegree[graph[x][i]]==1 && !visited[graph[x][i]]){
                        q.push(graph[x][i]);    
                        visited[graph[x][i]]=1;                    
                    }                                                                                 
                }
            }
           }

        
        return ans;
        
        
        /*  gives TLE
        vector<int> currans;   
        int currmin = INT_MAX;
        
        for(int i=0;i<n;i++){
            int temp = bfs(i, graph, n);
            if(temp>currmin)
                continue;
            if(temp<currmin){
                currans.clear();
                currmin=temp;
            }                
            currans.push_back(i);
        }
        
        return currans;
        */
        
    
    }
};
