class Solution {
public: 
    int dfs(map<int, Employee*> &graph, int pos){
        int sum = graph[pos]->importance;
        for(int i=0; i<graph[pos]->subordinates.size(); i++){
            sum+=dfs(graph, graph[pos]->subordinates[i]);
        }
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> graph;
        int n =employees.size();
        
        for(int i=0;i<n;i++){
            graph[employees[i]->id]=employees[i];    
        }        
        return dfs(graph, id);    
    }
};
