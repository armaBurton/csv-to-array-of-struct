#include <iostream>
// #include <string>
#include <stdio.h>

// using namespace std;

// typedef struct {
//   // std::string dirtBike;
//   // std::string seatHeight;
//   // std::string length;
//   // std::string width;
//   // std::string weight;
//   char dirtBike[50];
//   char seatHeight[10];
//   char length[10];
//   char width[10];
//   char weight[10];

// } Dirtbike;

typedef struct{
  char type;
  char name[50];
  int age;
  double average;
} Student

int main(void){
  FILE *file;

  file = fopen("file.txt", "r");

  if (file == NULL){
    printf("Error opening file.\n");
    return 1;
  }

  Student students[100];

  int read = 0;
  int records = 0;
  do{
    read = fscanf(file,
                  "%c, %49[^,],%d, %lf\n",
                  &students[records].type,
                  students[records].name,
                  &students[records].age,
                  &students[records].average
                );


  }while(!feof(file));



  return 0;
}