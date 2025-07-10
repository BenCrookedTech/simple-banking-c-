#include <iostream>
using namespace std;

/* Luhn Algorithm
1. Double every second digit from right to left, 
If doubled number ix 2 digits, split them
2. Add all single digits from step 1
3. Add all odd numbered digits from right to left
4. Sum results from steps 2 & 3
5. If step 4 is divisible by 10, credit card number is valid
*/

int getDigit(const int number);
int sumOddDigits(string cardNumber);
int sumEvenDigits(string cardNumber);

int main(){
    
    string cardNumber;
    int result = 0;

    cout<<"Enter card Number ";
    cin>>cardNumber;

    result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);

    if(result%10==0){
        cout<<"Card Number is Valid."<<endl;
    }
    else{
        cout<<"Invalid card Number!"<<endl;
    }


    return 0;
}
int getDigit(const int number){
    return number % 10 + (number/10%10);
}
int sumOddDigits(string cardNumber){

    int sum = 0;

    for(int i = cardNumber.size()-1; i >= 0; i-=2){
        sum += cardNumber[i]-'0';
    }
    return sum;
}
int sumEvenDigits(string cardNumber){

    int sum = 0;

    for(int i = cardNumber.size()-2; i >= 0; i-=2){
        sum += getDigit((cardNumber[i]-'0')*2);
    }

    return sum;
}