#include <iostream>
#include "CNodeDynamic.h"
#include <vector>
CNodeDynamic::~CNodeDynamic()
{
	for (int i = 0; i < v_children.size(); i++)
		delete v_children[i];
}

void CNodeDynamic::vAddNewChild()
{
	if (this != NULL)
	{
		CNodeDynamic* pcChild = new CNodeDynamic;
		pcChild->pc_parent_node = this;
		v_children.push_back(pcChild);
	}
}


bool CNodeDynamic::bAddNewChild(CNodeDynamic* pc_other)
{
	if (pc_other == NULL)
		return false;

	pc_other->pc_parent_node = this;
	v_children.push_back(pc_other);

	return true;
}

bool CNodeDynamic::bDeleteNodeFromChildren()
{
	if (pc_parent_node != NULL)
	{
		for (int i = 0; i < pc_parent_node->v_children.size(); i++)
		{
			if (pc_parent_node->v_children[i] == this)
			{
				pc_parent_node->v_children.erase(pc_parent_node->v_children.begin() + i);
				return true;
			}
		}
	}
	return false;
}

bool CNodeDynamic::bIsRoot()
{
	if (pc_parent_node == NULL)
		return true;
	return false;
}

CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset)
{
	if (this == NULL || (iChildOffset < 0 || iChildOffset >(v_children.size() - 1)))
		return NULL;
	else
		return v_children[iChildOffset];
}

void CNodeDynamic::vPrintAllBelow()
{
	if (this != NULL)
	{
		vPrint();
		for (int i = 0; i < v_children.size(); i++)
		{
			v_children[i]->vPrintAllBelow();
		}
	}
}

int CNodeDynamic::iHeight()
{
	if (v_children.empty())
		return 1;
	else
	{
		for (int i = 0; i < v_children.size(); i++)
		{
			if (!v_children[i]->v_children.empty())
			{
				return 1 + v_children[i]->iHeight();
			}
		}
	}
}

void CNodeDynamic::vPrintLevels(int iLevel)
{
	if (iLevel == 1)
	{
		vPrint();
	}

	else
	{
		for (int i = 0; i < v_children.size(); i++)
		{
			v_children[i]->vPrintLevels(iLevel - 1);
		}
	}
}

int CNodeDynamic::getNodeValue()
{
	return i_val;
}

void CNodeDynamic::deleteChild(CNodeDynamic* pcChild)
{
	for (int i = 0; i < v_children.size(); i++) {
		if (v_children.at(i) == pcChild)
		{
			v_children.erase(v_children.begin() + i);
			return;
		}
	}

	vector<CNodeDynamic*> v_children2;
	for (int i = 0; i < v_children.size(); i++) {
		if (v_children[i] != pcChild) v_children2.push_back(v_children[i]);
	}
	v_children.clear();
	for (int i = 0; i < v_children2.size(); i++) {
		v_children.push_back(v_children2[i]);
	}
	v_children2.clear();
}

void CNodeDynamic::deleteValue(int valToDelete)
{
	if (i_val == valToDelete) {
		(*pc_parent_node).deleteChild(this);
		for (int i = 0; i < v_children.size(); i++) {
			(*v_children[i]).pc_parent_node = pc_parent_node;
			(*pc_parent_node).bAddNewChild(v_children[i]);
		}
	}
	for (int i = 0; i < v_children.size(); i++) {
		(*v_children[i]).deleteValue(valToDelete);
	}
	
}