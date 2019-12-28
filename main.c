// A STUDY OF HIGH ORDER FUNCTIONS IN C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//EXAMPLES OF FUNCTION POINTERS IN C
//function foo takes an int and adds the int onto itself
int foo(int a){
  return a + a;
}
//function bar takes an int and multiplies it into itself
int bar(int a){
  return a * a;
}

//notice that the two functions above have similar signatures -
//they both return an int and takes in an int
//we can use this to design some flexible code

//we can design a function that takes in a function pointer that has
//a similar signature
//the below function takes a int, and a function pointer to a function
//that returns an int and takes a int parameter
//look at main to see how this is used
int testFunctionPointers(int a, int (*functionToCall)(int)){
  return functionToCall(a);
}


//lets use function pointers to make something a bit more useful
//the map function is a popular built in function in many modern languages
//lets see how we can implement it in C

//lets define a function that will be executed for each element
//caesar encryption and decryption - even though not a great way to ecrypt data -
//is fine enough of an example here

//we will make a function to encrypt
char caesarEncrypt(const char* orgChar, const int key){
  return(char)((*orgChar + key) % 256);
}
//and one to decrypt
char caesarDecrypt(const char* orgChar, const int key){
  return(char)((*orgChar - key) % 256);
}
//the map function will take a string and create a new string and apply the given function over
//each char
//check out main to see how this is used
char* map(const char* originalString, const int key, char(*mapFunction)(const char*, const int)){
  char* result = (char*)malloc(sizeof(char) * strlen(originalString));
  for(int i = 0; i < strlen(originalString); ++i){
    result[i] = mapFunction(&originalString[i], key);
  }
  return result;
} 

int main(int argc, char** argv){
  //testing out function pointers
  printf("result of calling foo : %d\n", testFunctionPointers(4, foo)); //prints 8
  printf("result of calling bar : %d\n", testFunctionPointers(4, bar)); //prints 16

  //testing out map
  int key = 999;
  char* originalString = "oi! how ya doin?";
  char* encryptedString = map(originalString, key, caesarEncrypt);
  char* decryptedString = map(encryptedString, key, caesarDecrypt);
  printf("original string : %s\n", originalString);
  printf("encrypted string : %s\n", encryptedString);
  printf("decrypted string : %s\n", decryptedString);

  free(encryptedString);
  free(decryptedString);
  return 0;
}
