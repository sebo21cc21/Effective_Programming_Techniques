#pragma once

#include "CNodeStatic.h"

class CTreeStatic
{
private:
	CNodeStatic c_root;
public:
	CNodeStatic* pcGetRoot() { return(&c_root); };
	void vPrintTree();
	bool bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode);
};