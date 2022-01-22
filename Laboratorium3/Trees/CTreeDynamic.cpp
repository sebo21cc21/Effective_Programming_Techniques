#include <iostream>
#include "CNodeDynamic.h"
#include "CTreeDynamic.h"

void CTreeDynamic::vPrintTree()
{
	pc_root->vPrintAllBelow();
}

void CTreeDynamic::vPrintTreeLevels()
{
	for (int i = 1; i < pc_root->iHeight()+1; i++)
	{
		pc_root->vPrintLevels(i);
		cout << endl;
	}
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode)
{
	if (pcParentNode == NULL || pcNewChildNode == NULL || pcNewChildNode->bIsRoot())
		return false;

	pcNewChildNode->bDeleteNodeFromChildren();
	pcParentNode->bAddNewChild(pcNewChildNode);

	return true;
}
bool CTreeDynamic::bDeleteNodesOfValue(int valToDelete)
{
	if ((*pc_root).getNodeValue() == valToDelete) return false;

	(*pc_root).deleteValue(valToDelete);
	return true;
}
