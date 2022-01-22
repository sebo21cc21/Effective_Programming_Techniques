#pragma once
#include <iostream>
#include <vector>

using namespace std;

class CNodeDynamic
{
public:
	CNodeDynamic() { i_val = 0; pc_parent_node = NULL; };
	~CNodeDynamic();
	void vSetValue(int iNewVal) { i_val = iNewVal; };
	int iGetChildrenNumber() { return(v_children.size()); };
	void vAddNewChild();
	bool bAddNewChild(CNodeDynamic* pc_other);
	bool bDeleteNodeFromChildren();
	bool bIsRoot();
	CNodeDynamic* pcGetChild(int iChildOffset);
	int iHeight();
	void vPrintParent() { pc_parent_node->vPrint(); };
	void vPrint() { cout << " " << i_val; };
	void vPrintAllBelow();
	void vPrintLevels(int iLevel);
	void deleteChild(CNodeDynamic* pcChild);
	int getNodeValue();
	void deleteValue(int valToDelete);
private:
	vector<CNodeDynamic*> v_children;
	CNodeDynamic* pc_parent_node;
	int i_val;
};