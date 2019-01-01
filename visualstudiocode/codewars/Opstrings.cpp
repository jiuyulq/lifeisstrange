//https://www.codewars.com/kata/moves-in-squared-strings-i/cpp

#include<iostream>
#include<string>


//by jiuyu
//2016-11-22 15:00:51
class Opstrings
{
public:
  static std::string vertMirror(const std::string &strng) {
    int count = 0;          //计算一行字母数量
    for (auto c : strng) {
      if (c == '\n')
        break;
      ++count;
    }

    std::string result;
    
    //通过下标换算，直接插入result
    for (int i = 0; i < count; ++i) {
      for (int j = 0; j < count; ++j) {
        result.push_back(strng.at(count - 1 - j % (count + 1) + i * (count + 1)));
      }
      result.push_back('\n');
    }
    result.pop_back();

    return result;
  }


  static std::string horMirror(const std::string &strng) {
    int count = 0;          //计算一行字母数量
    for (auto c : strng) {
      if (c == '\n')
        break;
      ++count;
    }
    
    std::string result;

    //通过下标转换，直接插入result
    int j = 0;
    for (auto c : strng) {
      result.insert((j++) % (count + 1),1, c);
    }
    
    result.insert(j%(count+1), 1,'\n');
    result.pop_back();

    return result;
  }

  // your high order function oper
  //... oper(...); 
  template<typename Mirror>
  static std::string oper(Mirror func,const std::string &s){
      return func(s);
  }

};
