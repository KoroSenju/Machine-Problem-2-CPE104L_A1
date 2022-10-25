#include<iostream>
#include<fstream>
#include"graphType.h"
#include"weightedGraph.h"
#include"minimalSpanTreeType.h"

using namespace std;

int main()
{
    char n;
    char nameFile[50];

    graphType myGraph(50);
    weightedGraphType shortestPathGraph(50);
    msTreeType spanTree(50);

    cout<<"Enter the File Name: ";
    cin>>nameFile;

    myGraph.createGraph(nameFile);
    shortestPathGraph.createWeightedGraph(nameFile);
    spanTree.createSpanningGraph(nameFile);

    cout<<endl<<endl;
    cout<<"============================================================="<<endl;
    cout<<"\tChoose: "<<endl;
    cout<<" \t\tA - Breadth First Traversal"<<endl<<" \t\tB - Depth First Traversal"<<endl;
    cout<<" \t\tC - Shortest Path"<<endl<<" \t\tD - Minimal Spanning Tree"<<endl;
    cout<<" \t\tE - Print in Array the Graph"<<endl;
    cout<<"============================================================="<<endl;
    cout<<"\n>> Choice: ";
    cin>>n;
    cout<<endl;

    while(n)
    {
        if (n== 'A' || n=='a')
        {
        	cout<<"============================================================="<<endl;
            cout<<">> Breadth First Traversal: ";
            myGraph.breadthFirstTraversal();
            cout<<endl;
            cout<<"============================================================="<<endl;
            break;
        }

        if (n== 'B' || n=='b')
        {
        	cout<<"============================================================="<<endl;
            cout<<">> Depth First Traversal: ";
            myGraph.depthFirstTraversal();
            cout<<endl;
            cout<<"============================================================="<<endl;
            break;
        }

        if (n== 'C' || n=='c')
        {
        	cout<<"============================================================="<<endl;
            cout<<"\t      Shortest Path: ";
            shortestPathGraph.shortestPath(0);
            shortestPathGraph.printShortestDistance(0);
            cout<<endl;
            cout<<"============================================================="<<endl;
            break;
        }

        if (n== 'D' || n=='d')
        {
        	cout<<"============================================================="<<endl;
        	cout<<"\t  Minimum Spanning Tree: ";
            spanTree.minimalSpanning(0);
            spanTree.printTreeAndWeight();
            cout<<endl;
            cout<<"============================================================="<<endl;
            break;

        }
        if (n== 'E' || n=='e')
		{
			cout<<"============================================================="<<endl;
			cout<<"\tGraph Representation (Adjacency List):"<<endl;
			myGraph.printGraph();
			cout<<"============================================================="<<endl;
			break;
		}
		
        else
            cout<<">> Please Choose from the options below! "<<endl;
    		cout<<"============================================================="<<endl;
    		cout<<"\tChoose: "<<endl;
    		cout<<" \t\tA - Breadth First Traversal"<<endl<<" \t\tB - Depth First Traversal"<<endl;
    		cout<<" \t\tC - Shortest Path"<<endl<<" \t\tD - Minimal Spanning Tree"<<endl;
    		cout<<" \t\tE - Print in Array the Graph"<<endl;
    		cout<<"============================================================="<<endl;
            cout<<">> Choice: ";
    		cin>>n;
    		cout<<endl;

    }
    return 0;
}

