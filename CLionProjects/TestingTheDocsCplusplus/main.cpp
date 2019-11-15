#include <iostream>
using namespace std;



// FUNCTION simple example
int addition(int a, int b) {
    int result = a + b;
    return result;
}

// VOID FUNCTION
void printMessage() {
    cout << "I'm a function!\n";
}

// FUNCTION VARIABLE REFRENCE
void square(int& x, int& y, int& z) {
    x *= 2;
    y *= 2;
    z *= 2;
}

// FUNCTION THAT ONLY READS FROM THE REFRENCED VALUES (more efficient for COMPOUND TYPES/BIGGER DATATYPES)
string concatinate_efficient(const string long1, const string long2) {
    return long1 + long2;
}

// FUNCTION THAT COPIES THE WHOLE REFRENCED VALUES INTO PARAMETER VARIABLES (Less efficient for COMPOUND TYPES/BIGGER DATATYPES, but more efficient for FUNDAMETAL TYPES)
string concatinate_inefficient(string long1, string long2) {
    return long1 + long2;
}

// INLINE FUNCTIONS TELL THE COMPILER TO REPLACE THE FUNCTION CALL WITH THE CODE GENERATED FROM THIS FUNCTION
// This means that we tell the compiler to insert the code generated at each point where this function is called,
// instead of being invoked with a regular function call.
// This can reduce cost for smaller functions.
// IN-LINE, moves the code into the line where it was called.
// Does the exact same thing as a normal function. No difference in result.
// Most compiler do this automatically where they see fit. Thus the compiler might ignore and add inline to wherever it wants...
// We can only tell the compiler that we would prefer to have this inlined.
inline string concatinate_inline(const string long1, const string long2) {
    return long1 + long2;
}

// DEFAULT FUNCTION PARAMETERS
float divide(float a, float b = 2) {
    return a / b;
}


// PROTOTYPE FUNCTIONS!
// This is a prototype function which allows us to call the function in our code without having fully written the functionallity.
// It can be seen as a placeholder.
// This only works as long as we define the full function somewhere else in our program.
// A prototype function can be declared either with only the type as a parameter, or both the type and the variable name specified.
string myProtoFunction(int, int);
string mySecondProtoFunciton(int a, int b);

// RECURSIVE FUNCTION
int triangularNumber(int i) {
    if(i < 1) return i;
    else return i + triangularNumber(i - 1);
}
int triangularNumberWithAcc(int i, int acc) {
    if(i < 1) return acc;
    else return triangularNumberWithAcc(i - 1, i + acc);
}


// FUNCTION OVERLOADING
void whatAmI(int a) {
    cout << "I'm an integer\n";
}
void whatAmI(float a) {
    cout << "I'm a float\n";
}
void whatAmI(double a) {
    cout << "I'm a double\n";
}
void whatAmI(string a) {
    cout << "I'm a string\n";
}

// FUNCTION TEMPLATE: (Instantiates at compile time a different function for each call)
// Let's you use a generic class type inside your function.
// ("class" can be replaced with "typename", in this context they are synonyms)
template <class SomeType>
SomeType sum(SomeType a, SomeType b) {
        return a + b;
}
template <class T, typename U>
bool areEqual(T a, U b) {
    return (a == b);
}
// Fixed types
template <class T, int N>
T fixedMultiply(T val) {
    return val * N;
}

