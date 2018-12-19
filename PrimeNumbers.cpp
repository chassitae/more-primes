#include <iostream>
using namespace std;

int getNum();
void findPrime(int, int []);
void printAll(int [], int);
bool isPrime(int);

int main(){
    int num;
    char choice;

    do {
        num = getNum();
        int numbers[num];

        for(int i = 0; i < num; i++)
            numbers[i] = -1;

        cout << "\nWe will return all prime numbers from 2 to "
             << num << endl << endl;
        findPrime(num, numbers);
        printAll(numbers, num);

        cout << "\n\nTry again? [y/n]:\t";
        cin >> choice;

        choice  = toupper(choice);

        while (choice != 'Y' && choice != 'N'){
            cout << "Invalid input: choice must be [y/n]\n"
                 << "Re-enter your choice [y/n]:\t";
            cin >> choice;
            choice  = toupper(choice);
        }

    } while (choice == 'Y');

    cout << "\n\nEnd of program." << endl << endl;

    return 0;

}

int getNum(){
    int num;

    cout << "Enter a number greater than 1:\t";
    cin >> num;

    while (!cin || num < 1){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nInvalid input: must be a number greater than 2.\n"
             << "Re-enter a number greater than 2:\t";
        cin >> num;
    }
    return num;
}

void findPrime(int num, int array[]){
    bool prime;
    int count = 0;

    for (int i = 2; i <= num; i++){
        prime = isPrime(i);
        if(prime){
            array[count] = i;
            count++;
        }
    }
}

void printAll(int array[], int size){

    cout << "Prime numbers:\n\t";
    for (int i = 0; i < size; i++){
        if(array[i] == -1)
            cout << "";
        else
            cout << array[i] << "  ";
    }
}

bool isPrime(int num){
    bool isPrime = false;
    int count = 0;

    for (int i = 2; i < num; i++){
        if(i == num)
            isPrime = true;
        else if (num % i == 0)
            count++;
    }
    if(count == 0)
        isPrime = true;
    return isPrime;
}
