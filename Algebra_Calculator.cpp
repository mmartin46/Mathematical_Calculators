#include "Basic_Calculator.h"
#include "Algebra_Calculator.h"
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