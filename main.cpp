
 //William Wong
 //4/7/23
 //This project allows one to create, insert, search, delete, and traverse
 //a binary tree data structure!

 #include <cstring>
 #include <iosstream>
 #include <fstream>
 #include <vector>
 #include "node.h"
 using namespace std;

 node * root = NULL;

 int main() {

   int userIn = 0;
   char input[50];
   bool continue = false;

   cout << "--------------------------------------" << endl;

   cout << "This is BST! Burgers, Milk Shakes, and Tequila! Hold up... I meant Binary Search Tree!" << endl; 

 do {

   cout << "Hey User! Input the number 1 if you want to create the numbers through a file or input the number 2 to create them manually";

   cin >> userIn;
   cin.get();

   if (answer == 1) {
     //Input the file function here
     continue = true;
   } else if (answer == 2) {
     //Input the user file function here
     continue = true;
   } else {
     cout << endl;
     "Invalid input! Repeat again" << endl;
   }
 } while (!cont);

 cout << "--------------------------------------" << endl;
 print(root, 0);

  int numz = 0;

 do {
   cout << "--------------------------------------" << endl;
   cout << "Please choose the follow commands --> ADD or SEARCH or REMOVE or PRINT or QUIT: ";
   cin.get(input, 50);
   cin.get();

   if (strcmp(input, "ADD") == 0) {
     cout << "Please enter what number you would to add: ";
     cin >> numz;
     cin.get();
     //Insertion function here
     cout << "Successfully Added!" << endl;
   } else if (strcmp(input, "SEARCH") == 0) {
     cout << "Please enter the number you want to look for: ";
     cin >> numz;
     cin.get();
     //Search function here
   } else if (strcmp(input, "REMOVE") == 0) {
     cout << "Please enter the number you want to remove: ";
     cin >> numz;
     cin.get();
     //remove function here
     cout << "Successfull Removed!" << endl;
   } else if (strcmp(input, "PRINT") == 0) {
     //print function here
   } else if (strcmp(input, "QUIT")) {
     cout << "Thanks for using this application!" << endl;
   } else {
     cout << "Invalid command. Please try again!" << endl;
   }
 } while (strcmpy(input, "QUIT") != 0);

}

