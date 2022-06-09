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
        // with no arguments
        Fraction(){
            this->number = 0;
            this->numerator = 0;
            this->denominator = 1;
        }
        
        // constructor with one argument, and one optional argument.
        Fraction(int numeratorArg, int denominatorArg = 1){
            this->number = 0;
            this->numerator = numeratorArg;
            // constructor when dneominator is zero, so force it to be one.
            if (denominatorArg == 0 )
                this->denominator = 1;
            else 
                this->denominator = denominatorArg;
        
            // reducing to proper format
            this->reduceFraction();
        }

        // constructor with trhee arguments
        Fraction(int numberArg, int numeratorArg, int denominatorArg){
            this->number = numberArg;
            this->numerator = numeratorArg;
            // constructor when dneominator is zero, so force it to be one.
            if (denominatorArg == 0 )
                this->denominator = 1;
            else 
                this->denominator = denominatorArg;

            // reducing to preper format
            this->reduceFraction();
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

        // Overloading operators
        // Overloading = operator
        void operator=(Fraction fract){
            this->number = fract.number;
            this->numerator = fract.numerator;
            this->denominator = fract.denominator;
        }

        // Overloading == operator
        bool operator== (Fraction fract){
            if (this->number == fract.number &&
                this->numerator == fract.numerator &&
                this->denominator == fract.denominator) return true;
            else return false;
        }

        // Overloading + operator
        Fraction operator+(Fraction fract){
            Fraction temporal;
            temporal.numerator = (this->numerator * fract.denominator) + (fract.numerator * this->denominator);
            temporal.denominator = this->denominator * fract.denominator;
            temporal.number= this->number+ fract.number;
            //*this = temporal;
            temporal.reduceFraction();
            return temporal;
        }

        // Overloading * operator
        Fraction operator*(Fraction fract){
            Fraction temporal;
            temporal.numerator = (this->number * this->denominator + this->numerator) *
            (fract.number * fract.denominator + fract.numerator);
            temporal.denominator = this->denominator * fract.denominator;
            temporal.number= 0;
            temporal.reduceFraction();
            return temporal;
        }
};

class MathProblem{
    private:
    Fraction operand1;
    Fraction operand2;
    Fraction userAnswer;
    Fraction correctAnswer;
    string currentOperator;
    bool isAnswerCorrect;

    public:
    // Class methods
    void setProblem(){
        cin >> operand1;
        cin >> operand2;
        cout << "Choise operation: (+, *):";
        cin >> currentOperator;

        // Computing and saving correect asnswer;
        if (currentOperator == "+") correctAnswer = operand1 + operand2;
        else correctAnswer = operand1 * operand2;

        //cout << "User answer is: " << userAnswer;
        //cout << "Correct answer is: " << correctAnswer;
    }

    void displayProblem(){
        cout << "The problem you entered is: " << endl;
        cout << operand1 << " " << endl << currentOperator << " " << operand2;
    }

    void askUserForAnswer(){
        cout << endl << endl << "Enter your answer: ";
        cin >> userAnswer;
        if (userAnswer == correctAnswer) isAnswerCorrect = true;
        else isAnswerCorrect = false;

    }
    void displayAnswer(){
        cout << endl << "The fraction you entered is: " << userAnswer << endl;
        cout << endl << "The correct answer is: " << correctAnswer << endl;
        (isAnswerCorrect) ? cout << "Congragulation the answer you entered is correct!" :
                            cout << "Unfortunelly you did not get entered the correct answer.";
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
    /*MathProblem myProblem;

    /*myProblem.setProblem();
    myProblem.displayProblem();
    myProblem.askUserForAnswer();*/

    // manual testing
    /*cin >> fraction1;
    cin >> fraction2;
    cout << fraction1 + fraction2;
    cout << fraction1 * fraction2;*/


    // Part b
    const int NUMBER_OF_PROBLEMS = 2;
    
    // creating n number of problems in to an array
    MathProblem studentProblems[NUMBER_OF_PROBLEMS];
    for (int i = 0; i < NUMBER_OF_PROBLEMS; i++){
        cout << endl << endl << 
        "PROBLEM #:" << + i + 1 << endl;
        studentProblems[i].setProblem();
        studentProblems[i].displayProblem();
        studentProblems[i].askUserForAnswer();
    }

    // printing data out
    /*for (int i = 0; i < NUMBER_OF_PROBLEMS; i++){

    }*/



    return 0;
}
