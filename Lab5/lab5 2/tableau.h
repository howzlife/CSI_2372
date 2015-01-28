// ==========================================================================
// $Id: tableau.h,v 1.1 2013/11/28 05:09:36 jlang Exp $
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
// $Log: tableau.h,v $
// Revision 1.1  2013/11/28 05:09:36  jlang
// completed solution for lab 5
//
// ==========================================================================
#include <iostream>

using std::cerr;
using std::endl;

template <class T> class Tableau  {
protected:
  int d_maxNumberOfArrays;
  int d_currentNumberOfArrays;
  T** d_arrays;
  int* d_arraySizes;
  virtual void invalidate() = 0;   // private helper function to ensure 
  // that we know when a new table has been added
  void add(T* _anArray, int _len); // private helper function which does the work
public:
  Tableau(unsigned int _maxNumberOfArrays);
  // must define own c-ctor because of pointer members
  Tableau(const Tableau<T>& _oTableau );
  // we also must define our own assignment operator but that was not 
  // covered yet
  Tableau& operator=(const Tableau<T>& _oTableau );
  // must define own dtor because of pointer members
  // its a base class, make it virtual
  virtual ~Tableau();
  void reset(); 
  int getNumberOfInputs();
  virtual int getDimOutput() = 0; // Needs to be pure virtual because 
  // it depends on the run method of the derived class
  int addArray(T* _anArray, int _len);
  virtual T getOutput(int _i) = 0;   // Needs to be pure virtual because 
  // it depends on the run method of the derived class 
  virtual void run() = 0;   // pure virtual run method which does the work
};

// ctor
template<class T> Tableau<T>::Tableau(unsigned int _maxNumberOfArrays) 
: d_maxNumberOfArrays(_maxNumberOfArrays), d_currentNumberOfArrays(0) {
  d_arrays =  new T*[_maxNumberOfArrays];
  d_arraySizes = new int[_maxNumberOfArrays];
}

// cctor
template<class T> Tableau<T>::Tableau(const Tableau<T>& _oTableau ) 
: d_maxNumberOfArrays(_oTableau.d_maxNumberOfArrays) {
  cerr << "Tableau cctor: " << d_maxNumberOfArrays << ":" << _oTableau.d_currentNumberOfArrays << endl;
  d_currentNumberOfArrays = 0;
  d_arrays =  new T*[d_maxNumberOfArrays];
  d_arraySizes = new int[d_maxNumberOfArrays];
  for ( int i=0; i<_oTableau.d_currentNumberOfArrays; ++i ) {
    add(_oTableau.d_arrays[i], _oTableau.d_arraySizes[i] );
  }
}

// assignment operator
template<class T> 
Tableau<T>& Tableau<T>::operator=(const Tableau<T>& _oTableau ) {
  if ( this != &_oTableau ) { // guard against self assgnment
    d_maxNumberOfArrays=_oTableau.d_maxNumberOfArrays;
    for (int i=0; i < d_currentNumberOfArrays; i++)
      delete[] d_arrays[i];
    delete[] d_arrays;
    delete[] d_arraySizes;
    d_currentNumberOfArrays = 0;
    d_arrays =  new T*[d_maxNumberOfArrays];
    d_arraySizes = new int[d_maxNumberOfArrays];
    for ( int i=0; i<_oTableau.d_currentNumberOfArrays; ++i ) {
      addArray(_oTableau.d_arrays[i], _oTableau.d_arraySizes[i] );
    }
  }
  return *this; // return reference to ourself
}

// destructor
template<class T> Tableau<T>::~Tableau() {
  for (int i=0; i < d_currentNumberOfArrays; i++)
    delete[] d_arrays[i];
  delete[] d_arrays;
  delete[] d_arraySizes;
}

template<class T> void Tableau<T>::reset() {
  for (int i=0; i < d_currentNumberOfArrays; i++)
    delete[] d_arrays[i];
  d_currentNumberOfArrays = 0;
}

template<class T> int Tableau<T>::getNumberOfInputs() { 
  return d_currentNumberOfArrays; 
}

template<class T> int Tableau<T>::getDimOutput() {
  int dim = 0;
  for (int i=0; i < d_currentNumberOfArrays; ++i )
    dim += d_arraySizes[i];
  return dim;
}
 
