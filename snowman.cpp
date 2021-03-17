#include <cstdio>
#include <string>
#include <iostream>
#include <stdexcept>
#include <array>

#include "snowman.hpp"

using namespace std;

namespace ariel
{


std::string hat(int n){
  std::string str = "";
  if(n==1){
        str+= " _===_\n";
  }
  else if(n==2){
        str+="  ___ \n.....\n";
  }
  else if(n==3){
          str+="  _ \n/_\\\n";
  }
  else if(n==4){
        str+="  ___ \n(_*_)\n";
      }
  return str;
}

std::string nose(int n){
  std::string str = "";
  if(n==1){
        str+=",";
  }
  else if(n==2){
        str+=".";
  }
  else if(n==3){
        str+="_";
  }
  else if(n==4){
        str+=" ";
  }
  return str;
}

std::string l_eye(int n){
    std::string str = "";
    if(n==1){
      str+="(.";
      }
    else if(n==2){
      str+="(o";
    }
    else if(n==3){
      str+="(O";
    }
    else if(n==4){
      str+="(-";
    }
    return str;
}

std::string r_eye(int n){
    std::string str="";
    if(n==1){
      str+=".)";
    }
    else if(n==2){
      str+="o)";
    }
    else if(n==3){
      str+="O)";
    }
    else if(n==4){
      str+="-)";
    }
    return str;
}

std::string l_arm(int n){
      std::string str="";
    if(n==1){
      str+="<";
    }
    else if(n==2){
      str+="\\";
    }
    else if(n==3){
      str+="/";
    }
    else if(n==4){
      str+=" ";
    }
    return str;
}

std::string r_arm(int n){
      std::string str ="";
    if(n==1){
      str+=">";
    }
    else if(n==2){
      str+="/";
    }
    else if(n==3){
      str+="\\";
    }
    else if(n==4){
      str+=" ";
    }
    return str;
}

std::string torso(int n){
      std::string str="";
    if(n==1){
      str+="( : )";
        }
    else if(n==2){
      str+="(] [)";
        }
    else if(n==3){
      str+="(> <)";
    }
    else if(n==4){
      str+="(   )";
    }
    return str;
}

std::string base(int n){
      std::string str="";
    if(n==1){
      str+="\n( : )\n";
    }
   else  if(n==2){
      str+="\n(\" \")\n";
    }
    else if(n==3){
      str+="\n(___)\n";
    }
    else if(n==4){
      str+="\n(   )\n";
    }
    return str;
}

//constexpr int _1=1,_2=2,_3=3,_4=4,_5=5,_6=6,_7=7;


std::string snowman (int n){
    std::string str;
    std::array<int, 8> arr;
    

     if(n>44444444||n<11111111){
         throw -1;
    }
    for(int i=0;i<8;i++)
    {
        if(n%10>4|| n%10<1){
            throw -1;
    }
   
      arr.at(7-i)=n%10;
      n= n/10;
    }

    // for(int i=0;i<8;i++){
    //     if(arr[i])
    // }

    str+=hat(arr[0]);

    if(arr[4]==2)
    {
      str+=l_arm(arr[4]);
      str+=l_eye(arr[2]);
      str+=nose(arr[1]);
      str+=r_eye(arr[3]);
      if(arr[5]==2)
      {
        str+=r_arm(arr[5]);
        str+="\n ";
        str+=torso(arr[6]);
      }
      else
      {
        str+="\n ";
        str+=torso(arr[6]);
        str+=r_arm(arr[5]);              
      }
    }
    else
    {
      str+=l_eye(arr[2]);
      str+=nose(arr[1]);
      str+=r_eye(arr[3]);
      if(arr[5] == 2)
      {
        str+=r_arm(arr[5]);
        str+="\n ";
        str+=l_arm(arr[4]);
        str+=torso(arr[6]);
      }
      else
      {
        str+="\n ";
        str+=l_arm(arr[4]);
        str+=torso(arr[6]);
        str+=r_arm(arr[5]);
      }
    }
    str+=base(arr[7]);
    return str;
    }
}
// int main(){
//     std::string str =  snowman(33232124);
//     cout << str;
// }