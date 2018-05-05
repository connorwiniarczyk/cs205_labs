#ifndef PLAYER_GAME_HISTORY_H
#define PLAYER_GAME_HISTORY_H

#include <vector>
#include <algorithm>


#include "game.h"
#include "player.h"

class Game;
class Player;
class Configuration;


class PlayerGameHistory {
public:
	PlayerGameHistory() {}

	~PlayerGameHistory() {
		std::for_each(players.begin(), players.end(), [](Player* element){
			delete(element);
		});

		std::for_each(games.begin(), games.end(), [](Game* element){
			delete(element);
		});
	}

	int games_played() { return games.size(); }
	int players() { return players.size(); }
	float avg_games_per_player() {
		return ((float)games_played() / (float)players());
	}

	int top_game_score() {
		int output = 0;
		std::for_each(games.begin(), games.end(), [](Game* game){
			if(game->score > output) output = game->score;
		});

		return output;
	}

	float avg_game_score() {
		int sum = std::accumulate(games.begin(), games.end(), 0, [](int accumulator, Game* game){
			return accumulator + game -> score;
		});

		return sum / games_played();
	}

	avg_score(Player* player) {
		std::vector<Game*> games_with_player = ;

	}


	std::vector<Player*> players;
	std::vector<Game*> games;
};

#endif