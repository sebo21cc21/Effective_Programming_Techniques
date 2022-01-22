#pragma once
#include "CNodeDynamic.h"

class CTreeDynamic
{
private:
	CNodeDynamic* pc_root;
public:
	CTreeDynamic() { pc_root = new CNodeDynamic; };
	~CTreeDynamic() { delete pc_root; };
	CNodeDynamic* pcGetRoot() { return(pc_root); }
	void vPrintTree();
	void vPrintTreeLevels();
	bool bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode);
	bool bDeleteNodesOfValue(int valToDelete);
};