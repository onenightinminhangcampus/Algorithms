#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <list>
using namespace std;

//Build a tree using in-order traverse
list<int> inorderBuildTree(int node, list<int> tree, multimap<int, int> aMap)
{
		pair <multimap<int, int>::iterator, multimap<int, int>::iterator> pos;
		pos = aMap.equal_range(node);

		//Equal_range cannot search with value, will have to set up a new process

		for (multimap<int, int>::iterator iter = pos.first; iter != pos.second; ++iter)
		{
			//Find all elements that are connected to the current element, push them into its tree.
			int new_ele_in_current_tree = iter->second;
			tree.push_back(new_ele_in_current_tree);
			//In-order Search Recursion on this element
			tree=inorderBuildTree(new_ele_in_current_tree, tree, aMap);
		}
		return tree;
}


int main()
{
	////Input
	multimap<int, int> aMap;
	//First tree
	aMap.insert(make_pair(1, 5));
	aMap.insert(make_pair(1, 6));
	aMap.insert(make_pair(6, 3));
	aMap.insert(make_pair(6, 9));
	//Second tree
	aMap.insert(make_pair(2, 7));
	aMap.insert(make_pair(2, 8));
	//Third tree
	aMap.insert(make_pair(4, 11));
	aMap.insert(make_pair(11, 12));
	aMap.insert(make_pair(10, 12));


	////Process

	//Initialize a list of multiple trees
	list<list<int>> trees;

	//Every effective iteration only one new tree is set
	for (int i = 1; i <= 12; i++)
	{
		if (i>1)
		{
			bool already_in_a_tree = 0;
			//Check if the variable exist in the current trees
			for (list<list<int>>::iterator iter = trees.begin(); iter != trees.end(); ++iter)
			{
				for (list<int>::iterator iter2 = (*iter).begin(); iter2 != (*iter).end(); ++iter2)
				{
					if (i==*iter2)
					{
						already_in_a_tree = 1;
					}
				}
			}

			if (already_in_a_tree) continue;
		}

		if (i==4)
		{
			cout << "break here" << endl;
		}

		//Initialize a new tree
		list<int> tree;
		tree.push_back(i);

		//Build a tree based on the current node
		tree=inorderBuildTree(i,tree,aMap);

		//Add the tree to trees
		trees.push_back(tree);

		//Test Output:
		cout << "A new tree is generated:" << endl;
		for (list<int>::iterator iter2 = tree.begin(); iter2 != tree.end(); ++iter2)
		{
			cout << *iter2 << endl;
		}		
	}



	cin.get();
	return 0;
}

