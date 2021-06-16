#include <iostream>
#include <map>

template <typename T>
class Arithmetic_operations
{
public:
    T sum(T a, T b)
    {
        return a + b;
    }
    T sub(T a, T b)
    {
        return a - b;
    }
    T mul(T a, T b)
    {
        return a * b;
    }
    T divide(T a, T b)
    {
        return (b != 0) ? a / b : 0;
    }
};

int main()
{
    int (Arithmetic_operations<int>:: * ptfptr_sum) (int, int) = &Arithmetic_operations<int>::sum;
    int (Arithmetic_operations<int>:: * ptfptr_m) (int, int) = &Arithmetic_operations<int>::mul;
    int (Arithmetic_operations<int>:: * ptfptr_d) (int, int) = &Arithmetic_operations<int>::divide;
    int (Arithmetic_operations<int>:: * ptfptr_sub) (int, int) = &Arithmetic_operations<int>::sub;
  
    Arithmetic_operations<int> ob;
    int a, b;
    char symb;
  
   std:: cin >> a >> symb >> b;
   std:: map<char, int> mp;

       mp['+'] = (ob.*ptfptr_sum)(a, b);
       mp['-'] = (ob.*ptfptr_sub)(a, b);
       mp['*'] = (ob.*ptfptr_m)(a, b);
       mp['/'] = (ob.*ptfptr_d)(a, b);
       
       for (auto it = mp.cbegin(); it != mp.cend(); ++it)
       {
           std::cout << it->first << " "<< it->second << "\n";
       }

}
