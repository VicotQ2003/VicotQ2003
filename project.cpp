#include <iostream>
#include <vector>
using namespace std;




void addEdge(vector<int> adj[], int u, int v) //from in-class
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V) //from in-class
{
    for (int v = 1; v < V; ++v)
    {
        cout << " The roads connected to (adjacent to) " << v << " are ";
        for (auto x: adj[v])
           cout << " -> " << x;
        printf("\n");
    }
}
//////////////

// Data structure to store Adjacency list nodes
struct Node {
//COST IS WHERE WE PUT WIEGHT
    int val, cost;
    Node* next;
};

// Data structure to store graph edges
struct Edge {
    int src, dest, weight;
};

class Graph
{
    // Function to allocate new node of Adjacency List
    Node* getAdjListNode(int value, int weight, Node* head)
    {
        Node* newNode = new Node;
        newNode->val = value;
        newNode->cost = weight;
        
        // point new node to current head
        newNode->next = head;

        return newNode;
    }

    int N;  // number of nodes in the graph

public:

    // An array of pointers to Node to represent
    // adjacency list
     Node **head;

    // Constructor
    Graph(Edge edges[], int n, int N)
    {
        // allocate memory
        head = new Node*[N]();
        this->N = N;

        // initialize head pointer for all vertices
        for (int i = 0; i < N; ++i)
            head[i] = nullptr;

        // add edges to the directed graph
        for (unsigned i = 0; i < n; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;

            // insert in the beginning
            Node* newNode = getAdjListNode(dest, weight, head[src]);

            // point head pointer to new node
            head[src] = newNode;

            //  undirected graph

            
            newNode = getAdjListNode(src, weight, head[dest]);

            // change head pointer to point to the new node
            head[dest] = newNode;
            
            
        
        }
    }

    // Destructor
    ~Graph() {
        for (int i = 0; i < N; i++)
            delete[] head[i];

        delete[] head;
    }
};

// print all neighboring vertices of given vertex
void printList(Node* ptr, int i)
{
    while (ptr != nullptr)
    {
        cout << "(" << i << ", " << ptr->val
            << ", " << ptr->cost << ") ";

        ptr = ptr->next;
    }

    cout << endl;
}


void printList(Node* ptr) //For Choice 1
{
    while (ptr != nullptr)
    {
        if(ptr->val != 1)
        cout << " -> " << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}






int main()
{

    int choice =0;
    cout<<" Welcome to the Inland Empire Solar Sales Travel ";
    cout<< "Choose the following 1-4 down below \n";
    cout<< "1. Varation of trips \n";
    cout<< "2. Shortest route\n";
    cout<< "3. adjacencies\n";
    cout<< "4. Matrix\n";
    cin>>choice;

    if(choice < 1 || choice > 4)//if number is not 1-4
    {
        cout << "That is not a valid option, please select another option 1-4.\n";
        
        cin>>choice;
        
        //varaition of trip
        if(choice == 1) 
            //city into #
    {
        cout << " Routes From Each City:"
         "\n 1.Riverside 2.Hemet 3.Moreno Valley 4.Perris\n ";


        Edge edges[] =

            {
                
                { 1, 2 }, { 1, 3 }, { 1, 4 }, { 3, 4 },
                { 3, 2 }, { 4, 2 }
            };

           
            int N = 5;
            int n = sizeof(edges)/sizeof(edges[0]);
            Graph graph(edges, n, N);
            for (int i = 1; i < N; i++)
            {
                cout << i;
                printList(graph.head[i]);
            }
            cin >> choice;

}//end of choice 1
        

    }
    if(choice == 2) //shortest path / lowest cost
    {
        cout << "Locations:\n1.Riverside 2.Hemet 3.Moreno Valley 4.Perris" << endl;
        cout << "Based on the Matrice generated from the graph" << endl;

                Edge edges[] =
                    {
                        // (1st Vertice, 2nd Vertice , weight (value))
                        { 1, 2, 33 }, { 1, 3, 16 }, { 1, 4, 24 }, { 2, 3, 26 },
                        { 3, 4, 18 }, { 4, 2, 30 }
                    };
                int numOfVertices = 5;

                int n = sizeof(edges)/sizeof(edges[0]);

                Graph graph(edges, n , numOfVertices);

                for(int i = 1; i < numOfVertices; i++)
                {
                    printList(graph.head[i] , i);
                }
        cout << "\nThe matrice displays ,along with the trip repersentation from choice 1 , a potential of\n"
                "6 routes that can be utilized for the trip." << endl;
        cout << "(1,2,3,4) = 77 \n(1,2,4,3) = 81 \n(1,4,2,3) = 80\n(1,4,3,2) = 68" << endl;
        cout << "(1,3,2,4) = 72\nWith the shortest path/lowest cost path being (1,3,4,2) = 64 miles";

    }//end of choice 2


        if(choice == 3) // Adjancies
    {
        int v = 5;
        vector<int> arr[v];
        addEdge(arr, 1, 2);
        addEdge(arr, 1, 3);
        addEdge(arr, 1, 4);
        addEdge(arr, 3, 4);
        addEdge(arr, 3, 2);
        addEdge(arr, 4, 2);

        printGraph(arr, v);

        cin >> choice;
    } // end of choice 3

    if(choice == 4) //Matrix with weight 
    {
        cout << "Cities: 1.Riverside 2.Hemet 3.Moreno Valley 4.Perris" << endl;
        cout << "Here is the following Matrix with the included weights." << endl;

        Edge edges[] =
            {
                // (1st Vertice, 2nd Vertice , weight (value))
                { 1, 2, 33 }, { 1, 3, 16 }, { 1, 4, 24 }, { 2, 3, 26 },
                { 3, 4, 18 }, { 4, 2, 30 }
            };
        int numOfVertices = 5;

        int n = sizeof(edges)/sizeof(edges[0]);

        Graph graph(edges, n , numOfVertices);

        for(int i = 1; i < numOfVertices; i++)
        {
            printList(graph.head[i] , i);
        }

        cin >> choice; // option to  other choices

    }//end of choice 4

    
    return 0;
}
