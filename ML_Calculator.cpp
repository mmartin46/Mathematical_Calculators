#include "Algebra_Calculator.h"

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
   ML_Calculator<double> ml;
   cout << ml.k_nearest_neighbor(n, n) << endl;
}
