// This program will give you a unique identification key from your
// id number. This number can not be stored by the program, therefore,
// it is not prone to be stolen. Using this program you can be verified,
// but your identification key can not be stolen.

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

long long convert(int);
 //To change decimal into binary

int main(){
    
    srand(time(NULL));//to help seed the random number generator
    
    int userNum;
    int num1[50], num2[50];
    // num1 & num2 are random numbers
    // prime numbers are useful in cryptography
        printf("Select a prime ID number(2, 3, 5, 7, 11, 13, 17, etc.)  ");
        scanf("%d", &userNum);
            for(int ctr=0; ctr<=50; ctr++){
                num1[ctr] = rand()%100;
                num2[ctr] = convert(num1[ctr]);  
            }
            for(int ctr = 0; ctr<4; ctr++){
                int a;
                a = num2[ctr]*userNum;
                //The number is the product of userNum and randomly
                //generated number, thus, can not be stolen
                printf("%d ", a);
            }
        // Simple way to verify password
        // The more number of digits we produce, the safer this gets
        printf("\nLet's check your password! \nEnter any number of your password;    ");
        int var;
        scanf("%d", &var);
        if((var%userNum)==0){
            printf("This password belongs to you!");
        }else{
            printf("This is not your password!");
        }
}
        


//This is the function definition of converting decimal into binary
long long convert(int n) {
  long long bin = 0;
  int rem, i = 1;

  while (n!=0) {
    rem = n % 2;
    n /= 2;
    bin += rem * i;
    i *= 10;
  }

  return bin;
}