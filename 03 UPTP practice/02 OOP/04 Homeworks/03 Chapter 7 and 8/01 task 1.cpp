#include <iostream>
using namespace std;

// Global variables
bool RUNNING = true;

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
            this->denominator = 1;
        }

        // Functions methods
        void enterFractionValue(/*int numeratorArg, int denominatorArg*/){
           cin >> *this; 
        }

        /**
         * @brief Reduces a Fraction to proper form, For example, 
         * a Fraction with the value 0 2/6 would be reducted to 0 1/3 and a
         * Fraction with the value 4 18/4 would be reduced to 8 1/2.
         */
        void reduceFraction(){
            // reducing fraction
            int newNumber = this->number, newNumerator; // avoiding overwriting when doing calculations
            if (this->numerator > this->denominator){
                newNumber += (int) (this->numerator / this->denominator);
                newNumerator = (this->numerator % this->denominator);
                this->number= newNumber;
                this->numerator = newNumerator;
            }
            
            // simplify
            // choosing the lowest value between numerator and denominator in min
            int min;
            if (this->numerator > this->denominator)
                min = this->denominator;
            else min = this->numerator;

            // If numerator and denominator are divisible by i then divide numerator and denominator
            for (int i = 1; i <= min; i++){
                if (((this->numerator % i) == 0) && ((this->denominator % i) == 0)){
                    this->numerator = (this->numerator) / i;
                    this->denominator = (this->denominator) / i;
                    i = 1;
                }
            }

            // special case when both numerator and denominator has the same value
            if (this->numerator == 1 && this->denominator == 1){
                this->number++;
                this->numerator = 0;
            } 
        }

        void displayFraction(){
            cout << *this;
        }
};

// Overloading >> operator
istream& operator>>(istream &in, Fraction &fract){
    cout << endl << "Integer: ";
    in >> fract.number;
    cout << "Numerator: ";
    in >> fract.numerator;
    do {
        cout << "Denominator: ";
        in >> fract.denominator;
        if (fract.denominator == 0) cout << "Denominator can not be zero!." << endl << "Try again: " << endl;
    } while (fract.denominator == 0);
    if (fract.number == 0 && fract.numerator == 0){
        cout << "Ending program..." << endl;
        RUNNING = false;
    }
    return in;
}

// Overloading << operator
ostream& operator<<(ostream &out, const Fraction &fract){
    // out << fract.number << " " << fract.numerator << fract.SYMBOL << fract.denominator << endl;
    out << endl; // cleaning out
    if (fract.number == 0 && fract.numerator == 0) out << "0";
    else if (fract.number > 0 && fract.numerator == 0) out << fract.number;
    else if (fract.number == 0 && fract.numerator > 0) out << fract.numerator << fract.SYMBOL << fract.denominator;
    else out << fract.number << " " << fract.numerator << fract.SYMBOL << fract.denominator; 
    return out;
}

// Assigning value to a static constant
const string Fraction::SYMBOL = "/";

int main(void){
    // manual testing examples
    /*Fraction fraction1;
    fraction1.enterFractionValue();
    fraction1.displayFraction();
    fraction1.reduceFraction();
    fraction1.displayFraction();*/

    Fraction fraction1;
    while (RUNNING)
    {
        cin >> fraction1;
        fraction1.reduceFraction();
        cout << fraction1;;
    }
    



    //cin << fraction1;
    //cout << fraction1;

    return 0;
}