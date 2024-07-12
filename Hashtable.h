#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "AdresnaKlasa.h"

using namespace std;

struct HashNode {
	long key;
	string value;
	bool isFull;
	int steps;

	HashNode() : key(-1), value(""), isFull(false),steps(0) {}
	HashNode(long key, string value, int steps) : key(key), value(value), isFull(true),steps(steps) {}
};

class Hashtable {
	int size;
	vector<HashNode> table;
	int keysNum = 0;
	int avgSuccess = 0;
	int	avgUnsuccess = 0;
	int hashFunction(long k) {
		return k % size;
	}
	AdresnaKlasa* adresnaKlasa;
	
public:
	Hashtable(AdresnaKlasa* ak,int size = 10001) :adresnaKlasa(ak),size(size),table(size) {};
	
	bool insertKey(long k, string s);
	string findKey(long k);
	bool deleteKey(long k);
	int avgAccessSuccess();
	int avgAccessUnsuccess();
	void resetStatistics();
	void clear();
	int keyCount();
	int tableSize();
	friend ostream& operator<<(ostream& os, const Hashtable& h);
	double fillRatio();

};