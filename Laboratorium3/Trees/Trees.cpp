#include <iostream>
#include "CTreeStatic.h"
#include "CTreeDynamic.h"

using namespace std;

void staticNodeTest()
{
	CNodeStatic c_root;

	c_root.vAddNewChild();
	c_root.vAddNewChild();

	c_root.pcGetChild(0)->vSetValue(1);
	c_root.pcGetChild(1)->vSetValue(2);

	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->vAddNewChild();

	c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->vAddNewChild();

	c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	//c_root.vPrintAllBelow();

	//c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();

	CNodeStatic c_root_1 = CNodeStatic(*c_root.pcGetChild(0), NULL);

	c_root_1.vPrintAllBelow();
	c_root.vPrintAllBelow();
}

void staticTreeTest()
{
	CTreeStatic c_tree;

	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->vAddNewChild();

	c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_tree.pcGetRoot()->pcGetChild(2)->vSetValue(3);

	//c_tree.vPrintTree();

	c_tree.pcGetRoot()->pcGetChild(2)->vPrintUp();

	//cout << c_tree.pcGetRoot()->iGetChildrenNumber();
}

void staticTreeTest2()
{
	CTreeStatic tree;

	tree.pcGetRoot()->vSetValue(0);
	tree.pcGetRoot()->vAddNewChild();
	tree.pcGetRoot()->vAddNewChild();
	tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(2);
	tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vPrintParent();
	tree.pcGetRoot()->vAddNewChild();
	tree.pcGetRoot()->vAddNewChild();
	tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vPrintUp();
}

void staticTreeMoveTest()
{
	CTreeStatic c_tree_1;
	c_tree_1.pcGetRoot()->vAddNewChild();
	c_tree_1.pcGetRoot()->vAddNewChild();
	c_tree_1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree_1.pcGetRoot()->pcGetChild(1)->vSetValue(2);

	c_tree_1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_1.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_tree_1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_tree_1.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree_1.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree_1.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_tree_1.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	CTreeStatic c_tree_2;
	c_tree_2.pcGetRoot()->vAddNewChild();
	c_tree_2.pcGetRoot()->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(0)->vSetValue(10);
	c_tree_2.pcGetRoot()->pcGetChild(1)->vSetValue(20);

	c_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(110);
	c_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(120);

	c_tree_2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(210);
	c_tree_2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(220);

	c_tree_1.vPrintTree();
	cout << endl;
	c_tree_2.vPrintTree();
	cout << endl << endl;

	c_tree_1.bMoveSubtree(c_tree_1.pcGetRoot()->pcGetChild(1)->pcGetChild(1), c_tree_2.pcGetRoot()->pcGetChild(0));
	c_tree_1.pcGetRoot()->vAddNewChild();
	c_tree_2.pcGetRoot()->vAddNewChild();
	c_tree_1.vPrintTree();
	cout << endl;
	c_tree_2.vPrintTree();
	//c_tree_1.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->pcGetChild(0)->vPrintUp();
}

void dynamicNodeTest()
{
	CNodeDynamic* c_root = new CNodeDynamic;

	c_root->vAddNewChild();
	c_root->vAddNewChild();

	c_root->pcGetChild(0)->vSetValue(1);
	c_root->pcGetChild(1)->vSetValue(2);

	c_root->pcGetChild(0)->vAddNewChild();
	c_root->pcGetChild(0)->vAddNewChild();

	c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_root->pcGetChild(1)->vAddNewChild();
	c_root->pcGetChild(1)->vAddNewChild();

	c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	//c_root->vPrintLevels();
}

void dynamicTreeTest()
{
	CTreeDynamic* c_root = new CTreeDynamic;

	c_root->pcGetRoot()->vAddNewChild();
	c_root->pcGetRoot()->vAddNewChild();

	c_root->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root->pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_root->pcGetRoot()->pcGetChild(1)->vAddNewChild();

	c_root->pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_root->pcGetRoot()->pcGetChild(1)->vSetValue(2);

	c_root->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_root->pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root->pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	c_root->vPrintTreeLevels();

	delete c_root;
}

