#include <iostream>
using namespace std;

// Class declarations
class Fraction{
    //friend functions:
        friend istream& operator>>(istream &in, Fraction &fract);
        friend ostream& operator<<(ostream &out, const Fraction &fract);
    private:
        int number;
        int numerator;
        int denominator;
        const static string SYMBOL;
        //const static string SYMBOL;
    public:
        // Constructors
        Fraction(){
            this->number = 0;
            this->numerator = 0;
            this->denominator = 0;
        }

        // Functions methods

        void enterFractionValue(int numeratorArg, int denominatorArg){
            this->numerator = numeratorArg;;
            this->denominator = denominatorArg;
        }

        void displayFraction(){
            cout << *this;
        }
};

istream& operator>>(istream &in, Fraction &fract){
    cout << "Numerator: ";
    in >> fract.numerator;
    cout << "Denominator: ";
    in >> fract.denominator;
    return in;
}

ostream& operator<<(ostream &out, const Fraction &fract){
    out << fract.numerator << fract.SYMBOL << fract.denominator << endl;
    return out;
}

// Assigning value to a static constant
const string Fraction::SYMBOL = "/";

int main(void){
    Fraction fraction1;

    fraction1.enterFractionValue(10, 20);
    fraction1.displayFraction();

    //cin << fraction1;
    //cout << fraction1;

    return 0;
}