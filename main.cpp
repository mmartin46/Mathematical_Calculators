#include <math.h>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
template <typename T>
class Calculator
{
   private:
      T first_value;
   public:
      virtual void add(T val) = 0;  // Adds a value to the Basic_Calculator.
      virtual void add(vector<T> vals) = 0; // Adds multiple values to the Basic_Calculator.
      virtual void sub(T val) = 0;  // Subtract a value from the Basic_Calculator.
      virtual void sub(vector<T> vals) = 0; // Subtracts values from the Basic_Calculator.
      virtual void mul(T val) = 0; // Multiply a value to the Basic_Calculator.
      virtual void mul(vector<T> vals) = 0; // Multiplies values to the Basic_Calculator.
      virtual void div(T val) = 0; // Divide a value from the Basic_Calculator.
      virtual void div(vector<T> vals) = 0; // Divide values from the Basic_Calculator.
      virtual void exp(T val) = 0; // Raise the value of the Basic_Calculator by a certain power.
};

// Basic_Calculator that performs basic arithmetic.
template <typename T>
class Basic_Calculator : public Calculator<T>
{
   private:
      T first_value;
   public:
      Basic_Calculator<T>() : first_value(0) {}
      Basic_Calculator<T>(T n) : first_value(n) {}
      void add(T val);  // Adds a value to the Basic_Calculator.
      void add(vector<T> vals); // Adds multiple values to the Basic_Calculator.
      void sub(T val);  // Subtract a value from the Basic_Calculator.
      void sub(vector<T> vals); // Subtracts values from the Basic_Calculator.
      void mul(T val); // Multiply a value to the Basic_Calculator.
      void mul(vector<T> vals); // Multiplies values to the Basic_Calculator.
      void div(T val); // Divide a value from the Basic_Calculator.
      void div(vector<T> vals); // Divide values from the Basic_Calculator.
      void exp(T val); // Raise the value of the Basic_Calculator by a certain power.
      inline void neg() { this->first_value = -this->first_value; }
      inline T get_value() const { return this->first_value; } // Returns the current value in the Basic_Calculator.
      inline void set_value(T val) { this->first_value = val; }; // Sets the current value in the Basic_Calculator.
      inline void reset() { this->first_value = 0; }

      Basic_Calculator<T> operator-(const Basic_Calculator<T> &rhs);
      Basic_Calculator<T> operator+(const Basic_Calculator<T> &rhs);
      Basic_Calculator<T> operator*(const Basic_Calculator<T> &rhs);
      Basic_Calculator<T> operator/(const Basic_Calculator<T> &rhs);
      
      Basic_Calculator<T>& operator++();
      Basic_Calculator<T> operator++(int);
      Basic_Calculator<T>& operator--();
      Basic_Calculator<T> operator--(int);

      Basic_Calculator<T>& operator=(const Basic_Calculator<T> &rhs);
      bool operator==(const Basic_Calculator<T> &rhs) const; 
      bool operator!=(const Basic_Calculator<T> &rhs) const;
      bool operator<(const Basic_Calculator<T> &rhs) const;
      bool operator<=(const Basic_Calculator<T> &rhs) const;
      bool operator>=(const Basic_Calculator<T> &rhs) const;
      bool operator>(const Basic_Calculator<T> &rhs) const;
};



template <typename T>
Basic_Calculator<T> Basic_Calculator<T>::operator*(const Basic_Calculator<T> &rhs)
{
   this->mul(rhs.get_value());
   return *this; 
}

template <typename T>
Basic_Calculator<T> Basic_Calculator<T>::operator/(const Basic_Calculator<T> &rhs)
{
   this->div(rhs.get_value());
   return *this;
}
template <typename T>
Basic_Calculator<T>& Basic_Calculator<T>::operator=(const Basic_Calculator<T> &rhs)
{
   if (this != &rhs)
   {
      this->set_value(rhs.get_value());
   }
   return *this;
}

template <typename T>
Basic_Calculator<T>& Basic_Calculator<T>::operator++()
{
   this->add(1);
   return *this;
}
template <typename T>
Basic_Calculator<T> Basic_Calculator<T>::operator++(int)
{
   Basic_Calculator<T> copy = *this;
   copy.add(1);
   return copy;  
}

