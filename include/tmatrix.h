// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 10000000;
const int MAX_MATRIX_SIZE = 1000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T> // Динамический Вектор 
class TDynamicVector
{
protected:
  size_t sz; // Размер вектора
  T* pMem;  // (указатель на память)
public:
  TDynamicVector(size_t size = 1) : sz(size)
  {
    if (sz == 0)
      throw out_of_range("Vector size should be greater than zero"); //Размер вектора должен быть больше нуля
    if (sz > MAX_VECTOR_SIZE)
        throw out_of_range("Size of the vector is larger than the allowed"); //Размер вектора больше допустимого 
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию, () - заполнен нулями
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
      if (sz == 0)
          throw out_of_range("Vector size should be greater than zero"); 
      if (sz > MAX_VECTOR_SIZE)
          throw out_of_range("Size of the vector is larger than the allowed"); 

      assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg"); //Для динамического векторного ctor требуется аргумент non-nullptr (проверка не нулевой ли массив)
    pMem = new T[sz];// выделяем память под вектор Т размера sz
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v)// копирование
  {
      sz = v.sz;
      if (v.pMem == nullptr) { //Если v.pMem равно nullptr, это означает, что нет данных для копирования
          pMem = nullptr;
      }
      else {
          pMem = new T[sz];
          for (int i = 0; i < sz; i++)
          {
              pMem[i] = v.pMem[i];
          }
      }
  }
  TDynamicVector(TDynamicVector&& v) noexcept // перемещение
  {
      sz = v.sz;
      pMem = v.pMem;
      v.sz = 0;
      v.pMem = nullptr;
  }//Этот конструктор также принимает ссылку на другой объект TDynamicVector, но в отличие от конструктора копирования, он осуществляет перемещение данных из объекта v в новый объект, вместо их копирования.
  ~TDynamicVector()
  {
      delete[]pMem;// освобождает память, занятую массивом pMem
  }
  TDynamicVector& operator=(const TDynamicVector& v)//Оператор присваивания копированием
  {
      if (this == &v) { //Проверка, не является ли текущий объект this уже равным объекту v
          return *this;
      }
      if (pMem != nullptr) { //Если массив pMem имеет данные, они удаляются, чтобы освободить память.
          delete[]pMem;
      }
      if (v.pMem == nullptr) {
          sz = 0;
          pMem = nullptr;
      }
      else { //Размер и элементы массива копируются из объекта v в текущий объект.
          sz = v.sz;
          pMem = new T[sz];
          for (int i = 0; i < sz; i++) {
              pMem[i] = v.pMem[i];
          }
      }
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept//Оператор присваивания перемещением
  {
      if (this == &v) { 
          return *this;
      }
      if (pMem != nullptr) { 
          delete[]pMem;
      }
      if (v.pMem == nullptr) {
          sz = 0;
          pMem = nullptr;
      }
      else { //размер и указатель на массив присваиваются из объекта v в текущий объект, а объект v становится недействительным
          sz = v.sz;
          pMem = v.pMem;

          v.sz = 0;
          v.pMem = nullptr;
      }
      return *this;
  }

  size_t size() const noexcept { return sz; }//возвращает размер

  // индексация
  T& operator[](size_t ind)
  {
      return pMem[ind];//возвращает ссылку на элемент массива pMem по указанному индексу ind
  }
  const T& operator[](size_t ind) const
  {
      return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if ((ind < 0) || (ind >= sz)) {//выходит за границы 
          throw "Error";
      }
      if (pMem == nullptr) {//массив пуст
          throw "Error";
      }
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if ((ind < 0) || (ind >= sz)) {
          throw "Error";
      }
      if (pMem == nullptr) {
          throw "Error";
      }
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz) {
          return 0;
      }
      for (int i = 0; i < sz; i++) {
          if (pMem[i] != v.pMem[i]) {//сравнение массивов поэлементно 
              return 0;
          }
      }
      return 1;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz) {
          return 1;
      }
      for (int i = 0; i < sz; i++) {
          if (pMem[i] != v.pMem[i]) {
              return 1;
          }
      }
      return 0;
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector temp(*this);
      for (int i = 0; i < sz; i++) {
          temp[i] = pMem[i] + val;
      }
      return temp;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector temp(*this);
      for (int i = 0; i < sz; i++) {
          temp[i] = pMem[i] - val;
      }
      return temp;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector<T> temp(*this);
      for (int i = 0; i < sz; i++) {
          temp[i] = pMem[i] * val;
      }
      return temp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (this->sz != v.sz)
          throw exception("Error");
      TDynamicVector temp(v);
      for (int i = 0; i < sz; i++) {
          temp[i] = pMem[i] + v.pMem[i];
      }
      return temp;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (this->sz != v.sz)
          throw exception("Error");
      TDynamicVector temp(v);
      for (int i = 0; i < sz; i++) {
          temp[i] = pMem[i] - v.pMem[i];
      }
      return temp;
  }
  T operator*(const TDynamicVector& v) /*noexcept(noexcept(T()))*/
  {
      if (sz != v.sz) {
          throw "Error";
      }
      T temp{};
      for (int i = 0; i < sz; i++) {
          temp = temp + (pMem[i] * v.pMem[i]);
      }
      return temp;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; 
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; 
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
      if (sz == 0)
          throw out_of_range("Vector size should be greater than zero"); //Размер вектора должен быть больше нуля
      if (sz > MAX_MATRIX_SIZE)
          throw out_of_range("Size of the vector is larger than the allowed");
      for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];
  size_t size() const noexcept { return sz; }

  T& at(int a, int b)
  {
      if (((a < 0) || (b < 0)) || ((a > sz) || (b > sz)))
          throw "Error";
      return pMem[a][b];
  }

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      if (this->sz != m.sz)
          return 0;
      for (size_t i = 0; i < sz; i++)
          if (pMem[i] != m.pMem[i])
              return 0;
      return 1;
  }
  bool operator!=(const TDynamicMatrix& m) const noexcept
  {
      if (this->sz != m.sz)
          return 1;
      for (size_t i = 0; i < sz; i++)
          if (pMem[i] != m.pMem[i])
              return 1;
      return 0;
  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      TDynamicMatrix res(*this);
      for (size_t i = 0; i < sz; i++)
          res.pMem[i] = res.pMem[i] * val;
      return res;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (sz != v.sz)
          throw exception("Error");
      TDynamicVector<T> res(sz);
      for (size_t i = 0; i < sz; i++)
          res[i] = pMem[i] * v;
      return res;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw "Error";
      TDynamicMatrix res(*this);
      for (size_t i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] + m.pMem[i];
      return res;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw "Error";
      TDynamicMatrix res(*this);
      for (size_t i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] - m.pMem[i];
      return res;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw "Error";
      TDynamicMatrix res(*this);
      for (size_t i = 0; i < sz; i++)
          for (size_t j = 0; j < sz; j++)
              for (size_t k = 0; k < sz; k++)
                  res.pMem[i][j] += pMem[i][k] * m.pMem[k][j];
      return res;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
          for (size_t j = 0; j < v.sz; j++)
              istr >> v[i][j];
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
      {
          for (size_t j = 0; j < v.sz; j++)
          {
              ostr << v[i][j] << " ";
          }
          ostr << endl;
      }
      return ostr;
  }
};

#endif
