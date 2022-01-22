#include "CTab.h"

CTab::CTab(const CTab& cOther) {
	v_copy(cOther);
	std::cout << "Copy ";
}
CTab::~CTab() {

	if (pi_tab != NULL) {
		delete pi_tab;
	}
	std::cout << "Destr ";
}


CTab::CTab(CTab&& cOther) {

	pi_tab = cOther.pi_tab;
	i_size = cOther.i_size;

	cOther.i_size = 0;
	cOther.pi_tab = NULL;

	std::cout << "MOVE ";
}


CTab CTab::operator=(const CTab& cOther) {

	if (pi_tab != NULL) {
		delete pi_tab;
	}

	v_copy(cOther);
	std::cout << "op= ";
	return(*this);
}
void CTab::v_copy(const CTab& cOther) {

	pi_tab = new int[cOther.i_size];
	i_size = cOther.i_size;

	for (int ii = 0; ii < cOther.i_size; ii++) {
		pi_tab[ii] = cOther.pi_tab[ii];
	}
}

CTab CTab::operator=(CTab&& cOther) {

	if (pi_tab != NULL) {
		delete pi_tab;
	}

	pi_tab = cOther.pi_tab;
	i_size = cOther.i_size;

	cOther.i_size = 0;
	cOther.pi_tab = NULL;

	return *this;
}


bool CTab::bSetSize(int iNewSize) {

	if (iNewSize > 0) {
		int* tmp_table = new int[iNewSize];
		if (iNewSize > this->i_size) { //wydluzamy tablice
			for (int i = 0; i < this->i_size; i++) {
				tmp_table[i] = pi_tab[i];
			}
		}
		else {  //skracamy tablice
			for (int i = 0; i < iNewSize; i++) {
				tmp_table[i] = pi_tab[i];
			}
		}

		delete pi_tab;
		pi_tab = tmp_table;
		this->i_size = iNewSize;

		return true;
	}
	else {
		return false;
	}
}
