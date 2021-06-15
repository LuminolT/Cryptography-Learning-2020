//Luminolt, 2021.06.14
#include <bits/stdc++.h>
using namespace std;

class intZ26{
    public:
        int value;
        intZ26(int a = 0){
            value = a;
        }
        intZ26 operator+(const intZ26& b){
            intZ26 a;
            a.value = (this->value + b.value) % 26;
            return a;
        }
        intZ26 operator*(const intZ26& b){
            intZ26 a;
            a.value = (this->value * b.value) % 26;
            return a;
        }
        bool operator==(const intZ26& b){
            return this->value == b.value;
        }
        intZ26 operator=(const int &b){
            intZ26 a;
            a.value = b % 26;
            this->value = b % 26;
            return a;
        }
        friend istream &operator>>(istream &in, intZ26 &a){
	        in >> a.value;
	        return in;
        }
        friend ostream &operator<<(ostream &os, const intZ26 &a){
            os << a.value;
	        return os;
        }
};

intZ26 encode(intZ26 a, intZ26 b, intZ26 x){
    intZ26 ans = a * x + b;
    return ans;
}

int main() {
    string cypher = "gkhl";
    string plain = "flag";
    intZ26 c[4], p[4];
    for(int i = 0; i <= 3; i++){
        c[i] = cypher[i] - 'a';
        p[i] = plain[i] - 'a';
    }
    for(int i = 0; i <= 25; i++){
        for(int j = 0; j <= 25; j++){
            // cout << i << ' ' << j << endl;
            for(int m = 0; m <= 3; m++){
                if((encode(i, j, p[m]) == c[m])){
                    if(m == 3)
                        cout << i << ',' << j;
                    else
                        continue;
                }
                else
                    break;
            }
        }
    }
}
