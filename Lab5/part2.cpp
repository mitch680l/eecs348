#include <iostream>
#include <vector>

void displayScoringBreakdown(int totalScore) {
    std::cout << "Scoring Breakdown:" << std::endl;
    for (int touchdowns = 0; touchdowns * 6 <= totalScore; touchdowns++) {
        //all td possiblities
        for (int fieldGoals = 0; fieldGoals * 3 <= totalScore - touchdowns * 6; fieldGoals++) {
            //all field goals
            for (int twoPointConversion = 0; twoPointConversion * 2 <= totalScore - touchdowns * 6 - fieldGoals * 3; twoPointConversion++) {
                    for (int extraPoints = 0; extraPoints * 1 <= totalScore - touchdowns * 6 - fieldGoals * 3 - twoPointConversion * 2; extraPoints++) {
                        
                        int score = touchdowns * 6 + fieldGoals * 3 + twoPointConversion * 2 + extraPoints;

                        //if checks
                        //touchdowns match the extra points
                        //if saftey points can cover the rest. AKA divisible by 2
                        if (twoPointConversion + extraPoints <= touchdowns && (totalScore - score) % 2 == 0) {
                            std::cout << "td(+0) " << touchdowns - (twoPointConversion + extraPoints); //6 point td with no extra points
                            std::cout << ", td(+1): " << extraPoints; //one point extra td
                            std::cout << ", td(+2): " << twoPointConversion; //two point extra td
                            std::cout << ", fg: " << fieldGoals; // feild goal
                            std::cout << " safety: " << (totalScore - score) / 2 << '\n' //the rest of the points are the safety's
                                << '\n';
                        }
                    }
               }
        }
    }

   
}

int main() {
    int totalScore;
    do {
        std::cout << "Enter the total score: " << '\n';
        std::cout << "Enter 0 or 1 to Stop:" << '\n';
        std::cin >> totalScore;
        if (totalScore > 1) {
            displayScoringBreakdown(totalScore);
        }
       
    } while (totalScore > 1);

    return 0;
}