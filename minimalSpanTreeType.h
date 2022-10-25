#ifndef H_msTree
#define H_msTree

#include <iostream>
#include <fstream>
#include <iomanip> 
#include <cfloat>
#include "graphType.h"

using namespace std;

class msTreeType: public graphType
{
public:
    void createSpanningGraph(char fileName[50]); 
      //Function to create the graph and the weight matrix.
      //Postcondition: The graph using adjacency lists and 
      //               its weight matrix is created.

    void minimalSpanning(int sVertex);
      //Function to create a minimal spanning tree with
      //root as sVertex. 
      // Postcondition: A minimal spanning tree is created.
      //                The weight of the edges is also
      //                saved in the array edgeWeights.

    void printTreeAndWeight();
      //Function to output the edges of the minimal
      //spanning tree and the weight of the minimal
      //spanning tree.
      //Postcondition: The edges of a minimal spanning tree
      //               and their weights are printed.

    msTreeType(int size = 0); 
      //Constructor
      //Postcondition: gSize = 0; maxSize = size;
      //               graph is an array of pointers to linked
      //               lists.
      //               weights is a two-dimensional array to 
      //               store the weights of the edges.
      //               edges is an array to store the edges 
      //               of a minimal spanning tree.
      //               egdeWeight is an array to store the 
      //               weights of the edges of a minimal 
      //               spanning tree.

    ~msTreeType();
      //Destructor
      //The storage occupied by the vertices and the arrays
      //weights, edges, and edgeWeights is deallocated.

protected:
    int source;
    double **weights;
    int *edges;
    double *edgeWeights;
};

void msTreeType::createSpanningGraph(char fileName[50])
{
    ifstream infile;

    int vertex;
    int adjacentVertex;

    infile.open(fileName);

    if (!infile)
    {
        cout << "Cannot open input file." << endl;
        return;
    }

    infile >> gSize;

    for (int index = 0; index < gSize; index++)
    {
        infile >> vertex;
        infile >> adjacentVertex;

        while (adjacentVertex != -999)
        {
            graph[vertex].insertLast(adjacentVertex);
            infile >> adjacentVertex;
        } //end while
    } //end for

    for (int i = 0; i < gSize; i++)
        for (int j = 0; j < gSize; j++)
            weights[i][j] = DBL_MAX;

    int weight;

    infile >> vertex;
    while (infile)
    {
        infile >> adjacentVertex;
        while (adjacentVertex != -999)
        {
            infile >> weight;
            weights[vertex][adjacentVertex] = weight;
            infile >> adjacentVertex;
        }
        infile >> vertex;
    }

    infile.close();
} //createWeightedGraph

void msTreeType::minimalSpanning(int sVertex)
{
    int startVertex, endVertex;
    double minWeight;

    source = sVertex;

    bool *mstv;
    mstv = new bool[gSize];

    for (int j = 0; j < gSize; j++)
    {
        mstv[j] = false;
        edges[j] = source;
        edgeWeights[j] = weights[source][j];
    }

    mstv[source] = true;
    edgeWeights[source] = 0;

    for (int i = 0; i < gSize - 1; i++)
    {
        minWeight = DBL_MAX;

        for (int j = 0; j < gSize; j++)
            if (mstv[j])
                for (int k = 0; k < gSize; k++)
                    if (!mstv[k] && weights[j][k] < minWeight)
                    {
                        endVertex = k;
                        startVertex = j;
                        minWeight = weights[j][k];
                    }

        mstv[endVertex] = true;
        edges[endVertex] = startVertex;
        edgeWeights[endVertex] = minWeight;
    } //end for
} //end minimalSpanning

void msTreeType::printTreeAndWeight()
{
    double treeWeight = 0;

    cout << "Source Vertex: " << source << endl;
    cout <<endl;
    cout << "Edges    Weight" << endl;

    for (int j = 0; j < gSize; j++)
    {
        if (edges[j] != j)
        {
            treeWeight = treeWeight + edgeWeights[j];
            cout << "("<<edges[j] << ", " << j << ")    "
                 << edgeWeights[j] << endl;
        }
    }

    cout << endl;
    cout << ">> Minimal Spanning Tree Weight: " 
         << treeWeight << endl;
} //end printTreeAndWeight

    //Constructor
msTreeType::msTreeType(int size)
           :graphType(size)
{
    weights = new double*[size];

    for (int i = 0; i < size; i++)
        weights[i] = new double[size];

    edges  = new int[size];

    edgeWeights = new double[size];
}

    //Destructor
msTreeType::~msTreeType()
{
    for (int i = 0; i < gSize; i++)
       delete [] weights[i];

    delete [] weights;
    delete [] edges;
    delete edgeWeights;
}

#endif
