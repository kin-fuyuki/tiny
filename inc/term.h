#pragma once
#ifndef TINYTERM_H
#define TINYTERM_H


#include <cstdio>
#include <cstring>
#include <stdarg.h>
#include <string>

namespace tiny {

	
	
struct ErrorLevel {
    int value;
    ErrorLevel(int var){

        this->value=var;
    }
    void setvalue(int var){
        this->value=var;
    }
};

/*
-1: none
0: error
1: success
2: warning
3: message
4: echo

ex (i recommend using on main.cpp):
tiny::ErrorLevel tiny::level={1};
*/

extern tiny::ErrorLevel level;

#define WHITE   "\033[0m"       /* White */
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BGRED   "\033[41m"      /* Red */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define ending \
   mixer.append(info); mixer.append("\033[0m\n");\
   const char * finalinfo=mixer.c_str();\
   va_start (arg, finalinfo);\
   vfprintf (stdout, finalinfo, arg);\
   va_end (arg);

inline void echo(char * info,...){
   if (level.value==4)
   {
   va_list arg;
   std::string mixer=info;
   mixer.append("\n");
   const char * finalinfo=mixer.c_str();
   va_start (arg, finalinfo);
   vfprintf (stdout, finalinfo, arg);
   va_end (arg);}
}
inline void warning( char * info,...){
   if (level.value>=1)
   {
   va_list arg;
   std::string mixer=YELLOW;ending
}
}
inline void fatal( char * info,...){
   va_list arg;
   std::string mixer=BOLDWHITE+std::string(BGRED);ending
}
inline void error( char * info,...){
   if (level.value>=0)
   {
   va_list arg;
   std::string mixer=BOLDRED;ending
}}
inline void success(char * info , ...){
   if (level.value>=2)
   {
   va_list arg;
   std::string mixer=GREEN;ending}
}
inline void message(char * info , ...){
   if (level.value>=3)
   {
   va_list arg;
   std::string mixer=BOLDWHITE;ending}
}
inline void startup(char* game,char*version){
int lv=level.value;level.value=6;
    echo("%s %s",game,version);
    warning("be warned that");
    error("ERRORS MIGHT OCCUR!!!");
    success("but dont worry");
    message("this is not an error");
	fatal("I SWEAR");
level.value=lv;
}




}

#endif



