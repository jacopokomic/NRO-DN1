#include <iostream>
#include <cmath>
using namespace std;

double st = 1000;

double arctan(double x) {
    double output = 0;
    for (int i = 0; i <= st; i ++) {
        output += pow(-1, i) * (pow(x, 2 * i + 1)) / (2 * i + 1);
    }
    return output;
}

double funkcija(double x) {
    double vrednost = exp(3 * x) * arctan(x / 2);
    return vrednost;
}

double integral(double a, double b, int n) {
    double h = (b - a) / n;
    double k = 0;
    double rezultat = 0;
    for (int i = 0; i <= n; i++) {
        double x = a + i * h;
        if (i == 0 || i == n) {
            k = 0.5;
        }
        else {
            k = 1;
        }
        rezultat += k * h * funkcija(x);
    }
    return rezultat;
}

int main() {
    const double pi = 3.141592653589793238462643383279502884;
    // definiramo vrednosti (a0 in b0 sta podani v definiciji naloge):
    double a0 = 0;
    double b0 = pi / 4;
    double n0 = 1000;
    cout << "VREDNOST INTEGRALA: " << integral(a0, b0, n0);
    return 0;
}