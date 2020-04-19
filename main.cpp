#include <iostream>
#include <unistd.h>
using namespace std;

struct CAR{
  string plateNum;
  string model;
  string colorWay;
  string manufactureDate;
  int kilometers;
  char condition;
  float score;
  bool rented;
  float prize;
};
//data
/*******************/
bool Create(CAR* cars,int& size,string plateNum,string model,string colorWay, string manufactureDate,int kilometers,char condition,float score,float prize)
{
  if(size >99)
  {
    return false;
  }
  cars[size].plateNum = plateNum;
  cars[size].model = model;
  cars[size].colorWay = colorWay;
  cars[size].manufactureDate = manufactureDate;
  cars[size].kilometers = kilometers;
  cars[size].condition = condition;
  cars[size].score = score;
  cars[size++].prize = prize;
  return true;
}
bool Rent(CAR* cars, int index)
{
  if(!cars[index].rented)
  {
    cars[index].rented = !cars[index].rented;
  }
  else
  {
    return false;
  }
  return true;
}
bool Return(CAR* cars, int index)
{
  if(cars[index].rented)
  {
    cars[index].rented = !cars[index].rented;
  }
  else
  {
    return false;
  }
  return true;
}

bool Update(CAR* cars, int value , int i, string stat)
{
  if(stat == "kilometers")
  {
    cars[i].kilometers = value;    
  }
  else
  {
    return false;
  }
  return true;
}
bool Update(CAR* cars, string value, int i,string stat)
{
  if(stat == "plateNum")
  {
    cars[i].plateNum = value;
  }
  else if(stat == "model")
  {
    cars[i].model = value;
  }
  else if(stat == "colorWay")
  {
    cars[i].colorWay = value;
  }
  else if(stat == "manufactureDate")
  {
    cars[i].manufactureDate = value;
  }
  else if(stat == "condition")
  {
    cars[i].condition = value[0];
  }
  else
  {
    return false;
  }
  return true;
}
bool Update(CAR* cars, float value, int i,string stat)
{
  if(stat == "score")
  {
    cars[i].score = value;
  }
  else if(stat == "prize")
  {
    cars[i].prize = value;
  }
  else
  {
    return false;
  }
  return true;
}
bool Update(CAR* cars,bool value, int i,string stat)
{
 if(stat == "rented")
 {
   cars[i].rented = value;
 } 
 else
  {
    return false;
  }
  return true;
}

void RemoveCar(CAR* cars, int& size, int index)
{
  for(int i = index;i<=size;i++)
  {
    cars[i] = cars[i+1];
  }
  size--;
}
/*******************/

//presentation
/*******************/
void CoolPrint(string text)
{
  for(int i =0;i<text.size();i++)
  {
    if(text[i]=='`')
    {
    cout.flush();
    usleep(1000000);
    }
    else
    {
    cout << text[i];
    }
    cout.flush();
    usleep(100000);
  }
}

void ShowAllCars(CAR* cars, int& size)
{
  string message = "List of all the cars: \n";
  CoolPrint(message);
  for(int i =0;i<size;i++)
  {
    cout << " " << i+1 << ". " << cars[i].model << " , " << cars[i].plateNum << " , " << cars[i].colorWay << " , " << cars[i].manufactureDate << " , " << cars[i].kilometers << "km , " << cars[i].condition << " , " << cars[i].score << " to 10 , ";
    if(cars[i].rented)
    {
      cout << "rented , ";
    }
    else
    {
      cout << "free , ";
    }
    cout << cars[i].prize << endl;
  }
}


void EnterCarDetails(CAR* cars, int& size)
{
  CoolPrint("OK, now enter your car data in this order: `\n plateNum model colorWay manufactureDate kilometers condition score prize `\n\n");
  string plateNum, model , colorWay , manufactureDate;
  int kilometers;
  char condition;
  float score, prize;
  cin >> plateNum >> model >> colorWay >> manufactureDate >> kilometers >> condition >> score >> prize;
  if(Create(cars, size , plateNum,model,colorWay,manufactureDate,kilometers,condition,score,prize)){
    CoolPrint("Successfuly bought! `\n\n");
  }
  else{
    CoolPrint("Error. Maximum limit cars reached. `\n\n");
  }
}

