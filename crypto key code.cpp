#include<iostream>
using namespace std;

void split(int number, int available, int needed, int prime){
int coef[10];
int shar[10][2]={0,0};
coef[0] = number;
int n = prime - 1;
for(int c = 1; c < needed; c++) {
coef[c] = rand() % n + 1; 
}
int x, exp, y;
double accum;
for(x = 1, y = 0; x <= available; x++)
{
	for(exp = 1, accum = coef[0]; exp < needed; exp++)
{
double inn= fmod((pow(double(x), exp)), prime); 
double ac = accum + fmod(coef[exp] * inn,prime);
accum = fmod(ac,prime);

shar[x – 1][y] = x;
shar[x – 1][y + 1] = accum;
std::cout << “( index = “<< shar[x – 1][y];
std::cout << “, value = “<< shar[x – 1][y + 1] << ” )” << std::endl;
}
}
pair<int, pair<int, int> > extendedEuclid(int a, int b) {
if(a == 0) return make_pair(b, make_pair(0, 1));
pair<int, pair<int, int> > p;
p = extendedEuclid(b % a, a);
return make_pair(p.first, make_pair(p.second.second – p.second.first*(b/a), p.second.first));
}

int modInverse(int a, int m) {
return (extendedEuclid(a,m).second.first + m) % m;
}

int combine(int shares[10][2], int primeNum, int threshold) {
long double accum = 0, startposition =0, nextposition =0;
for (int i=0 ; i<threshold; i++)
{
	cout<< shares[i][0] << “-“<<shares[i][1] << endl;
}
for (int i = 0; i < threshold; i++) {
long double num = 1;
long double den = 1;

for (int j = 0; j < threshold; j++) {
if (i != j) {
startposition = shares[i][0];
nextposition = shares[j][0];
num = fmod((num * (-nextposition)), primeNum);
den = fmod((den * (startposition – nextposition)), primeNum);
}
else if (i==j) {continue;}
}

cout<< “den: ” << den ;
cout<<” num: ” << num ;
int mi = modInverse(den, primeNum);
cout<<” inv: ” << mi <<endl;
int value = shares[i][1];

long double tmp = value* num * (modInverse(den, primeNum));
long double acc = (accum + primeNum + tmp);
accum = fmod(acc,primeNum);

cout<< ” value: ” << value ;
cout<< ” tmp: ” << tmp ;
cout<< ” accum: ” << accum <<endl;
}

cout<< “The secret is: ” << accum;
return accum;
}
	