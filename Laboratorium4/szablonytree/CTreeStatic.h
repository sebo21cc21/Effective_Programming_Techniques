#pragma once

#include "CNodeStatic.h"

template <typename T> class CTreeStatic
{
private:
	CNodeStatic<T> c_root;
public:
	CTreeStatic() {};
	~CTreeStatic() {};
	CNodeStatic<T>* pcGetRoot() { return(&c_root); };
	void vPrintTree();
	bool bMoveSubtree(CNodeStatic<T>* pcParentNode, CNodeStatic<T>* pcNewChildNode);
	string sGetKnownType();
};

template <typename T>
void CTreeStatic<T>::vPrintTree()
{
	c_root.vPrintAllBelow();
}

template <typename T>
bool CTreeStatic<T>::bMoveSubtree(CNodeStatic<T>* pcParentNode, CNodeStatic<T>* pcNewChildNode)
{
	if (pcParentNode == NULL || pcNewChildNode == NULL || pcNewChildNode->bIsRoot())
		return false;

	CNodeStatic<T>* c_node_to_insert = new CNodeStatic<T>(*pcNewChildNode, NULL);

	pcParentNode->bAddNewChild(c_node_to_insert);
	pcNewChildNode->bDeleteNodeFromChildren();

	return true;
}

template <>
string CTreeStatic<int>::sGetKnownType()
{
	return "INT";
}

template <>
string CTreeStatic<char>::sGetKnownType()
{
	return "CHAR";
}

template <>
string CTreeStatic<bool>::sGetKnownType()
{
	return "BOOL";
}

template <>
string CTreeStatic<string>::sGetKnownType()
{
	return "STRING";
}

template <typename T>
string CTreeStatic<T>::sGetKnownType()
{
	return "UNKNOWN";
}