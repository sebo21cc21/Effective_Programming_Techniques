#pragma once
#include "CNodeDynamic.h"

template <typename T> class CTreeDynamic
{
private:
	CNodeDynamic<T>* pc_root;
public:
	CTreeDynamic() { pc_root = new CNodeDynamic<T>; };
	~CTreeDynamic() { delete pc_root; };
	CNodeDynamic<T>* pcGetRoot() { return(pc_root); }
	void vPrintTree();
	void vPrintTreeLevels();
	bool bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode);
	string sGetKnownType();

};


template <typename T>
void CTreeDynamic<T>::vPrintTree()
{
	pc_root->vPrintAllBelow();
}

template <typename T>
void CTreeDynamic<T>::vPrintTreeLevels()
{
	for (int i = 1; i < pc_root->iHeight() + 1; i++)
	{
		pc_root->vPrintLevels(i);
		cout << endl;
	}
}

template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode)
{
	if (pcParentNode == NULL || pcNewChildNode == NULL || pcNewChildNode->bIsRoot())
		return false;

	pcNewChildNode->bDeleteNodeFromChildren();
	pcParentNode->bAddNewChild(pcNewChildNode);

	return true;
}

template <>
string CTreeDynamic<int>::sGetKnownType()
{
	return "INT";
}

template <>
string CTreeDynamic<double>::sGetKnownType()
{
	return "DOUBLE";
}

template <>
string CTreeDynamic<char>::sGetKnownType()
{
	return "CHAR";
}

template <>
string CTreeDynamic<bool>::sGetKnownType()
{
	return "BOOL";
}

template <>
string CTreeDynamic<string>::sGetKnownType()
{
	return "STRING";
}

template <typename T>
string CTreeDynamic<T>::sGetKnownType()
{
	return "UNKNOWN";
}