int main() {
    cout << "Hello, World!" << endl;
    cout << "I'm a c++ program." << endl;

    int a = 1;
    int b (2);
    int c {3};

    cout << a << endl;
    cout << c << endl;
    cout << b << endl;

    string myString = "hello world v2";
    cout << myString << endl;

    // Constants
    // 75 // decimal
    // 0113 // Octal
    // 0x4b // Hexadecimal
    // All of the above are equivalent.

    //Defining constants
    const double pi = 3.14;
    cout << pi << endl;
    // Suffixes
    // 75 int
    // 75u unsigned int
    // 75l long
    // 75ul unsigned long

    // Double
    // 4.62345
    // 4.2e10
    // 4.123f // float

    // Character and string literals
    // 'a' // Character
    // "abc" // String literal
    // Concatination???
    string weirdString = "Hey " "I'm really weird " "Wow";
    char character = '\t';

    cout << weirdString << endl;

    bool foo = true;
    bool bar = false;
    int* p = nullptr;

    // Assignment
    int x;
    int y = 2 + (x = 5);
    cout << "x: " << x << ", y: " << y << endl;

    x = y = 1;
    cout << ++x << endl;
    cout << y++ << endl;

    // Conditional ternary operator
    bool isCookieJarFull = false;
    int amountOfCookies = (isCookieJarFull) ? 10 : 1; // If true use left value, else use right value
    cout << "Amount of cookies in jar: " << amountOfCookies << endl;

    // Comma operator
    a = (b = 2, b + 5);
    cout << "a: " << a << ", b: " << b << endl;
    a = (b = 2, b += 4, b + 3);
    cout << "a: " << a << ", b: " << b << endl;

    // Type casting
    //int i;
    //float f = 3.14;
    //i = (int) f;

    // Stream operators
    // << Insertion operator
    // >> Extraction operator
    // cout << "hey"
    // cin >> x

    // If statements
    if(false)
        cout << "Awwww" << endl;
    else if(false)
        cout << "noooo" << endl;
    else
        cout << "huh" << endl;

    // While loop
    int n = 10;
    while(n > 0) {
        cout << n << ", ";
        n--;
    }

    cout << "Liftoff!" << endl;

    // Do While Loop. Useful when the loop needs to be executed at least once. While statement is evaluated after the run.
    bool isOn = false;
    string str;
    do {
        cout << "Enter text: ";
        if(isOn) getline(cin, str);
        cout << "You entered: " << str << "\n";
    } while (str != "goodbye" &&isOn);


    // For loop
    for(int i = 10; i > 0; i--) {
        cout << i << ", ";
    }
    cout << "liftoff!\n";

    // For loop with comma operator
    int i, j;
    for(i = 0, j = 10; i <= 10; i++, j--) {
        cout << i << j;
    }
    cout << "\n";

    // Foreach : range based for loop
    str = "Hello";
    for(char c : str) cout << c << ", ";

    // break, continue keywords work as usual


    // SWITCH statement
    i = 3;
    switch(i) {
        case 1:
            cout << "i is one\n";
            break;
        case 2:
            cout << "i is two\n";
            break;
        case 3:
            cout << "i is three\n";
            break;
        default:
            cout << "I dont know what i is...\n";
            break;
    }

    // FUNCTION CALL
    a = addition(1, 3);
    cout << a << "\n";
    printMessage();

    // FUNCTION WILL MODIFY REFERENCE
    int f = 1, g = 3, h = 5;
    square(f, g, h);
    cout << "f: " << f << ", g: " << g << ", h: " << h << "\n";

    // FUNCTION WITH CONST PARAMETERS (Faster for bigger structures that need not be modified)
    string longString1 = "ÖOIGJÖROIJÖOVIJöroigsjöeorigjsöodfigjsöreonkwjer,jwhlajheliuwhqieutpoidfjgvfdklnv.xjdfkjghölsoeijr5gsöor";
    string longString2 = "6464654684f6e84a6w54f68876h84t6r846ti8i4684yu6öå85465v jm4 s4r.654645548965a4sr6a54df6g4h65rts4654l65465";

    // Uses const parameter values (keeps the reference, but forbidds modification).
    concatinate_efficient(longString1, longString2);
    // Uses copied parameter values (creates a new local copy of the parameters passed in. No refrence is kept).
    concatinate_inefficient(longString1, longString2);
    // Function call is replaced by the code generated from the function instead of using a regular function call.
    concatinate_inline(longString1, longString2);

    // FUNCTION DEFAULT PARAMETERS
    a = 8, b = 4;
    // Function can be called with only one parameter... (second parameter defaults to 2 if left out)
    cout << "Uses default: " << divide(a) << "\n"; // 8/2 = 4
    // Or, like normal, with two parameters.
    cout << "Uses specified: " << divide(a, b) << "\n"; // 8/4 = 2

    // PROTOTYPE FUNCTIONS !!!
    cout << myProtoFunction(3, 10);
    cout << mySecondProtoFunciton(5, 10);

    // RECURSION
    a = 10000;
    b = triangularNumber(a);
    cout << "Triangular number of " << to_string(a) << " is: " << to_string(b) << "\n";
    // RECURSION
    a = 100000; // CANNOT EXCEED THIS NUMBER?? Too big result? Tail recursion problem? Stack overflow?
    b = triangularNumber(a);
    cout << "Triangular number of " << to_string(a) << " is: " << to_string(b) << "\n";

    // OVERLOAD FUNCTIONS
    whatAmI(1);
    whatAmI(1.0);
    whatAmI(1.0f);
    whatAmI("huh");

    // TEMPLATE FUNCTION
    cout << "Template of sum:" << "\n";
    cout << sum<int>(10, 30) << "\n";
    cout << sum<double>(10.0, 30.5) << "\n";
    cout << sum<float>(5.43f, 123.32f) << "\n";
    double aa = 2.54, bb = 123.42;
    int cc = 1, dd = 2;
    // The previous declaration implies the type.
    cout << sum(aa, bb) << "\n";
    cout << sum(cc, dd) << "\n";
    if(areEqual(10, 10.0)) {
        cout << "x and y are equal\n";
    } else {
        cout << "x and y are not equal\n";
    }
    if(areEqual<float, double>(15.0f, 10.0)) {
        cout << "x and y are equal\n";
    } else {
        cout << "x and y are not equal\n";
    }
    // Fixed types
    cout << fixedMultiply<int, 2>(10) << "\n"; // Instantiates a new method that only multiplies by two.

    return 0;
}

string myProtoFunction(int a, int b) {
    return std::to_string(a) + std::to_string(b) + "\n";
}
string mySecondProtoFunciton(int a, int b) {
    return std::to_string(a) + std::to_string(b) + " with a 2 on the end.\n";
}


// CONTINUE READING on Name visibility: