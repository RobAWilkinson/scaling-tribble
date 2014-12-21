#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct card {
  string suit;
  int value;
  string english_name;
};
card getCard()
{
  string suits[4] = {"Clubs","Spades","Hearts","Diamonds" };
  card acard;
  string playercard;
  int value;
  int random = rand() % 52 + 1;
  if(random <= 13){
    acard.value = random % 13;
    acard.value++;
    acard.suit = suits[0];
    playercard = to_string(random) + suits[0] ;
  }
  if( 13 < random && random <= 26){
    acard.value = random % 13;
    acard.value++;
    acard.suit = suits[2];
    playercard = to_string(random) + suits[1] ;
  }
  if( 26 < random && random<= 39){
    acard.value = random % 13 ;
    acard.value++;
    acard.suit = suits[2];
    playercard = to_string(random) + suits[2] ;
  } 
  if( random > 39) {
    acard.value = random % 13;
    acard.value++;
    acard.suit = suits[3];
    playercard = to_string(random) + suits[3] ;
  }
  switch(acard.value)
  {
    case 11:
      acard.english_name = "Jack";
      break;
    case 12:
      acard.english_name = "Queen";
      break;
    case 13:
      acard.english_name = "King";
    default:
      acard.english_name = to_string(acard.value);
  }
  return acard;
}
int getScore(card player_hand[5]){
  int sum = 0;
  for(int i =0; i < 5; i++){
    sum += player_hand[i].value;
  }
  return sum;
}
void play(string hit_or_stand, card player_hand[5], int index)
{
    if( hit_or_stand == "HIT"){

      player_hand[index] = getCard();
    cout << "you are dealt a: " << to_string(player_hand[index].value) << " of " << player_hand[index].suit << "\n";
    }
}

int main() 
{
  srand ( time(NULL) );
  card computer_hand [5];
  card player_hand[5];
  string hit_or_stand;
  

  player_hand[0] = getCard();
  cout << "you are dealt a: " << player_hand[0].english_name << " of " << player_hand[0].suit << "\n";
  player_hand[1] = getCard();
  cout << "you are dealt a: " << player_hand[1].english_name << " of " << player_hand[1].suit << "\n";
  computer_hand[0] = getCard();
  computer_hand[1] = getCard();
  cout << "The Computer has a: " << computer_hand[1].english_name << " of " << computer_hand[1].suit << " showing \n";
  cout << "Would you like to HIT or STAND?";
  cin >> hit_or_stand;
  play(hit_or_stand, player_hand, 2);
  if ( getScore(player_hand) > 21){
    cout << "BUST";
  }
  if( getScore(player_hand) < 21){
  cout << "Would you like to HIT or STAND?";
  cin >> hit_or_stand;
  play(hit_or_stand, player_hand, 3);
    if ( getScore(player_hand) > 21){
      cout << "BUST";
    }
  }
  if( getScore(player_hand) < 21){
  cout << "Would you like to HIT or STAND?";
  cin >> hit_or_stand;
  play(hit_or_stand, player_hand, 4);
    if ( getScore(player_hand) > 21){
      cout << "BUST";
    }
  }

    
  return 0;
}
// there is a deck of 52 cards
// a player receives a card
// the computer receives a random card
// the player receives a second random card
// the computer receives a second random card
// the player has the option to take another or hold
// if the player goes over 21 he busts
// when he holds
// if the computer is less than 17 he hits until he is over