bool MainMenu(CAR* cars, int& size)
{
  int index;
  string stat;
  string start = "List: \n 1.Buy a car. \n 2.Quit. \n\n";
  string then = "List: \n 1.Buy a car. \n 2.Rent a car. \n 3.Update car slot. \n 4.Remove a car. \n 5.See all models. \n 6.Return a car. \n 7.Quit `\n\n";
  string rentReturn = "Choose a car by its index (the first number).`\n\n";
  string update = "Choose an index and stat to update(the first number is the index). `\nThe stats are (plateNum , model , colorWay , manufactureDate , kilometers , condition , score , rent , prize) `\nThe input should look like this: `\n 2 plateNum A23BC  `\n\n";
  string remove = "Choose the index of the car you want to remove from the list(the first number is the index) `\n\n";
  if(size==0)
  {
    CoolPrint(start);
  }
  else
  {
    CoolPrint(then);
  }
  int option;
  cin >> option;
  if(size==0)
  {
    if(option==1)
    {
    EnterCarDetails(cars,size);
    }
    if(option==2)
    return false;
  }
  else
  {
    if(option ==1)
    {
    EnterCarDetails(cars,size);
    }
    if(option ==2)
    {
      ShowAllCars(cars, size);
      CoolPrint(rentReturn);
      cin >> index;
      if(Rent(cars,index))
      {
        CoolPrint("Successfuly rented `\n\n");
      }
      else
      {
        CoolPrint("This car is already rented `\n\n");
      }
    }
    if(option == 3)
    {
      CoolPrint(update);
      cin >> index >> stat;
      index--;
      if(stat == "plateNum" || stat == "model"|| stat == "colorWay" || stat =="manufactureDate" ||stat == "condition")
      {
        string value;
        cin >> value;
        if(Update(cars, value,index,stat))
        {
        CoolPrint("Successfuly updated. \n\n");
        }
        else
        {
          CoolPrint("Incorrect input. Try again. `\n\n");
        }
      }
      else if(stat == "kilometers")
      {
        int value;
        cin >> value;
         if(Update(cars, value,index,stat))
        {
        CoolPrint("Successfuly updated. \n\n");
        }
        else
        {
          CoolPrint("Incorrect input. Try again. `\n\n");
        }
      }
      else if(stat == "score" || stat == "prize")
      {
        float value;
        cin >> value;
         if(Update(cars, value,index,stat))
        {
        CoolPrint("Successfuly updated. \n\n");
        }
        else
        {
          CoolPrint("Incorrect input. Try again. `\n\n");
        }
      }
      else if(stat == "rented")
      {
        bool value;
        cin >> value;
         if(Update(cars, value,index,stat))
        {
        CoolPrint("Successfuly updated. \n\n");
        }
        else
        {
          CoolPrint("Incorrect input. Try again. `\n\n");
        }
      }
    }
    if(option == 4)
    {
      CoolPrint("Enter the index of the car you want to remove. `\n\n");
      cin >> index;
      index--;
      RemoveCar(cars, size, index);
      CoolPrint("`\nSuccessfuly removed `\n\n");
    }
    if(option == 5)
    {
      ShowAllCars(cars, size);
    }
    if(option == 6)
    {
      CoolPrint("Enter the index of the car you want to return. `\n\n");
      if(Return(cars, index))
      {
        CoolPrint("`\nSuccessfuly returned.`\n\n");
      }
      else
      {
        CoolPrint("`\nThe car is already free.`\n\n");
      }
    }
    if(option == 7)
    {
      return false;
    }
  }
  return true;
}

void Greetings()
{
  string hello = "Hello!`\nWelcome to CarRentINC!`\nChoose an option from the main menu down below. `\n\n";
  CoolPrint(hello);
}

/*******************/

int main() {
  CAR cars[1000];
  string quit = "OK,` bye!\n";
  int size =0;
  Greetings();
  while(MainMenu(cars,size));
  CoolPrint(quit);
}