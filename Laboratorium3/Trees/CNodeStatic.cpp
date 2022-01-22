#include <iostream>
#include "CNodeStatic.h"

using namespace std;

CNodeStatic::CNodeStatic(const CNodeStatic& pc_other, CNodeStatic* pcParentNode)
{
	i_val = pc_other.i_val;
	pc_parent_node = pcParentNode;
	for (int i = 0; i < pc_other.v_children.size(); i++)
	{
		v_children.push_back(CNodeStatic(pc_other.v_children[i], this));
	}
}

void CNodeStatic::vAddNewChild()
{
	if (this != NULL)
	{
		CNodeStatic cChild;
		cChild.pc_parent_node = this;
		v_children.push_back(cChild);
		vRepair();
	}
}

void CNodeStatic::vRepair()
{
	for (int i = 0; i < v_children.size(); i++)
	{
		v_children[i].pc_parent_node = this;
		v_children[i].vRepair();
	}
}

bool CNodeStatic::bAddNewChild(CNodeStatic* pc_other)
{
	if (pc_other == NULL)
		return false;

	pc_other->pc_parent_node = this;
	v_children.push_back(*pc_other);

	vRepair();

	return true;
}

bool CNodeStatic::bDeleteNodeFromChildren()
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

bool CNodeStatic::bIsRoot()
{
	if (pc_parent_node == NULL)
		return true;
	return false;
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset)
{
	if (this==NULL || (iChildOffset < 0 || iChildOffset >(v_children.size() - 1)))
		return NULL;
	else
		return &v_children[iChildOffset];
}

void CNodeStatic::vPrintAllBelow()
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

void CNodeStatic::vPrintUp()
{
	vPrint();
	if (pc_parent_node != NULL)
		pc_parent_node->vPrintUp();
}
