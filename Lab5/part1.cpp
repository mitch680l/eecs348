#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
int ring12(int n);

int main() {
  std::string months[] = {"January  ", "February ", "March    ", "April    ",
                          "May      ", "June     ", "July     ", "August   ",
                          "September", "October  ", "November ", "December "};
  double report[12];
  float minNum = 0.0;
  float maxNum = 0.0;
  float avgNum = 0.0;
  float sumNum = 0.0;
  std::ifstream myFile;
  std::string fileName;
  std::cout << "name for textfile: " << '\n' << '\n';
  std::cin >> fileName;

  myFile.open(fileName);

  for (int i = 0; i < 12; i++) {
   //this loop uses fstream to read the data
    float k;
    myFile >> k;
    report[i] = k;
    sumNum += k;
  }
  avgNum = sumNum / 12;
  minNum = report[0];
  maxNum = report[0];

  //basic search algorithm for min and max
  for (int i = 0; i < 12; i++) {
    if (report[i] > maxNum) {
      maxNum = report[i];
    }
    if (report[i] < minNum) {
      minNum = report[i];
    }
  }

  //outputs baisc sales report
  std::cout << '\n' << "Monthly sales report for 2022:" << '\n';
  for (int i = 0; i < 12; i++) {
    std::cout << std::setw(8) << months[i];
    std::cout << " $" << std::fixed << std::setprecision(2) << report[i]
              << '\n';
  }

  //outputs for average, max and min sales
  std::cout << '\n'
            << std::left << std::setw(15) << "Average: "
            << " $" << std::fixed << std::setprecision(2) << avgNum << '\n';
  std::cout << std::left << std::setw(15) << "Highest Sales: "
            << " $" << std::fixed << std::setprecision(2) << maxNum << '\n';
  std::cout << std::left << std::setw(15) << "Lowest Sales: "
            << " $" << std::fixed << std::setprecision(2) << minNum << '\n';


  for (int i = 0; i < 8; i++) {
    float six_month_sum = 0.0;
    for (int k = 0; k < 6; k++) {
      //finds 6 month interval by using a ring structure where 12 and above loops around(in a ring)
      int month = i + k;
      six_month_sum += report[ring12(month)];
    }
    //rolling 6 month sales report outputs
    std::cout << '\n' << std::setw(12) << std::left << months[i];
    std::cout << '-';
    std::cout << std::setw(12) << std::internal << months[ring12(i + 5)];
    std::cout << std::setw(12) << " $" << std::fixed << std::setprecision(2)
              << six_month_sum / 6 << '\n';
  }

  std::string sortedMonthes[12] = {"January  ", "February ", "March    ",
                                   "April    ", "May      ", "June     ",
                                   "July     ", "August   ", "September",
                                   "October  ", "November ", "December "};
  double sortedReport[12];

  //copies report to sortedReport to keep them seperated
  for (int i = 0; i < 12; i++) {
    sortedReport[i] = report[i];
  }

  //very basic bubble sort
  for (int i = 0; i < 12; i++) {
    for (int k = i; k < 11; k++) {
      if (sortedReport[k] > sortedReport[k + 1]) {

        int temp = sortedReport[k];
        sortedReport[k] = sortedReport[k + 1];
        sortedReport[k + 1] = temp;
        //sort the month strings at the same time
        std::string tempM = sortedMonthes[k];
        sortedMonthes[k] = sortedMonthes[k + 1];
        sortedMonthes[k + 1] = tempM;
      }
    }
  }
  //sorted sales summery outputs
  std::cout << '\n' << "Sales Report (Highest to Lowest):\n" << '\n';
  std::cout << std::setw(10) << "Month"
            << " Sales" << std::endl;
  for (int i = 11; i >= 0; i--) {
    std::cout << std::setw(10) << months[i] << " $" << std::fixed
              << std::setprecision(2) << report[i] << std::endl;
  }
}

int ring12(int n) {
  if (n >= 12) {
    return n - 12;
  } else {
    return n;
  }
}