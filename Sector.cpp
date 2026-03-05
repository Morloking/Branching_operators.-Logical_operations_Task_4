#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

string numToStr(int x) {
    string str{ "" };
    string base[]{ "ноль","один","два","три","четыре",
                   "пять","шесть","семь","восемь","девять" };
    string afterbase[]{ "десять","одиннадцать","двенадцать","тринадцать","четырнадцать",
                        "пятнадцать","шестнадцать", "семнадцать","восемнадцать","девятнадцать" };
    string lastbase[]{ "двадцать","тридцать","сорок","пятьдесят",
                        "шестьдесят","семьдесят","восемьдесят","девяносто" };
    if (x < 0) { str += "минус "; x *= -1; }
    if (x < 10) str += base[x];
    else if (x >= 10 && x < 20) str += afterbase[x - 10];
    else if (x >= 20) { 
        if (x % 10 != 0) str += lastbase[(x / 10) - 2] + " " + base[x % 10];
        else str += lastbase[(x / 10) - 2];
    }
    return str;
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int num1{ 0 }; int num2{ 0 };
    cout << "Введите целое число: ";
    cin >> num1;
    cout << "Введите целое число: ";
    cin >> num2;
    if ((num1 < -99|| num1 > 99) || (num2 < -99|| num2 > 99)) {
        cout << "Ошибка! Одно из чисел вне диапазона!\n";
        return 44;
    }
    else {
        if (num1 == num2) cout << numToStr(num1) + " равно " + numToStr(num2) + "\n";
        else if (num1 > num2) cout << numToStr(num1) + " больше чем " + numToStr(num2) + "\n";
        else cout << numToStr(num1) + " меньше чем " + numToStr(num2) + "\n";
    }
    return 0;
}
