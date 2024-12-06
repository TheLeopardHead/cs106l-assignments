/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include "class.h"
/* #### Please don't change this line! #### */
int run_autograder();

int main() {
  MyClass myClass(10);
  std::cout << "Init Data: " << myClass.getData() << std::endl;
  myClass.setData(20);
  std::cout << "Set Data: " << myClass.getData() << std::endl;
  MyClass myClass2;
  std::cout << "Default Data: " << myClass2.getData() << std::endl;


  /* #### Please don't change this line! #### */
  return run_autograder();
}

/* #### Please don't change this line! #### */
#include "utils.hpp"