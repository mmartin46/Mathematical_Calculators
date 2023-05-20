#ifndef ALGEBRA_CALCULATOR
#define ALGEBRA_CALCULATOR
#include "Basic_Calculator.h"
using namespace std;

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

#endif