template <typename T>
Basic_Calculator<T>& Basic_Calculator<T>::operator--()
{
   this->sub(1);
   return *this;
}
template <typename T>
Basic_Calculator<T> Basic_Calculator<T>::operator--(int)
{
   Basic_Calculator<T> copy = *this;
   copy.sub(1);
   return copy;
}



/* EQUIVALENCE */


template <typename T>
bool Basic_Calculator<T>::operator==(const Basic_Calculator<T> &rhs) const
{
   if (this->get_value() != rhs.get_value())
   {
      return false;
   }
   return true;
}
template <typename T>
bool Basic_Calculator<T>::operator!=(const Basic_Calculator<T> &rhs) const
{
   return !(*this == rhs);
}
template <typename T>
bool Basic_Calculator<T>::operator<(const Basic_Calculator<T> &rhs) const
{
   if (this->get_value() >= rhs.get_value())
   {
      return false;
   }
   return true;   
}
template <typename T>
bool Basic_Calculator<T>::operator>=(const Basic_Calculator<T> &rhs) const
{
   return !(*this < rhs);
}
template <typename T>
bool Basic_Calculator<T>::operator>(const Basic_Calculator<T> &rhs) const
{
   if (this->get_value() <= rhs.get_value())
   {
      return false;
   }
   return true;   
}
template <typename T>
bool Basic_Calculator<T>::operator<=(const Basic_Calculator<T> &rhs) const
{
   return !(*this > rhs);
}





// Only subtracts calculator values of the same type.
template <typename T>
Basic_Calculator<T> Basic_Calculator<T>::operator-(const Basic_Calculator<T> &rhs)
{
   Basic_Calculator<T> cal(*this);
   cal.sub(rhs.get_value());
   return cal;
}

// Only adds calculator values of the same type.
template <typename T>
Basic_Calculator<T> Basic_Calculator<T>::operator+(const Basic_Calculator<T> &rhs)
{
   Basic_Calculator<T> cal(*this);
   cal.add(rhs.get_value());
   return cal;
}


// Raise the value of the Basic_Calculator by a certain power.
template <typename T>
void Basic_Calculator<T>::exp(T val)
{
   this->first_value = static_cast<T>(pow(static_cast<double>(this->first_value), static_cast<double>(val)));
}
// Divide a value from the Basic_Calculator.
template <typename T>
void Basic_Calculator<T>::div(T val)
{
   this->first_value /= val;
}
// Divide values from the Basic_Calculator.
// Params: vector<T>
template <typename T>
void Basic_Calculator<T>::div(vector<T> vals)
{
   typename vector<T>::const_pointer ptr, end = vals.data() + vals.size();
   for (T *ptr = vals.data(); ptr < end; ++ptr)
   {
      this->first_value /= *ptr;
   }
}

/* MULTIPLICATION */

// Multiply a value to the Basic_Calculator.
template <typename T>
void Basic_Calculator<T>::mul(T val)
{
   this->first_value *= val;
}
// Multiplies values to the Basic_Calculator.
// Params: vector<T>
template <typename T>
void Basic_Calculator<T>::mul(vector<T> vals)
{
   typename vector<T>::const_pointer ptr, end = vals.data() + vals.size();
   for (T *ptr = vals.data(); ptr < end; ++ptr)
   {
      this->first_value *= *ptr;
   }
}

/* ADDITION */

// Adds a value to the Basic_Calculator.
template <typename T>
void Basic_Calculator<T>::add(T val)
{
   this->first_value += val;
}

// Adds multiple values to the Basic_Calculator.
// Params: vector<T>
template <typename T>
void Basic_Calculator<T>::add(vector<T> vals)
{
   typename vector<T>::const_pointer ptr, end = vals.data() + vals.size();
   for (T *ptr = vals.data(); ptr < end; ++ptr)
   {
      this->first_value += *ptr;
   }
}

/* SUBTRACTION */

// Subtract a value from the Basic_Calculator.
template <typename T>
void Basic_Calculator<T>::sub(T val)
{
   this->first_value -= val;
}
// Subtracts values from the Basic_Calculator.
// Params: vector<T>
template <typename T>
void Basic_Calculator<T>::sub(vector<T> vals)
{
   typename vector<T>::const_pointer ptr, end = vals.data() + vals.size();
   for (T *ptr = vals.data(); ptr < end; ++ptr)
   {
      this->first_value -= *ptr;
   }
}


