#include <bits/stdc++.h>
using namespace std;
 
// Graph is represented using adjacency list. Every node of
// adjacency list contains vertex number of the vertex to
// which edge connects. It also contains weight of the edge
class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)
    {
        v = _v;
        weight = _w;
    }
    int getV()
    {
        return v;
    }
    int getWeight()
    {
        return weight;
    }
};
 
// Graph class represents a directed graph using adjacency
// list representation
class Graph
{
    int V; // No. of vertices
 
    // Pointer to an array containing adjacency lists
    list<AdjListNode>* adj;
 
    // This function uses DFS
    void longestPathUtil(int, vector<bool> &, stack<int> &);
public:
    Graph(int); // Constructor
    ~Graph();   // Destructor
 
    // function to add an edge to graph
    void addEdge(int, int, int);
 
    void longestPath(int);
};
 
Graph::Graph(int V) // Constructor
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}
 
Graph::~Graph() // Destructor
{
    delete[] adj;
}
 
void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node); // Add v to u's list
}
 
// A recursive function used by longestPath. See below
// link for details.
// https://www.geeksforgeeks.org/topological-sorting/
void Graph::longestPathUtil(int v, vector<bool> &visited,
                            stack<int> &Stack)
{
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    for (AdjListNode node : adj[v])
    {
        if (!visited[node.getV()])
            longestPathUtil(node.getV(), visited, Stack);
    }
 
    // Push current vertex to stack which stores topological
    // sort
    Stack.push(v);
}
 
// The function do Topological Sort and finds longest
// distances from given source vertex
void Graph::longestPath(int s)
{
    // Initialize distances to all vertices as infinite and
    // distance to source as 0
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[s] = 0;
 
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);
 
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            longestPathUtil(i, visited, Stack);
 
    // Process vertices in topological order
    while (!Stack.empty())
    {
        // Get the next vertex from topological order
        int u = Stack.top();
        Stack.pop();
 
        if (dist[u] != INT_MAX)
        {
            // Update distances of all adjacent vertices
            // (edge from u -> v exists)
            for (AdjListNode v : adj[u])
            {
                // consider negative weight of edges and
                // find shortest path
                if (dist[v.getV()] > dist[u] + v.getWeight() * -1)
                    dist[v.getV()] = dist[u] + v.getWeight() * -1;
            }
        }
    }
 
    // Print the calculated longest distances
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "INT_MIN ";
        else
            cout << (dist[i] * -1) << " ";
    }
}

class Graph1
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
public:
    Graph1(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();    // returns true if there is a cycle in this graph
};
 
Graph1::Graph1(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph1::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
// This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212
bool Graph1::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
 
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}
 
// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
bool Graph1::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if ( !visited[i] && isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}
	
const int N = 1e5;
int main()
{	

	string st;
	getline(cin, st);


	cout << st << endl;


	vector<string> stt;

	string c = "";
	for(auto it : st){

		if(it == ' '){

			stt.push_back(c);
			c = "";
		}

		c += it;
	}

	stt.push_back(c);

	map<int, vector<int> > mp;

	for(string z : stt){

		cout << z << " ";
		int sz = z.size();

		int u = z[0] - '0';
		cout << u << endl;

		for(int i = 3; i < sz; i++){

			while(i < sz and z[i] != '}'){

				int v = z[i] - '0';
				mp[u].push_back(v);
				i += 2;
			}
		}
	}


	for(auto it : mp){

		cout << it.first << " ";

		for(auto it1 : mp[it.first]){

			cout << it1 << ", ";
		}
		cout << endl;
	}


	// vector<int> edges[N + 1];
	// vector<int> ut;

	// string t;
	// for(int i = 0 ; i < st.size(); i++){

	// 	cout << i << " ";
	// 	if(st[i] == '{'){

	// 		i++;
	// 		while(i < st.size() and st[i] != '}'){

	// 			string p = "";
	// 			p += st[i];
	// 			int v = stoi(p);
	// 			edges[stoi(t)].push_back(v);
	// 			i++;
	// 			if(st[i] == ',') i++;
	// 		}

	// 		if(i < st.size()){

	// 			i += 1;
	// 			continue;
	// 		}
	// 	}



	// 	while(i < st.size() and st[i] != '.'){

	// 		t += st[i];
	// 		i++;
	// 	}

	// 	ut.push_back(stoi(t));
	// 	t = "";
	// }
	
	//for(auto it : ut) cout << it << " ";

  //   Graph g(4);
 
  //   g.addEdge(1, 3, 1);
  //   //g.addEdge(1, 4, 1);
  //   g.addEdge(2, 3, 1);
  //   //g.addEdge(3, 2, 1);
  //  // g.addEdge(0, 1, 1);
  //  // g.addEdge(5, 1, 1);

  //   Graph1 g1(4);
 
  //   g1.addEdge(1, 3);
  //   //g1.addEdge(1, 4);
  //   g1.addEdge(2, 3);
  // //  g1.addEdge(3, 2);
  //  // g1.addEdge(0, 1);
  //  // g1.addEdge(5, 1);
  //   // g.addEdge(2, 4, 1);
  //   // g.addEdge(3, 2, 1);
   	

  //  if(g1.isCyclic()){

  //  		cout << "error" << endl;
  //  		return 0;
  //  }
        


  //   int s = 1;
 
  //   cout << "Following are longest distances from "
  //        << "source vertex " << s << " \n";
  //   g.longestPath(s);
 
    return 0;
}






    
 