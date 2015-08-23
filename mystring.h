/*
 ============================================================================
 File Name   : mystring.h
 Author      : Chris Jordan
 Revision History: None
 Date             Version     Change ID    Author          Comment
 7-14-15          1.0         NA           Chris Jordan    None
 ============================================================================
 Description:     Header file for class myString. myString is designed to 
                  be a string class, adding convenience to and reducing errors
                  of working with c-strings.

 Public Funtions:
 
 myString();
 Precondition:    None.
 Postcondition:   An object of class myString has been created, which has a
                  c-string with only '\0'.

 myString(const char *inMyCString);
 Precondition:    inMyCString is a c-string.
 Postcondition:   An object of class myString has been created, which has a
                  inMyCString c-string.

 myString(const myString& right);
 Precondition:    right is a myString object.
 Postcondition:   An object of class myString has been created, which is a copy
                  of (the myString object) right.

 ~myString();
 Precondition:    The memory for a myString object is being deallocated.
 Postcondition:   The variable that myCString was pointing to has had its memory
                  deallocated.

 myString operator= (const myString& right);
 Precondition:    right is a myString object.
 Postcondition:   The variable that the left.myCString was pointing to has been
                  deallocated, and left.myCString now points to a copy of 
                  right.myCString.

 friend std::ostream& operator<< (std::ostream& out, const myString& right);
 Precondition:    out is an ostream. right is a myString object.
 Postcondition:   right.myCString is sent to the ostream (out).

 friend std::istream& operator>> (std::istream& in, myString& right);
 Precondition:    in is an istream. right is a myString variable.
 Postcondition:   The istream, in, will read up to 127 characters, ignoring any
                  leading whitespace, and stops at the first whitespace. The 
                  variable that right.myCString was pointing to on the heap has 
                  had its memory deallocated, and right.myCString is now pointing
                  to a new c-string from the in buffer.

 void read(std::istream& in, char delim);
 Precondition:    in is an istream. delim is the character that will be the
                  delimiting char for extraction.
 Postcondition:   The istream, in, will read up to 127 characters, including any 
                  leading whitespace, and stop as the first occurence of the
                  char, delim. The variable that right.myCString was pointing to
                  on the heap has had its memory deallocated, and right.myCString
                  is now pointing to a new c-string from the in buffer.

 long length() const;
 Precondition:    None.
 Postcondition:   Returns a long with the value of strlen(myCString).

 friend bool operator< (const myString& left, const myString& right);
 Precondition:    left and right are myString objects or c-strings.
 Postcondition:   Returns a boolean representing the relationship between left 
                  and right. Returns true if strcmp(left.myCString,right.myCString)
                  is less than 0, false otherwise.

 friend bool operator<= (const myString& left, const myString& right);
 Precondition:    left and right are myString objects or c-strings.
 Postcondition:   Returns a boolean representing the relationship between left
                  and right. Returns true if strcmp(left.myCString,right.myCString)
                  is less than or equal to 0, false otherwise.

 friend bool operator> (const myString& left, const myString& right);
 Precondition:    left and right are myString objects or c-strings.
 Postcondition:   Returns a boolean representing the relationship between left
                  and right. Returns true if strcmp(left.myCString,right.myCString)
                  is greater than 0, false otherwise.

 friend bool operator>= (const myString& left, const myString& right);
 Precondition:    left and right are myString objects or c-strings.
 Postcondition:   Returns a boolean representing the relationship between left
                  and right. Returns true if strcmp(left.myCString,right.myCString)
                  is greater than or equal to 0, false otherwise.

 friend bool operator== (const myString& left, const myString& right);
 Precondition:    left and right are myString objects or c-strings.
 Postcondition:   Returns a boolean representing the relationship between left
                  and right. Returns true if strcmp(left.myCString,right.myCString)
                  is 0, false otherwise.

 friend bool operator!= (const myString& left, const myString& right);
 Precondition:    left and right are myString objects or c-strings.
 Postcondition:   Returns a boolean representing the relationship between left
                  and right. Returns true if strcmp(left.myCString,right.myCString)
                  is not 0, false otherwise.

 char operator[](int index) const;
 Precondition:    Calling object is a const myString object.
 Postcondition:   Returns the value of myCString[index].

 char& operator[](int index);
 Precondition:    Calling object is a myString object (not const).
 Postcondition:   Returns a reference to myCString[index].

 friend myString operator+ (const myString& left, const myString& right);
 Precondition:    left and right are myString objects or c-strings.
 Postcondition:   Returns a new myString object, whose myCString data member
                  points to a new c-string on the heap with a value of the
                  concatenation of left.myCString and right.myCString.

 myString operator+= (const myString& right);
 Precondition:    right is a myString object or a c-string.
 Postcondition:   myCString is assigned the value of the concatenation of 
                  right.myCString and myCString.
 */


#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

namespace cs2b_mystring {

   class myString {
   public:
      myString();
      myString(const char *inMyCString);
      myString(const myString& right);
      ~myString();
      myString operator= (const myString& right);
      friend std::ostream& operator<< (std::ostream& out, const myString& right);
      friend std::istream& operator>> (std::istream& in, myString& right);
      void read(std::istream& in, char delim);
      long length() const;
      friend bool operator< (const myString& left, const myString& right);
      friend bool operator<= (const myString& left, const myString& right);
      friend bool operator> (const myString& left, const myString& right);
      friend bool operator>= (const myString& left, const myString& right);
      friend bool operator== (const myString& left, const myString& right);
      friend bool operator!= (const myString& left, const myString& right);
      char operator[](int index) const;
      char& operator[](int index);
      friend myString operator+ (const myString& left, const myString& right);
      myString operator+= (const myString& right);
   private:
      char *myCString;
   }; // class end
} // namespace end

#endif