template<class T> void Tableau<T>::add(T* _anArray, int _len) {
  if (d_currentNumberOfArrays < d_maxNumberOfArrays) {
    // copy array
    d_arrays[d_currentNumberOfArrays] = new T[_len];
    for (int i=0; i<_len; ++i) {
      d_arrays[d_currentNumberOfArrays][i] = _anArray[i];
    }
    d_arraySizes[d_currentNumberOfArrays] = _len;
    ++d_currentNumberOfArrays;
  }
  return;
}

template<class T> int Tableau<T>::addArray(T* _anArray, int _len) {
  add( _anArray, _len );
  invalidate();
  return d_currentNumberOfArrays;
}

//**********************************************************
//Union
//**********************************************************

template<class T> class Union : public Tableau<T> {
  int d_size;
  T* d_result;
  bool d_processed;
 protected:
  void invalidate();
 public:
  Union(unsigned int _maxNumberOfArrays);
  Union(const Union<T>& _oUnion ); // d_result is dynamic need own copy control
  Union<T>& operator=(const Union<T>& _oUnion );
  ~Union();
  int getDimOutput();
  T getOutput(int _i);
  void run();
};

template<class T> void Union<T>::invalidate() {
  delete[] d_result;
  d_processed = false;
  return;
}

template<class T> Union<T>::Union(unsigned int _maxNumberOfArrays) 
: Tableau<T>::Tableau(_maxNumberOfArrays), d_size(0), d_result(0), d_processed(false) 
{};

template<class T> Union<T>::Union(const Union<T>& _oUnion ) 
: Tableau<T>::Tableau( _oUnion ), d_size( _oUnion.d_size ), d_result( 0 ), d_processed( _oUnion.d_processed ) {
  cerr << "Union cctor: " << d_size << endl;
  if ( d_size > 0 ) {
    d_result = new T[d_size];
    for (int i=0; i<d_size; ++i ) {
      d_result[i] = _oUnion.d_result[i];
    }
  }
}

template<class T> 
Union<T>& Union<T>::operator=(const Union<T>& _oUnion ) {
  if ( this != &_oUnion ) {
    // parent assignment
    Tableau<T>::operator=( _oUnion );
    if ( d_size > 0 ) delete [] d_result;
    d_size = _oUnion.d_size;
    d_result = 0;
    d_processed = _oUnion.d_processed;
    if ( d_size > 0 ) {
      d_result = new T[d_size];
      for (int i=0; i<d_size; ++i ) {
	d_result[i] = _oUnion.d_result[i];
      }
    }
  }
  return *this;
}



template<class T> Union<T>::~Union() { // parent dtor always runs after us 
  if ( d_size > 0 ) delete [] d_result;
};

template<class T> int Union<T>::getDimOutput() {
  if (!d_processed) run();
  return d_size;
} 

template<class T> T Union<T>::getOutput(int _i) {
  if (!d_processed) run();
  if (_i >= d_size ) throw "Out of Range";
  return d_result[_i];
}

template<class T> void Union<T>::run() {
  // count the duplicates -- could use a std::set but not covered yet
  int maxSize = 0;
  for (int i=0; i < Tableau<T>::d_currentNumberOfArrays; ++i )
    maxSize += Tableau<T>::d_arraySizes[i];
  // Make a maximum size array -- copy at the end
  // cerr << "Max size: " << maxSize << endl;
  T* result = new T[maxSize];
  int curEntry = 0;
  for (int i=0; i < Tableau<T>::d_currentNumberOfArrays; ++i ) {
    for ( int j=0; j< Tableau<T>::d_arraySizes[i]; ++j ) {
      // For each element we have to check if it is already in the output
      bool skip = false;
      for (int k=0; k<curEntry; ++k ) {
	if ( result[k] == Tableau<T>::d_arrays[i][j] ) {
	  skip = true;
	  break;
	}
      }
      if ( !skip ) {
	result[curEntry] = Tableau<T>::d_arrays[i][j];
	++curEntry;
      }
    }
  }
  // cerr << "Final size: " <<  curEntry << endl;
  d_size = curEntry;
  d_result = new T[d_size];
  for ( int i=0; i<d_size; ++i) {
    d_result[i] = result[i];
  }
  delete[] result;
  d_processed = true;
  return;
} 

