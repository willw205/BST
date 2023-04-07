
 //William Wong
 //4/7/23
 //This project allows one to create, insert, search, delete, and traverse
 //a binary tree data structure!

 #include <cstring>
 #include <iostream>
 #include <fstream>
 #include <vector>
 #include "node.h"
 using namespace std;

 //Function Prototypes

 void insert(Node * &current, int num);
 void search(Node * current, int num);
 void print(Node * current, int fold);
 void fileGenerator();
 void manualGenerator();
 Node * remove(Node * current, int num);

 Node * root = NULL;

 int main() {

   int userIn = 0;
   char input[50];
   bool continues = false;

   cout << "--------------------------------------" << endl;

   cout << "This is BST! Burgers, Milk Shakes, and Tequila! Hold up... I meant Binary Search Tree!" << endl; 

 do {

   cout << "Hey User! Input the number 1 if you want to create the numbers through a file or input the number 2 to create them manually";

   cin >> userIn;
   cin.get();

   //Below asking user if they want to genrate through file input (1) or manual (2)
   
   if (userIn == 1) {
     fileGenerator();
     continues = true;
   } else if (userIn == 2) {
     manualGenerator();
     continues = true;
   } else { //Invalid input
     cout << endl;
     cout << "Invalid input! Repeat again" << endl;
   }
 } while (!continues);

 cout << "--------------------------------------" << endl;
 print(root, 0);

  int numz = 0;

 //Below asking user which commands they want to go through

 do {
   cout << "--------------------------------------" << endl;
   cout << "Please choose the follow commands --> ADD or SEARCH or REMOVE or PRINT or QUIT: ";
   cin.get(input, 50);
   cin.get(); //user adding num

   if (strcmp(input, "ADD") == 0) {
     cout << "Please enter what number you would to add: ";
     cin >> numz;
     cin.get();
     insert(root, numz);
     cout << "Successfully Added!" << endl;
   } else if (strcmp(input, "SEARCH") == 0) { //Looking for num user inputted
     cout << "Please enter the number you want to look for: ";
     cin >> numz;
     cin.get();
     search(root, numz);
   } else if (strcmp(input, "REMOVE") == 0) { //removing number
     cout << "Please enter the number you want to remove: ";
     cin >> numz;
     cin.get();
     root = remove(root, numz);
     cout << "Successfull Removed!" << endl;
   } else if (strcmp(input, "PRINT") == 0) { //printing out tree
     print(root, 0);
   } else if (strcmp(input, "QUIT")) {
     cout << "Thanks for using this application!" << endl;
   } else {
     cout << "Invalid command. Please try again!" << endl;
   }
 } while (strcmp(input, "QUIT") != 0);

}

 //below we are addting the num into tree
 void insert(Node * &current, int num) {

   if (current == NULL) {
     current = new Node(num, NULL, NULL);
     return;
   }
   if (num >= current->data) {
     if (current->right == NULL) {
       current->right = new Node(num, NULL, NULL);
       return;
     } else {
       insert(current->right, num);
     }
   } else {
     if (current->left == NULL) {
       current->left = new Node(num, NULL, NULL);
       return;
     } else {
       insert(current->left, num);
     }
   }
 }

 //Below is function searching for userinputted num 
 void search(Node * current, int num) {

   int numB = 0;

   while (current != NULL) {
     numB = current->data;
     if(numB == num) {
       cout << "Number is inside tree" << endl;
       return;
     }
     if(num > numB) {
       current = current->right;
     } else {
       current = current->left;
     }
   }

   cout << "Number is not within tree" << endl;
   
 }

//Below is function the prints out tree w/inorder tree traversal
 void print(Node * current, int fold) {

   if(current == NULL) {
     return;
   }

   print(current->right, fold + 1);

   for(int i = 0; i < fold; i++) {
     cout << "    ";
   }

   cout << current->data << endl;

   print(current->left, fold + 1);
   
 }

 //generates binary tree through a random file input
 void fileGenerator() {

   int num = 0;
   ifstream numbers("numbers.txt");
   srand(time(NULL));
   vector<int> nums;

   while(!numbers.eof()) {
     numbers >> num;
     nums.push_back(num);
   }

   int count = 0;
   int rando = 0;

   while(count != 10) {
     rando = (rand() % 999) + 1;
     num = nums.at(rando);
     cout << num << " ";
     insert(root, num);
     count++;
   }
   cout << endl;
   
 }

//generate binary tree through user input
 void manualGenerator() {

   int count = 0;
   int input = 0;

   cout << "Hey user! Please enter number by number, and also one can cease the loop by entering -1" << endl;

   while(input != 0 || count < 50) {
     cout << endl;
     cout << "Please enter a num: ";
     cin >> input;
     if(input == -1) {
       break;
     } else {
       insert(root, input);
       cout << endl;
       cout << "Number has been entered!" << endl;
       count++;
     }
   }

   cin.get();
   
 }

//Removes num through the use of pointers to left and right children
//Function updates tree by either delete node or replacing with in-order successor

 Node * remove(Node * current, int num) {

   if(current == NULL) {
     return current;
   }

   if(num > current->data) {
     current->right = remove(current->right, num);
     return current;
   }

   if(num < current->data) {
     current->left = remove(current->left, num);
     return current;
   } else {
     if(current->right == NULL && current->left == NULL) {
       return NULL;
     } else if (current->left == NULL) {
         Node * temp = current->right;
         delete current;
         return temp;
     } else if (current->right == NULL) {
         Node * temp = current->left;
         delete current;
         return temp;
     } else {
        Node * par = current;
        Node * small = current->left;

        while(small->right != NULL) {
          par = small;
          small = small->right;
        }
       if(par != current) {
         par->right = small->left;
       } else {
        par->left = small->left;
       }
       current->data = small->data;
       delete small;
       return current;
     }
    }

    return current;

  }