void dynamicTreeMoveTest()
{
	CTreeDynamic* c_tree_1 = new CTreeDynamic;

	c_tree_1->pcGetRoot()->vAddNewChild();
	c_tree_1->pcGetRoot()->vAddNewChild();

	c_tree_1->pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree_1->pcGetRoot()->pcGetChild(1)->vSetValue(2);

	c_tree_1->pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree_1->pcGetRoot()->pcGetChild(1)->vAddNewChild();

	c_tree_1->pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(3);
	c_tree_1->pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(4);

	//c_tree_1->vPrintTree();
	//c_tree_1->pcGetRoot()->pcGetChild(1)->vPrintParent();

	CTreeDynamic* c_tree_2 = new CTreeDynamic;
	c_tree_2->pcGetRoot()->vAddNewChild();
	c_tree_2->pcGetRoot()->pcGetChild(0)->vSetValue(1);

	c_tree_1->vPrintTree();
	cout << endl;
	c_tree_2->vPrintTree();
	//c_tree_2->pcGetRoot()->pcGetChild(0)->vPrintParent();

	cout << endl << endl;

	c_tree_2->bMoveSubtree(c_tree_2->pcGetRoot(), c_tree_1->pcGetRoot()->pcGetChild(1));
	//c_tree_1->pcGetRoot()->vAddNewChild();
	//c_tree_2->pcGetRoot()->vAddNewChild();
	c_tree_1->vPrintTree();
	cout << endl;
	c_tree_2->vPrintTree();

	delete c_tree_1;
	delete c_tree_2;
}

void dynamicTreeMoveTest2()
{
	CTreeDynamic* c_tree_1 = new CTreeDynamic;

	c_tree_1->pcGetRoot()->vAddNewChild();
	c_tree_1->pcGetRoot()->vAddNewChild();

	c_tree_1->pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree_1->pcGetRoot()->pcGetChild(1)->vSetValue(2);


	CTreeDynamic* c_tree_2 = new CTreeDynamic;

	c_tree_2->pcGetRoot()->vAddNewChild();
	c_tree_2->pcGetRoot()->pcGetChild(0)->vSetValue(1);

	c_tree_1->vPrintTree();
	cout << endl;
	c_tree_2->vPrintTree();
	cout << endl << endl;

	c_tree_1->bMoveSubtree(c_tree_1->pcGetRoot(), c_tree_2->pcGetRoot());

	c_tree_1->vPrintTree();
	cout << endl;
	c_tree_2->vPrintTree();
	cout << endl << endl;

	delete c_tree_1;
	delete c_tree_2;
}


int main()
{
	CTreeDynamic* c_root = new CTreeDynamic;

	c_root->pcGetRoot()->vSetValue(1);
	c_root->pcGetRoot()->vAddNewChild();
	c_root->pcGetRoot()->vAddNewChild();

	c_root->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root->pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_root->pcGetRoot()->pcGetChild(1)->vAddNewChild();

	c_root->pcGetRoot()->pcGetChild(0)->vSetValue(2);
	c_root->pcGetRoot()->pcGetChild(1)->vSetValue(3);

	c_root->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(48);
	c_root->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(3);
	c_root->pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(6);
	c_root->pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(7);

	c_root->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vAddNewChild();
	c_root->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->pcGetChild(0)->vSetValue(5);
	c_root->vPrintTree();

	c_root->bDeleteNodesOfValue(3);
	delete c_root;


	//staticNodeTest();
	//staticTreeTest();
	//staticTreeTest2();
	//staticTreeMoveTest();
	//dynamicNodeTest();
	//dynamicTreeTest();
	//dynamicTreeMoveTest();
	//dynamicTreeMoveTest2();
}