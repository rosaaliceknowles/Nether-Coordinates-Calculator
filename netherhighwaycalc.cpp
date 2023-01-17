#include <iostream>
#include <string>
using namespace std;

int coords[3];
string userInput; 
int mode = 0; // 1 == overworld --> nether, 2 == nether --> overworld, 3 == terminate program
bool loop = true;
bool inputController = true;
int count = 0;



int checkInput(string x){ // checks that the string x only contains numbers 
    try {
        for (char c : x){
            if (!(c > 47 && c < 58) && c != 45){ // 48 - 57 is 0-9, 45 is "-"
                throw(0);
            }
        }

        return stoi(x); // converts x to an integer

    }
    catch (int i){ // exception caught if the string contains non-numerical characters 
        cout << "\nInput must contain only numbers!\n" << endl;
        inputController = true;
        return 0;
    }
}


void getInput(){ // function that collects user input 
    count = 0;

    // each of the while loops will gather input then check if that input is a number, if that input is not a number it it will ask for the input again

    inputController = true;
    while (inputController){
        inputController = false;
        cout << "X = ";
        cin >> userInput;
        coords[0] = checkInput(userInput);
    }
    inputController = true;
    while (inputController){
        inputController = false;
        cout << "Y = ";
        cin >> userInput;
        coords[1] = checkInput(userInput);
    }
    inputController = true;
    while (inputController){
        inputController = false;
        cout << "Z = ";
        cin >> userInput;
        coords[2] = checkInput(userInput);
    }
    
}

void printCoords(string x){ // prints coords 
    cout 
    << "\n\n" << x << "\n" << endl
    << "X = " << coords[0] << endl
    << "Y = " << coords[1] << endl
    << "Z = " << coords[2] << endl;

    // i fucking love languages the require semicolons because it lets me do multi-line print statements, it's so fucking nice 
    // python and javascript can suck my 3-inch peen
}

int main(void){
    while(loop){
        // get mode
        while (1){
            cout << "1 == Overworld --> Nether" << endl
            << "2 == Nether --> Overworld" << endl
            << "3 == Terminate Program" << endl;

            cin >> userInput;

            try {
                for (char c : userInput){ // check to see if the user's input contains any non-numeric characters
                    if (!(c > 47 && c < 58)){
                        throw(1);
                    }
                }

                mode = stoi(userInput); // converts string to an integer 
                if (mode < 1 || mode > 3){ // checks to see if the user's input is within the intended scope 
                    throw(2);
                }

                break;

            }
            catch(int code){
                switch (code){
                    case 1:
                        cout << "\nInput must contain only numbers!\n" << endl;
                        break;
                    case 2: 
                        cout << "\nInput is not a valid number!\n" << endl;
                        break;
                    default:
                        cout << "\nUnknown error.\n" << endl;
                }
            }

        }

        cout << "\n\n";

        switch (mode){
            case 1:
                cout << "Overworld Coordinates: \n" << endl;
                getInput();

                for (int& i : coords){ // calculates the coords 
                    if ((count & 1) == 0){
                        i /= 8;
                    }
                    count++;
                }

                printCoords("Nether Coordinates: ");

                break;
            case 2:
                cout << "Nether Coordinates: \n" << endl;
                getInput();

                for (int& i : coords){ // calculates the coords 
                    if ((count & 1) == 0){
                        i *= 8;
                    }
                    count++;
                }

                printCoords("Overworld Coordinates: ");

                break;
            case 3:
                loop = false;
                break;
            default:
                cout << "\nUnknown error.\n" << endl;
        }

        cout << "\n\n";
    }

    system("pause");
    
    return 0;
}