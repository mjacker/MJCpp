#include <iostream>
using namespace std;

// Class declarations
class Fraction{
    private:
        int number;
        int numerator;
        int denominator;
        const static string SYMBOL;
        //const static string SYMBOL;
    public:
        // Constructors
        Fraction(){

        }
        //Fraction(int = 0, int = 0, int = 0, const string = "/");
        //Fraction(int numeratorArg, int denominatorArg);
        //Fraction(int number, int numerator, int denominator);

        // Functions methods
        /*void enterFractionValue();
        void reduceFraction();
        void displayFraction();        */

        // Implementation
        Fraction(int numeratorArg, int denominatorArg){
            this->numerator = numeratorArg;
            this->denominator = denominatorArg;
            const string SYMBOL = "/";
        }
        void enterFractionValue(int numeratorArg, int denominatorArg){
            this->numerator = numeratorArg;;
            this->denominator = denominatorArg;
        }

        void displayFraction(){
            cout << this->numerator << this->SYMBOL << this->denominator << endl;
        }
};

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