#include "Hashtable.h"

using namespace std;

bool Hashtable::insertKey(long k, string s)
{
	int originalA, tmpA,i;
	originalA = tmpA = hashFunction(k);
	i = 1;
	if (k ) {
	while (table[tmpA].isFull) {
		while (table[tmpA].value != s) {


			if (table[tmpA].key == k) {
				return false;
			}
			tmpA = adresnaKlasa->getAddress(tmpA, i) % size;
			i++;
			if (tmpA == originalA) {
				return false;
			}
		}
	}
	}
	else {
		cout << "greska";
	}

	table[tmpA] = HashNode(k, s, i);
	keysNum++;
	return true;
}

string Hashtable::findKey(long k)
{
	int originalA, tmpA, i;
	originalA = tmpA = hashFunction(k);
	i = 1;
	if (k) {
	while (table[tmpA].isFull) {
		while (table[tmpA].key != k) {

			return "/";
			if (table[tmpA].key == k) {
				return table[tmpA].value;
			}
			tmpA = adresnaKlasa->getAddress(tmpA, i) % size;
			i++;
			if (tmpA == originalA) {
				return "/";
			}
		}
	} 
	}
	else {
		cout << "greska";
	}
	
}

bool Hashtable::deleteKey(long k)
{
	int originalA, tmpA, i;
	originalA = tmpA = hashFunction(k);
	i = 1;
	while (table[tmpA].isFull) {
		if (table[tmpA].key == k) {
			table[tmpA] = HashNode();
			keysNum--;
			return true;
		}
		tmpA = adresnaKlasa->getAddress(tmpA, i) % size;
		i++;
		if (tmpA == originalA) {
			return false;
		}
	}
}

int Hashtable::avgAccessSuccess()
{
	int stepSum = 0;
	for (int i = 0; i < size; i++) {
		stepSum += table[i].steps;
	}
	return stepSum/keysNum;
}

int Hashtable::avgAccessUnsuccess()
{
	double s = size;
	double kn = size - keysNum;
	double k = 1;
	double p = 0;
	for (int i = 1; i < size - 1; i++) {
		p += i * k * (kn / s);
		k *= (abs(s - kn)) / s;
		s--;
	}
	return p;
}

void Hashtable::resetStatistics()
{
	avgSuccess = avgUnsuccess = 0;
}

void Hashtable::clear()
{
	table.clear();
	table.resize(size);
}

int Hashtable::keyCount()
{
	return keysNum;
}

int Hashtable::tableSize()
{
	return this->size;
}

double Hashtable::fillRatio()
{
	double k = keysNum;
	double s = size;
	double resp = (k / s) * 100;
	return resp;
}

ostream& operator<<(ostream& os, const Hashtable& h)
{
	for (int i = 0; i < h.size; i++) {
		os << "[" << i << "]" << " (" << h.table[i].key << " , " << h.table[i].value<< ")" << endl << endl;
	}
	return os;
}
