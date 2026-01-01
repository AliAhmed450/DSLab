#include "task1/task1.h"
#include "task2/task2.h"
#include "task3/task3.h"
#include "task4/task4.h"
#include "task5/task5.h"
#include "task6/task6.h"
#include "task7/task7.h"
#include "task8/task8.h"
#include "task9/task9.h"
#include "task10/task10.h"
#include "task11/task11.h"
#include "task12/task12.h"
#include "task13/task13.h"
#include "task14/task14.h"
#include "task15/task15.h"
#include "task16/task16.h"
#include "task17/task17.h"
#include "task18/task18.h"
#include "task19/task19.h"
#include "task20/task20.h"
#include <iostream>

task1 t1;
task2 t2;
task3 t3;
task4 t4;
task5 t5;
task6 t6;
task7 t7;
task8 t8;
task9 t9;
task10 t10;
task11 t11;
task12 t12;
task13 t13;
task14 t14;
task15 t15;
task16 t16;
task17 t17;
task18 t18;
task19 t19;
task20 t20;

int main() {
  bool app = true;

  while (app) {
    cout << endl;
    cout << "\nEnter a number to open a program corresponding to the task given: ";
    cout << endl;
    int a;
    cin >> a;
    switch (a) {
    case 1:
      t1.main();
      break;
    case 2:
      t2.main();
      break;
    case 3:
      t3.main();
      break;
    case 4:
      t4.main();
      break;
    case 5:
      t5.main();
      break;
    case 6:
      t6.main();
      break;
    case 7:
      t7.main();
      break;
    case 8:
      t8.main();
      break;
    case 9:
      t9.main();
      break;
    case 10:
      t10.main();
      break;
    case 11:
      t11.main();
      break;
    case 12:
      t12.main();
      break;
    case 13:
      t13.main();
      break;
    case 14:
      t14.main();
      break;
    case 15:
      t15.main();
      break;
    case 16:
      t16.main();
      break;
    case 17:
      t17.main();
      break;
    case 18:
      t18.main();
      break;
    case 19:
      t19.main();
      break;
    case 20:
      t20.main();
      break;
    default:
      app = false;
      break;
    }
  }
}
