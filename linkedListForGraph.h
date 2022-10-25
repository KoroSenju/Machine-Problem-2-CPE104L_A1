#ifndef H_LinkedListForGraph
#define H_LinkedListForGraph

#include <iostream>
#include "linkedList.h"

using namespace std; 

template<class vType>
class linkedListGraph: public linkedListType<vType>
{ 
public:
    void getAdjacentVertices(vType adjacencyList[], 
     				         int& length);
	//Function to retrieve the vertices adjacent to a
	//given vertex. 
	//Postcondition: The vertices adjacent to a given vertex
	//               from the linked list are retrieved in the
	//               array adjacencyList. The parameter length 
	//               specifies the number of vertices adjacent 
	//               to given vertex.
};


template<class vType>
void linkedListGraph<vType>::getAdjacentVertices
      			            (vType adjacencyList[], int& length)
{
	nodeType<vType> *current;

	length = 0;
	current = this->first;

	while (current != nullptr)
	{
		adjacencyList[length++] = current->info;
		current = current->link;
	}
}

#endif
