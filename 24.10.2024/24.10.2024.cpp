#include<iostream>
using namespace std;

class Circle {
    double r;
    double const PI = 3.1415;
    public:
    Circle() { r = 0; }
    Circle(double _r) { r = _r; }
    bool operator==(Circle& b) {
        if (r == b.r) {
            return true;
        }
        return false;
    }
    bool operator>(Circle & b) {
        if (2 * PI * r > 2 * PI * b.r) {
            return true;
        }
        return false;
    }
    Circle operator+=(int a) {
        r += a;
        return *this;
    }
    Circle operator-=(int a) {
        r -= a;
        return *this;
    }

    bool operator==(Circle&b) {
        if (r == b.r) {
            return true;
        }
        return false;
    }
};


class AirPlane {
    char* type;
    int maxPass;
    int currPass;
public:
    AirPlane() {
        type = nullptr;
        currPass = 0;
        maxPass = 0;
    }
    AirPlane(const char* _type,int _currPass,int _maxPass) {
        type = new char[strlen(_type) + 1];
        strcpy_s(type, strlen(_type) + 1,_type);
        currPass = _currPass;
        maxPass = _maxPass;
    }

    AirPlane& operator=(const AirPlane& b) {
        if (this != &b) {
            delete[] type;
            type = new char[strlen(b.type) + 1];
            strcpy_s(type, strlen(b.type) + 1, b.type);
            currPass = b.currPass;
            maxPass = b.maxPass;
        }
        return *this;
    }
    bool operator==(AirPlane&type2) {
        if (strlen(type) != strlen(type2.type)) {
            return false;
        }
        if (strlen(type) > strlen(type2.type)) {
            for (int i = 0; i < strlen(type); i++)
            {
                if (type[i] != type2.type[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    AirPlane& operator++() {
        if (currPass < maxPass) {
            ++currPass;
        }
       
        return *this;
    }
    AirPlane& operator--() {
        if (currPass > 0) {
            --currPass;
        }

        return *this;
    }

    AirPlane operator--(int) {
        AirPlane temp(*this);
        if (currPass > 0) {
            --currPass;
        }

        return temp;
    }

    AirPlane operator++(int) {
        AirPlane temp(*this);
        if (currPass < maxPass) {
            ++currPass;
        }

        return temp;
    }

    bool operator>(AirPlane& b) {
        if (maxPass > b.maxPass) {
            return true;
        }
        return false;
    }

    void Print() {
        cout << type << endl << currPass << endl << maxPass;
    }

    ~AirPlane() {
        delete[]type;
    }
};

int main()
{
   
    AirPlane a("boing", 10, 300);
    AirPlane b("boing", 12, 200);
    ++b;
    ++a;
    if (a == b) {
        cout << "Good";
    }
 
    //c = a * 3;
    
}