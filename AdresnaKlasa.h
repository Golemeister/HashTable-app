#pragma once
#include <iostream>

using namespace std;

class AdresnaKlasa {

public:
	virtual int getAddress(int a, int i) = 0;
};

class BLAdresiranje : public AdresnaKlasa {
private:
    int s;

public:
    BLAdresiranje(int s) : s(s) {}

    int getAddress(int a, int i) override {
        return a + (i % 2 == 0 ? (i - 1) * s : i * s);
    }
};