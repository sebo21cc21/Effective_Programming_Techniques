#pragma once
class CTable {
public:
	CTable();
	CTable(std::string s_name, int iTableLen);
	CTable(CTable& pcOther);
	~CTable();
	CTable* pcClone();
	int getLength() { return tabSize; }
	void info();
	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	void vPrint();
	void vSetValueAt(int offSet, int newValue);
	void copyTable(int* tab1, int* tab2, int size);
	void operator=(const CTable& obj);
	CTable operator+(CTable& pcOther);
	CTable operator-(const CTable& pcOther);
	CTable loop(CTable pcOther, int number);
	CTable operator*(int number);
	void operator/(int number);
private:
	std::string s_name;
	int* tab;
	int tabSize;
};
