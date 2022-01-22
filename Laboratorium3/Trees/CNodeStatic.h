#pragma once

#include <iostream>
#include <vector>
using namespace std;

class CNodeStatic
{
private:
	vector<CNodeStatic> v_children;
	CNodeStatic* pc_parent_node;
	int i_val;

public:
	CNodeStatic() { i_val = 0; pc_parent_node = NULL; };
	~CNodeStatic() { };
	CNodeStatic(const CNodeStatic& pc_other, CNodeStatic* pcParentNode);
	void vSetValue(int iNewVal) { i_val = iNewVal; };
	int iGetChildrenNumber() { return v_children.size(); };
	void vAddNewChild();
	bool bDeleteNodeFromChildren();
	bool bAddNewChild(CNodeStatic* pc_other);
	bool bIsRoot();
	void vPrintParent() { pc_parent_node->vPrint(); };
	void vRepair();
	CNodeStatic* pcGetChild(int iChildOffset);
	void vPrint() { cout << " " << i_val; };
	void vPrintAllBelow();
	void vPrintUp();

};