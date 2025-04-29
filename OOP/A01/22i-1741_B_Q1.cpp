#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int ***init(int dimension);
void print_reward_locations(int ***matrix);
void play_game(int ***matrix);

int main() {
    int dimension;
    cout << "Enter dimension (length, breadth and height) of the matrix: ";
    cin >> dimension;
    int ***matrix = init(dimension);
    bool quit = false;
    int choice;
    while(!quit) {
        cout << "Enter choice:\n1. Initialize\n2. Print matrix\n3. Play\n4. Quit\n";
        cin >> choice;
        switch(choice) {
            case 1:
                matrix = init(dimension);
                break;
            case 2:
                print_reward_locations(matrix);
                break;
            case 3:
                play_game(matrix);
                break;
            case 4:
                quit = true;
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    }
    return 0;
}

int ***init(int dimension) {
    // Allocate memory for the 4D matrix
    int ***matrix = new int**[dimension];
    for(int i = 0; i < dimension; i++) {
        matrix[i] = new int*[dimension];
        for(int j = 0; j < dimension; j++) {
            matrix[i][j] = new int[dimension];
            for(int k = 0; k < 3; k++) {
                matrix[i][j][k] = rand() % 10 < 4 ? rand() % 10 + 1 : 0;
            }
        }
    }
    return matrix;
}

void print_reward_locations(int ***matrix) {
    cout << "Reward Locations:\n";
    int reward_count = 0;
	    for(int i = 0; i <dimension; i++) {
        for(int j = 0; j < dimension; j++) {
            for(int k = 0; k < dimension; k++) {
                for(int l = 0; l < 3; l++) {
                    if((matrix[i][j][k][1]) > 0) {
                        cout << "Reward_" << ++reward_count << ": " << i << "," << j << "," << k << ",";
                        switch(l) {
                            case 0:
                                cout << "PAST";
                                break;
                            case 1:
                                cout << "PRESENT";
                                break;
                            case 2:
                                cout << "FUTURE";
                                break;
                        }
                        cout << endl;
                    }
                }
            }
        }
    }
}

void play_game(int ***matrix) {                   //function definition
    int moves;
    cout << "Enter number of moves: ";
    cin >> moves;
    int x, y, z, t;
    cout << "Enter starting location (x,y,z,t): ";
    cin >> x >> y >> z >> t;
    int score = 0;
    for(int i = 0; i < moves; i++) {
        int reward_count = 0;
        int reward_indices[40][4];
        int reward_distances[40];
        for(int j = 0; j < dimension; j++) {
            for(int k = 0; k < dimension; k++) {
                for(int l = 0; l < dimension; l++) {
                    for(int m = 0; m < 3; m++) {
                        if(matrix[j][k][l][m] > 0) {
                            reward_indices[reward_count][0] = j;
                            reward_indices[reward_count][1] = k;
                            reward_indices[reward_count][2] = l;
                            reward_indices[reward_count][3] = m;
    int dx = j - x;
    int dy = k - y;
    int dz = l - z;
reward_distances[reward_count] = sqrt(dxdx + dydy + dzdz);
reward_count++;
               }
                     }
                          }
                     }
                        }
  cout << "Score for move " << i+1 << ": " << score << endl;
  cout << "Rewards and their distances: " << endl;
  for(int j = 0; j < reward_count; j++) {
  cout << "Reward_" << j+1 << ": Distance is " << reward_distances[j] << endl;
   }
  cout << "Enter new location (x,y,z,t): ";
  int new_x, new_y, new_z, new_t;
  cin >> new_x >> new_y >> new_z >> new_t;
bool reward_found = false;
  for(int j = 0; j < reward_count; j++) {
  if(reward_distances[j] == 0 && reward_indices[j][3] == new_t) {
  if(reward_indices[j][0] == new_x && reward_indices[j][1] == new_y && reward_indices[j][2] == new_z) {
  reward_found = true;
  score++;
}
} else if(reward_indices[j][3] == new_t) {
  int dx = reward_indices[j][0] - new_x;
  int dy = reward_indices[j][1] - new_y;
  int dz = reward_indices[j][2] - new_z;
  int distance = sqrt(dxdx + dydy + dzdz);
  if(distance == 0.5) {
  reward_found = true;
  score += 0.5;
}
}
}
  if(reward_found) {
 cout << "Reward found! ";
} else {
 cout << "No reward found. ";
}
 cout << "Current score: " << score << endl;
 x = new_x;
 y = new_y;
 z = new_z;
 t = new_t;
}
  cout << "Game over. Total score: " << score << endl;
}