//**********************************************************
//Intersection
//**********************************************************
template<class T> class Intersection : public Tableau<T> {
  int d_size;
  T* d_result;
  bool d_processed;
 protected:
  void invalidate();
 public:
  Intersection(unsigned int _maxNumberOfArrays);
  Intersection(const Intersection<T>& _oInt ); // d_result is dynamic need own copy control
  Intersection<T>& operator=(const Intersection<T>& _oInt );
  ~Intersection();
  int getDimOutput();
  T getOutput(int _i);
  void run();
};

template<class T> void Intersection<T>::invalidate() {
  delete[] d_result;
  d_processed = false;
  return;
}

template<class T> Intersection<T>::Intersection(unsigned int _maxNumberOfArrays) 
: Tableau<T>::Tableau(_maxNumberOfArrays), d_size(0), d_result(0), d_processed(false) {};

template<class T> Intersection<T>::Intersection(const Intersection<T>& _oInt ) 
: Tableau<T>::Tableau( _oInt ), d_size( _oInt.d_size ), d_result( 0 ), d_processed( _oInt.d_processed ) {
  if ( d_size > 0 ) {
    d_result = new T[d_size];
    for (int i=0; i<d_size; ++i ) {
      d_result[i] = _oInt.d_result[i];
    }
  }
}


template<class T> 
Intersection<T>& Intersection<T>::operator=(const Intersection<T>& _oInt ) {
  if ( this != &_oInt ) {
    // parent assignment
    Tableau<T>::operator=( _oInt );
    if ( d_size > 0 ) delete [] d_result;
    d_size = _oInt.d_size;
    d_result = 0;
    d_processed = _oInt.d_processed;
    if ( d_size > 0 ) {
      d_result = new T[d_size];
      for (int i=0; i<d_size; ++i ) {
	d_result[i] = _oInt.d_result[i];
      }
    }
  }
  return *this;
}



template<class T> Intersection<T>::~Intersection() {
  if ( d_size > 0 ) delete [] d_result;
};

template<class T> int Intersection<T>::getDimOutput() {
  if (!d_processed) run();
  return d_size;
} 

template<class T> T Intersection<T>::getOutput(int _i) {
  if (!d_processed) run();
  if (_i >= d_size ) throw "Out of Range";
  return d_result[_i];
}

template<class T> void Intersection<T>::run() {
  // Intersection is maximally the size of the smallest array
  // could use std::min_element
  if ( Tableau<T>::d_currentNumberOfArrays == 0 ) { // nothing to be done
    d_size = 0;
    d_result = 0;
    d_processed = true;
    return;
  }
  int maxSize = Tableau<T>::d_arraySizes[0];
  int minArrayId = 0;
  for (int i=1; i < Tableau<T>::d_currentNumberOfArrays; ++i ) {
    if ( Tableau<T>::d_arraySizes[i] < maxSize ) {
       maxSize = Tableau<T>::d_arraySizes[i];
       minArrayId = i;
    }
  }
  // cerr << "maxSize: " << maxSize << endl;
  // Make a maximum size array -- copy at the end
  T* result = new T[maxSize];
  bool* keep = new bool[maxSize];
  int keepCount = maxSize; 
  // copy the elements from the minArray
  for ( int k=0; k<maxSize; ++k ) {
    result[k] = Tableau<T>::d_arrays[minArrayId][k];
    keep[k] = true;
  }
  // Now delete all entries in result that do not occur elsewhere
  for ( int k=0; k<maxSize; ++k ) {
    for (int i=0; i < Tableau<T>::d_currentNumberOfArrays; ++i )  {
      if ( i==minArrayId ) continue;
      bool found = false;
      for ( int j=0; j< Tableau<T>::d_arraySizes[i]; ++j ) {
	if ( result[k] == Tableau<T>::d_arrays[i][j] ) {
	  found = true;
	  break;
	}
      }
      if(!found) { keep[k] = false; --keepCount; break; }
    }
  }
  // cerr << "keepCount: " << keepCount << endl;
  // Now copy over
  d_size = keepCount;
  d_result = new T[d_size];
  for ( int k=0,m=0; k<maxSize; ++k) {
    if ( keep[k] ) {
      d_result[m] = result[k];
      ++m;
    }
  }
  delete[] result;
  delete[] keep;
  d_processed = true;
  return;
} 


