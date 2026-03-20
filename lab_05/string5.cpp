/**
 *
 * \file string5.cpp
 *
 * Itt kell megvalósítania a hiányzó tagfüggvényeket.
 * Segítségül megadtuk a C++ nem OO eszközeinek felhasználásával készített String-kezelő
 * függvényke neveit.
 *
 * Ha valamit INLINE-ként valósít meg, akkor annak a string5.h-ba kell kerülnie,
 * akár kívül akár osztályon belül definiálja. (Az inline függvényeknek minden
 * fordítási egységben elérhetőknek kell lenniük)
 * *
 * A teszteléskor ne felejtse el beállítani a string5.h állományban az ELKESZULT makrót.
 *
 */

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>             // Kiíratáshoz
#include <cstring>              // Sztringműveletekhez

#include "memtrace.h"           // a standard headerek után kell lennie
#include "string5.h"


/// Konstruktorok: egy char karakterből (createString)
///                egy nullával lezárt char sorozatból (createString)
String::String(char c) : len(1) {
  pData = new char[len+1];
  pData[0] = c;
  pData[len] = '\0';
}

String::String(const char* s) {
  len = strlen(s);
  pData = new char[len + 1];
  strcpy(pData, s);
  pData[len] = '\0';
}

/// Másoló konstruktor: String-ből készít (createString)
String::String(const String& str) {
  len = str.len;
  pData = new char[len + 1];
  strcpy(pData, str.pData);
  pData[len] = '\0';
}

/// Destruktor (disposeString)
String::~String() {
  delete[] pData;
}

/// operator=
String& String::operator=(const String& str) {
  if (this == &str) return *this;
  delete[] this->pData;
  this->len = str.len;
  this->pData = new char[len+1];
  strcpy(this->pData, str.pData);
  this->pData[len] = '\0';
  return *this;
}

/// [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza (charAtString)
/// indexhiba esetén const char * kivételt dob!
char& String::operator[](size_t idx) {
  if (idx < 0 || idx >= this->len) throw "TJ0Z3R";
  return this->pData[idx];
}

const char& String::operator[](size_t idx) const {
  if (idx < 0 || idx >= this->len) throw "TJ0Z3R";
  return this->pData[idx];
}

/// + operátorok:
///                 String-hez jobbról karaktert ad (addString)
String String::operator+(const char c) const {
  String res;
  delete[] res.pData;
  res.len = this->len+1;
  res.pData = new char[res.len + 1];
  strcpy(res.pData, this->pData);
  res.pData[res.len-1] = c;
  res.pData[res.len] = '\0';
  return res;
}

///                 String-hez String-et ad (addString)
String String::operator+(const String& str) const {
  String res;
  delete[] res.pData;
  res.len = this->len + str.len;
  res.pData = new char[res.len + 1];
  strcpy(res.pData, this->pData);
  strcat(res.pData, str.pData);
  res.pData[res.len] = '\0';
  return res;
}

String operator+(const char c, const String& str) {
  String res;
  delete[] res.pData;
  res.len = str.len + 1;
  res.pData = new char[res.len + 1];
  res.pData[0] = c;
  strcpy(res.pData+1, str.pData);
  return res;
}


/// << operator, ami kiír az ostream-re
std::ostream& operator<<(std::ostream& os, const String& str) {
  for (size_t i = 0; i < str.len; i++) {
    os << str[i];
  }
  return os;
}


/// >> operátor, ami beolvas az istream-ről egy szót
