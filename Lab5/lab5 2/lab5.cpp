// ==========================================================================
// $Id: lab5.cpp,v 1.1 2013/11/28 05:09:35 jlang Exp $
// CSI2372 example solution lab 5 Fall 2013
// ==========================================================================
// (C)opyright:
//
//   Jochen Lang
//   EECS, University of Ottawa
//   800 King Edward Ave.
//   Ottawa, On., K1N 6N5
//   Canada. 
//   http://www.eecs.uottawa.ca
// 
// Creator: Jochen Lang, Amir Rad
// Email:   jlang@eecs.uottawa.ca
// ==========================================================================
// $Log: lab5.cpp,v $
// Revision 1.1  2013/11/28 05:09:35  jlang
// completed solution for lab 5
//
// ==========================================================================
#include <iostream>
#include <string>

#include "tableau.h"

using std::string;
using std::cout;
using std::endl;


int main()
{
  Union<int> t(3);
  int x[] = {12, 54, 42};
  int y[] = {54, 3, 42, 7}; 
  int z[] = { 3, 42, 54, 57, 3};
  t.addArray(x, 3);
  t.addArray(y, 4);
  t.addArray(z, 5);
  int size = t.getDimOutput();
  cout << "Result size: " <<  size << endl;
  cout << "Result: ";
  for ( int i=0; i<size; ++i ) 
    cout << t.getOutput(i) << " ";
  cout << endl;




  Intersection<int> intObj(3);
  intObj.addArray(x, 3);
  intObj.addArray(y, 4);
  intObj.addArray(z, 5);
  size = intObj.getDimOutput();
  cout << "Result size: " <<  size << endl;
  cout << "Result: ";
  for ( int i=0; i<size; ++i ) 
    cout << intObj.getOutput(i) << " ";
  cout << endl;

  Unique<int> uniObj(3);
  uniObj.addArray(x, 3);
  uniObj.addArray(y, 4);
  uniObj.addArray(z, 5);
  size = uniObj.getDimOutput();
  cout << "Result size: " <<  size << endl;
  cout << "Result: ";
  for ( int i=0; i<size; ++i ) 
    cout << uniObj.getOutput(i) << " ";
  cout << endl;
  

  //************** float

  Union<float> uoObjF(4);
  float xf[] = {1.1, 3.3, 4.4, 5.5, 6.6};
  float yf[] = {1.1, 1.2, 1.3}; 
  float zf[] = {0.1, 1.1, 5.5};
  float tf[] = {1.1, 0.1, 6.6, 3.3, 4.5, 5.5};
  uoObjF.addArray(xf, 5);
  uoObjF.addArray(yf, 3);
  uoObjF.addArray(zf, 3);
  uoObjF.addArray(tf, 6);
  size = uoObjF.getDimOutput();
  cout << "Result size: " <<  size << endl;
  cout << "Result: ";
  for ( int i=0; i<size; ++i ) 
    cout << uoObjF.getOutput(i) << " ";
  cout << endl;
 
  Intersection<float> intObjF(4);
  intObjF.addArray(xf, 5);
  intObjF.addArray(yf, 3);
  intObjF.addArray(zf, 3);
  intObjF.addArray(tf, 6);
  size = intObjF.getDimOutput();
  cout << "Result size: " <<  size << endl;
  cout << "Result: ";
  for ( int i=0; i<size; ++i ) 
    cout << intObjF.getOutput(i) << " ";
  cout << endl;

  Unique<float> uniObjF(4);
  uniObjF.addArray(xf, 5);
  uniObjF.addArray(yf, 3);
  uniObjF.addArray(zf, 3);
  uniObjF.addArray(tf, 6);
  size = uniObjF.getDimOutput();
  cout << "Result size: " <<  size << endl;
  cout << "Result: ";
  for ( int i=0; i<size; ++i ) 
    cout << uniObjF.getOutput(i) << " ";
  cout << endl;
  
  //****************String

  Union<string> uoObjS(2);
  string xs[] = {"banana", "apple", "orange", "raisin", "pear"};
  string ys[] = {"apple", "pear", "cherry"}; 
  uoObjS.addArray(xs, 5);
  uoObjS.addArray(ys, 3);
  size = uoObjS.getDimOutput();
  cout << "Result size: " <<  size << endl;
  cout << "Result: ";
  for ( int i=0; i<size; ++i ) 
    cout << uoObjS.getOutput(i) << " ";
  cout << endl;
 
  Intersection<string> intObjS(2);
  intObjS.addArray(xs, 5);
  intObjS.addArray(ys, 3);
  size = intObjS.getDimOutput();
  cout << "Result size: " <<  size << endl;
  cout << "Result: ";
  for ( int i=0; i<size; ++i ) 
    cout << intObjS.getOutput(i) << " ";
  cout << endl;

  Unique<string> uniObjS(2);
  uniObjS.addArray(xs, 5);
  uniObjS.addArray(ys, 3);
  size = uniObjS.getDimOutput();
  cout << "Result size: " <<  size << endl;
  cout << "Result: ";
  for ( int i=0; i<size; ++i ) 
    cout << uniObjS.getOutput(i) << " ";
  cout << endl;
  
  return 0;
}