//***********************************************************
//Unique
//***********************************************************
template<class T> class Unique : public Tableau<T> {
  int d_size;
  T* d_result;
  bool d_processed;
 protected:
  void invalidate();
 public:
  Unique(unsigned int _maxNumberOfArrays);
  Unique(const Unique<T>& _oUni ); // d_result is dynamic need own copy control
  Unique<T>& operator=(const Unique<T>& _oUni );
  ~Unique();
  int getDimOutput();
  T getOutput(int _i);
  void run();
};

template<class T> void Unique<T>::invalidate() {
  delete[] d_result;
  d_processed = false;
  return;
}

template<class T> Unique<T>::Unique(unsigned int _maxNumberOfArrays) 
: Tableau<T>::Tableau(_maxNumberOfArrays), d_size(0), d_result(0), d_processed(false) {};

template<class T> Unique<T>::Unique(const Unique<T>& _oUni ) 
: Tableau<T>::Tableau( _oUni ), d_size( _oUni.d_size ), d_result( 0 ), d_processed( _oUni.d_processed ) {
  if ( d_size > 0 ) {
    d_result = new T[d_size];
    for (int i=0; i<d_size; ++i ) {
      d_result[i] = _oUni.d_result[i];
    }
  }
}

template<class T> 
Unique<T>& Unique<T>::operator=(const Unique<T>& _oUni ) {
  if ( this != &_oUni ) {
    // parent assignment
    Tableau<T>::operator=( _oUni );
    if ( d_size > 0 ) delete [] d_result;
    d_size = _oUni.d_size;
    d_result = 0;
    d_processed = _oUni.d_processed;
    if ( d_size > 0 ) {
      d_result = new T[d_size];
      for (int i=0; i<d_size; ++i ) {
	d_result[i] = _oUni.d_result[i];
      }
    }
  }
  return *this;
}

template<class T> Unique<T>::~Unique() {
  if ( d_size > 0 ) delete [] d_result;
};

template<class T> int Unique<T>::getDimOutput() {
  if (!d_processed) run();
  return d_size;
} 

template<class T> T Unique<T>::getOutput(int _i) {
  if (!d_processed) run();
  if (_i >= d_size ) throw "Out of Range";
  return d_result[_i];
}

template<class T> void Unique<T>::run() {
  // could use a std::multimap amd only keep entries in the result that occur exactly once
  // Worst case -- all elements are unique
  int maxSize = 0;
  for (int i=0; i < Tableau<T>::d_currentNumberOfArrays; ++i )
    maxSize += Tableau<T>::d_arraySizes[i];
  // Make a maximum size array -- copy at the end
  T* result = new T[maxSize];
  int curEntry = 0;
  bool skip = false;
  for (int i=0; i < Tableau<T>::d_currentNumberOfArrays; ++i )  {
    for ( int j=0; j< Tableau<T>::d_arraySizes[i]; ++j ) {
      // take each element and now loop over all elements to make sure it is not there again
      // sorting would be more efficent O(n^2m^2) vs O(nm log(nm))
      for (int k=0; k < Tableau<T>::d_currentNumberOfArrays; ++k ) {
	for ( int l=0; l< Tableau<T>::d_arraySizes[k]; ++l ) {
	  if (k==i && l==j) continue;
	  if(Tableau<T>::d_arrays[i][j]==Tableau<T>::d_arrays[k][l]) {
	    skip = true;
	    break;
	  }
	}
	if (skip) break; // break out of outer loop
      }
      if (!skip) { // found unique entry, copy over
	result[curEntry] = Tableau<T>::d_arrays[i][j];
	++curEntry;
      }
      skip = false; // reset
    }
  }
   
  // cerr << "Final size: " <<  curEntry << endl;
  d_size = curEntry;
  d_result = new T[d_size];
  for ( int i=0; i<d_size; ++i) {
    d_result[i] = result[i];
  }
  delete[] result;
  d_processed = true;
  return;
} 


