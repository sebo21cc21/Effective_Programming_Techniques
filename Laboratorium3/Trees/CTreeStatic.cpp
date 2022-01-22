#include <iostream>
#include "CTreeStatic.h"
#include "CNodeStatic.h"

using namespace std;

void CTreeStatic::vPrintTree()
{
	c_root.vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode)
{
	if (pcParentNode == NULL || pcNewChildNode == NULL || pcNewChildNode->bIsRoot())
		return false;

	CNodeStatic* c_node_to_insert = new CNodeStatic(*pcNewChildNode, NULL);

	pcParentNode->bAddNewChild(c_node_to_insert);
	pcNewChildNode->bDeleteNodeFromChildren();
	
	return true;
}