#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

double difShemaCentralna(double Fminus, double Fplus, double D) {
    double dif = (Fplus - Fminus) / D;
    return dif;
}

double difShemaNaprej(double F, double Fplus, double Fplusplus, double D) {
    double dif = (-3 * F + 4 * Fplus - Fplusplus) / D;
    return dif;
}

double difShemaNazaj(double F, double Fminus, double Fminusminus, double D) {
    double dif = (3 * F - 4 * Fminus + Fminusminus) / D;
    return dif;
}

double odvajanje(std::string input, std::string output) {
    std::ifstream inputDatoteka(input);
    std::ofstream outputDatoteka(output);

    if (!inputDatoteka.is_open() || !outputDatoteka.is_open()) {
        std::cerr << "Napaka pri odpiranju datoteke!" << std::endl;
        return 1;
    }

    std::string vrstica;
    std::vector<std::pair<int, std::pair<double, double>>> podatki;

    while (getline(inputDatoteka, vrstica)) {

        int ID;
        double x, fx;

        std::istringstream iss(vrstica);
        char dvopicje;

        iss >> ID >> dvopicje >> x >> fx;

        podatki.push_back({ ID, {x, fx} });
    }

    for (int i = 0; i < podatki.size(); i++) {

        if (i == 0) {
            std::cout << "Tocke iz datoteke \"" << input << "\" in odvodi v teh tockah:\n" << std::endl;
        }
        else {
            double difFX;
            if (i == 1) {
                double FX = podatki[i].second.second;
                double FXpotem = podatki[i + 1].second.second;
                double FXpotempotem = podatki[i + 2].second.second;
                double dvaDX = 2 * (podatki[i + 1].second.first - podatki[i].second.first);
                difFX = difShemaNaprej(FX, FXpotem, FXpotempotem, dvaDX);
            }
            else if (i == podatki.size() - 1) {
                double FX = podatki[i].second.second;
                double FXprej = podatki[i - 1].second.second;
                double FXprejprej = podatki[i - 2].second.second;
                double dvaDX = 2 * (podatki[i].second.first - podatki[i - 1].second.first);
                difFX = difShemaNazaj(FX, FXprej, FXprejprej, dvaDX);
            }
            else {
                double FXprej = podatki[i - 1].second.second;
                double FXpotem = podatki[i + 1].second.second;
                double dvaDX = podatki[i + 1].second.first - podatki[i - 1].second.first;
                difFX = difShemaCentralna(FXprej, FXpotem, dvaDX);
            }
            std::cout << "ID: " << podatki[i].first << ", x: " << podatki[i].second.first << ", f(x): " << podatki[i].second.second << ", f'(x): " << difFX << std::endl;
            outputDatoteka << "f'(" << podatki[i].second.first << "): " << difFX << "\n";
        }
    }

    inputDatoteka.close();
    outputDatoteka.close();

    std::cout << "\nOdvodi so shranjeni v datoteki \"" << output << "\"." << std::endl;
}

int main() {

    odvajanje("poly.txt", "diff_poly.txt");

    return 0;
}