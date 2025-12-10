#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#define BUF 1024
namespace smirnova 
{
  void check_common_characters(const char *a, const char *b, int *result, size_t n, size_t m)
  {
    for (size_t i = 0; i < n; i++)
    {
      for (size_t j = 0; j < m; j++)
      {
        if (a[i] == b[j])
        {
          *result = 1;
        }
      }
    }
  }
  void append_digits_from_second(const char *a, const char *b, char *result, size_t n, size_t m)
  {
    size_t count = 0;
    for (size_t i = 0; i < n; i++)
    {
      result[count++] = a[i];
    }
    for (size_t j = 0; j < m && count < BUF - 1; j++)
    {
      if (std::isdigit(static_cast<unsigned char>(b[j])))
      {
        result[count++] = b[j];
      }
    }
    result[count] = '\0';
  }
}
int main() 
{
  char *str1 = static_cast<char*>(malloc(BUF));
  char *str2 = static_cast<char*>(malloc(BUF));
  int result1 = 0;
  char *result2 = static_cast<char*>(malloc(BUF));
  if (!str1 || !str2 || !result2) {
      std::cerr << "Memory allocation error\n";
      return 1;
  }
  std::cin.getline(str1, BUF);
  if (str1[0] == '\0') {
        free(str1);
        free(str2);
        free(result2);
        return 0;
    }
  std::cin.getline(str2, BUF);
  if (str2[0] == '\0') {
    std::strcpy(str2, "default_string");
  }
  size_t n = std::strlen(str1);
  size_t m = std::strlen(str2);
  smirnova::check_common_characters(str1, str2, &result1, n, m);
  std::cout << result1 << "\n";
  smirnova::append_digits_from_second(str1, str2, result2, n, m);
  std::cout << result2 << "\n";
  free(str1);
  free(str2);
  free(result2);
  return 0;
}

