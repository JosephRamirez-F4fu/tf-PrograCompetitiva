
#include<vector>
using namespace std;
class Grafo
{
    public:
    int nodes;
    vector<vector<int>>LA;
    Grafo(int numCourses){
        this->nodes=numCourses;
        vector<int>vertices;
        this->LA.resize(this->nodes,vertices);
    }
    ~Grafo(){}
    void Build(vector<vector<int>>& prerequisites){
       for (int i = 0; i < prerequisites.size(); i++)
       {
            int need=prerequisites[i][0];
            int want=prerequisites[i][1];
            LA[want].push_back(need);
       }
    }
    bool isciclic(){
        vector<bool>visited(nodes,false);
        vector<bool>pila(nodes,false);
        for (int v = 0; v < nodes; v++)
        {
            if(!visited[v]){
                if(_dfs(visited,pila,v))
                    return true;
            }
        }
        return false;
    }
    bool _dfs(vector<bool>&visited,vector<bool>& pila,int node){
        visited[node]=true;
        pila[node]=true;
        for(int u : LA[node]){
            if(!visited[u]){
                if(_dfs(visited,pila,u)){
                    return true;
                }
            }else if(pila[u]){
                    return true;
                }
           
        }
        pila[node]=false;
        return false;
       
    }

};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Grafo objG = Grafo(numCourses);
        objG.Build(prerequisites);
        return !objG.isciclic();
       
    }
};