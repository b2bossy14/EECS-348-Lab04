#include <stdio.h>


int main() {

    int score;
    int total_score;


    do {
        
        printf("\nEnter 0 or 1 to stop \nEnter a score: ");
        scanf("%d", &score);

        // Initialize variables for each type of scoring play
        // I added total_score to track how many combinations there are in total
        total_score = 0;
        int num_td_2pt;
        int num_td_1pt;
        int num_td; 
        int num_fg;
        int num_safety;

        // Loop through all possible score combinations
        for (num_td_2pt = 0; num_td_2pt <= score / 8; num_td_2pt++) {
            for (num_td_1pt = 0; num_td_1pt <= (score - num_td_2pt * 8) / 7; num_td_1pt++) {
                for (num_td = 0; num_td <= (score - num_td_2pt * 8 - num_td_1pt * 7) / 6; num_td++) {
                    for (num_fg = 0; num_fg <= (score - num_td_2pt * 8 - num_td_1pt * 7 - num_td * 6) / 3; num_fg++) {
                        for (num_safety = 0; num_safety <= (score - num_td_2pt * 8 - num_td_1pt * 7 - num_td * 6 - num_fg * 3) / 2; num_safety++) {

                            // Check if the combinations add up to the score
                            // Print all possible combination
                            if (num_td_2pt * 8 + num_td_1pt * 7 + num_td * 6 + num_fg * 3 + num_safety * 2 == score) {
                                total_score += 1;
                                printf("[%d TD + 2PT], [%d TD + PAT], [%d TD], [%d FG], [%d Safety]\n", num_td_2pt, num_td_1pt, num_td, num_fg, num_safety);

                            }
                        }
                    }
                }
            }
        }

        printf("\n%d total combinations\n", total_score);

    // Until the user inputs 0 or 1, the progam will continue to ask for scores
    } while (score >= 2);


}