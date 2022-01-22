#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T> class CNodeStatic
{
private:
	vector<CNodeStatic> v_children;
	CNodeStatic* pc_parent_node;
	T t_val;
public:
	CNodeStatic() { t_val = {}; pc_parent_node = NULL; };
	~CNodeStatic() { };
	CNodeStatic(const CNodeStatic& pc_other, CNodeStatic* pcParentNode);
	void vSetValue(T tNewVal) { t_val = tNewVal; };
	int iGetChildrenNumber() { return v_children.size(); };
	void vAddNewChild();
	bool bDeleteNodeFromChildren();
	bool bAddNewChild(CNodeStatic* pc_other);
	bool bIsRoot();
	void vPrintParent() { pc_parent_node->vPrint(); };
	void vRepair();
	CNodeStatic* pcGetChild(int iChildOffset);
	void vPrint() { cout << " " << t_val; };
	void vPrintAllBelow();
	void vPrintUp();
};

template<typename T>
CNodeStatic<T>::CNodeStatic(const CNodeStatic& pc_other, CNodeStatic* pcParentNode)
{
	t_val = pc_other.t_val;
	pc_parent_node = pcParentNode;
	for (int i = 0; i < pc_other.v_children.size(); i++)
	{
		v_children.push_back(CNodeStatic(pc_other.v_children[i], this));
	}
}

template<typename T>
void CNodeStatic<T>::vAddNewChild()
{
	if (this != NULL)
	{
		CNodeStatic cChild;
		cChild.pc_parent_node = this;
		v_children.push_back(cChild);
		vRepair();
	}
}

template<typename T>
void CNodeStatic<T>::vRepair()
{
	for (int i = 0; i < v_children.size(); i++)
	{
		v_children[i].pc_parent_node = this;
		v_children[i].vRepair();
	}
}

template<typename T>
bool CNodeStatic<T>::bAddNewChild(CNodeStatic* pc_other)
{
	if (pc_other == NULL)
		return false;

	pc_other->pc_parent_node = this;
	v_children.push_back(*pc_other);

	vRepair();

	return true;
}

template<typename T>
bool CNodeStatic<T>::bDeleteNodeFromChildren()
{
	if (pc_parent_node != NULL)
	{
		for (int i = 0; i < pc_parent_node->v_children.size(); i++)
		{
			if (&pc_parent_node->v_children[i] == this)
			{
				pc_parent_node->v_children.erase(pc_parent_node->v_children.begin() + i);
				return true;
			}
		}
	}
	return false;
}

template<typename T>
bool CNodeStatic<T>::bIsRoot()
{
	if (pc_parent_node == NULL)
		return true;
	return false;
}

template<typename T>
CNodeStatic<T>* CNodeStatic<T>::pcGetChild(int iChildOffset)
{
	if (this == NULL || (iChildOffset < 0 || iChildOffset >(v_children.size() - 1)))
		return NULL;
	else
		return &v_children[iChildOffset];
}

template<typename T>
void CNodeStatic<T>::vPrintAllBelow()
{
	if (this != NULL)
	{
		vPrint();
		for (int i = 0; i < v_children.size(); i++)
		{
			v_children[i].vPrintAllBelow();
		}
	}
}

template<typename T>
void CNodeStatic<T>::vPrintUp()
{
	vPrint();
	if (pc_parent_node != NULL)
		pc_parent_node->vPrintUp();
}