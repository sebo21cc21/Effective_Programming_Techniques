#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T> class CNodeDynamic
{
public:
	CNodeDynamic() { t_val = {}; pc_parent_node = NULL; };
	~CNodeDynamic();
	void vSetValue(T tNewVal) { t_val = tNewVal; };
	int iGetChildrenNumber() { return(v_children.size()); };
	void vAddNewChild();
	bool bAddNewChild(CNodeDynamic* pc_other);
	bool bDeleteNodeFromChildren();
	bool bIsRoot();
	CNodeDynamic* pcGetChild(int iChildOffset);
	int iHeight();
	void vPrintParent() { pc_parent_node->vPrint(); };
	void vPrint() { cout << " " << t_val; };
	void vPrintAllBelow();
	void vPrintLevels(int iLevel);

private:
	vector<CNodeDynamic*> v_children;
	CNodeDynamic* pc_parent_node;
	T t_val;
};

template <typename T>
CNodeDynamic<T>::~CNodeDynamic()
{
	for (int i = 0; i < v_children.size(); i++)
		delete v_children[i];
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild()
{
	if (this != NULL)
	{
		CNodeDynamic* pcChild = new CNodeDynamic;
		pcChild->pc_parent_node = this;
		v_children.push_back(pcChild);
	}
}

template <>
void CNodeDynamic<int>::vAddNewChild()
{
	if (this != NULL && v_children.size() < t_val && t_val > 0)
	{
		CNodeDynamic* pcChild = new CNodeDynamic;
		pcChild->pc_parent_node = this;
		v_children.push_back(pcChild);
	}
}
template <typename T>
bool CNodeDynamic<T>::bAddNewChild(CNodeDynamic* pc_other)
{
	if (pc_other == NULL)
		return false;

	pc_other->pc_parent_node = this;
	v_children.push_back(pc_other);

	return true;
}

template <typename T>
bool CNodeDynamic<T>::bDeleteNodeFromChildren()
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

template <typename T>
bool CNodeDynamic<T>::bIsRoot()
{
	if (pc_parent_node == NULL)
		return true;
	return false;
}

template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetChild(int iChildOffset)
{
	if (this == NULL || (iChildOffset < 0 || iChildOffset >(v_children.size() - 1)))
		return NULL;
	else
		return v_children[iChildOffset];
}

template <typename T>
void CNodeDynamic<T>::vPrintAllBelow()
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

template <typename T>
int CNodeDynamic<T>::iHeight()
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

template <typename T>
void CNodeDynamic<T>::vPrintLevels(int iLevel)
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