/*
// FACTORY METHOD
template <typename T>
class Calculator_Factory
{
   private:
      Calculator<T>* calc;
   public:
      Calculator<T>* getCalculator(string s);
      ~Calculator_Factory<T>();
};

// Generates a calculator.
template <typename T>
Calculator<T>* Calculator_Factory<T>::getCalculator(string s)
{
   if (s == "BASIC")
   {
      calc = new Basic_Calculator<T>();
   }
   else
   {
      calc = NULL;
   }
   return calc;
}

template <typename T>
Calculator_Factory<T>::~Calculator_Factory<T>()
{
   if (calc)
   {
      delete calc;
      calc = NULL;
   }
}
*/

// Calculator that performs on algebric expressions
template <typename T>
class Algebra_Calculator : public Basic_Calculator<T>
{
   private:
      T first_value;
   public:
      Algebra_Calculator<T>() : Basic_Calculator<T>(0) {}
      Algebra_Calculator<T>(T n) : Basic_Calculator<T>(n) {}
      T euclidean_distance(T q_1, T p_1, T q_2, T q_3);
      T manhattan_disance(T x_1, T y_1, T x_2, T y_2);
      T double_angle_sin(T theta);
      T double_angle_cos(T theta);
      T double_angle_tan(T theta);
      T product_to_sum_sin_sin(T x, T y);
      T product_to_sum_cos_cos(T x, T y);
      T product_to_sum_sin_cos(T x, T y);
      T product_to_sum_cos_sin(T x, T y);
      T area_of_triangle(T a , T b, T c);
};      

// Returns the area of a triangle
// Parameters: a, b, c
template <typename T>
T Algebra_Calculator<T>::area_of_triangle(T a, T b, T c)
{
   Algebra_Calculator<T> cal;
   cal.add(a);
   c.add(b);
   cal.add(c);
   cal.div(2);
   T s = cal.get_value();
   cal.reset();
   cal.add( s * (s - a) );
   cal.mul( (s - b) );
   cal.mul( (s - c) );
   cal.set_value(sqrt(cal.get_value()));
}

template <typename T>
T Algebra_Calculator<T>::product_to_sum_sin_sin(T x, T y)
{
   Algebra_Calculator<T> c;
   Algebra_Calculator<T> c2;

   c.add(cos(x - y));
   c.sub(cos(x + y));
   c.exp(.5);
   return static_cast<T>(c.get_value());
}


template <typename T>
T Algebra_Calculator<T>::product_to_sum_cos_cos(T x, T y)
{
   Algebra_Calculator<T> c;
   Algebra_Calculator<T> c2;

   c.add(cos(x - y));
   c.add(cos(x + y));
   c.div(2);
   return static_cast<T>(c.get_value());
}

template <typename T>
T Algebra_Calculator<T>::product_to_sum_sin_cos(T x, T y)
{
   Algebra_Calculator<T> c;
   Algebra_Calculator<T> c2;

   c.add(sin(x + y));
   c.add(sin(x - y));
   c.div(2);
   return static_cast<T>(c.get_value());
}

template <typename T>
T Algebra_Calculator<T>::product_to_sum_cos_sin(T x, T y)
{
   Algebra_Calculator<T> c;
   Algebra_Calculator<T> c2;

   c.add(sin(x + y));
   c.sub(sin(x - y));
   c.div(2);
   cout << c.get_value() << endl;
   return static_cast<T>(c.get_value());
}


// Returns tan2(theta)
template <typename T>
T Algebra_Calculator<T>::double_angle_tan(T theta)
{
   Algebra_Calculator<T> c;
   c.add(static_cast<T>(2 * tan(theta)));

   Algebra_Calculator<T> c2;
   c2.add(static_cast<T>(1 - pow(tan(theta), 2)));
   c.div(c2.get_value());
   return static_cast<T>(c.get_value());
}

// Returns sin2(theta)
template <typename T>
T Algebra_Calculator<T>::double_angle_sin(T theta)
{ 
   T n = (sin(theta) * cos(theta));
   return n;
}

// Returns cos2(theta)
template <typename T>
T Algebra_Calculator<T>::double_angle_cos(T theta)
{
   Algebra_Calculator c1(cos(theta));
   c1.exp(2);

   Algebra_Calculator c2(sin(theta));
   c2.exp(2);
   c1.sub(c2.get_value());
}

