#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include <string>

using namespace std;

#include "AVL_ADT.h"

struct DATA
{
	int key;
	string info;
};

void print(DATA ss) {
	cout << ss.key <<  ", " << ss.info << endl;
}

int TestAVL() {
	AvlTree<DATA, int> tree;
	if(tree.AVL_Empty()) 
		cout << "Empty tree."<< endl;

	DATA newItem;
	newItem.info = "Dongmo";
	newItem.key = 10;
	tree.AVL_Insert(newItem);

	newItem.info = "John";
	newItem.key = 20;
	tree.AVL_Insert(newItem);

	newItem.info = "Jane";
	newItem.key = 30;
	tree.AVL_Insert(newItem);

	tree.AVL_Print();

	cout<< "More to go ..." << endl;

	newItem.info = "Daniel";
	newItem.key = 40;
	tree.AVL_Insert(newItem);
	newItem.info = "Michelle";
	newItem.key = 50;
	tree.AVL_Insert(newItem);

	tree.AVL_Print();

	cout<<endl;

	tree.AVL_Traverse(print);

    return 0;
}
