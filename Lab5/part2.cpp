#include <iostream>
#include <vector>

void displayScoringBreakdown(int totalScore) {

  for (int touchdowns = 0; touchdowns * 6 <= totalScore; touchdowns++) {
    for (int fieldGoals = 0; fieldGoals * 3 <= totalScore - touchdowns * 6;
         fieldGoals++) {
      for (int twoPointConversion = 0;
           twoPointConversion * 2 <=
           totalScore - touchdowns * 6 - fieldGoals * 3;
           twoPointConversion++) {
        for (int extraPoints = 0;
             extraPoints * 1 <= totalScore - touchdowns * 6 - fieldGoals * 3 -
                                    twoPointConversion * 2;
             extraPoints++) {
          int score = touchdowns * 6 + fieldGoals * 3 + twoPointConversion * 2 +
                      extraPoints;
          if (twoPointConversion + extraPoints < touchdowns &&
              (totalScore - score) % 2 == 0) {
            std::cout << "touchdowns: " << touchdowns
                      << ", field goals: " << fieldGoals;
            std::cout << " extra 2pt: " << twoPointConversion
                      << ", extra 1pt: " << extraPoints;
            std::cout << " safety: " << (totalScore - score) / 2 << '\n'
                      << '\n';
          }
        }
      }
      if (touchdowns == 0 && (totalScore - fieldGoals * 3) % 2 == 0) {
        std::cout << "touchdowns: 0,";
        std::cout << " field goals: " << fieldGoals;
        std::cout << " extra 2pt: 0, extra 1pt: 0";
        std::cout << " safety: " << (totalScore - fieldGoals * 3) / 2 << '\n'
                  << '\n';
      }
    }
  }

  // Display the breakdown for each scoring combination
  std::cout << "Scoring Breakdown:" << std::endl;
}

int main() {
  int totalScore;
  std::cout << "Enter the total score: ";
  std::cin >> totalScore;

  displayScoringBreakdown(totalScore);

  return 0;
}