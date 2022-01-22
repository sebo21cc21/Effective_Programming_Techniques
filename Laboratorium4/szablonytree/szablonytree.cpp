#include <iostream>
#include "CTreeStatic.h"
#include "CTreeDynamic.h"

using namespace std;

void dynamicTreeIntMoveTest()
{
	CTreeDynamic<int>* c_tree_1 = new CTreeDynamic<int>;

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

	CTreeDynamic<int>* c_tree_2 = new CTreeDynamic<int>;
	c_tree_2->pcGetRoot()->vAddNewChild();
	c_tree_2->pcGetRoot()->pcGetChild(0)->vSetValue(1);

	c_tree_1->vPrintTree();
	cout << endl << c_tree_1->sGetKnownType() << endl;
	c_tree_2->vPrintTree();
	cout << endl << c_tree_2->sGetKnownType() << endl;
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

void dynamicTreeBoolTest()
{
	CTreeDynamic<bool>* c_tree = new CTreeDynamic<bool>;

	c_tree->pcGetRoot()->vSetValue(true);
	c_tree->pcGetRoot()->vAddNewChild();
	c_tree->pcGetRoot()->vAddNewChild();

	c_tree->pcGetRoot()->pcGetChild(0)->vSetValue(true);
	c_tree->pcGetRoot()->pcGetChild(1)->vSetValue(false);

	c_tree->vPrintTreeLevels();

	cout << c_tree->sGetKnownType();

	delete c_tree;
}

void staticTreeCharTest()
{
	CTreeStatic<char> c_tree;

	c_tree.pcGetRoot()->vSetValue('a');

	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->vAddNewChild();

	c_tree.pcGetRoot()->pcGetChild(0)->vSetValue('b');
	c_tree.pcGetRoot()->pcGetChild(1)->vSetValue('c');
	c_tree.pcGetRoot()->pcGetChild(2)->vSetValue('d');

	c_tree.vPrintTree();
	//cout << endl << c_tree.sGetKnownType();
}

void staticTreeFloatMoveTest()
{
	CTreeStatic<float> c_tree_1;
	CTreeStatic<float> c_tree_2;

	c_tree_1.pcGetRoot()->vSetValue(5);

	c_tree_1.pcGetRoot()->vAddNewChild();
	c_tree_1.pcGetRoot()->vAddNewChild();

	c_tree_1.pcGetRoot()->pcGetChild(0)->vSetValue(3.1);
	c_tree_1.pcGetRoot()->pcGetChild(1)->vSetValue(8.5);

	c_tree_1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_1.pcGetRoot()->pcGetChild(0)->vAddNewChild();

	c_tree_1.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(1.9);
	c_tree_1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(9.1);

	c_tree_1.vPrintTree();
	cout << endl;
	//c_tree_1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();

	c_tree_2.pcGetRoot()->vSetValue(5);

	c_tree_2.pcGetRoot()->vAddNewChild();
	c_tree_2.pcGetRoot()->vAddNewChild();

	c_tree_2.pcGetRoot()->pcGetChild(0)->vSetValue(3.1);
	c_tree_2.pcGetRoot()->pcGetChild(1)->vSetValue(8.5);

	c_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();

	c_tree_2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree_2.pcGetRoot()->pcGetChild(1)->vAddNewChild();

	c_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(1.9);
	c_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(1.9);

	c_tree_2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(8.5);
	c_tree_2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(9);

	c_tree_2.vPrintTree();
	cout << endl;

	c_tree_1.bMoveSubtree(c_tree_1.pcGetRoot()->pcGetChild(1), c_tree_2.pcGetRoot()->pcGetChild(1));

	cout << endl;
	c_tree_1.vPrintTree();
	cout << endl;
	c_tree_2.vPrintTree();
	cout << endl;
	//c_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
}

void dynamicTreeIntAddChildTest()
{
	CTreeDynamic<int>* c_tree_1 = new CTreeDynamic<int>;
	c_tree_1->pcGetRoot()->vSetValue(2);
	
	c_tree_1->pcGetRoot()->vAddNewChild();
	c_tree_1->pcGetRoot()->vAddNewChild();

	c_tree_1->pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree_1->pcGetRoot()->pcGetChild(1)->vSetValue(1);
	delete c_tree_1;
}
void dynamicTreeIntAddChildTest2()
{
	CTreeDynamic<int>* c_tree_1 = new CTreeDynamic<int>;
	c_tree_1->pcGetRoot()->vSetValue(1);

	c_tree_1->pcGetRoot()->vAddNewChild();
	
	c_tree_1->pcGetRoot()->pcGetChild(0)->vSetValue(0);

	delete c_tree_1;
}
class  CMyClass
{};

int main()
{
	//dynamicTreeIntMoveTest();
	//dynamicTreeBoolTest();
	//staticTreeCharTest();
	//staticTreeFloatMoveTest();

	//zmieniaj 2 na 1 w vSetValue do moda :)
	dynamicTreeIntAddChildTest();
	//dynamicTreeIntAddChildTest2();
}