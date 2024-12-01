q2:
#include <stdio.h>
#include <string.h>

struct Player {
    int ballScores[12];
    char playerName[50];
    int totalScore;
};

int validateScore(int score) {
    return score >= 0 && score <= 6;
}

void playGame(struct Player *player) {
    player->totalScore = 0;
    printf("Enter scores for %s:\n", player->playerName);
    for (int i = 0; i < 12; i++) {
        printf("Ball %d: ", i + 1);
        int score;
        scanf("%d", &score);
        if (validateScore(score)) {
            player->ballScores[i] = score;
            player->totalScore += score;
        } else {
            player->ballScores[i] = 0;
        }
    }
}

void findWinner(struct Player player1, struct Player player2) {
    printf("\n--- Match Result ---\n");
    if (player1.totalScore > player2.totalScore) {
        printf("Winner: %s\n", player1.playerName);
    } else if (player2.totalScore > player1.totalScore) {
        printf("Winner: %s\n", player2.playerName);
    } else {
        printf("The match is a tie!\n");
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2) {
    printf("\n--- Match Scoreboard ---\n");
    for (int i = 0; i < 2; i++) {
        struct Player player = i == 0 ? player1 : player2;
        printf("%s's Performance:\n", player.playerName);
        for (int j = 0; j < 12; j++) {
            printf("Ball %d: %d\n", j + 1, player.ballScores[j]);
        }
        printf("Total Score: %d\n", player.totalScore);
        printf("Average Score: %.2f\n", player.totalScore / 12.0);
    }
}

int main() {
    struct Player player1, player2;

    printf("Enter name for Player 1: ");
    scanf("%s", player1.playerName);
    printf("Enter name for Player 2: ");
    scanf("%s", player2.playerName);

    playGame(&player1);
    playGame(&player2);

    displayMatchScoreboard(player1, player2);
    findWinner(player1, player2);

    return 0;
}
