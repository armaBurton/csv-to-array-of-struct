#include <stdio.h>

typedef struct{                                     //Create struct Student
  char type;
  char name[50];
  int age;
  double average;
} Student;

int main(void){
  FILE *file;                                       //File pointer

  file = fopen("file.txt", "r");                    //Open file.txt in read mode

  if (file == NULL){
    printf("Error opening file.\n");
    return 1;
  }

  Student students[100];

  int read = 0;
  int records = 0;
  do{
    read = fscanf(file,                             //Read file data into array
                  "%c, %49[^,],%d, %lf\n",
                  &students[records].type,
                  students[records].name,
                  &students[records].age,
                  &students[records].average);

    if(read == 4)records++;                         //if read finds 4 entries increment records

    if(read != 4 && !feof(file)){                   //if read does not find 4 entries return error
      printf("File format incorrect.\n");
      return 1;
    }

    if(ferror(file)){
      printf("Error reading file.\n");
      return 1;
    }

  }while(!feof(file));

  fclose(file);

  printf("\n%d records read.\n\n", records);

  for (int i = 0; i < records; i++){                //Print individual lines form array of struct
    printf("%c %s %d %.2f\n",
           students[i].type, 
           students[i].name, 
           students[i].age, 
           students[i].average);
  }
  printf("\n");

  return 0;
}