// Returns the euclidean distance
// (q1 - p1)^2 + (q2 - p2)^2
template <typename T>
T Algebra_Calculator<T>::euclidean_distance(T q_1, T p_1, T q_2, T p_2)
{
   Algebra_Calculator<T> f1(q_1);
   f1.sub(p_1);
   f1.exp(2);
   Algebra_Calculator<T> f2(q_2);
   f2.sub(p_2);
   f2.exp(2);
   f1.add(f2.get_value());
   return static_cast<T>(sqrt(f1.get_value()));
}
// Returns the manhattan distance
// |x1 - x2| + |y1 - y2|
template <typename T>
T Algebra_Calculator<T>::manhattan_disance(T x_1, T y_1, T x_2, T y_2)
{
   Algebra_Calculator<T> f1(abs(x_1));
   f1.sub(abs(x_2));
   f1.set_value(abs(f1.get_value()));

   Algebra_Calculator<T> f2(abs(y_1));
   f2.sub(abs(y_2));
   f1.add(f2.get_value());
   return static_cast<T>(f1.get_value());
}

template <typename T>
class ML_Calculator
{
   public:
      T mean(const vector<T> &x);
      T k_nearest_neighbor(const vector<T> &x, const vector<T> &y);
      T standard_deviation(const vector<T> &x, int num_points);
      T sample_variance(const vector<T> &x);
      T weighted_sum(vector<T> &data, vector<T> &weights);
};

// Returns the weighted sum
// of all the values.
template <typename T>
T ML_Calculator<T>::weighted_sum(vector<T> &data, vector<T> &weights)
{
   double accum = 0;
   vector<T> result(data.size(), 0);
   for (int i = 0; i < data.size(); ++i)
   {
      if (i == 0)
      {
         result[i] = 1 * weights[i];
      }
      else
      {
         result[i] = data[i] * weights[i];
      }
   }
   for (const auto &val : data)
   {
      accum += val;
   }
   cout << accum << endl;
}


// Returns the sample variance of the data.
// x - x values
// s^2 = sum(x - mean)^2 / n - 1
template <typename T>
T ML_Calculator<T>::sample_variance(const vector<T> &x)
{
   Algebra_Calculator<T> c(standard_deviation(x, x.size()));
   c.exp(2);
   return c.get_value();
}

// Returns the mean of the data.
template <typename T>
T ML_Calculator<T>::mean(const vector<T> &x)
{
   int n = x.size();
   T acc = 0;
   for (const auto &val : x)
   {
      acc += val;
   }
   acc /= n;
   return acc;
}

// DEBUG
// Returns the K-Nearest Neighbor
// Parameters:
// x - x values
// y - y values
// D(x_i, x_j) = sqrt((x_i - x_j)^2 + (y_i - y_j)^2)
template <typename T>
T ML_Calculator<T>::k_nearest_neighbor(const vector<T> &x, const vector<T> &y)
{
   Algebra_Calculator<T> vals;
   double accumulator = 0;

   for (int i = 0; i < x.size(); ++i)
   {
      for (int j = 0; j < y.size(); ++j)
      {
         vals.add(x[i]);
         vals.sub(x[j]);
         vals.exp(2);
         vals.add(pow((y[i] - y[j]), 2));
         accumulator += vals.get_value();
      }
   }
   vals.reset();
   vals.set_value(accumulator);
   vals.exp(.5);
   return static_cast<T>(vals.get_value());
}

// Returns the standard deviation.
// x - Values of all data points
// SD = sqrt(sum(x_i - mean) / size(x))
template <typename T>
T ML_Calculator<T>::standard_deviation(const vector<T> &x, int num_points)
{
   T mean = this->mean(x);
   Algebra_Calculator<T> vals;

   typename vector<T>::const_pointer ptr, end = x.data() + x.size();
   for (ptr = x.data(); ptr < end; ++ptr)
   {
      vals.add(*ptr);
      vals.sub(mean);
   }
   vals.exp(2);
   vals.div(x.size());
   vals.exp(.5);
   return vals.get_value();
}

int main()
{
   vector<double> n = { 1, 2, 0, 20, 11, 3 };
   vector<double> r = { 0.2, 0.1, 0.0, 0.3, 0.4, 0.5 };
   ML_Calculator<double> ml;
}
