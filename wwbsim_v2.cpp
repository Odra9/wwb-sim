#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int highscore = 0;
long long turnCount = 0L;

class Player {
	public:
	Player(int p) {
		player = p;
		place = 0;
	}

	void roll() {
		turnCount++;
		
		if (rand()%6+1==5) {
			place++;
			
			if (rand()%6+1!=5)
				place=0; 
		}
	
		if (place>highscore) {
			highscore = place;
			cout << "Player " << player << " ha raggiunto la casella " << highscore << " in " << turnCount << " turni\n";
		}
	}

	private:
	int place;
	int player;
};

int main() {
	srand(time(NULL));

	Player player1(1);
	Player player2(2);

	while(true) {
		player1.roll();
		player2.roll();		
	}

	return 0;
}
